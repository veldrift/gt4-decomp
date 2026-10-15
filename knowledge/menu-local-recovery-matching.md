# Menu recovery matching continuation

Current checkpoint: [stalled matching functions](../research/stalled-functions/README.md)
on `feat/stalled-functions` preserves candidate sources and per-target diary
snapshots in Git. The six-target results below describe the earlier bounded
pass. SelectBox `002D8C90` has since been supplied by upstream PR 12 and verified
over all 168 bytes with explicit full-build `linked` status; five menu targets
remain unmatched. See [upstream validation](../docs/research/upstream-pr-11-12-validation.md).

Tim requested matching the menu bodies previously recovered for the Godot host,
starting with Composite. All matching drafts, results and accepted source belong
in this repository. Leave `gt4-godot` unchanged; do not remove its currently
consumed adapters during matching work.

## Targets and evidence

The current source map has no registered source for these six addresses:

| Address | Role | Original span | Scratch owner |
| --- | --- | --- | --- |
| `00207590` | Composite property reader | 840 bytes | `build/menu-composite-sol/` |
| `00233E38` | RootWindow property reader | 1880 bytes | `build/menu-root-luna/` |
| `002A29F0` | ImageFace property reader | 2744 bytes | `build/menu-image-luna/` |
| `002A38A0` | ImageFace pattern coordinates | 312 bytes | `build/menu-pattern-luna/` |
| `0020EEB8` | Layout tokenizer implementation | 3104 bytes | `build/menu-token-luna/` |
| `002D8C90` | SelectBox constructor | 168 bytes | `build/menu-select-luna/` |

Saved Ghidra inputs were copied read-only from the sibling into ignored
`build/menu-recovery-inputs/`. These are provisional binary recoveries, not
matched PS2 source. Host pointer, storage and service adaptations are unsuitable
as matching inputs. The tokenizer export is named `0020eea0.c`, encompassing
the forwarding entry and implementation. Confirm the judge's implementation
span before treating it as an independent target.

The SelectBox prior h01--h10 inputs and h07 diff are preserved under
`build/menu-recovery-inputs/select-prior/`. Its recent retained h07 covers all
168 bytes and differs in ten words; the older diary's seven-difference draft
was not recovered by that pass. Do not count shortened prefix comparisons.

Widget copy `00262C78` and hObject copy `0030B888` already have source bodies
in `src/ui/mSceneViewFace/` and `src/adhoc/mLoggerControl/`. They are not missing
contribution candidates, even though Godot still consumes older adaptations.

## Validation and coordination

One Sol worker owns Composite; five Luna workers own the other five targets.
Only two compiler slots may be active; queued workers prepare source and inspect
existing evidence without compiling. Each worker records every judged hypothesis
in its own scratch journal; the coordinator appends the results to the shared
attempts diary. No worker promotes source or runs a full build.

Before accepting a candidate, require unchanged-judge MATCH, complete emitted
body/relocation/padding verification, then a foreground full build with original
text/data hashes and the new function explicitly marked `linked`. Check for
duplicate/orphan sources. Preserve earlier CarData notes and diary changes.

This bounded pass is finished: 42 new trials, no MATCH, no source promotion,
full build, commit or push. All six targets remain deferred. Godot's working
tree is unchanged. Existing CarData edits are preserved.

| Target | New trials |
| --- | ---: |
| Composite | 10 |
| RootWindow | 8 |
| ImageFace reader | 5 |
| ImageFace pattern helper | 8 |
| Tokenizer | 3 |
| SelectBox | 8 |

Counts include compilation failures and the rejected Image frame experiment,
but exclude unjudged references, object-size measurements and copied historical
attempts. All compiler slots have been released.

## Checked findings

Composite: ten new hypotheses, no MATCH. Retain
`build/menu-composite-sol/00207590_best.cpp` and `REPORT.md`. The natural
scaffold emits 828 bytes, short of the original 840; all 45 relocations resolve.
Three shifted instruction runs totaling 812 bytes agree exactly. Initial success
return placement and the final refcount branch still differ. Raw judge score
196/207 is dominated by shifted rows. A branch-hinted draft gives 16/209 but
does not solve routing and is not the preferred source. Enlarged string/callback
carriers were borrowed from matched siblings; exact original carrier sizes and
lifetimes remain unproved. Neither source is ready for promotion.

Pattern: eight new hypotheses, no MATCH. Retain
`build/menu-pattern-luna/002a38a0-reciprocals-first.cpp`. Score 35/70 compares
only 280 emitted bytes against a shortened original; the full original is 312
bytes, with a nonzero final instruction at `002A39D4`. Do not call this a
complete-body score. Scalar reciprocal/clamp setup agrees, but post-lock byte
reloads, float product copies and coordinate stores differ. Adjacent sources
prove four eight-byte UV pairs and a pair setter at `002A3800`; they do not yet
prove the inline source structure behind this helper. Volatile-field experiments
were explicitly rejected and left unjudged.

Tokenizer: three checks (one compilation failure, two compiled hypotheses), no
MATCH. Retain `build/menu-token-luna/0020eeb8_h02.cpp`. Actual emitted STT_FUNC
size is 2864 bytes versus 3104 original; 638/716 is a shortened comparison.
The equal displayed row counts are not evidence of complete coverage. Changing
the reader helper's `throw()` declaration produces identical output. There are
16 pushback calls in the saved source and original, but 11 in the candidate's
emitted control flow; this suggests optimizer/source-structure differences,
without proving a missing semantic path. `0020EEB8` is a genuine independent
function, not an interior fragment of the forwarding entry.

Cross-function source review established that Root's base reader and Image's
base reader receive both `self` and `reader`. Image's parsed stack float requires
a union/scalar carrier, not dereferencing a pointer carrying its bits. Its pattern
setter call arguments are full signed integers: the caller has no narrowing
instructions, even though the setter stores their low bytes. Root's original
callback slots are first `+30`, second `+50`, then shared `+20`, with value `+0`,
name `+10`, saved registers from `+60` and frame `B0`. Model actual object scopes
and cleanup nesting; invented volatile objects or filler to force stack size are
not acceptable replacements for source recovery.

SelectBox: eight new checks, no MATCH. The existing h07 remains 10/42 over the
full 168-byte span. New `build/menu-select-luna/h11.cpp` is 11/42 and correctly
assigns D0/D4 to the target f1/f0 registers through a range base-class constructor.
Other natural constructor/body/base variations collapse to either h07 or h11.
h11 instead swaps v0/v1 for the vtable/state addresses and starts state stores
CC,C8 instead of C8,CC. Full sources and judge outputs are retained. The ten
earlier Godot-owned matching hypotheses have also been imported into this
repository's diary with their saved source paths remapped to this scratch tree;
they are historical evidence, not new checks.

Image reader: five checks, no MATCH. The corrected ordinary draft is
`build/menu-image-luna/attempt3.cpp`: 617/621, 2484 emitted bytes versus 2744
original, frame 100 versus original 110. These are shortened scores. The fifth
check replaces raw sixteen-byte vector-reader buffers with actual eight-byte
objects and scoped constructor/destructor calls, supported by the generated
header's observed fields and another matched call site's eight-byte buffer.
`002a29f0-vector-object.candidate.cpp` scores 621/631, emits 2524 bytes, and has
frame F0; both object lifetimes are balanced, but overall stack and code remain
different. Trial four's volatile frame carrier was rejected and removed from
the working draft; it survives only as failed evidence. A proposed aggregate
with explicit gaps was rejected before judging. Recover actual callback/string/
vector lifetime and alias relationships rather than forcing frame offsets.

Evidence retention limits: Pattern's original eight judge outputs were streamed
and not saved; exact sources and per-check summaries are preserved. Root's first
two raw diffs were not captured, but sources and explicit result summaries were
saved. Do not present a reconstructed output as an original verdict. The strict
span corrections above supersede earlier worker descriptions of full coverage.

RootWindow: eight new checks, no MATCH. Best is
`build/menu-root-luna/00233e38_cbslots.cpp`, 109/469. Explicit first/second/common
callback identities improve the initial 484/491 and revised 370/467, but frame
A0 differs from B0 and callback slots are 20/30/40 instead of native 30/50/20.
The 469 compared words occupy 1876 bytes; the omitted original final word is
zero padding (last nonzero is `00234588`), so this particular four-byte length
difference is not a proven missing semantic instruction. There are still 109
different compared words, so no acceptance is implied. Real scoped callback
constructors/destructors and returned callback factories worsen or reproduce
earlier forms. A larger unused string slot does not affect generated output.
Preserve actual callback lifetime/storage identity as the next source question;
do not repeat padding or already-identical constructor variations.

One worker initially wrote a redundant scratch copy under the workspace parent.
It was moved intact into `build/menu-image-luna/preserved-parent-scratch/`, so
new decompilation artifacts are consolidated inside this repository.
