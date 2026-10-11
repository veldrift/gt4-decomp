# GT4 workflow and GTHD symbol research

Recorded 2026-10-09 against GT4 revision `2afbee5f5d012a539535c4fb975161b8d0c962c4`. Repository/container details are in [workspace access](../workspace-access.md).

## Project status and scope

GT4 is recovering C/C++ that compiles into the original PS2 instructions. A native port is its longer-term goal; the current full-build target is the original PS2 executable.

The checkout contained 15,679 `src/func_*` files. This is a source-file count, not an independently verified count of functions surviving the full link. The README's 3,112 linked-source count is older than the checkout. The [coverage notes](../../knowledge/coverage-map.md) report about 50.9% of functions and 21.3% of code bytes matched, with their own checkpoint caveats. The cloned `origin/progress` report is older still: it describes revision `bee050e`, 12,099/31,128 functions, 10.27% matched bytes and 9.63% linked bytes. Do not mix these checkpoints or present any as a newly verified build result.

## What the tools do

| Tool | Role |
| --- | --- |
| [Splat](https://github.com/ethteck/splat) | Splits the original binary into code/data pieces for incremental rebuilding. GT4 uses it to generate per-function assembly under `build/splat/`. |
| [Rabbitizer](https://github.com/Decompollaborate/rabbitizer) | Decodes MIPS instructions, including PS2 R5900 instructions. GT4 uses it for assembly views and instruction inspection. It is not a C++ decompiler. |
| [m2c](https://github.com/matt-kempster/m2c) | Produces draft C, with partial C++ support, from assembly. It is designed to assist matching decompilation; recovered types and names still need evidence. |
| Sony ee-gcc 2.96 | Original-style C/C++ compiler targeting the PS2 Emotion Engine. GT4 identifies build `001003-1` and uses `-O2 -G0 -fno-exceptions`. Compiler identity and settings matter because equivalent source can otherwise produce different instructions. |
| decomp-permuter | Tries source variations to bring near matches closer to the original compiler output. |
| Ghidra | Useful for exploring functions, references and types. The GT4 converter produces a compatible ELF, but Ghidra is not a dependency of the documented automatic matching loop. |

Sources: upstream [pipeline documentation](../../TOOLS.md), [compiler configuration](../../project.toml), [matching judge](../../tools/match.py), [full build](../../tools/build.py), and the tool repositories linked above.

## GT4 matching loop

1. Extract and decompress `CORE.GT4`, then convert it to ELF.
2. Inventory functions, split code/data with Splat, and group duplicates/similar functions.
3. Generate m2c drafts and provide assembly, strings, solved examples and compiler knowledge.
4. Improve candidates with templates, automatic rules, human/agent work or the permuter.
5. Compile with Sony ee-gcc and compare instructions and address-bearing relocations with `tools/match.py check`.
6. Save accepted source and propagate it to duplicates, rechecking each copy.
7. Link recovered source at original addresses with remaining assembly and verify both loaded segments against the original hashes using `tools/build.py`.

The documented automatic model loop uses Claude Code CLI. The guided `agent_step.py` queue also supports people or agents; continuing the matching work does not inherently require adopting that automatic model backend. No ps2recomp integration was found in this checkout.

## Comparison with SOCOM

The inspected SOCOM workspace has an active Godot engine-replacement route and a separate paused PS2Recomp experiment. Its `memory/STATUS.md` was dated 2026-10-08 when read. This is a snapshot of another actively changing project.

| Aspect | GT4 matching decompilation | SOCOM PS2Recomp experiment | Active SOCOM Godot route |
| --- | --- | --- | --- |
| Purpose | Recover source reproducing original PS2 instructions | Translate original CPU instructions into code executable on a PC | Implement an engine reading original assets and recreating behavior |
| Main analysis | Assembly, compiler idioms, RTTI, script registrations | Ghidra function boundaries and original execution/service evidence | Ghidra/debug references, asset formats and behavior evidence |
| Compiler | Original Sony PS2 compiler | Modern PC C++ compiler | Modern .NET/C# tools |
| Validation | Function matching and complete-image hashes | Runtime tests, traces and original behavior comparison | Data, rendering and behavior comparisons |
| Remaining challenge | Recover source, then make a PC port | Implement required PS2 runtime/service behavior | Recover and implement faithful systems |

SOCOM's experiment exported a Ghidra retail function map, translated the executable into literal C++ operations, built a native runner, and investigated startup boundaries. Translating the CPU code does not itself provide correct disc, IOP, graphics or audio services. Its current engine route instead decodes maps, textures, models, animation and mission data into application-owned structures and behavior.

Read-only local evidence:

- `F:\_projects\SOCOM-OpenSource\README.md`
- `F:\_projects\SOCOM-OpenSource\memory\STATUS.md`
- `F:\_projects\SOCOM-OpenSource\memory\DECISIONS.md`
- `F:\_projects\SOCOM-OpenSource\docs\research\socom-recomp-experiment.md`
- `F:\_projects\SOCOM-OpenSource\docs\research\ps2recomp-public-workflows.md`
- [PS2Recomp upstream](https://github.com/ran-j/PS2Recomp)

GT4's tools could help SOCOM selectively: m2c as a second decompilation view, Rabbitizer for instruction checks, and a matching loop for important recovered functions. A SOCOM matching effort would first need to establish its actual compiler and settings; GT4's ee-gcc configuration cannot simply be assumed correct. These tools would not directly resolve PS2Recomp's missing runtime services. No SOCOM implementation or workflow change was made or authorized by this comparison.

## GTHD symbols and their source

The only explicit GTHD symbol reference found in the GT4 checkout was [NOTES.md](../../NOTES.md), which lists mapping GT HD prototype names onto GT4 functions as future work. Current naming tools recover names from GT4's own RTTI/vtables and native script registrations. No GTHD importer or verified correspondence set was found in the inspected tree; this does not establish what the author may have done privately.

Nenkai's [GT4 resources page](https://nenkai.github.io/gt-modding-hub/ps2/gt4/tools/#useful-resources) links **GTHD Prototype Debug Symbols** through Mega. It says most symbols apply to GT4 and recommends IDA/Ghidra with a PS3 EBOOT loader. The page was inspected; the linked download could not be inspected through the browser tool. Its availability, exact build, format and contents remain unverified. No symbol archive was downloaded.

The [GTHD build reference](https://nenkai.github.io/gt-modding-hub/builds/gthd/) describes GTHD as a PS3 derivative of GT4 and documents multiple builds. Do not assume the linked symbol reference is the standard public demo or a particular prototype without inspecting its identity.

## Proposed continuation with GTHD

This is the sequence discussed, not completed implementation or an active execution goal:

1. Establish the container toolchain and a passing full GT4 baseline using the user's USA v1.01 game files.
2. Obtain the resource linked by Nenkai, preserve its original form, record its hash/build identity, and inspect whether it contains an executable, separate symbol data or an analysis database.
3. Import an appropriate reference into Ghidra/IDA and export names plus whatever type information actually exists. Do not assume debug symbols include complete structs or source code.
4. Select one shared class/subsystem already recognizable through GT4 RTTI or script registration.
5. Establish correspondences using class names, vtable relationships, strings, call relationships and behavior. GTHD PS3 PowerPC addresses and instruction bytes cannot be copied onto GT4 PS2 MIPS. Layouts and implementations may differ.
6. Store verified mappings separately with GT4 address, GTHD identity/address/name, supporting evidence and unresolved ambiguity. Preserve GT4 address-based source identifiers so the current judge continues to resolve references.
7. Feed confirmed names/types into analysis and agent context, then continue the existing compile/compare/refine loop. Confirm every new recovered function and the full linked image.

Integration caution: `tools/rtti.py` rewrites `config/symbol_addrs.txt`. A separately maintained mapping input and explicit merge would avoid losing GTHD-derived names when RTTI output is regenerated. Symbols improve understanding; only the existing compiler/judge/build process establishes matching GT4 code.

First useful milestone: **a passing GT4 baseline and one convincingly mapped shared class**. Game input, GTHD resource contents, and analysis-tool availability are still prerequisites to verify.
