# GT4 workspace and dev container access

Recorded 2026-10-09. This workspace continues Gustavo Canepa's GT4 matching decompilation. The repository was cloned locally and transferred with Git history to the user's Linux dev container.

## Current fork and branches

- `upstream`: https://github.com/gustavocanepa/gt4-decomp
- `origin`: https://github.com/veldrift/gt4-decomp
- `codex/mcardata-matches`: the contribution branch, based on upstream `f0b3e403`, containing commit `c792b68b` with 20 native methods and seven lookup/selection helpers. Every function passes the exact-match judge; the full build preserves the original code and data hashes.
- `dev`: the user's development branch, including the contribution plus the six earlier unrelated matching sources and these workspace/research notes.

The remotes are configured in both checkouts. Pull author changes from `upstream/master` and push personal branches to `origin`. The sections below preserve earlier setup checkpoints. Game inputs and ignored build outputs remain local. Seven unfinished CarData drafts remain in the container's ignored `build/auto/mcardata/manual/` directory.

## Repository locations

| Item | Location |
| --- | --- |
| Upstream repository | https://github.com/gustavocanepa/gt4-decomp |
| Windows checkout | `F:\_projects\gt4-decomp` |
| Linux container checkout | `/home/dev/gt4-decomp` |
| Upstream branch | `master` |
| Verified transferred revision | `2afbee5f5d012a539535c4fb975161b8d0c962c4` |

Both checkouts were clean after transfer and pointed to the GitHub upstream as `origin`. This describes the transfer checkpoint, not a guarantee that either checkout remains unchanged.

## SSH access

Run from Windows:

```powershell
ssh -i C:/Users/timpa/.ssh/id_ed25519 -o IdentitiesOnly=yes -p 2225 dev@192.168.0.42
```

Then:

```sh
cd /home/dev/gt4-decomp
```

Connection details: host `192.168.0.42`, port `2225`, user `dev`. The key path above refers to the existing Windows private key; no key contents are stored here.

During the initial transfer, the sandbox's `ssh` and `scp` commands resolved to blocked wrappers. Approved calls to `C:\Windows\System32\OpenSSH\ssh.exe` and `scp.exe` worked. Restricted GitHub network access also required an approved clone operation. Use the normal permission mechanism if those restrictions apply again.

## Initial transfer checkpoint

- Container SSH access worked and the transferred revision matched the local checkout.
- Container Python was 3.12.3. Git, GCC and tar were available.
- The source assembly-policy check passed in the container.
- Sony ee-gcc, MIPS binutils, Rabbitizer and Splat were not present at the initial inspection.
- The original game executable was absent. No full matching build was run.
- Temporary repository transfer files were removed.

## Game inputs and build prerequisites

The project targets **Gran Turismo 4 USA, SCUS-97328 v1.01**. Follow the upstream [README](../README.md), [original-file instructions](../orig/README.md), and [contribution rules](../CONTRIBUTING.md).

Expected disc location:

```text
orig/SCUS-97328/Gran Turismo 4 (USA) (v1.01).iso
```

Expected extracted executable:

```text
orig/SCUS-97328/files/CORE.GT4
```

The documented setup installs Linux tools with `bash tools/setup_linux.sh`, extracts/converts the executable, splits it with `bash tools/splat.sh`, and verifies the rebuilt image with `python3 tools/build.py`. Follow the full upstream instructions for inventories and duplicate groups. Setup has now been run as recorded below; extraction and the full build still await game input.

Keep disc images, executables, extracted game data and generated build outputs out of Git. The next useful checkpoint is a full build reproducing both original loaded segments before adding new matches.

## Toolchain setup on 2026-10-09

The user requested reading `CONTRIBUTING.md` and attempting a contribution. Its acceptance rules require a `MATCH` for each accepted source, a full matching build, English repository content and no committed game data.

Container setup completed using the upstream script after creating `/home/dev/.local/share` and its `gt4` child with ownership assigned to `dev`; the existing `.local` parent was root-owned. Installed Sony compiler version: `2.96-ee-001003-1`, plus MIPS binutils, 32-bit libc, decomp-permuter and Splat 0.50.0.

Python tools live in `~/.local/share/gt4/venv`. Activate this environment before running the project's Python tools:

```sh
cd /home/dev/gt4-decomp
source ~/.local/share/gt4/venv/bin/activate
```

m2c was cloned into ignored `tools/ext/m2c` at revision `708d2d2cb2698f091a92492b328f73b24209f72d`. Its dependency declaration is `pyproject.toml`, not `requirements.txt`. It was installed editable into the venv with `toml` and `python-Levenshtein`. The project's supplied `m2c-unused-params.patch` applied successfully. m2c help and Rabbitizer R5900 import checks passed; the setup script's permuter help check passed.

Two existing sources, `src/func_00100230.cpp` and `src/func_003951D0.c`, compiled using the configured flags. Their ignored outputs are under `build/setup/`; MIPS readelf confirmed little-endian ELF32 objects carrying the R5900 flag. `tools/asm_policy.py src/*` passed. These are toolchain smoke checks, not new function matches or a full-build verification. The guided queue loaded and displayed its usage; it exits 1 for `--help`, which is not a supported command.

The container source checkout was not edited by toolchain setup; dependency patches and generated objects remain ignored. At that point a bounded search under `/home/dev` found no game input. The user subsequently supplied the ISO, and the baseline and first contributions now pass as recorded below. GTHD symbols have not been downloaded or imported.

## Verified game input and first matches on 2026-10-09

Source ISO: `\\victor-nas\Roms\PS2\Gran Turismo 4 (USA) (v1.01).iso`, 5,314,478,080 bytes. Copied with SCP to `/home/dev/gt4-decomp/orig/SCUS-97328/Gran Turismo 4 (USA) (v1.01).iso`; the NAS original was preserved. SCP completed successfully and the container copy has the same byte count. The entire ISO was not independently hashed.

Extracted `CORE.GT4`, `SCUS_973.28` and `SYSTEM.CNF`. The configuration reports NTSC version 1.01. Both executable SHA-1 hashes exactly match `orig/README.md`. The current converter's generated ELF SHA-1 is `ca47e116503e12b2db95aa7ee7debaaa99870c8b`, which differs from the old generated-ELF hash in that README; both original executables and the rebuilt loaded segments are verified independently.

The first batch used branch `codex/first-matches`, based on `2afbee5f`. Eight verified C++ additions were copied back to Windows, and both full builds reproduced the original segments. See [first contribution evidence](research/first-matching-contribution.md) for that checkpoint and the Splat compatibility workaround.

## Upstream merge on 2026-10-09

At the user's request, both checkouts fetched GitHub upstream and fast-forwarded `codex/first-matches` to `8358a18de7dbc9a2f82365dc949dab46b6d1cb20`. No merge conflicts occurred. Local notes and sources were backed up before merging in ignored `build/upstream-merge/local-work-before-merge.tar.gz` in each checkout.

Upstream independently added sources for `004CF498` and `0060AE88`. Both upstream versions passed the exact judge. Our copies were moved into ignored `build/upstream-merge/superseded-matches/` in both checkouts to avoid duplicate source addresses. Six original additions remain uncommitted under `src/`; no commits or pushes were made.

Upstream reorganizes sources under subsystem/unit folders and supports per-source compiler markers. Container compiler variants `ee-gcc2.9-991111`, `ee-gcc2.96-no-strict-aliasing` and `ee-gcc2.96-stl` were installed from the archive URLs in `project.toml`. The recursive source assembly-policy check passed, and all six retained local sources passed the updated exact judge.

Full merged-build validation is recorded in [the merge checkpoint](research/upstream-merge-2026-10-09.md). The earlier first-batch results describe their original revision and must not be substituted for the merged build.

## SOCOM boundary

The comparison project is `F:\_projects\SOCOM-OpenSource`. The user explicitly required read-only inspection because it is under active work. No files were changed there, and no SOCOM builds, translations or game runs were started. Preserve this boundary for related comparison work.

See [workflow and GTHD research](research/workflow-and-gthd-symbols.md) for the discussion and possible continuation.
