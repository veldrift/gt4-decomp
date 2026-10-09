"""Judge a selected source batch, verify direct linkage, and package safe checkpoints.

    verify_batch.py --base REF [--build] [--package build/auto/batch.zip]
    verify_batch.py --manifest FILE [--build] [--package build/auto/batch.zip]

Without --build, require a proof produced by this tool for the current inputs.
"""
import argparse
import hashlib
import json
import os
from pathlib import Path
import subprocess
import sys
import zipfile

import build
import layout
import project
import matching_candidates as mc
from matching_replay import atomic_json, digest, fingerprints

ROOT = Path(project.ROOT)
OUT = ROOT/'build/auto/deterministic/verification'


def source_fingerprint():
    values = fingerprints()
    for path in sorted((ROOT/'src').rglob('*')):
        if path.is_file() and path.suffix in ('.c', '.cpp'):
            values[path.relative_to(ROOT).as_posix()] = digest(path)
    return hashlib.sha256(json.dumps(values, sort_keys=True).encode()).hexdigest()


def validate_report(report, rows, segments):
    if not report.get('text_matches') or not report.get('data_matches'):
        raise ValueError('Full build segment mismatch')
    for row in rows:
        if report.get('functions', {}).get(row['address'].lower()) != 'linked':
            raise ValueError('Not directly linked: ' + row['address'])
        if report.get('sizes', {}).get(row['address'].lower()) != row['matched_instruction_bytes']:
            raise ValueError('Judge/build size mismatch: ' + row['address'])
    hashes = {}
    for section, (original, rebuilt) in segments.items():
        if original != rebuilt: raise ValueError('Segment bytes differ: ' + section)
        hashes[section] = {'original_sha1': hashlib.sha1(original).hexdigest(),
                           'built_sha1': hashlib.sha1(rebuilt).hexdigest()}
    return hashes


def validate_proof(proof, fingerprint, report_hash, rows):
    if proof.get('fingerprint') != fingerprint or proof.get('report_sha256') != report_hash:
        raise ValueError('Stale build proof; run --build for the current inputs')
    if proof.get('sources') != rows:
        raise ValueError('Proof source selection has changed')


def package_members(root, paths):
    root = Path(root).resolve()
    output = []
    for name in sorted(set(paths)):
        relative = Path(name)
        if relative.is_absolute() or '..' in relative.parts or '\\' in name:
            raise ValueError('Unsafe package path: ' + name)
        path = root / relative
        if any((root/Path(*relative.parts[:i])).is_symlink() for i in range(1, len(relative.parts)+1)):
            raise ValueError('Symlink in package path: ' + name)
        if not path.resolve().is_relative_to(root) or not path.is_file():
            raise ValueError('Package path outside root or missing: ' + name)
        allowed = name.startswith(('src/', 'docs/', 'knowledge/', 'build/auto/deterministic/'))
        suffix_ok = path.suffix in ('.c', '.cpp', '.py', '.json', '.log', '.md') or name.endswith('.judge.txt')
        if not allowed or not suffix_ok or '.asm' in name.lower():
            raise ValueError('Disallowed package member: ' + name)
        output.append((path, name))
    return output


def selected_sources(base=None, manifest=None):
    sources = project.sources(refresh=True)
    if manifest:
        rows = json.loads(Path(manifest).read_text())
        addresses = [int(r['address'], 16) for r in rows]
        if len(addresses) != len(set(addresses)): raise ValueError('Duplicate manifest addresses')
    else:
        # Include current working edits, including untracked sources; do not infer paths from names.
        old = set(subprocess.check_output(['git', 'ls-tree', '-r', '--name-only', base, '--', 'src'], text=True).splitlines())
        changed = set(subprocess.check_output(['git', 'diff', '--name-only', base, '--', 'src'], text=True).splitlines())
        addresses = [a for a, p in sources.items()
                     if Path(p).relative_to(ROOT).as_posix() not in old or Path(p).relative_to(ROOT).as_posix() in changed]
    if not addresses: raise ValueError('Empty source batch')
    selected = []
    for addr in sorted(addresses):
        if addr not in sources: raise ValueError(f'Missing source: {addr:08X}')
        path = Path(sources[addr])
        relative = path.relative_to(ROOT).as_posix()
        if relative != layout.path_for(addr, path.suffix): raise ValueError('Noncanonical source: ' + relative)
        # Both extensions or flat/canonical duplicates must not silently collapse to one address.
        alternatives = [ROOT/layout.path_for(addr, ext) for ext in ('.c', '.cpp')]
        alternatives += [ROOT/'src'/f'func_{addr:08X}{ext}' for ext in ('.c', '.cpp')]
        if sum(p.exists() for p in set(alternatives)) != 1: raise ValueError(f'Ambiguous source: {addr:08X}')
        candidate = mc.Candidate(addr, path.read_text(), path.suffix)
        result = mc.check(candidate, OUT/'judges')
        if result['state'] != 'match': raise ValueError(relative + ': ' + result['state'])
        selected.append({'address': f'{addr:08X}', 'path': relative, 'source_sha256': digest(path),
                         'matched_instruction_bytes': result['total']*4})
        if len(selected) % 20 == 0: print('Verified', len(selected), 'sources', flush=True)
    return selected


def ensure_build_available():
    # Linux-only build orchestration. A foreground process check is conservative.
    processes = subprocess.check_output(['ps', '-eo', 'pid=,comm=,args='], text=True).splitlines()
    for line in processes:
        columns = line.split(None, 2)
        if len(columns) != 3 or int(columns[0]) == os.getpid() or not columns[1].startswith('python'):
            continue
        args = columns[2].split()
        if len(args) > 1 and Path(args[1]).name in ('build.py', 'cpu_solve.py', 'matching_replay.py',
                                                 'virtual_forwarders.py', 'verify_batch.py'):
            raise ValueError('A build or solver is already running')
    available = next(int(line.split()[1])*1024 for line in Path('/proc/meminfo').read_text().splitlines()
                     if line.startswith('MemAvailable:'))
    if available <= 4*1024**3: raise ValueError('Need more than 4 GB available RAM')


def main():
    ap = argparse.ArgumentParser(description=__doc__)
    selection = ap.add_mutually_exclusive_group(required=True)
    selection.add_argument('--base')
    selection.add_argument('--manifest')
    ap.add_argument('--build', action='store_true')
    ap.add_argument('--package')
    a = ap.parse_args()
    OUT.mkdir(parents=True, exist_ok=True)
    rows = selected_sources(a.base, a.manifest)
    fingerprint = source_fingerprint()
    proof_path = OUT/'proof.json'
    report_path = ROOT/'build/full/report.json'
    if a.build:
        ensure_build_available()
        with (OUT/'full-build.log').open('w') as log:
            subprocess.run([sys.executable, 'tools/build.py', '--keep-going', '--jobs', '2'],
                           cwd=ROOT, stdout=log, stderr=subprocess.STDOUT, check=True)
        if source_fingerprint() != fingerprint: raise ValueError('Inputs changed during build')
    else:
        if not proof_path.exists(): raise ValueError('No current build proof; run --build')
        validate_proof(json.loads(proof_path.read_text()), fingerprint, digest(report_path), rows)
    report = json.loads(report_path.read_text())
    segments = {s: (build.elf_section(build.ELF, s), (ROOT/'build/full'/f).read_bytes())
                for s, f in (('.text', 'built_text.bin'), ('.data', 'built_data.bin'))}
    hashes = validate_report(report, rows, segments)
    proof = {'fingerprint': fingerprint, 'report_sha256': digest(report_path), 'sources': rows,
             'hashes': hashes, 'new_source_bytes': sum(r['matched_instruction_bytes'] for r in rows),
             'revision': subprocess.check_output(['git', 'rev-parse', 'HEAD'], text=True).strip()}
    atomic_json(proof_path, proof)
    if a.package:
        destination = Path(a.package).resolve()
        if not destination.is_relative_to(ROOT/'build/auto') or destination.suffix != '.zip':
            raise ValueError('Package destination must be an ignored build/auto/*.zip')
        paths = [r['path'] for r in rows]
        paths += [p.relative_to(ROOT).as_posix() for p in (ROOT/'docs').rglob('*.md')]
        paths += [p.relative_to(ROOT).as_posix() for p in OUT.parent.rglob('*') if p.is_file()
                  and (p.suffix in ('.py', '.json', '.c', '.cpp', '.log') or p.name.endswith('.judge.txt'))]
        members = package_members(ROOT, paths)
        destination.parent.mkdir(parents=True, exist_ok=True)
        with zipfile.ZipFile(destination, 'w', zipfile.ZIP_DEFLATED) as archive:
            for path, name in members: archive.write(path, name)
    print(f'PASS: {len(rows)} directly linked sources; {proof["new_source_bytes"]} bytes; both original hashes match')


if __name__ == '__main__':
    try:
        main()
    except (ValueError, OSError, subprocess.CalledProcessError) as error:
        sys.exit('FAIL: ' + str(error))
