# Localized text constructor siblings and original header structure

Checked 2026-10-15 against clean matching revision `8f425cfe3`, branch `feat/stalled-functions`. Research only: no new `002B7310` candidate or hypothesis was judged, no accepted source changed, and no viewer integration occurred. The target remains unmatched at 2/104.

## Result

Found verified partial siblings, but not a verified sibling combining a fixed literal, this temporary's inline copy assignment/destruction, and the disputed instruction order. The useful comparisons are:

| Address | Source | Current unchanged-judge result | Relationship to target |
| --- | --- | --- | --- |
| `0021FC78` | [func_0021FC78.cpp](../../src/ui/unit_0021FAD0/func_0021FC78.cpp) | MATCH, 99 compared instructions | Constructs temporary, inline copy-assigns a string member, destroys temporary. Input is a runtime pointer, so no literal-address scheduling competition. |
| `00212DD0` | [func_00212DD0.cpp](../../src/ui/unit_002117A0/func_00212DD0.cpp) | MATCH, 64 instructions | Literal constructor and destructor, with a separate handle lifetime and intervening consumer call; no inline string copy assignment. Default compiler profile. |
| `002DA400` | [mSelectBox__virtual_63.cpp](../../src/ui/mSelectBox/mSelectBox__virtual_63.cpp) | MATCH, 71 instructions | Literal constructor and destructor under the same no-strict-aliasing profile; consumer computes a symbol ID rather than copying the string. |

These are rechecks of existing registered sources, not new acceptance or full-linked-image claims. In particular, the 99-word judge report for `0021FC78` should not be presented as independent proof of its complete 400-byte inventory span and padding.

## Search scope

Local source searches found 851 files mentioning clone/empty-Rep machinery and 632 containing all four helper identifiers: clone, replace, strlen and deallocate. Short sources, class/operator forms, nearby localized-text methods and explicit literal construction sites were inspected. Neighbor `002B71D0` constructs an empty temporary then assigns from a member; `002B74B0` copies a returned temporary. Neither supplies the missing literal schedule.

A read-only scan of the original text segment searched the seven-instruction opcode sequence `lui, lui, addiu, lw, addiu, beq, daddu`, with the first high-half immediate `0x66` and load displacement `12`. It found only the target block at `002B734C`. This is a narrowly defined sequence search, not proof that no semantically equivalent sibling exists. A second search ranked registered functions by clone/replace/strlen/deallocation call counts and led to `0021FC78`; other short hits used runtime text, reference handles, or separate branch-local strings.

Search scripts and outputs are retained in ignored evidence. No raw game bytes were added to Git.

## Compiler dump comparison

Generated full RTL dumps for all three siblings using the existing `tools/rtl_dumps.py`, without changing profile definitions or scheduling flags. Compared them with the retained first-pass target dumps, including pre-allocation scheduling, post-allocation scheduling and final assembly.

The target's baseline constructor block schedules both symbol high halves at clock 0, both low halves at clock 1, and the selfish load plus temporary-address move at clock 2. Delay-slot processing moves the temporary address to the branch slot, leaving the literal low half before the load. The desired original order is still absent.

`0021FC78` is the closest lifetime comparison. Before allocation, its empty-Rep high/low address is followed by the selfish load at clock 2 and temporary-address materialization at the same clock. In final code the empty Rep is held in `a0`, shared data in `v1`, and the temporary address in a saved register; copy assignment uses the same self-assignment guard and release/grab pattern as the target. This supports the recovered temporary/copy/destruction structure, but cannot answer where a fixed literal's low half would be scheduled.

The literal siblings differ earlier than the final delay-slot pass. Their header-shaped `grab` permits the shared data pointer and clone argument copy to move into the predecessor block. The target's retained branch-local result form keeps data construction in the nonselfish arm. The sibling assembly therefore has additional pointer preparation around the selfish test, with the Rep in `v1` and data in `a1`, rather than the target's Rep in `a0` and result in `v1`.

In `002DA400`, post-allocation block 2 issues both high halves at clock 0, literal low then Rep low at clock 1, load and temporary address at clock 2, then clone-argument/data-pointer preparation at clock 3. Its branch slot receives data-pointer construction. In `00212DD0`, constructor operations share a block with the preceding handle call; the literal high half is already scheduled alongside that call in the first scheduling pass. Neither is a clean substitute for the target block. Transplanting either source shape solely because it matches elsewhere would conflate lifetime, predecessor and register-allocation differences.

## Original-era headers

The repository's documented external `gcc-20001003` tree was absent at the inspected sibling paths. Retrieved upstream GCC sources instead. The latest upstream mainline commit before 2000-10-04 is [7e51098e709b1248a2334b7a19b6d27e6ce88cfc](https://github.com/gcc-mirror/gcc/commit/7e51098e709b1248a2334b7a19b6d27e6ce88cfc), dated 2000-10-03 20:19:54 UTC. The last change to `bastring.h` before that cutoff was `dc329d293894ba51b1630a2d41c8e23e1478893b`, 2000-08-11. Both revisions yielded identical copies of the three inspected files.

The relevant upstream chain is constructor -> `assign(s)` -> `assign(s,n)` -> member `replace`; `traits::length` supplies strlen. The nested `Rep` owns `grab`, `data`, release and deletion. MIPS uses the generic retain/release branch, not the x86 atomic branch. `nilRep` is a static member of the string template. These details are visible in [bastring.h](https://github.com/gcc-mirror/gcc/blob/7e51098e709b1248a2334b7a19b6d27e6ce88cfc/libstdc%2B%2B/std/bastring.h#L120), [straits.h](https://github.com/gcc-mirror/gcc/blob/7e51098e709b1248a2334b7a19b6d27e6ce88cfc/libstdc%2B%2B/std/straits.h#L124), and [bastring.cc](https://github.com/gcc-mirror/gcc/blob/7e51098e709b1248a2334b7a19b6d27e6ce88cfc/libstdc%2B%2B/std/bastring.cc#L38).

The retained target collapses this into an external replace call and free grab helper. Prior experiments tested individual nesting/template changes, but do not establish equivalence to the complete original header context. The verified siblings also reconstruct only portions of that context.

This is the documented upstream-era implementation, **not authenticated Sony SDK or Polyphony headers**. The game allocator and addresses require their existing adapters; upstream sources do not prove the game's exact preprocessed translation unit. Copies remain ignored with their original license notices; no third-party implementation was vendored.

SHA-256 for the inspected upstream files:

- `bastring.h`: `bbd8ffcd075456b06aab2f5b5d32469e7886a409ff082ac65a2a11520753c0d8`
- `bastring.cc`: `5afc9ea91414f9d66f1b599e589cb1ed71989134de102fbd0e4741aa8a50d0c0`
- `straits.h`: `e8c9bab6b3083494f1d2b889f52c58c20a968f9b2d0df949d2db6ed5a9812c17`

## Next discriminating experiment

Use a faithful, licensed header-based diagnostic harness preserving the complete constructor/assign/traits/member-replace chain, nested Rep and static nilRep, with only the established game allocator and symbol adapters. Establish its compiler dump against a verified sibling before judging a target candidate. Compare the earliest expansion and pre-scheduling differences, particularly whether data construction is already outside the nonselfish arm and whether the temporary `this` survives as a distinct pseudo. This is a specific evidence-backed experiment, not a claimed fix or authorization to weaken the judge. Avoid another statement-order permutation pass.

## Evidence locations and checks

- Remote private scratch: `/home/dev/gt4-localized-text-matching/build/swarm/localized-text-sibling/` (`find.py`, `find-copy.py`, JSON results and three RTL directories).
- Local ignored mirror: `build/localized-text-sibling-evidence/remote-scratch/`.
- Upstream sources/history: `build/localized-text-sibling-evidence/oct03-*` and `snapshot-history.json`; earlier history query in `header-history.json`.
- Baseline target RTL: remote `build/swarm/localized-text/rtl/`.
- Actual checks: three unchanged `match.py check` calls, three diagnostic RTL compilations, two read-only executable scans, source/header inspection and upstream file hash verification.
- No new target judge invocation, full build, viewer suite, emulator access, push or external message. The runtime gate remains `002B7310`.
