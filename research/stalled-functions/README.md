# Stalled matching functions

Branch: `feat/stalled-functions`. Base: `4f078903c394e62356ef035d1abbcec2c5eb5f37` (the locally validated upstream PR 11/12 integration).

This checkpoint preserves all 18 targets in our recent stalled scope: twelve CarData functions and six menu functions. It does not inventory every unmatched function in the game. The existing matched source, tools and PR integration are inherited from the base. No unmatched candidate is registered under `src/`.

## Target list

| Address | Group | Role | Retained work |
| --- | --- | --- | --- |
| `00148B60` | CarData | Engine curve data | [Notes and candidates](00148b60/README.md) |
| `00449190` | CarData | DatabaseTable searchNumber | [Notes and candidates](00449190/README.md) |
| `00449F80` | CarData | Byte getter | [Notes and candidates](00449f80/README.md) |
| `004490F8` | CarData | Table initialization | [Notes and candidates](004490f8/README.md) |
| `004478F8` | CarData | Tuner-code extraction | [Notes and candidates](004478f8/README.md) |
| `00448B48` | CarData | Specification copy | [Notes and candidates](00448b48/README.md) |
| `0043BBC0` | CarData | Packed controls / selector update | [Notes and candidates](0043bbc0/README.md) |
| `00449AF8` | CarData | Table lookup helper | [Notes and candidates](00449af8/README.md) |
| `00443518` | CarData | Language-table loading | [Notes and candidates](00443518/README.md) |
| `00445B88` | CarData | Specification comparison | [Notes and candidates](00445b88/README.md) |
| `00447DD0` | CarData | DisabledInfo searchInfo / identifier conversion | [Notes and candidates](00447dd0/README.md) |
| `00440FB8` | CarData | Randomization bounds helper | [Notes and candidates](00440fb8/README.md) |
| `00207590` | Menu | Composite property reader | [Notes and candidates](00207590/README.md) |
| `00233E38` | Menu | RootWindow property reader | [Notes and candidates](00233e38/README.md) |
| `002A29F0` | Menu | ImageFace property reader | [Notes and candidates](002a29f0/README.md) |
| `002A38A0` | Menu | ImageFace pattern coordinates | [Notes and candidates](002a38a0/README.md) |
| `002B7310` | Menu | Localized literal text setter | [Notes and candidates](002b7310/README.md) |
| `0020EEB8` | Menu | Layout tokenizer | [Notes and candidates](0020eeb8/README.md) |

## What is preserved

- `knowledge/attempts.jsonl` remains the canonical append-only hypothesis diary; each target also has a checkpoint snapshot.
- Each target includes the available candidate sources referenced by its diary and a retained starting point. The manifest records original paths, SHA-256 digests and missing source references.
- Existing narrative handoffs remain in [CarData recovery](../../knowledge/cardata-next-ten-recovery.md) and [menu recovery](../../knowledge/menu-local-recovery-matching.md). Their dated historical results are superseded by the current status here where noted.
- Original game data, binary dumps, compiler outputs and raw disassembly are excluded. Compiler caches and full validation evidence remain local under ignored `build/`.

## Previously stalled, now resolved

- `002D8C90` SelectBox constructor: [registered source](../../src/ui/mSelectBox/mSelectBox__structor_0.cpp).
- `00140FA8` Garage tuner list: [registered source](../../src/gamedata/unit_0013B5F8/MCarGarage__getTunerList.cpp).
- `00148940` Garage gear-ratio data: [registered source](../../src/gamedata/unit_00148030/MCarGarage__buildGearRatioData.cpp).

SelectBox came from upstream PR 12 and passed full 168-byte verification and explicit linked status. It is no longer one of the stalled menu targets. See [upstream validation](../../docs/research/upstream-pr-11-12-validation.md).

## Resuming

Work was deliberately stopped at Tim's request; this branch is a preservation checkpoint, not a new matching pass. Read the per-target notes and diary before trying a genuinely new hypothesis. Restore a chosen candidate into ignored scratch space before editing/judging; preserve this checkpoint. Raw row scores do not establish complete-body matching. Acceptance still requires unchanged judge MATCH, full body/relocation/padding verification and original full-build hashes with the function explicitly `linked`.

The current Godot menu loader stops at TextFace. TextFace matching is future work, not one of these 17 previously attempted targets. No Godot files are changed by this checkpoint.

2026-10-15: TextFace/VBox host loading has advanced since the historical checkpoint above. Its current localized-literal gate is `002B7310`, preserved here after a bounded Sony-compiler recovery pass. See the target notes for current probe results.
