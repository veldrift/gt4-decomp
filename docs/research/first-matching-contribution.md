# First verified GT4 matching contribution

Checked 2026-10-09. Basis `2afbee5f5d012a539535c4fb975161b8d0c962c4`, contribution branch `codex/first-matches` in the Windows and container checkouts. This first batch adds eight small C++ matches, totaling 96 newly linked source bytes. No game data was added to Git, no changes were made in SOCOM, and no upstream publication was performed.

## Input and baseline

The user supplied `\\victor-nas\Roms\PS2\Gran Turismo 4 (USA) (v1.01).iso`. The 5,314,478,080-byte ISO was copied to the container's ignored `orig/SCUS-97328/` directory. The original was preserved. SCP succeeded and the destination byte count matched; no independent full-ISO checksum was performed.

Extracted-file checks:

| Input | SHA-1 | Result |
| --- | --- | --- |
| `CORE.GT4` | `30031137ce494323816bb707b90d3ec0d07937d2` | Exact upstream expected hash |
| `SCUS_973.28` | `1df6f08c348e55f66c3a38e1774a9a989ce7d6ba` | Exact upstream expected hash |
| Generated `CORE.GT4.elf` | `ca47e116503e12b2db95aa7ee7debaaa99870c8b` | Current converter output; differs from the old README generated-ELF hash |

`SYSTEM.CNF` identified `SCUS_973.28`, version 1.01, NTSC. The ELF hash difference does not invalidate the verified original input or the exact loaded-segment comparison below.

Splat generated 31,164 functions; `tools/inventory.py` identified 31,128 decompilation targets after excluding the original assembly list. Duplicate scanning reported 27,396 considered bodies, 18,640 distinct bodies, 1,520 groups with copies and 8,756 copies. These duplicate-scan counts use that tool's own filters and are not the total inventory.

The baseline `python tools/build.py --jobs 6` exited zero with both segments matching. It linked 15,437 functions directly and 1,086,368 bytes from source out of the main loaded segment's 5,339,668 bytes (20.35%). The remaining assembly/raw-byte paths reproduce undecompiled code; a passing full build does not mean the whole game is recovered source.

## Splat compatibility and reproduction

Splat 0.50.0 with spimdisasm 1.42.4 rejected the checked-in symbol file's `type:data` annotation and duplicate aliases at an address. An ignored helper at `build/setup/prepare_splat.py` generated:

- `build/setup/symbol_addrs.txt`: one unique address label per symbol address, using `func_ADDR` for functions and `D_ADDR` for other entries. These labels also preserve the filename format expected by the current inventory/build tools.
- `build/setup/gt4.yaml`: the upstream configuration with its base path resolved to this checkout and its symbol input redirected to the generated copy.

Original semantic names remain untouched in `config/symbol_addrs.txt`. Run in the container after activating the venv:

```sh
python build/setup/prepare_splat.py
python -m splat split build/setup/gt4.yaml
python tools/inventory.py
python tools/dedup.py scan
```

The helper exists locally and in the container but is ignored by Git. It must be explicitly preserved or recreated if the ignored build directory is removed. A permanent upstream compatibility fix has not been implemented.

Splat also regenerated `include/include_asm.h` with absolute container include paths. The only generated change to that tracked header was inspected and restored to `HEAD` before contribution work. A future split may regenerate it again; preserve unrelated user edits rather than blindly restoring the file.

## Source additions and verification

Four candidates were authored from the original assembly and established compiler rules, without inline assembly or pinned registers. The judge accepted each, and `tools/dedup.py apply` generated one previously unmatched copy of each. Every copy was rechecked by the tool.

| Primary function | Operation represented by source | Verified duplicate |
| --- | --- | --- |
| `00105500` | Store two float arguments at offsets 0x20 and 0x24 | `005FA570` |
| `004CF498` | Store two integer arguments at offsets 0x6C and 0x70 | `0060AE88` |
| `00565B98` | Store two integer arguments at offsets 0x24 and 0x28 | `005F9A90` |
| `005C34A0` | Store the second argument into the global at 0x00618714 | `005FBD40` |

The field names are deliberately generic because their higher-level meaning has not been established. Each function matched three executable instructions, with original alignment padding excluded by the judge. `tools/asm_policy.py src/*` passed after adding all eight.

One initial candidate, `0010AA08`, was deferred: a plain pointer store had the correct global address and operation but used `$v0` where the original used `$v1`. No source for it was accepted. Its ignored candidate and agent result retain that investigation; resolving the original source form remains future work.

## Full-build acceptance

`python tools/build.py --jobs 6` exited zero after the additions:

- Code segment: exact match, SHA-1 `28422e7e20a6298224294255355487b9a22cef31`.
- Data segment: exact match, including constants placed from 145 sources.
- All eight new functions reported `linked` in `build/full/report.json`.
- Directly linked functions increased from 15,437 to 15,445.
- Source bytes increased from 1,086,368 to 1,086,464: **96 additional bytes**.
- `tools/report.py` reported 15,687/31,128 functions matched (50.40%), about 21.12% of counted function code bytes matched and 20.49% linked. This denominator differs from the whole loaded-segment percentage above.

The assembler emitted 298 instructions as raw words where its syntax could not represent Splat's instruction text. This is the upstream build's existing fallback for undecompiled assembly and does not affect the eight new C++ sources.

Ignored container evidence is under `build/setup/`: `baseline-build.log`, `baseline-report.json`, `baseline-progress.json`, `first-matches-build.log`, `splat.log`, and the compatibility helper/config. The final per-function report is `build/full/report.json`; the local progress summary is `progress/report.json`. These files were not published through `publish_progress.py`.

## Handoff

The eight source files and these notes are present in the Windows workspace; the same source additions exist in the container. They are uncommitted and unpushed. Review the source additions before deciding whether to commit or contribute the batch. A later PR should describe them as AI-assisted source recovery plus tool-generated duplicate matches and cite the exact-judge/full-build checks.

Future work can continue the guided queue or address a useful compiler rule/family. GTHD symbol acquisition/import remains separate unfinished work, documented in [the workflow research](workflow-and-gthd-symbols.md).
