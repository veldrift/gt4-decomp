"""Synthetic behavioral checks; no game code/data fixtures."""
import json
from pathlib import Path
import subprocess
import sys
import tempfile
import unittest
from unittest.mock import patch

sys.path.insert(0, str(Path(__file__).resolve().parents[1]/'tools'))
import matching_candidates as mc
import matching_replay as replay
import cpu_solve
import fragments
import project
import verify_batch as vb
import virtual_forwarders as vf


def i(op, rs, rt, imm):
    return (op << 26) | (rs << 21) | (rt << 16) | (imm & 65535)


def r(rs, rt, rd, fn):
    return (rs << 21) | (rt << 16) | (rd << 11) | fn


def wrapper():
    # Hand-authored fictitious method, with an arbitrary entry offset.
    return [i(9,29,29,-16), r(4,0,5,45), i(63,29,31,0),
            i(35,5,2,0), i(9,2,2,0x70), i(33,2,4,0), i(35,2,3,4),
            r(3,0,31,9), r(5,4,4,33), i(55,29,31,0), r(31,0,0,8), i(9,29,29,16)]


class MatchingToolsTests(unittest.TestCase):
    def test_judge_requires_explicit_success_and_checked_references(self):
        self.assertEqual(mc.verdict(0, 'nothing')['state'], 'compile-error')
        self.assertEqual(mc.verdict(1, 'x: MATCH (8 instructions)')['state'], 'compile-error')
        self.assertEqual(mc.verdict(0, 'x: MATCH (8 instructions)')['state'], 'match')
        self.assertEqual(mc.verdict(0, 'x: MATCH (8 instructions)\nnote: references could not be checked')['state'], 'unchecked-reference')
        self.assertNotEqual(cpu_solve.differs_by(subprocess.CompletedProcess([], 0, 'nothing', '')), 0)

    def test_policy_distinguishes_unused_macros_from_operations(self):
        self.assertFalse(mc.policy('#define M2C_ERROR(x) 0\nint f() { return 2; }'))
        self.assertTrue(mc.policy('#define M2C_ERROR(x) 0\nint f() { return M2C_ERROR(1); }'))
        self.assertTrue(mc.policy('int f() { return M2C_CARRY; }'))
        self.assertTrue(mc.policy('int f() { return M2C_TRAP_IF(1); }'))
        self.assertTrue(mc.policy('asm(".word 0");'))

    def test_cpp_preserves_marker_and_linkage(self):
        source = '/* compiler: example */\nvoid f() {}\n'
        result = mc.cpp_source(source)
        self.assertTrue(result.startswith('/* compiler: example */\nextern "C" {'))
        self.assertEqual(mc.cpp_source(result), result)

    def test_variants_bounded_unique_and_ordered(self):
        source = 'typedef int M2C_UNK;\nM2C_UNK func_00001234(int);\nvoid func_00005678(int x) {\n    func_00001234(x);\n}\n'
        variants = list(mc.variants(0x5678, source, limit=3))
        self.assertEqual(len(variants), 3)
        self.assertEqual([v.extension for v in variants[:2]], ['.c', '.cpp'])
        self.assertEqual(len({(v.extension,v.sha256) for v in variants}), 3)
        self.assertIn('void func_00001234', variants[2].source)

    def test_used_callee_return_not_discarded(self):
        source = 'typedef int M2C_UNK;\nM2C_UNK func_00001234(int);\nint func_00005678(int x) {\n    return func_00001234(x);\n}\n'
        self.assertEqual(list(mc.ignored_returns(source)), [])

    def test_store_rule_proves_layout_and_refuses_alias_volatile_calls(self):
        source = 'struct S { int a; int b; };\nvoid f(S *obj, int x) { obj->a = x; obj->b = 0; }'
        self.assertTrue(list(fragments.deterministic_edits(source)))
        for unsafe in [source.replace('obj->b', 'other->b'), source.replace('int a', 'volatile int a'),
                       source.replace('= x;', '= query();'), source.replace('int a; int b;', 'short a; short b;')]:
            self.assertFalse(list(fragments.deterministic_edits(unsafe)))
        chain = source.replace('obj->a = x; obj->b = 0;', 'obj->a = obj->b = x;')
        self.assertIn('store:split-chain', dict(fragments.deterministic_edits(chain)))

    def test_clamp_and_tail_rules_are_guarded(self):
        self.assertTrue(list(fragments.deterministic_edits('int f(int x) { return x < 32 ? x : 32; }')))
        self.assertFalse(list(fragments.deterministic_edits('float f(float x) { return x < 32 ? x : 32; }')))
        source = 'void callee(int);\nvoid f(int x) { if (x) { callee(x); return; } other(); }'
        self.assertIn('tailcall:void', dict(fragments.deterministic_edits(source)))
        self.assertFalse(list(fragments.deterministic_edits(source.replace('void callee', 'int callee'))))

    def test_wrapper_decoding_and_negative_shapes(self):
        shape = vf.recognize(wrapper())
        self.assertEqual(shape['entry_offset'], 0x70)
        self.assertEqual(shape['object'], ('param', 0))
        for index, replacement in [(5,i(37,2,4,0)), (3,i(43,5,2,0)), (7,r(3,0,0,8))]:
            words = wrapper()
            words[index] = replacement
            with self.assertRaises(ValueError): vf.recognize(words)
        with self.assertRaises(ValueError): vf.recognize(wrapper()[:-1])

    def test_existing_source_is_not_overwritten(self):
        with patch.object(project, 'source_for', return_value='already.cpp'), patch.object(mc, 'check') as judge:
            self.assertEqual(mc.promote(mc.Candidate(1, 'invalid', '.cpp'), 'unused')['state'], 'existing')
            judge.assert_not_called()

    def test_promotion_checks_canonical_file_and_rolls_back_only_owned_file(self):
        with tempfile.TemporaryDirectory() as directory:
            dest = Path(directory)/'src/test.cpp'
            candidate = mc.Candidate(1, 'extern "C" void f() {}', '.cpp')
            with patch.object(project, 'ROOT', directory), patch.object(project, 'source_for', return_value=None), \
                 patch.object(project, 'sources'), patch.object(mc.layout, 'path_for', return_value='src/test.cpp'), \
                 patch.object(mc, 'check', return_value={'state':'match'}), \
                 patch.object(mc.subprocess, 'run', return_value=subprocess.CompletedProcess([], 1, 'mismatch', '')):
                with self.assertRaises(RuntimeError): mc.promote(candidate, directory)
                self.assertFalse(dest.exists())

    def test_build_proof_requires_both_hashes_linkage_and_size(self):
        rows = [{'address':'00001234', 'matched_instruction_bytes':4}]
        report = {'text_matches':True, 'data_matches':True, 'functions':{'00001234':'linked'}, 'sizes':{'00001234':4}}
        segments = {'.text':(b'ab',b'ab'), '.data':(b'cd',b'cd')}
        self.assertEqual(len(vb.validate_report(report, rows, segments)), 2)
        for replacement in [{'text_matches':False}, {'data_matches':False}, {'functions':{}},
                            {'functions':{'00001234':'raw bytes'}}, {'sizes':{'00001234':8}}]:
            with self.assertRaises(ValueError): vb.validate_report(dict(report, **replacement), rows, segments)
        with self.assertRaises(ValueError): vb.validate_report(report, rows, {'.text':(b'a',b'b')})
        proof = {'fingerprint':'current', 'report_sha256':'hash', 'sources':rows}
        vb.validate_proof(proof, 'current', 'hash', rows)
        with self.assertRaises(ValueError): vb.validate_proof(proof, 'stale', 'hash', rows)

    def test_package_paths_are_allowlisted(self):
        with tempfile.TemporaryDirectory() as directory:
            root = Path(directory)
            (root/'src').mkdir()
            (root/'src/f.cpp').write_text('void f() {}')
            self.assertEqual(len(vb.package_members(root, ['src/f.cpp'])), 1)
            for name in ['../other.cpp', '/tmp/other.cpp', '.git/config', 'orig/game.bin', 'src/dump.asm.txt', 'src/file.bin']:
                with self.assertRaises(ValueError): vb.package_members(root, [name])
            (root/'src/link.cpp').symlink_to(root/'src/f.cpp')
            with self.assertRaises(ValueError): vb.package_members(root, ['src/link.cpp'])

    def test_near_miss_keeps_legacy_c_draft_and_result_contract(self):
        body = 'void func_00005678(int x) { }\n'
        def judge(addr, path):
            difference = 1 if str(path).endswith('.cpp') else 2
            return subprocess.CompletedProcess([], 1, f'x: {difference} of 12 instructions differ (original 12, mine 12)', '')
        with tempfile.TemporaryDirectory() as directory, \
             patch.object(cpu_solve.match, 'm2c_asm', return_value='same'), \
             patch.object(cpu_solve.match, 'gnu_asm', return_value='same'), \
             patch.object(cpu_solve, 'draft', return_value=body), \
             patch.object(cpu_solve, 'prepared', side_effect=lambda addr,text,path:text), \
             patch.object(cpu_solve, 'variants', side_effect=lambda addr,text,*args:[('original',text)]), \
             patch.object(cpu_solve, 'judge', side_effect=judge):
            result = cpu_solve.attempt(0x5678, out=directory, apply=False)
            self.assertEqual(result['result'], 'differs')
            self.assertEqual(result['differ'], 2)
            self.assertEqual(result['of'], 12)
            self.assertNotIn('extern "C"', (Path(directory)/'00005678.c').read_text())
            self.assertIn('extern "C"', (Path(directory)/'00005678.cpp').read_text())

    def test_interrupted_replay_resumes_completed_cases(self):
        with tempfile.TemporaryDirectory() as directory:
            root = Path(directory)
            (root/'input.c').write_text('void func_00005678(int x) {}')
            case = {'address':'00005678','family':'frontend','path':'input.c',
                    'sha256':replay.digest(root/'input.c'),'extension':'.c'}
            replay.atomic_json(root/'manifest.json', {'known':[case,dict(case,address='00005679')],'fresh':[]})
            def result(candidate, path):
                return {'state':'match','differ':0,'total':1,'rules':list(candidate.rules),
                        'candidate_sha256':candidate.sha256,'extension':candidate.extension,'log_path':'synthetic'}
            def interrupted(candidate, path):
                if candidate.address == 0x5679: raise KeyboardInterrupt()
                return result(candidate,path)
            with patch.object(replay,'ROOT',root), patch.object(replay,'OUT',root), \
                 patch.object(replay,'fingerprints',return_value={}):
                with patch.object(replay.mc,'check',side_effect=interrupted):
                    with self.assertRaises(KeyboardInterrupt): replay.run('known',False,0)
                self.assertEqual(len(json.loads((root/'known-improved.json').read_text())['results']),1)
                with patch.object(replay.mc,'check',side_effect=result) as judge:
                    replay.run('known',False,0)
                    self.assertEqual(judge.call_count,1)
                self.assertEqual(len(json.loads((root/'known-improved.json').read_text())['results']),2)


if __name__ == '__main__': unittest.main()
