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
