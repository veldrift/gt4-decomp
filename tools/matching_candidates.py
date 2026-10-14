"""Bounded source candidates and strict, canonical acceptance shared by solvers."""
from dataclasses import dataclass
import hashlib
from pathlib import Path
import re
import subprocess
import sys

import asm_policy
import layout
import project

RULE_VERSION = 1
LIMIT = 16


@dataclass(frozen=True)
class Candidate:
    address: int
    source: str
    extension: str
    rules: tuple = ()

    def __post_init__(self):
        if self.extension not in ('.c', '.cpp'):
            raise ValueError('Expected .c or .cpp')

    @property
    def sha256(self):
        return hashlib.sha256(self.source.encode()).hexdigest()


def policy(source):
    bad = asm_policy.violations(source)
    # m2c's standard prelude defines placeholders even when the function never
    # uses them. Check usage separately; an unused definition is not an operation.
    body = re.sub(r'(?m)^\s*#.*(?:\\\n[^\n]*)*', '', source)
    if re.search(r'\b(?:M2C_(?:ERROR|TRAP\w*|BREAK|SYNC|LWL|FIRST3BYTES|UNALIGNED\w*|BITWISE|CARRY|OVERFLOW|DCACHE\w*|ICACHE\w*|PREFETCH\w*|LOAD_\w*|STORE_\w*|CMP_STR|TAS_B)|GLUE_F64|D?MULTU?_HI|CLZ|REVERSE_BITS|ROTATE_RIGHT|ARM_RRX|BSWAP\w*)\b', body):
        bad.append('unsupported m2c operation')
    return bad


def verdict(returncode, output):
    """Process success or a low difference score alone is never acceptance."""
    if 'REJECTED' in output:
        state = 'rejected'
    elif returncode == 0 and re.search(r': MATCH \((\d+) instructions\)', output):
        state = 'unchecked-reference' if 'could not be checked' in output else 'match'
    elif 'instructions differ' in output:
        state = 'differs'
    else:
        state = 'compile-error'
    diff = re.search(r'(\d+) of (\d+) instructions differ', output)
    matched = re.search(r': MATCH \((\d+) instructions\)', output)
    return {'state': state, 'differ': int(diff[1]) if diff else (0 if state == 'match' else 10**6),
            'total': int(diff[2]) if diff else (int(matched[1]) if matched else None),
            'output': output}


def check(candidate, directory, timeout=120):
    directory = Path(directory)
    directory.mkdir(parents=True, exist_ok=True)
    path = directory / (f'{candidate.address:08X}-{candidate.sha256[:16]}' + candidate.extension)
    path.write_text(candidate.source, encoding='utf-8', newline='\n')
    bad = policy(candidate.source)
    if bad:
        result = {'state': 'rejected', 'differ': 10**6, 'total': None, 'output': '; '.join(bad)}
    else:
        try:
            p = subprocess.run([sys.executable, str(Path(project.ROOT)/'tools/match.py'),
                                'check', f'{candidate.address:08X}', str(path)],
                               capture_output=True, text=True, timeout=timeout)
            result = verdict(p.returncode, p.stdout + p.stderr)
        except subprocess.TimeoutExpired:
            result = {'state': 'timeout', 'differ': 10**6, 'total': None, 'output': 'judge timed out'}
    log = path.with_suffix(path.suffix + '.judge.txt')
    log.write_text(result['output'], encoding='utf-8')
    return dict(result, path=str(path), log_path=str(log), rules=list(candidate.rules),
                candidate_sha256=candidate.sha256, extension=candidate.extension)


def promote(candidate, directory):
    """Coordinator-only promotion. Existing source wins; no overwrite or flat staging."""
    existing = project.source_for(candidate.address)
    if existing:
        return {'state': 'existing', 'path': str(existing)}
    result = check(candidate, directory)
    if result['state'] != 'match':
        return result
    dest = Path(project.ROOT) / layout.path_for(candidate.address, candidate.extension)
    dest.parent.mkdir(parents=True, exist_ok=True)
    created = False
    try:
        # Recheck the other extension in case another coordinator already accepted it.
        if project.source_for(candidate.address):
            return {'state': 'existing', 'path': str(project.source_for(candidate.address))}
        with dest.open('x', encoding='utf-8', newline='\n') as stream:
            stream.write(candidate.source)
        created = True
        p = subprocess.run([sys.executable, str(Path(project.ROOT)/'tools/match.py'),
                            'check', f'{candidate.address:08X}', str(dest)],
                           capture_output=True, text=True, timeout=120)
        final = verdict(p.returncode, p.stdout + p.stderr)
        if final['state'] != 'match':
            raise RuntimeError('Canonical recheck failed: ' + final['output'])
        project.sources(refresh=True)
        return dict(final, path=dest.relative_to(project.ROOT).as_posix())
    except BaseException:
        if created:
            dest.unlink()
            project.sources(refresh=True)
        raise


def cpp_source(source):
    if 'extern "C"' in source:
        return source
    marker = re.match(r'/\* compiler: [\w.+-]+ \*/\s*\n', source)
    prefix = marker[0] if marker else ''
    body = source[len(prefix):]
    return prefix + 'extern "C" {\n' + body + '\n}\n'


def ignored_returns(source):
    """Reuse the existing fragment transformation on discarded call results."""
    import fragments
    # Ctx needs the generated func_ADDR header; no diff means examine all eligible calls.
    m = re.search(r'\bfunc_([0-9A-Fa-f]{8})\([^;{}]*\)\s*\{', source)
    if not m:
        return
    ctx = fragments.Ctx(int(m[1], 16), source, [], None, [], [])
    edits = []
    for label, changed in fragments.mut_callee_ret(ctx):
        # Only discard an unknown/int callee result, never change a used result to void.
        if len(re.findall(r'^void func_', changed, re.M)) > len(re.findall(r'^void func_', source, re.M)):
            edits.append((label, changed))
            yield label, changed
    combined = source
    for _, changed in edits:
        for before, after in zip(source.splitlines(), changed.splitlines()):
            if before != after:
                combined = combined.replace(before, after, 1)
    if len(edits) > 1:
        yield 'callee:ret-all', combined


def corrections(source):
    """Small, guarded transformations. Unrecognized source is left alone."""
    import fragments
    yield from fragments.deterministic_edits(source)


def variants(address, source, extension='.c', limit=LIMIT, frontends='both', corrections_enabled=True):
    seen = set()
    count = 0
    bases = [('original', source)]
    bases.extend(ignored_returns(source) or [])
    if corrections_enabled:
        bases.extend(corrections(source))
    for label, text in bases:
        options = [(extension, text, (label,))]
        if frontends == 'both' and extension == '.c':
            options.append(('.cpp', cpp_source(text), (label, 'frontend:cpp')))
        elif frontends == 'cpp' and extension == '.c':
            options = [('.cpp', cpp_source(text), (label, 'frontend:cpp'))]
        for ext, body, rules in options:
            key = (ext, hashlib.sha256(body.encode()).hexdigest())
            if key in seen:
                continue
            seen.add(key)
            yield Candidate(address, body, ext, rules)
            count += 1
            if count >= limit:
                return
