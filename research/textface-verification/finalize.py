import csv
import hashlib
import json
import os
import struct
import sys
from pathlib import Path

sys.path.insert(0, 'tools')
import build
import match
import project

root = Path('build/textface-review')
rows = json.loads((root / 'function-results.json').read_text())
manifest = json.loads((root / 'manifest.json').read_text())
base, original = match.load_text()
_, sections = project.load_image()

def image_bytes(address, size):
    for start, data in sections:
        if start <= address and address + size <= start + len(data):
            return data[address - start:address - start + size]
    raise AssertionError(('outside image', address, size))

def signed16(word):
    value = word & 0xffff
    return value - 0x10000 if value & 0x8000 else value

# The destructor contains its own RefCounter literal. Resolve its placement only
# after checking all literal bytes against the retail data, as the full build does.
row = next(r for r in rows if r['address'] == '002436C0')
assert row['judge_match'] and row['unresolved'] == [172, 184]
obj = match.compile_c(row['path'])
try:
    blob, relocs, functions = match.read_object(obj, want_symbols=True)
    literal = build.elf_section(obj, '.rodata')
    assert literal and b'RefCounter\0' in literal
    assert len(functions) == 1
    _, offset, size = functions[0]
    words = list(struct.unpack_from('<%dI' % (size // 4), blob, offset))
    address = int(row['address'], 16)
    target = match.words_at(base, original, address, match.function_span(address))
    hi, lo = row['unresolved']
    assert relocs[hi][0] == match.R_MIPS_HI16 and relocs[lo][0] == match.R_MIPS_LO16
    assert relocs[hi][1] == relocs[lo][1] == '.rodata'
    addend = ((words[(hi-offset)//4] & 0xffff) << 16) + signed16(words[(lo-offset)//4])
    resolved = ((target[(hi-offset)//4] & 0xffff) << 16) + signed16(target[(lo-offset)//4])
    placement = resolved - addend
    assert image_bytes(placement, len(literal)) == literal
    mapped = {o: (r[0], 'D_%08X' % placement, r[2], r[3]) if r[1] == '.rodata' else r
              for o, r in relocs.items()}
    linked, unresolved = match.link_words(words, mapped, offset, address)
    assert not unresolved and size <= match.function_span(address)
    assert linked == target[:len(linked)] and not any(target[len(linked):])
    row['literal_verified_body'] = True
    row['literal_placement'] = '%08X' % placement
    row['literal_bytes'] = len(literal)
finally:
    os.remove(obj)

report = json.loads(Path('build/upstream-review/full-report.json').read_text())
assert not report['partial'] and report['text_matches'] and report['data_matches']
assert not report['orphan_sources'] and not report['duplicate_sources']
text = Path('build/full/built_text.bin').read_bytes()
data = Path('build/full/built_data.bin').read_bytes()
assert hashlib.sha1(text).hexdigest() == report['text_sha1']
assert hashlib.sha1(data).hexdigest() == report['data_sha1']
assert text == original
assert any(data == segment for _, segment in sections)
for r in rows:
    address = int(r['address'], 16)
    assert r['judge_match'] and (r.get('strict_body_verified') or r.get('literal_verified_body'))
    assert report['functions'][r['address'].lower()] == 'linked'
    size = r['body_bytes']
    assert text[address-base:address-base+size] == original[address-base:address-base+size]
    r['existing_full_build_status'] = 'linked'
for r in manifest:
    digest = hashlib.sha256(Path(r['path']).read_bytes().replace(b'\r\n', b'\n')).hexdigest()
    assert digest == r['sha256_lf']

known = list(csv.DictReader(open('build/functions.csv')))
main = [int(r['address'],16) for r in known if 0x2435a0 <= int(r['address'],16) < 0x246f18]
assert len(main) == 51
assert all(a in project.sources() for a in main)
assert all(any(int(r['address'],16)==a for r in rows) for a in main)

names = {}
for a in [0x699088,0x699098,0x699160,0x6991b8,0x6991c8,0x6991d0,0x6991e0,
          0x6991f0,0x6991f8,0x699208,0x699210,0x699218,0x699220,0x699228,0x699230]:
    names['%08X' % a] = image_bytes(a,64).split(b'\0',1)[0].decode('ascii')
summary = dict(main_textface_functions=len(main), support_functions=len(rows)-len(main),
               judge_matches=len(rows), direct_resolved_bodies=61,
               literal_resolved_bodies=1, linked_in_existing_full_build=len(rows),
               existing_full_build_generated=report['generated'],
               text_sha1=report['text_sha1'],data_sha1=report['data_sha1'],
               new_matches=0, source_changes=0, properties=names)
(root/'final-results.json').write_text(json.dumps(rows,indent=2)+'\n')
(root/'summary.json').write_text(json.dumps(summary,indent=2)+'\n')
print(json.dumps(summary,indent=2),flush=True)
