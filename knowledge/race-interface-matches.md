# Race interface and small-method matches

Recovered 2026-10-09 on `codex/car-geometry-virtual-wrappers`. The user expanded the
initial geometry task to larger methods and then requested at least 100 new
functions, including easy related matches. The completed batch contains **103 new
functions**, totaling **5,948 judged and directly linked instruction bytes**.

Proposed contribution title: **Recover car geometry and small race methods**.
All sources belong to the race subsystem. Geometry algorithms behind the recovered
dispatch methods remain outside this contribution.

## Scope and ancestry

| Group | New functions | Scope |
| --- | ---: | --- |
| Initial geometry checkpoint | 38 | 32 requested forwarding wrappers, four interface queries and two initializers. |
| Geometry extension | 6 | CarGeometry slots 24–26, MTRGeometry slot 07 and two adjacent geometry queries. |
| RaceCarModel | 8 | Slots 04, 15, 31, 32 and 39, plus three resource/cleanup support methods. |
| Other small race methods | 51 | Virtual forwarding, call sequences, display updates, flags, accessors, initialization, a clamp and an array clear. |
| Total | 103 | Each address counted once, with its canonical source path. |

The branch was renamed from `feat/easy-function-batches` without rebasing. Its base
is `dev` commit `cc47baf51d274bf6f6eb314c979488ca793fdd0f`, which already contains the
separate 27-function CarData contribution, six earlier matches and project notes.
Those earlier matches are excluded from the 103 count and their sources remain
unchanged. Commit `b2484e29b094b6accc26db8752e814370c0abcef` records the first 38.
Subsequent commits separate the six geometry additions, eight car-model methods
and 51 other race methods for review. No push or PR was made.

The broader scope was explicitly requested after the original focused batch.
For review, use the preserved `dev` base or review the individual commit groups;
an upstream-base diff includes earlier pending contributions as well.

## Reconstruction

This is AI-assisted reconstruction from local executable evidence, existing matching
siblings, `tools/agent_step.py` prompts, m2c drafts and manually reconstructed C/C++.
Candidate inventories and unsuccessful attempts are retained under the ignored
`build/auto/geometry-wrappers/` directory, separate from accepted sources.

The [geometry note](car-geometry-interface-matches.md) explains the initial virtual
dispatch representation. Slots 24–26 use an inline query helper that preserves the
original repeated virtual calls and their evaluation order. RaceCarModel methods
use explicit partial object layouts and preserve flag tests, call order and float
arguments. Broader candidates were limited to small race methods; C and C++ frontend
choices, store order and callee prototypes were tested against the original code.

Names, partial layouts and unresolved callee prototypes remain provisional. Some
m2c-derived sources retain generic field-access macros and inferred integer
returns. Exact code identity verifies the recovered implementation, not a complete
semantic class API. No judge or compiler-policy rules were weakened.

## Verification

Every new function was accepted only after the exact-match judge reported MATCH.
A final independent pass checked all 103 canonical paths with `tools/match.py check`,
checked source policy for forbidden assembly/pinned registers and unsupported m2c
operations, and recorded SHA-256 hashes for the accepted files. Windows and Linux
copies of every source have identical hashes. `git diff --check` passed.

The final full build ran in the Linux dev container with two jobs:

```sh
cd /home/dev/gt4-decomp
source ~/.local/share/gt4/venv/bin/activate
python tools/build.py --keep-going --jobs 2
```

Both original segments match byte for byte:

| Segment | Original and rebuilt SHA-1 |
| --- | --- |
| `.text` | `28422e7e20a6298224294255355487b9a22cef31` |
| `.data` | `c28c833f9716467545bf362f321e9acc876c3603` |

All 103 addresses have status exactly `linked` in `build/full/report.json`.
Raw-byte fallback is excluded from acceptance. The build reports 5,948 bytes from
these sources, agreeing with the sum of individual judge instruction counts.

Useful ignored checkpoints are synchronized between Windows and the container:
`verified-results.json` lists addresses, canonical paths, instruction sizes and
source hashes; `verify_all.py` repeats the consolidated judges/policy checks;
`100-plus-full-build.log` records the full build; `build-proof.json` records segment
hashes and directly linked addresses; `check_build.py` verifies that proof. Drafts,
attempt results and reconstruction scripts are included in the checkpoint transfer.
Game inputs, assembly dumps and generated build binaries are excluded from commits.

## Unresolved work

All 32 original targets and the three larger CarGeometry targets are complete.
The following additional attempts remain unresolved and are excluded from the count:

| Address | Candidate | Remaining issue |
| --- | --- | --- |
| `0038CFD8` | Geometry lookup loop | Loop/register allocation and scheduling still differ. |
| `0038DC30` | Geometry initialization support | Argument setup and common-expression scheduling still differ. |
| `00390E78` | RaceCarModel slot 03 | Compiler retains a float constant where the original reloads it. |
| `0038A2F0` | RaceBase slot 95 | Two prologue instructions remain in a different order. |

The small-method scans contain other unsuccessful candidates as well; those scan
results are checkpoints, not accepted functions. The race subsystem has not been
exhaustively reconstructed. Near matches are never counted as completed.
