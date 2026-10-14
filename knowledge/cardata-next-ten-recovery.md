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
