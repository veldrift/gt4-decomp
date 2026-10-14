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
