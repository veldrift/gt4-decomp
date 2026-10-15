import contextlib
import hashlib
import io
import json
import os
import struct
import sys
from pathlib import Path

sys.path.insert(0, 'tools')
import match
import project

root = Path('build/textface-review')
manifest = json.loads((root / 'manifest.json').read_text())
base, original = match.load_text()
sources = project.sources(refresh=True)
results = []
for row in manifest:
    result = dict(row)
    obj = None
    stderr = io.StringIO()
    try:
        addr = int(row['address'], 16)
        src = Path(row['path'])
        assert hashlib.sha256(src.read_bytes().replace(b'\r\n', b'\n')).hexdigest() == row['sha256_lf']
        with contextlib.redirect_stderr(stderr):
            obj = match.compile_c(str(src))
        blob, relocs, functions = match.read_object(obj, want_symbols=True)
        ok, verdict = match.judge(addr, str(src), obj=obj, sources=sources)
        obj = None
        (root / (row['address'].lower() + '.judge.txt')).write_text(verdict + '\n')
        result['judge_match'] = ok
        result['functions'] = functions
        assert ok, verdict.splitlines()[0]
        assert len(functions) == 1, ('multiple emitted functions', functions)
        name, offset, size = functions[0]
        words = list(struct.unpack_from('<%dI' % (size // 4), blob, offset))
        linked, unresolved = match.link_words(words, relocs, offset, addr)
        span = match.function_span(addr)
        target = match.words_at(base, original, addr, span)
        result.update(body_bytes=size, span_bytes=span, unresolved=sorted(unresolved))
        assert not unresolved, ('unresolved relocations', sorted(unresolved))
        assert size <= span, ('overlong emitted function', size, span)
        assert linked == target[:len(linked)], 'resolved instruction mismatch'
        assert not any(target[len(linked):]), ('omitted nonzero original suffix', size, span)
        result['strict_body_verified'] = True
    except (Exception, SystemExit) as failure:
        result['failure'] = str(failure)
        if stderr.getvalue():
            (root / (row['address'].lower() + '.compiler-error.txt')).write_text(stderr.getvalue())
    finally:
        if obj and os.path.exists(obj):
            os.remove(obj)
    results.append(result)
    if len(results) % 10 == 0 or row['address'] in ('00543338', '002D8C90'):
        print(len(results), '/', len(manifest), row['address'],
              'PASS' if result.get('strict_body_verified') else result.get('failure'), flush=True)
    (root / 'function-results.json').write_text(json.dumps(results, indent=2) + '\n')
passed = sum(row.get('strict_body_verified', False) for row in results)
print('Strict full-body verification:', passed, '/', len(manifest), flush=True)
for row in results:
    if not row.get('strict_body_verified'):
        print('REVIEW', row['address'], row.get('failure'), flush=True)
sys.exit(0 if passed == len(manifest) else 1)
