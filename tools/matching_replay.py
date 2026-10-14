"""Prepare local regression inputs and replay bounded candidates without src writes.

    matching_replay.py prepare
    matching_replay.py run [--suite known|fresh|all] [--baseline] [--limit N]
Real drafts/evidence remain ignored; accepted source is an oracle, never a candidate.
"""
import argparse
import ast
import csv
import hashlib
import json
from pathlib import Path
import subprocess
import time

import autoloop
import cpu_solve
import inventory
import layout
import match
import project
import matching_candidates as mc
import virtual_forwarders as vf

ROOT = Path(project.ROOT)
OUT = ROOT/'build/auto/deterministic'


def digest(path):
    return hashlib.sha256(Path(path).read_bytes()).hexdigest()


def atomic_json(path, value):
    path = Path(path)
    path.parent.mkdir(parents=True, exist_ok=True)
    temporary = path.with_suffix(path.suffix + '.tmp')
    temporary.write_text(json.dumps(value, indent=2) + '\n')
    temporary.replace(path)


def fingerprints():
    files = [ROOT/project.CONFIG['game']['executable'], ROOT/'project.toml']
    files += sorted((ROOT/'tools').glob('*.py')) + sorted((ROOT/'config').glob('*.txt'))
    values = {str(p.relative_to(ROOT)): digest(p) for p in files}
    configs = [project.CONFIG['compiler']] + list(project.CONFIG.get('compilers', {}).values())
    for config in configs:
        directory = Path(config['dir']).expanduser()
        for subdir in ('bin', 'lib/gcc-lib'):
            for path in sorted((directory/subdir).rglob('*')):
                if path.is_file(): values[str(path)] = digest(path)
    return values


def prepare():
    OUT.mkdir(parents=True, exist_ok=True)
    checkpoint = ROOT/'build/auto/geometry-wrappers'
    cases = []
    for group, results in [('frontend', 'cpp-results.json'), ('prototype', 'call-results.json')]:
        for row in json.loads((checkpoint/'race-small'/results).read_text()):
            addr = row['address']
            # The successful historical frontend log identifies which pre-C++ input was used.
            source = checkpoint/'race-small'/(addr+'-best.c')
            if group == 'frontend':
                options = ['-best.c', '-void-calls.c', '-refined.c']
                for i, suffix in enumerate(options):
                    log = checkpoint/'race-small'/(addr+'-cpp'+str(i)+'.judge.txt')
                    if log.exists() and log.read_text().strip() == 'MATCH':
                        source = checkpoint/'race-small'/(addr+suffix)
                        break
            if not source.exists():
                raise ValueError('Missing pre-success draft: ' + str(source))
            cases.append({'address': addr, 'family': group, 'path': source.relative_to(ROOT).as_posix(),
                          'sha256': digest(source), 'extension': '.c', 'expected': 'match'})
    initial = json.loads((checkpoint/'results.json').read_text())
    for row in initial:
        cases.append({'address': row['address'], 'family': 'wrapper', 'expected': 'match'})
    for addr in ('003BC5A8', '00390478', '004386C8'):
        p = checkpoint/(addr+'.cpp')
        cases.append({'address': addr, 'family': 'correction', 'path': p.relative_to(ROOT).as_posix(),
                      'sha256': digest(p), 'extension': '.cpp', 'expected': 'match'})
    # Reconstruct a pre-tail-return draft from the historical manual script, not src/.
    tree = ast.parse((checkpoint/'model.py').read_text())
    original = next(ast.literal_eval(n.value) for n in tree.body if isinstance(n, ast.Assign)
                    and isinstance(n.targets[0], ast.Subscript)
                    and isinstance(n.targets[0].slice, ast.Constant) and n.targets[0].slice.value == '0038FEB0')
    before = original.replace('int func_', 'void func_').replace('return func_003EDA10(0);', 'func_003EDA10(0);')
    before = before.replace('if (arg1 != 0) return func_00450AB0((char *)arg0 + 0x18, arg1);',
                            'if (arg1 != 0) { func_00450AB0((char *)arg0 + 0x18, arg1); return; }')
    p = OUT/'inputs/0038FEB0-before.cpp'
    p.parent.mkdir(parents=True, exist_ok=True)
    p.write_text(before)
    cases.append({'address': '0038FEB0', 'family': 'correction', 'path': p.relative_to(ROOT).as_posix(),
                  'sha256': digest(p), 'extension': '.cpp', 'expected': 'match',
                  'origin': 'reconstructed from model.py before the explicit void-tail-return edit'})
    asm_only = inventory.asm_functions()
    base, text = match.load_text()
    fresh = []
    for row in sorted(csv.DictReader(open(match.FUNCTIONS)), key=lambda r: int(r['address'], 16)):
        addr = int(row['address'], 16)
        if not 0x0032F028 <= addr < 0x0044D410 or addr in asm_only or project.source_for(addr):
            continue
        words = match.trim_padding(match.words_at(base, text, addr, int(row['max_size'])))
        if len(words)*4 > 64 or autoloop.other_compiler(words): continue
        fresh.append({'address': f'{addr:08X}', 'family': 'fresh', 'expected': None})
        if len(fresh) == 50: break
    # Never regenerate the fresh sample or its drafts on resume.
    manifest_path = OUT/'manifest.json'
    if manifest_path.exists():
        old = json.loads(manifest_path.read_text())
        fresh = old['fresh']
    for row in fresh:
        if row.get('inputs'):
            continue
        addr = int(row['address'], 16)
        directory = OUT/'fresh'/row['address']
        directory.mkdir(parents=True, exist_ok=True)
        row['inputs'] = []
        body = cpu_solve.draft(addr, out=str(directory))
        if body and 'M2C_ERROR' not in body:
            body = cpu_solve.prepared(addr, body, str(directory/'prepared.c'))
            for index, (how, draft) in enumerate(cpu_solve.variants(addr, body, out=str(directory))):
                path = directory/(str(index)+'.c')
                path.write_text(cpu_solve.PRELUDE + draft)
                row['inputs'].append({'path': path.relative_to(ROOT).as_posix(), 'sha256': digest(path),
                                      'extension': '.c', 'rules': [how]})
        atomic_json(manifest_path, {'schema_version': 1, 'known': cases, 'fresh': fresh})
        print('Prepared', row['address'], flush=True)
    atomic_json(manifest_path, {'schema_version': 1, 'baseline_revision': 'e4a78642f474453900f725bf0df5d11bd13aa248',
                               'known': cases, 'fresh': fresh})
    report = {'python': subprocess.check_output(['python', '--version'], text=True).strip(),
              'known_cases': len(cases), 'fresh_cases': len(fresh),
              'gates': {'U001': '7 frontend + 2 prototype pre-success C inputs retained; 3 correction drafts retained; tail input reconstructed from historical script',
                        'U002': 'match.words_at/load_text/trim_padding; fragments.mut_callee_ret through Ctx; strict shared candidate API',
                        'U003': 'initial 32 wrappers replayed by decoded object/table/entry flow; no source-template oracle',
                        'U004': 'reuse mut_callee_ret; guarded explicit select, void-tail and flat-struct store rules added'}}
    atomic_json(OUT/'discovery.json', report)
    print(json.dumps(report, indent=2), flush=True)


def run(suite, baseline, limit):
    manifest = json.loads((OUT/'manifest.json').read_text())
    rows = (manifest['known'] if suite == 'known' else manifest['fresh'] if suite == 'fresh'
            else manifest['known'] + manifest['fresh'])
    if limit: rows = rows[:limit]
    inputs_fingerprint = fingerprints()
    inputs_fingerprint['manifest'] = digest(OUT/'manifest.json')
    for row in rows:
        for item in row.get('inputs', [row] if row.get('path') else []):
            path = ROOT/item['path']
            if digest(path) != item['sha256']: raise ValueError('Replay input hash changed: ' + item['path'])
    fingerprint = hashlib.sha256(json.dumps(inputs_fingerprint, sort_keys=True).encode()).hexdigest()
    name = suite + ('-baseline' if baseline else '-improved')
    target = OUT/(name+'.json')
    old = json.loads(target.read_text()) if target.exists() else {}
    results = old.get('results', []) if old.get('fingerprint') == fingerprint else []
    done = {r['address'] for r in results}
    for row in rows:
        if row['address'] in done: continue
        addr = int(row['address'], 16)
        started = time.monotonic()
        attempts = []
        winner = None
        try:
            if row['family'] == 'wrapper':
                generated = [] if baseline else list(vf.candidates(addr, vf.words_for(addr)))
            else:
                generated = []
                inputs = row.get('inputs', [row] if row.get('path') else [])
                for input_row in inputs:
                    path = ROOT/input_row['path']
                    if digest(path) != input_row['sha256']: raise ValueError('Input hash changed')
                    source = path.read_text()
                    generated.extend([mc.Candidate(addr, source, input_row['extension'], ('baseline',))] if baseline
                                     else list(mc.variants(addr, source, input_row['extension'])))
            seen = set()
            for candidate in generated:
                key = (candidate.extension, candidate.sha256)
                if key in seen: continue
                seen.add(key)
                t = time.monotonic()
                result = mc.check(candidate, OUT/'attempts'/name/row['address'])
                attempts.append({k: result[k] for k in ('state', 'differ', 'total', 'rules', 'candidate_sha256', 'extension', 'log_path')})
                attempts[-1]['elapsed_ms'] = round((time.monotonic()-t)*1000)
                if result['state'] == 'match':
                    winner = candidate.rules
                    break
            state = 'match' if winner is not None else 'unresolved'
        except ValueError as e:
            state = 'unsupported'
            attempts.append({'state': state, 'reason': str(e)})
        results.append({'address': row['address'], 'family': row['family'], 'state': state,
                        'winner': winner, 'attempts': attempts,
                        'elapsed_ms': round((time.monotonic()-started)*1000)})
        report = {'fingerprint': fingerprint, 'results': results,
                  'matches': sum(r['state'] == 'match' for r in results),
                  'compiler_calls': sum(sum(a['state'] not in ('unsupported', 'rejected') for a in r['attempts']) for r in results),
                  'elapsed_ms': sum(r['elapsed_ms'] for r in results)}
        atomic_json(target, report)
        print(row['address'], row['family'], state, flush=True)
    print('Report:', target.relative_to(ROOT), flush=True)


def main():
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument('command', choices=['prepare', 'run'])
    ap.add_argument('--suite', choices=['known', 'fresh', 'all'], default='known')
    ap.add_argument('--baseline', action='store_true')
    ap.add_argument('--limit', type=int, default=0)
    a = ap.parse_args()
    if a.command == 'prepare': prepare()
    else: run(a.suite, a.baseline, a.limit)


if __name__ == '__main__':
    main()
