"""Generate small virtual-call forwarding candidates from decoded R5900 data flow.

    virtual_forwarders.py ADDR... [--apply]
Defaults to drafts only. Unsupported instructions and side effects decline.
"""
import argparse
from pathlib import Path

import match
import project
import symbols
from matching_candidates import Candidate, check, promote


def signed(value):
    return value - 0x10000 if value & 0x8000 else value


def plus(a, b):
    if a == ('const', 0): return b
    if b == ('const', 0): return a
    if a[0] == b[0] == 'const': return ('const', a[1] + b[1])
    return ('add', a, b)


def recognize(words):
    """Symbolically execute only the complete, narrow wrapper grammar."""
    if not 10 <= len(words) <= 18:
        raise ValueError('unsupported wrapper size')
    regs = {i: ('unknown', i) for i in range(32)}
    regs.update({0: ('const', 0), 29: ('stack',), 31: ('return',)})
    for i in range(4, 12): regs[i] = ('param', i - 4)
    call = None
    returned = False
    pending = None
    stack = 0
    saved = False
    restored = False
    base_register = None
    constant_return = None
    for index, word in enumerate(words):
        op, rs, rt, rd, fn = word >> 26, (word >> 21) & 31, (word >> 16) & 31, (word >> 11) & 31, word & 63
        imm = signed(word & 0xFFFF)
        if returned: raise ValueError('instructions after return delay slot')
        if word == 0:
            pass
        elif op == 9 and rs == rt == 29:
            if imm not in (-16, 16): raise ValueError('unsupported stack frame')
            stack += imm
        elif op == 63 and rs == 29 and rt == 31 and imm == 0 and stack == -16 and not saved:
            saved = True
        elif op == 55 and rs == 29 and rt == 31 and imm == 0 and call and not restored:
            restored = True
        elif call and not pending:
            if op == 0 and fn == 8 and rs == 31 and rt == rd == 0 and restored:
                pending = 'return'
                continue
            elif op == 9 and rs == 0 and rt == 2:
                constant_return = imm
            else:
                raise ValueError('unsupported operation after call')
        elif op == 15:
            regs[rt] = ('const', (word & 0xFFFF) << 16)
        elif op in (9, 13):
            if op == 13:
                if regs[rs][0] != 'const': raise ValueError('nonconstant ori')
                regs[rt] = ('const', regs[rs][1] | (word & 0xFFFF))
            else:
                regs[rt] = plus(regs[rs], ('const', imm))
        elif op in (35, 33):
            base = regs[rs]
            if base[0] == 'unknown' or rs == 29: raise ValueError('unknown load')
            regs[rt] = ('load', 'w' if op == 35 else 'h', base, imm)
        elif op == 0 and fn in (33, 45) and (word >> 6) & 31 == 0:
            left, right = regs[rs], regs[rt]
            regs[rd] = plus(regs[rs], regs[rt])
            if rd == 4:
                base_register = rt if left[0:2] == ('load', 'h') else rs
        elif op == 0 and fn == 9 and rd == 31 and rt == 0 and (word >> 6) & 31 == 0:
            if call or not saved or index + 1 >= len(words): raise ValueError('invalid call')
            pending = ('call', regs[rs])
            continue
        else:
            raise ValueError('unsupported instruction or memory side effect')
        if pending == 'return':
            returned = True
            pending = None
        elif pending and pending[0] == 'call':
            call = (pending[1], regs[4])
            pending = None
    if not returned or stack != 0 or not restored or pending or not call:
        raise ValueError('incomplete wrapper')
    function, adjusted = call
    if function[0:2] != ('load', 'w') or function[3] != 4 or adjusted[0] != 'add':
        raise ValueError('not a virtual entry call')
    entry = function[2]
    obj, delta = adjusted[1:]
    if obj[0:2] == ('load', 'h'): obj, delta = delta, obj
    if delta != ('load', 'h', entry, 0): raise ValueError('not a signed entry adjustment')
    if entry[0] != 'add' or entry[2][0] != 'const': raise ValueError('unknown entry offset')
    table = entry[1]
    if table[0:2] != ('load', 'w') or table[2] != obj: raise ValueError('unrelated object/table')
    offset = entry[2][1]
    if offset < 0 or offset % 8 or table[3] < 0: raise ValueError('invalid virtual entry/table offset')
    # The saved object uses a1/a2/a3 when zero/one/two original arguments remain live.
    extra = base_register - 5 if base_register in (5, 6, 7) else None
    if extra is None: raise ValueError('unsupported argument allocation')
    return {'object': obj, 'table_offset': table[3], 'entry_offset': offset,
            'extra_args': extra, 'constant_return': constant_return}


def candidates(address, words):
    shape = recognize(words)
    obj = shape['object']
    offset = shape['table_offset']
    extra = shape['extra_args']
    name = symbols.symbol(address)
    for ret in ('void', 'int', 'float'):
        args = ', '.join('void *arg' + str(i + 1) for i in range(extra))
        decl = ''.join(', void *' for _ in range(extra))
        callargs = ''.join(', arg' + str(i + 1) for i in range(extra))
        header = 'struct VEntry { short delta; short index; ' + ret + ' (*fn)(void *' + decl + '); };\n'
        header += 'struct Inner { ' + (f'char pad[{offset:#x}]; ' if offset else '') + 'VEntry *vtbl; };\n'
        if obj == ('param', 0):
            params = 'Inner *arg0' + (', ' + args if args else '')
            body = '    Inner *self = arg0;\n'
        elif obj[:2] == ('load', 'w') and obj[2] == ('param', 0) and obj[3] >= 0:
            header += 'struct Obj { ' + (f'char pad[{obj[3]:#x}]; ' if obj[3] else '') + 'Inner *implementation; };\n'
            params = 'Obj *arg0' + (', ' + args if args else '')
            body = '    Inner *self = arg0->implementation;\n'
        elif obj[:2] == ('load', 'w') and obj[2][:2] == ('load', 'w') and obj[2][2][0] == 'const' and obj[3] >= 0:
            global_address = obj[2][2][1] + obj[2][3]
            header += 'struct Root { ' + (f'char pad[{obj[3]:#x}]; ' if obj[3] else '') + 'Inner *object; };\n'
            header += f'extern "C" Root *D_{global_address:08X};\n'
            params = 'int unused' + (', ' + args if args else '') if extra else ''
            body = f'    Inner *self = D_{global_address:08X}->object;\n'
        else:
            raise ValueError('unsupported object origin')
        body += f'    VEntry *entry = (VEntry *)((char *)self->vtbl + {shape["entry_offset"]:#x});\n'
        body += '    ' + ('return ' if ret != 'void' and shape['constant_return'] is None else '') + 'entry->fn((char *)self + entry->delta' + callargs + ');\n'
        if shape['constant_return'] is not None:
            body += f'    return {shape["constant_return"]};\n'
        outer = 'int' if shape['constant_return'] is not None else ret
        yield Candidate(address, header + f'extern "C" {outer} {name}({params}) {{\n' + body + '}\n', '.cpp', ('virtual-forwarder', ret))


def words_for(address):
    base, text = match.load_text()
    return match.trim_padding(match.words_at(base, text, address, match.function_span(address)))


def main():
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument('addresses', nargs='+', type=lambda s: int(s, 16))
    ap.add_argument('--apply', action='store_true')
    a = ap.parse_args()
    out = Path(project.ROOT)/'build/auto/deterministic/wrappers'
    for addr in a.addresses:
        try:
            result = {'state': 'unsupported'}
            for candidate in candidates(addr, words_for(addr)):
                result = check(candidate, out)
                if result['state'] == 'match':
                    if a.apply: result = promote(candidate, out)
                    break
            print(f'{addr:08X}: {result["state"]}', flush=True)
        except ValueError as e:
            print(f'{addr:08X}: unsupported ({e})', flush=True)


if __name__ == '__main__':
    main()
