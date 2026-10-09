# First PR candidate: MCarData eligibility flags

**Historical two-function proposal.** The scope subsequently expanded; see [the current pause checkpoint](mcardata-pause-checkpoint.md) for the 17/23 additional matches, six remaining methods, validation limits, and follow-on candidates. The PR description below has not yet been updated for the expanded batch.

Checked 2026-10-09 against upstream commit `8358a18de7dbc9a2f82365dc949dab46b6d1cb20`, on `codex/first-matches`. Both new files are present in the Windows checkout and `/home/dev/gt4-decomp` in the dev container. They remain uncommitted and unpushed.

## Selected scope

| Address | Function | Source file | Verified code bytes |
| --- | --- | --- | --- |
| `00130300` | `MCarData::NotForSell` | `src/gamedata/unit_0012D680/MCarData__NotForSell.cpp` | 284 |
| `00130420` | `MCarData::RaceForbidden` | `src/gamedata/unit_0012D680/MCarData__RaceForbidden.cpp` | 284 |

This is a coherent pair of script-facing car-data flag getters. Both obtain a car identifier through the existing virtual string interface, parse it, release the reference-counted string, query `func_004489A0`, convert the result to a Boolean script value, and assign/release the reference-counted result handle. The flag selector is 0 for NotForSell and 2 for RaceForbidden. These names come from the repository's existing symbol mapping; this work does not independently establish the underlying flag representation.

The source was recovered with AI assistance by adapting the already matched upstream `MCarData__GetPrice.cpp` wrapper and checking the original assembly. Neither a permuter nor inline assembly was used. GTHD debug symbols were not downloaded or imported for this work.

Only these two C++ files belong in this proposed PR. The six earlier small matches and local workspace/research notes are separate work.

## Validation

In the container, after activating `~/.local/share/gt4/venv`:

```sh
python tools/match.py check 00130300 src/gamedata/unit_0012D680/MCarData__NotForSell.cpp
python tools/match.py check 00130420 src/gamedata/unit_0012D680/MCarData__RaceForbidden.cpp
python tools/asm_policy.py src/gamedata/unit_0012D680/MCarData__NotForSell.cpp src/gamedata/unit_0012D680/MCarData__RaceForbidden.cpp
python tools/build.py --keep-going --jobs 2
```

Both judges printed MATCH, each for 71 instructions. Assembly-policy validation passed. The full-build report independently confirms `text_matches: true`, `data_matches: true`, and `linked` for both addresses. This report check matters because `--keep-going` alone does not make exit status proof of a successful binary comparison.

- Code SHA-1: `28422e7e20a6298224294255355487b9a22cef31`, identical to the original.
- Directly linked functions: 17,412 to 17,414.
- Source code bytes: 1,604,528 to 1,605,096, an increase of **568 bytes**.
- Ignored container log: `build/pr-mcardata-build.log`.
- Copied local build report: `build/pr-mcardata/report.json`.

The full-checkout `tools/organize.py --check` reports 11 existing placement differences, including our six earlier flat sources and five upstream flat sources. It reports no rename or placement changes for this pair. No global organization operation was performed.

## PR description draft

Suggested title: **Match MCarData NotForSell and RaceForbidden getters**

Recover the two unmatched MCarData script getters for sale and race eligibility flags. Both use the existing car-ID parsing and reference-counted value conventions; the recovered sources query flag selectors 0 and 2 respectively.

AI-assisted recovery from the original assembly, using the already matched GetPrice wrapper as a reference. Both functions pass the exact-match judge (71 instructions each), source assembly-policy validation passes, and the full build preserves the original code and data. Both additions link directly from source, recovering 568 code bytes.

## Follow-on candidates

Nearby unmatched `MCarData` methods include `IsStrange`, `IsTestCar`, `GetMaker`, `GetTuner`, `GetCountry`, and `GetCategory`. These are candidates to investigate, not accepted matches. The two verified eligibility getters are sufficient for a small first PR without expanding its scope.
