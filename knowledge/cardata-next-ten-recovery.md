# CarData continuation on next-ten

Date: 2026-10-14. Branch: `feat/gamedata-tooling-next-ten`.

All other local branch tips were merged into this branch. This includes the
geometry expansion, combined geometry, dev, newer upstream, menu play-data,
and wheel-helper work. Reviewed source overlaps retain the current upstream
implementations. The matching-tool merge preserves both C/C++ candidate
handling and upstream stack-object recovery and incomplete-draft scoring.
The duplicate C source for `RaceCarModel__virtual_03` was removed in favor of
its current C++ source. No original game data is included in these changes.

## New compiler matches

| Address | Function | Matched body | Original span |
| --- | --- | --- | --- |
| `0012F3E0` | `MCarData__ShiftCarCode` | 1236 bytes / 309 instructions | 1240 bytes |
| `0014DF50` | `MCarGarage__haveWing` | 356 bytes / 89 instructions | 360 bytes |

Both use the established `ee-gcc2.96-no-strict-aliasing` profile and the
existing recovered copy-on-write string and reference-counted handle behavior.
Each object contains exactly one function. Every body instruction, including
resolved global and callee relocations, was compared directly with the original;
there are no unresolved references. The extra four span bytes are alignment
padding, to be checked by the full build.

`ShiftCarCode` obtains the second argument's course row through the native
64-bit identifier lookup. The returned row is 24 bytes, with its kind byte at
offset `0x10`. Kind 0/1 preserves the original name; kind 2 selects the code at
car-record offset `0x38`, and kind 3 selects offset `0x40`. Failed record or code
lookups preserve the original name. Putting course-kind extraction in an inline
helper recovers the original stack lifetimes and register allocation.

`haveWing` preserves the original string selection even for an empty string.
It maps the native sentinel name to a null lookup key and wraps the wing
identifier equality result in the normal integer-reference return object.
The older draft added a nonempty test that changed this behavior and allocation.

Attempts, including rejected drafts, are appended to `knowledge/attempts.jsonl`.
Reproduction artifacts are under ignored `build/cardata-next-ten/`; the Linux
validation snapshot is `/home/dev/gt4-cardata-next-ten`, with a private build
cache so previous workspaces and their caches are preserved.

The existing matching-tool regression suite passes all 14 tests. Source audit
finds 27,699 unique source addresses with no orphan or duplicate files.

## Full-build verification

The complete validation snapshot passes `.text OK` and `.data OK`:

- Text SHA-1: `28422e7e20a6298224294255355487b9a22cef31`.
- Data SHA-1: `c28c833f9716467545bf362f321e9acc876c3603`.
- Both new functions have `linked` status in `build/full/report.json`, as do
  all 12 other sources added relative to the wheel-helper branch.
- 27,005 functions are linked from source. Existing sources excluded by the
  full-link checker retain the project's original-assembly fallback.

The local evidence files are `build/cardata-next-ten/full-report.json` and
`full-build.log`. The validation snapshot has no Git metadata, so the report's
commit field is null; it validates the source state committed locally in
`c2588777c`, following merge cleanup `f13286ea0`.

## Further continuation: packed data helpers

Two more support functions now pass the original compiler's judge and direct
resolved-object comparison, with exactly one function in each object:

| Address | Recovered operation | Body / span |
| --- | --- | --- |
| `00430C28` | Compare a byte limit with the packed upper-nibble threshold; nibble `0xF` always yields zero | 40 bytes / 10 instructions |
| `0043C608` | Clear twelve destination bytes, copy an eleven-byte packed record from source offset `0x10`, return destination plus twelve | 104 bytes / 26 instructions |

Both use the default game compiler. The threshold operation keeps its inverted
comparison in the native unsigned 64-bit domain, eliminating the redundant
integer-result extensions seen in earlier drafts. The record copy uses direct
assignment of one packed aggregate, so all source fields are read before any
destination field is written. Both retain address names because their native
method names are unknown.

The direct CarData/garage methods attempted in this continuation remain
unaccepted. `MCarGarage__getTunerList` at `00140FA8` is now two instructions away
from matching: the only difference is the order of independent empty-string-rep
address and loop-counter initialization. Its corrected draft preserves native
64-bit car identifiers returned by `004454C0` and consumed by `00448788` and
`004478F8`. It is saved in ignored `build/cardata-more/00140fa8.cpp` on both
hosts. Gear-ratio output at `00148940` still needs register-allocation and
point-loop scheduling recovery; no near-match source has been promoted.

All 27 judged hypotheses and deferrals from this continuation are appended to
the attempts diary. New proofs and build evidence are under ignored
`build/cardata-more/`.

The final full build, generated at `2026-10-14T13:28:39Z`, passes both original
hashes listed above. Both newly accepted helpers are `linked` from source;
there are 27,701 unique source addresses, 27,007 linked functions, and no orphan
or duplicate sources. Evidence is saved as `build/cardata-more/full-report.json`
and `full-build-both.log`. No compiler tooling or shared header changes were
needed for this continuation.

## Garage range continuation

Three additional garage methods now pass both matching interfaces and direct
resolved-object comparison. Each object has exactly one function and no
unresolved relocations.

| Address | Method | Instructions | Body / span bytes |
| --- | --- | --- | --- |
| `0014AAD8` | `MCarGarage__getLSDRange` | 456 | 1,824 / 1,824 |
| `0014B478` | `MCarGarage__getSuspensionRange` | 1,008 | 4,032 / 4,032 |
| `00149538` | `MCarGarage__getGearRange` | 643 | 2,572 / 2,576 |

These recover 8,428 body bytes. All use the established
`ee-gcc2.96-no-strict-aliasing` profile, native handle constructors and
destructors, and the existing reference-counted assignment behavior.

The important source distinction is temporary lifetime. An inline context
lookup owns and releases its garage handle before the result array is created.
Inline field exporters own one named integer handle each, allowing the compiler
to reuse its sixteen-byte return area. LSD exports eighteen byte values from
six four-byte records. Suspension exports four unsigned halfwords and thirty-eight
bytes into a forty-two-element array.

Gear range exports twenty-three integers. It retains the native specification
copy, optional virtual integer argument, signed-short conversion, range
calculation, and zero-fill path. Its computed short-array values are read after
the element lookup, in separate blocks owning named integer handles. Passing
the arrays through exporter pointer arguments keeps an extra address register
alive; direct local reads recover the original scheduling and stack reuse.
The last four span bytes are alignment padding, verified by the full build.

The tuner list remains two instructions away. Ten fresh hypotheses did not
close the independent preheader scheduling difference, and the pass was stopped
at the project skill's per-function limit. The native 64-bit identifier ABI is
preserved. The canonical draft is `build/cardata-finish/tuner-seed.cpp`; its
compiler dumps are under `build/cardata-finish/rtl/`. The second scheduling pass
places loop-counter initialization ahead of the empty-string-rep low-address
instruction; the original places that address instruction first. No tuner
near-match has been added to `src/`.

Engine-curve drafts are also retained without promotion. A future attempt can
apply the now-proven scoped native-handle approach to the curve computation and
graph export lifetimes instead of explicit overlaid scratch slots.

All twenty-two new diary records and the accepted source files are preserved.
Proofs, drafts, compiler dumps, and full-build evidence are under ignored
`build/cardata-finish/`.

The full build at `2026-10-14T14:25:25Z` passes `.text OK` and `.data OK`,
with both original SHA-1 hashes listed above. All three new methods are
`linked` from source. The audit counts 27,704 unique source addresses and
27,010 linked functions, with no orphan or duplicate sources. Evidence is
saved as `build/cardata-finish/full-report.json` and `full-build.log`.

## Further native value recovery

Two more functions pass the matching interfaces and direct resolved-object
comparison, with one function per object and no unresolved relocations:

| Address | Recovered operation | Instructions | Body / span bytes |
| --- | --- | --- | --- |
| `004430F0` | Convert four floating-point fields to unsigned shorts and a fifth field, scaled by 10,000, to a signed short | 65 | 260 / 264 |
| `001360A0` | `MCalendar__dayToDate`: return year, month, day in an array, or a null reference when no argument is supplied | 115 | 460 / 464 |

Both use the established no-strict-aliasing profile. The field writer keeps
each unsigned conversion's correction path and destination store ahead of the
next source read. A typed layout and sequential assignments recover the native
branch-likely delay slots without special instruction helpers.

The calendar method calls `00579898` with its native four-byte Date aggregate
return: signed-short year followed by unsigned-byte month and day. The aggregate
ABI produces the two short stores directly. Declaring an unsigned 64-bit scalar
and narrowing its halves had introduced redundant masks in previous drafts.
Native array-object append returns a temporary Ref, while each IntegerRef
argument has its own full-expression lifetime; these recover the original
return slots, reference-counted assignment, and destructor order.

The engine-curve setup now matches, but its graph-loop headers and scheduling
remain unresolved. It reached ten failed hypotheses across these passes and
was deferred with the direct `00148b60-order.cpp` draft. Gear-ratio native
lookup and output-handle lifetimes now match; its closest current draft,
`00148940-scopes.cpp`, differs in 36 rows concentrated in the two point loops.
The other investigated table and randomization drafts remain unaccepted.
The attempts diary contains thirty-eight additional records, including the
judged hypotheses and engine deferral. Drafts and new direct proof are under
`build/cardata-finish/`; the latter is `proof-more.json`.

The full build at `2026-10-14T16:05:37Z` passes `.text OK` and `.data OK`
with both original hashes. Both new functions are `linked` from source.
There are 27,706 unique source addresses and 27,012 linked functions, with
no orphan or duplicate sources. Evidence is saved as
`build/cardata-finish/full-report-more.json` and `full-build-more.log`.

## Scored garage-array sorters after upstream synchronization

The three remaining scored-array sort helpers now pass the judge, worker
interface, and direct resolved-object comparison. Each object contains exactly
one function and no unresolved relocations.

| Address | Score key | Instructions | Body / span bytes |
| --- | --- | --- | --- |
| `001479B8` | Integer garage property from `00145EF0` | 212 | 848 / 848 |
| `001475A8` | Float car-data property from `0043DDB0` | 215 | 860 / 864 |
| `00146F38` | Normalized car name, represented by a vector of signed shorts | 367 | 1,468 / 1,472 |

Together these recover 3,176 body bytes. Their native method names remain
unknown, so the address names are retained. All use the existing SGI STL
profile and headers, with the game's allocator and native fill, copy, sort,
and array copy-back helpers declared at their original addresses.

The allocator is stateless. Its empty class still places the vector's three
pointers at offsets 4, 8, and 12. Giving it an invented four-byte state let
the compiler reuse its temporary for later GarageRef and ArrayRef objects;
removing that state recovered the original stack layout and reduced the
integer sorter's residual to six instructions. A native inline score factory
returning the intermediate object then recovered the order of the two
temporary addresses. Using the actual SGI `less<T>` predicate and the
const-input uninitialized-copy specialization preserves the native sort
and copy scheduling.

The scored element owns its GarageRef as a member, preserving the native
complete-object destructor flag. The integer and float forms have scalar
scores. The name form owns a short vector, with its separate native heap,
name decoding and normalization routines, guarded self-assignment, and all
three temporary-vector copy/deallocation sequences intact.

The fresh upstream gear-ratio source supplied allocator and output-layout
clues for the engine-curve method, but those attempts remain unmatched.
Database lookup and initialization drafts are also retained without
promotion. All twenty-three new attempt records are appended to the diary.
Drafts and direct proof are saved under ignored `build/cardata-post-sync/`.
The validation snapshot is `/home/dev/gt4-next-ten-upstream-sync`, with text
line endings normalized to LF before compilation.

The full build at `2026-10-14T18:44:56Z` passes `.text OK` and `.data OK`
with both original hashes. All three new sorters are `linked` from source.
There are 28,335 unique source addresses and 27,634 linked functions, with
no orphan or duplicate sources. Evidence is saved as
`build/cardata-post-sync/full-report.json` and `full-build.log`.

## Bounded remaining-helper pass

The next pass tested forty source hypotheses across eight remaining helpers:
`00449190`, `00449F80`, `004490F8`, `004478F8`, `00448C10`, `00448B48`,
`0043BBC0`, and `00449AF8`. None passed the exact-match judge. Forty-six
append-only diary records include those hypotheses and six deferrals. Drafts
and full comparisons are retained under ignored `build/cardata-continue/`.
No function source, shared header, compiler setting, or matching tool changed;
the previously verified full build remains the latest source validation.

For `0043BBC0`, direct inspection of the original nineteen-entry jump table at
`006A64F0` confirms active selector cases 4, 5, 6, and 7. Their divisors are
35, 65, 20, and 35, respectively; the remaining table entries take the default
path. Explicit empty sentinel cases -1 and 17 reproduce the table extent.
The record snapshot covers thirty bytes at input offset `0x10`, including
twelve tuning bytes and a seventeen-byte selector area. The embedded control
object starts at offset 4. Keeping its pointer alive and reading its count
through that pointer avoids retaining an additional parent-object register.
An inline signed-int flag getter over unsigned-short storage reproduces the
original `lhu` followed by `sra`; direct field expressions emit `srl`.
The percentage and clamp scheduling, selector-clear store order, and some
result register allocations remain unresolved. These drafts do not improve
on the old reported twenty-difference result, whose source was not found in
the available current snapshots.

Native row-view, TableData member, aggregate row, bool-fetch, scoped failure,
and identifier-normalization hypotheses did not resolve the smaller helpers.
Near matches remain outside `src/`. Own cumulative attempt limits were reached
for the table initializer, tuner-code extractor, and specification-copy helper;
the packed routine also reached ten hypotheses in this pass.

## Other remaining functions

The following pass investigated three functions untouched in the preceding
eight-helper pass: `001308C8` (PickUpEnemyCars), `00443518` (language-table
loading), and `00445B88` (specification comparison). Thirty hypotheses and
three deferrals were appended to the diary. None reached MATCH; no function
source changed. Drafts, original disassembly, and complete judge comparisons
are retained under ignored `build/cardata-untouched/`.

The older PickUpEnemyCars drafts were located under
`/home/dev/gt4-decomp/build/auto/mcardata/manual/`. The best baseline differs
in ten of 487 instructions. Giving the candidate output cursor a lifetime
inside a guarded nonempty-list phase, with a do-loop, recovers the original
initial branch and reduces this to eight. Declaring the library qsort call
nonthrowing then recovers the original non-likely backedge, leaving seven.
The entire candidate loop now matches. The remaining differences are a
three-instruction qsort argument rotation, a two-instruction subtraction/base
copy swap before the lower score search, and a two-instruction label/length
argument copy swap before string replacement. Native string size types, pure
strlen, standard qsort source naming, and explicit lower-score update do not
resolve these. The saved best draft is `pickup-qsort-nothrow.cpp`; future work
should inspect scheduling RTL rather than repeat those source forms.

The loader's primary directory pointer remains live across all three phases,
with a separate copied directory pointer in the secondary phase. Its final
table pointer is at object offset `0x1E4`, after an unknown word at `0x1E0`.
Its secondary signed-byte category must be snapshotted before the predicate
call and retained for table addressing. Fresh drafts still differ in register
allocation and preheader/address scheduling, and do not improve on the old
reported twelve-aligned-difference result, whose draft was not found.

The comparison routine's twenty-four input/row field pairs were extracted
directly from consecutive native input and stack loads. Its final sentinel
path has no separate return-value assignment. Callers use the returned value,
so a void signature would be incorrect. Missing-return hypotheses were kept
as diagnostic drafts only; neither those nor fully defined false-return forms
match. No source with an ambiguous fallthrough return was promoted.

## PickUpEnemyCars scheduling recovery

The scheduling-RTL investigation closes the remaining seven differences at
`001308C8`: MATCH for all 487 instructions, with 1,948 body bytes in a
1,952-byte span. Direct object verification finds exactly one function,
resolves every relocation, and reproduces every original body word. The
canonical source is `src/gamedata/unit_0012D680/MCarData__PickUpEnemyCars.cpp`.

The baseline has the correct registers and instruction set. The qsort and
lower-search argument order is already established by sched1 and retained
by sched2. The string label/length pair is reversed specifically by sched2:
the length copy has one more dependent than the label copy. These are not
delay-slot mistakes. The verbose scheduler's dependency tables explain why
mere statement rearrangements did not fix them.

| Reconstruction | Differing instructions |
| --- | ---: |
| Guarded candidate loop and nonthrowing qsort baseline | 7 / 487 |
| Model ignored pointer results of native reference constructors | 5 / 487 |
| Declare the binary-search helper with its float argument first | 0 / 487 |

The string, integer, and array reference constructors at `00314B20`,
`002FE278`, and `002EFBF0` were declared as void functions in the old draft.
Modeling their ignored constructor pointer results restores explicit v0
output dependencies. This corrects the relative priorities of the label
copy into a3 and the length copy into t0 before string replacement.

For `00130618`, the EE ABI assigns integer and floating-point arguments to
independent banks. Both `search(entries, low, high, score)` and
`search(score, entries, low, high)` use a0/a1/a2 for the first three integer
arguments and f12 for the score. The float-first source declaration changes
RTL argument births and dependencies without changing the executable call
ABI. It recovers both the lower-bound subtraction/base-copy order and the
preceding qsort argument order. This is evidence for the float-first source
signature, although the executable alone cannot distinguish equivalent
parameter orders in separate argument banks. The existing recovered callee
does not need to change.

Merging the score variable, adding pure/nothrow search metadata, and modeling
the append result did not improve the five-difference draft. Seven new source
hypotheses and one direct-verification record are appended to the diary.
The worker interface also accepts the final source under `func_001308C8`;
the named source path is retained. Dumps from every compiler pass, verbose
dependency/priority tables, judged drafts, and proof are under ignored
`build/pickup-rtl/`. Source audit: 28,336 unique addresses, no duplicates or
orphans.

The full build at `2026-10-15T00:51:49Z` passes `.text OK` and `.data OK`,
with original hashes `28422e7e20a6298224294255355487b9a22cef31` and
`c28c833f9716467545bf362f321e9acc876c3603`, respectively. PickUpEnemyCars is
`linked` from source. There are 28,336 unique source addresses and 27,635
linked functions, with no duplicate or orphan sources. Evidence is saved in
`build/pickup-rtl/full-report.json`, `full-build.log`, and `proof.json`.
The next-ten contribution count is now 26 new matches overall, including
15 CarData-related functions/helpers. Thirteen CarData-related functions
still lack source: the engine-curve method and twelve support helpers.

## Disabled-car query recovery

`SPEC_DATABASE__IsDisabledCar` at `00448C10` now passes the exact judge for
35 instructions: 140 body bytes in a 144-byte span. Direct resolved-object
proof finds one function, no unresolved relocations, and every original body
word reproduced. Its source is
`src/race/unit_004271E8/SPEC_DATABASE__IsDisabledCar.cpp`, using the existing
`ee-gcc2.96-nsa-nosib` profile.

The earlier conclusion that searchInfo cannot have a second kind argument
because it does not read incoming a1 was too strong. An unused formal is not
observable in the callee. A caller-compatible declaration taking identifier
and kind, combined with an inline conversion scope, recovers the original
identifier copy and the shared a1 constant `0x26`. The callee implementation
does not need to change. This is an inferred source signature, not independent
proof of an original parameter name or declaration.

That reconstruction differs in only five instructions. Naming the signed32
number extracted from the converted identifier before the final query moves
the mask's RTL expansion ahead of the global table base. This restores both
the original mask/address order and the empty conditional branch slot, closing
all five differences. The matched source neither needs a volatile global nor
additional nothrow declarations. Those alternatives, a signed64 query result,
and a different alias profile did not match.

Four other helpers were investigated with fresh type/ABI hypotheses. The
paired identifier conversion remains five differences away in its head, with
the same seventeen-instruction body length and an exact tail. Randomization
still needs the duplicated bounds pointer; copied value objects introduce
stack traffic. The table parser's hidden-result hypothesis requires extra
copy/return machinery absent in the original, and a shared advancing cursor
shortens its body incorrectly. Small aggregate returns for the byte getter
do not recover its extra sign-extension pair. No such draft was promoted.

Twenty-two judged source hypotheses, one mechanical compile failure, direct
verification, and three deferrals were appended as twenty-seven diary records.
Drafts, detailed comparisons, baseline query RTL, and direct proof are under
ignored `build/cardata-native-pass/`. Source audit finds 28,337 unique addresses
and no duplicate or orphan source files.

The full build at `2026-10-15T01:06:26Z` passes `.text OK` and `.data OK`,
with original hashes `28422e7e20a6298224294255355487b9a22cef31` and
`c28c833f9716467545bf362f321e9acc876c3603`. IsDisabledCar is `linked` from
source. There are 27,636 linked functions. Evidence is saved in
`build/cardata-native-pass/full-report.json`, `full-build.log`, and `proof.json`.
Next-ten now contains 27 new matches overall, including 16 CarData-related
functions/helpers. Twelve still lack source in that tracked scope: the
engine-curve method and eleven support helpers.

## Remaining-target continuation and parallel source review

The fresh continuation verified a clean local baseline at `a6b8ea410` and
reused the approved matching snapshot after checking for competing builds.
All 28,337 local and remote sources have the same normalized content digest:
`409a311846536df072d730037db8720e2cf90b703c63e0bea4f7735514481c2b`.
All twelve tracked remaining targets still lack source. No source, compiler,
header, or matching-tool changes were made in this pass.

Thirty-two original-compiler checks across eight targets produced no MATCH.
One check was an unchanged draft caused by a failed newline-sensitive edit;
the corrected hypothesis was judged separately. Thirty-three append-only
diary records preserve every check and the engine-method deferral. A separate
GPT-6.1-Sol chat prepared six candidates for the engine, packed selector, and
randomization helpers; this continuation judged all six. Its local review and
candidate explanations remain under `build/cardata-parallel-sol/`; complete
verdicts, additional drafts, and compiler diagnostics are under
`build/cardata-remaining/`.

`00449190` now has an eleven-difference, 31-instruction draft with the original
loop structure and guard reloads, without a volatile count. The important
combination is the original DatabaseTable wrapper/accessor nesting with the
existing `nogcse` profile, rather than a search method directly on TableData.
The allocator gives the row-result pseudo a2 (priority 12,000, eight references
over twenty instructions) ahead of the high-bound pseudo a3 (10,434, eight over
twenty-three); the original uses the opposite homes. A reversed address-add
operand is the only other residual. Direct accessor returns add a branch;
reference outputs materialize a stack slot. Explicit integer address arithmetic
does not reverse the addition. See `search-wrapper-nogcse.cpp` and
`search-alloc.txt` in the new evidence directory.

The engine method reached its ten-new-hypothesis limit. Indexed signed loops
produce a full-span 340-instruction comparison with 34 differing rows, but add
an unwanted second count test to each graph. They are not an accepted recovery.
The original direct-loop draft already has the correct loop registers and body
instructions. Its main displacement starts when reorg steals the end-RPM load
into the zero-count branch slot, shortening each graph. Predicting raw count
zero with `__builtin_expect(count, 0)` instead selects the original array-argument
copy from the skip path and reproduces the loop instruction sequence, but adds
a saved expected-count pseudo, expands the stack, and still misses header
alignment. Native-long counts, an early expected-value assignment, and a boolean
predicate do not remove that pseudo. Keep the direct-loop baseline and
`engine-zero-likely.cpp` as complementary diagnostics; do not report either as
matching on the basis of a shortened common prefix.

The parallel review also identified a concrete packed-control layout correction:
the embedded knob object starts at controls+4, while its count is at controls+6,
not controls+4. Corrected-layout and reference-cap candidates still fail the
judge. The randomization pointer-view candidate has 33 differing rows versus
the scalar draft's 52, but introduces a stack-resident pointer and a larger
frame, so it is not a native-layout match. The byte getter, identifier converter,
table initializer, and specification-copy alternatives did not improve their
retained baselines; all remain outside `src/`.

Contribution counts remain 27 new matches overall and 16 CarData-related,
with twelve CarData targets remaining. Since source content is unchanged, the
native-pass full build remains the latest applicable validation: 27,636 linked,
original text/data hashes, no duplicate or orphan sources. No new full build,
commit, push, or pull request was performed for this unmatched pass.

## Final bounded follow-up; stopped at Tim's request

Further original-compiler checks produced no MATCH. SearchNumber's guarded
byte-offset scope fixes the address-add operand order; its closest current
candidate is `build/cardata-new-shapes/search-guarded-offset.cpp`, ten of
31 rows different solely from the high-bound/row-result a2/a3 exchange.
The corrected native Knobs subobject at Controls+4 reads its count at Knobs+2
without retaining the parent pointer; `packed-native-knobs.cpp` differs in
140 of313 rows. Loader secondary-offset computation inside the successful
predicate scope improves the retained-directory candidate to59 of148 rows;
the pure strcmp declaration and actual Database member definition do not help.
New tuner exit/peeling, byte widening and lookup offset hypotheses all fail.

The parallel Sol investigation identifies the engine's extra expected-count
value precisely: expansion produces two DI sign-extension pseudos from the
SI count; GCSE PRE shares the first across the second graph guard, extending
its life across six calls and allocating s5. It is not created by reorg.
Its numbered evidence and two proposed candidates are under
`build/cardata-parallel-sol/second-pass/`. On Tim's instruction to make one
last attempt and stop, only `00148b60-expect-int-test.cpp` was judged:
325 of343 rows differ. The natural-while candidate remains unjudged.
No source was promoted and no full build, commit or push was performed.
All judgments are appended to the diary; new verdicts are retained under
`build/cardata-new-shapes/`. Counts remain27 new overall,16 CarData-related,
and twelve remaining. Work is stopped at Tim's explicit request.
