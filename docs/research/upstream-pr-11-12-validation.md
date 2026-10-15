# Upstream PRs 11 and 12: local integration and validation

Checked 2026-10-14. User requested a separate integration branch and comparison
against our 29 verified function sources. Existing `dev` and
`feat/matched-functions` were successfully pushed to `veldrift/gt4-decomp`.
The authenticated account for those pushes was the existing signed-in
`veldrift` account, selected only for each command; global login was unchanged.

## Reviewed revisions

- [PR 11: Fix 00543338](https://github.com/gustavocanepa/gt4-decomp/pull/11),
  head `43a597f73e724a67a133d6058a9215e8d5be5b32`.
- [PR 12: Match 104 more functions](https://github.com/gustavocanepa/gt4-decomp/pull/12),
  head `c50452e8f94aa1ff527d49d866c12839e495ecaf`.
- Upstream base: `b59952917`; our source-only batch:
  `984fc333cf073b8835c97a0da2ba470de8aef10a`.
- Integration branch: `feat/upstream-pr-11-12`, based on dev `f79c544c4`.
  Source-bearing integration commit: `fda71447387d6fd8d00f758b78d7fd5b6af64bd2`.

Both PR histories are preserved. Three add/add conflicts were symbol-name
differences; the integration keeps the incoming PR versions. All 105 reviewed
source files agree with their respective PR heads after CRLF normalization.
The original dev and source-only branch remain unchanged by this integration.
No upstream PR comments or changes were published.

## Results

| Batch | Sources | Compile and unchanged judge | Linked from source |
| --- | ---: | ---: | ---: |
| PR 11 | 1 | 1 | 1 |
| PR 12 | 104 | 104 | 100 |
| Combined | 105 | 105 | 101 |

The fresh full build passes the original text and data hashes, is not partial,
and reports 28,434 source addresses, 27,730 linked functions, zero duplicate
sources and zero orphans. Original hashes:

- Text SHA-1: `28422e7e20a6298224294255355487b9a22cef31`.
- Data SHA-1: `c28c833f9716467545bf362f321e9acc876c3603`.

**PR 12 is not fully accepted in this setup.** Four functions fall back to
original assembly despite individual judge MATCH. The strict acceptance script
fails on those four instead of treating the original-hash image as proof that
every new source participated:

| Address | Full-build exclusion |
| --- | --- |
| `00477890` | Own `.rodata`, not accepted by the build's data-placement path |
| `0052A588` | Own `.rodata`, not accepted by the build's data-placement path |
| `00485368` | Unmapped mangled STL vector `insert` symbol |
| `003323B0` | Unmapped mangled STL vector `insert` symbol |

These are full-link limitations, not observed syntax/compiler failures or
instruction-judge differences. No candidate sources or judge/compiler flags
were changed to conceal or bypass them. PR 12's description reports a stronger
full-build result; that claim was not reproduced for these four on this pinned
local toolchain.

One hundred sources pass direct complete-body, padding and resolved-relocation
comparison. Five initially need full-link resolution: the four above and
`001C7BF8`, whose literal data is successfully placed and which is linked.

## Overlap with our 29

Seven addresses overlap PR 12; 22 of our 29 are outside that batch. PR 11
overlaps none. This counts function identities by native address, rather than
filenames or C++ symbol spelling.

| Address | Function | Source comparison with our source-only branch |
| --- | --- | --- |
| `0012F3E0` | `MCarData__ShiftCarCode` | Byte-identical |
| `0014E1C8` | `MCarGarage__getCurrentWing` | Equivalent named entry alias and EOF formatting |
| `00190EA8` | `MOption__getAnalogConfig` | EOF whitespace only |
| `00191078` | `MOption__searchAnalogConfig` | Equivalent named entry alias |
| `001917B8` | `MOption__getButtonConfig` | EOF whitespace only |
| `0019B558` | `mPhotoRenderFace__virtual_67` | Equivalent named base-call alias |
| `00430C28` | Packed threshold helper | Byte-identical |

The three named aliases resolve to the same addresses as our generic names;
both versions have compiler/byte verification. This comparison makes no claim
about who first authored shared source.

PR 12 also adds `mSelectBox__structor_0` at `002D8C90`, one of our six recent
menu targets. It passes complete 168/168-byte verification with zero unresolved
relocations and is explicitly `linked`. It is an upstream contribution verified
here, not a newly authored match by this continuation. The other five menu
targets are absent from PR 12; Godot was left unchanged.

## Reproduction evidence

Ignored local evidence is under `build/upstream-review/`: the 105-file manifest,
all individual verdicts, object-verification results, full build log/report,
acceptance failure details and independent overlap JSON/report.

The isolated Linux snapshot was extracted from a Git archive of the integration
commit. Archive SHA-256:
`d34cb9b663ae146ccb3453ebd36c8aac157f8c3204d0d3864cbc380a9394969d`.
It has its own build cache and read-only references to existing original assets.
Tracked text build inputs were normalized from CRLF to LF for Linux. The first
transport-only failure (`pipefail` with a trailing CR in the shell wrapper) is
preserved under `initial-environment-errors/`; all reported final checks follow
that line-ending repair. No compiler, judge logic, or flags were weakened.
