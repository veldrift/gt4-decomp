# Localized text: complete used header-chain experiment

Date: 2026-10-15. Target `002B7310` remains unmatched at 2/104 instructions. The header-chain candidate emits exactly the same 416 text bytes and the same 19 relocation records as the retained best candidate. Restoring these helper layers is not sufficient to fix the schedule.

## Scope and provenance

This follows [the sibling/header investigation](localized-text-constructor-siblings.md). The experiment restores the complete **used** chain: constructor -> assign(pointer) -> assign(pointer,length) -> member replace, traits length/assign/eos, nested Rep data/grab/release, static nilRep, destructor -> release -> operator delete -> allocator. Copy assignment and c_str/terminate/data are retained for the target's other paths. It does not import unrelated string APIs or claim to reproduce the original translation unit.

Adapted from upstream GCC commit `7e51098e709b1248a2334b7a19b6d27e6ce88cfc`, `libstdc++/std/bastring.h`, `bastring.cc`, and `straits.h`, whose inspected hashes are in the preceding investigation. These are upstream-era headers, not authenticated Sony/Polyphony headers. The game allocator, empty-string sentinel and known external addresses use existing adapters. Source notices and COPYING are preserved with the candidates; see THIRD_PARTY.md.

All judged sources use the existing `ee-gcc2.96-no-strict-aliasing` profile. The target retains its existing strlen `throw()` context. No judge, compiler profile, symbol map or build rule was changed.

## Control and binding limitation

Control: registered `src/ui/mSelectBox/mSelectBox__virtual_63.cpp`, address `002DA400`, literal constructor and destructor.

| Source | Result | Interpretation |
|---|---|---|
| sibling-h1.cpp | 71 compared words match; four unresolved references | Generic template member asm labels were ignored. This is not a validated control. |
| sibling-h2.cpp | Same unresolved references | Explicit specialization declarations did not repair the bindings. |
| sibling-h3.cpp | MATCH, 71/71; no unresolved references | Concrete char class retains all used helper layers, nested Rep and static nilRep; labels resolve. |
| target-h1.cpp | 2/104 differ, 104 emitted | Same adjacent load/literal-low swap as baseline. |

The concrete-class control is an explicit limitation: template parsing/instantiation itself has not been proved equivalent to the unavailable original header context. Generic template controls nevertheless produced the same compared opcode/register shape. No control replaced a registered source.

Compared all 284 emitted text bytes and all 15 relocation records of sibling-h3 with the registered sibling object: identical. Text SHA-256 is `988e2e55de9a5d3f8b121798db5588d27edeab26ee6cd91d6a7f74e23921a4de`. This supplements the unchanged judge check; it is not a new full-image build claim.

## Early compiler evidence

Inspected `.00.rtl`, pre-allocation `.17.sched`, post-allocation `.25.sched2`, delay-slot `.29.dbr` and final output.

In the sibling's initial RTL, both registered and header-chain versions allocate temporary-this r88, literal r89/high r90, empty Rep r93/high r94, and selfish-load r95. The static symbol's leading `*` in RTL denotes its assembler label. It does not change the relocation. The member clone call removes wrapper bookkeeping after the branch; instruction IDs and later pseudos change. Data-pointer construction begins in the nonselfish arm in initial RTL.

The sibling's constructor scheduling remains:

| sched1 clock | Both sibling sources |
|---|---|
| 0 | empty-Rep high and literal high |
| 1 | literal low and temporary address |
| 4 | empty-Rep low |
| 5 | clone argument copy and data-pointer calculation |
| 7 | selfish load |
| 9 | branch |

The target's initial RTL retains temporary-this r97 and literal r98/high r99 in both baseline and header-chain versions. The chain changes the Rep from r101/high r102 to r102/high r103 and the selfish load from r105 to r104. Restoring helpers changes intermediate details without changing the scheduling dependency that matters:

| sched1 clock | Both target sources |
|---|---|
| 0 | empty-Rep high and literal high |
| 1 | empty-Rep low and literal low |
| 2 | selfish load and temporary-this move |
| 4 | branch |

The target keeps data-pointer calculation in the nonselfish arm, unlike the sibling's pre-allocation scheduled block. Thus the earlier observation cannot be attributed solely to the abbreviated grab helper: the complete used chain still behaves differently in the target's surrounding lifetime/control-flow context. Delay-slot processing places temporary-this in the branch slot, leaving literal-low before the load.

The unresolved original pair remains at `002B7358/002B735C`: original load then literal-low; candidate literal-low then load. No new source-level explanation for the original order is established.

The target object's 416 text bytes and all 19 relocation records equal the previous best exactly. Text SHA-256: `9f691ea202be8c11adc94d7b4ba57b8a56844be04608fd6af6a0d6ec28b794a2`. This is stronger than an equal row score, but still an unmatched candidate.

## Budget, preservation and next boundary

One target `swarm.py try` invocation; three sibling `match.py check` invocations. Conservatively count the two incomplete control bindings plus the target failure as **three unsuccessful hypotheses out of ten**. A local source-generation typo and unavailable optional ELF Python module were preparation errors, not compiler/judge hypotheses; the final object comparison used the repository's own read_object parser. No compiler failures occurred. Stopped because the experiment converged to identical target output, not because the budget was exhausted.

Every judged hypothesis is recorded using attempts.py. Candidate copies, hashes, target judge event and per-pass diary are preserved under `research/stalled-functions/002b7310/header-chain/`. Best.cpp remains the earlier candidate. No source promotion, full build or viewer integration occurred.

Further work needs evidence about the original translation-unit/compiler scheduling context, or a matched sibling with the same lifetime and predecessor structure and the desired schedule. Repeating helper nesting or statement permutations is unsupported by this experiment. Exact original headers/preprocessed source and original compiler RTL remain missing.

## Reproduction and ignored evidence

- Remote root: `/home/dev/gt4-localized-text-matching`; scratch `build/swarm/localized-text-header/`.
- Local mirror: `build/localized-text-header-evidence/`; full compiler dumps and object-comparison.json remain ignored, not committed.
- `python tools/rtl_dumps.py build/swarm/localized-text-header/sibling-h3.cpp --out build/swarm/localized-text-header/rtl-sibling-h3`
- `python tools/match.py check 002da400 build/swarm/localized-text-header/sibling-h3.cpp`
- `python tools/swarm.py try 002b7310 build/swarm/localized-text-header/target-h1.cpp --worker localized-text-header`
- `python tools/rtl_dumps.py build/swarm/localized-text-header/target-h1.cpp --out build/swarm/localized-text-header/rtl-target-h1`
- Baseline dumps: `build/swarm/localized-text/rtl/`; sibling dumps: `build/swarm/localized-text-sibling/rtl-selectbox/`.

Acceptance remains unchanged: judge MATCH, full body/relocation/padding validation, original full-build hashes and explicit linked status for this address before integration.
