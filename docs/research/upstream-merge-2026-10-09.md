# Upstream merge checkpoint

User request: fetch and merge upstream. Checked 2026-10-09 in the Windows checkout and Linux dev container.

Subsequent publication: the author's repository is now named `upstream` and the user's fork https://github.com/veldrift/gt4-decomp is named `origin` in both checkouts. The CarData batch is committed and pushed as `c792b68b` on `feat/mcardata-matches`; `dev` tracks the remaining source additions and project notes. Earlier uncommitted-state statements below are historical.

## Latest upstream sync

Both `codex/first-matches` checkouts now include `f0b3e403deeb7b71be6b67832bd84a99de01ca34`, "Library code without sibling calls: 118 functions; block-copy drafts". A fresh fetch from `origin` confirmed both are current with `origin/master`. The author's repository is configured as `origin`; there is no separate remote named `upstream`. CarData additions were preserved without conflicts.

The container has the two compiler configurations required by this commit, `ee-gcc2.96-nsa-nosib` and `ee-gcc2.96-nosib`, using the existing ee-gcc 2.96 archive. The combined full build passes code and data hash verification, with 17,573 functions directly linked. All 27 new CarData contribution functions are linked and pass the assembly-policy check. See [the current CarData checkpoint](mcardata-pause-checkpoint.md). Sources remain uncommitted and unpushed; SOCOM was not touched.

The sections below record the earlier sync to `8358a18d`.

## Repository result

Both `codex/first-matches` branches fast-forwarded from `2afbee5f` to `8358a18de7dbc9a2f82365dc949dab46b6d1cb20`, equal to the fetched `origin/master`. Eight upstream commits were integrated, with no merge conflicts. No local commits or pushes were made. The remote's mutable `progress` branch was fetched as well; it was not merged into the source branch.

Upstream adds architecture/class/runtime documentation, source organization by subsystem/unit, canonical symbol names, alternative compiler selection, accessor generators, third-party expat and STL/string recovery, and a compact GT4 project skill under `.claude/skills/gt4-decomp/SKILL.md`.

## Preservation and overlap

Before merging, the local notes and all eight previous source additions were archived in ignored `build/upstream-merge/local-work-before-merge.tar.gz` in each checkout. Game inputs and existing ignored build outputs were preserved.

Upstream now supplies these two addresses:

- `src/network/unit_00494578/func_004CF498.c`
- `src/runtime/unit_005FF878/func_0060AE88.c`

Both upstream sources passed `tools/match.py check` with their configured compiler. Our original C++ versions were moved to ignored `build/upstream-merge/superseded-matches/` in each checkout, rather than kept as competing source entries. They remain recoverable individually and in the pre-merge archive.

The six other original source additions remain uncommitted in both checkouts and passed the merged judge:

`00105500`, `00565B98`, `005C34A0`, `005F9A90`, `005FA570`, `005FBD40`.

Their temporary flat placement is supported by the updated tools; a future contribution preparation should apply upstream's canonical layout to these six specifically, then check source organization and matching again.

## Validation

The updated recursive source assembly-policy check passed. Git whitespace checks passed. Container compiler variants were installed using the archive URLs in merged `project.toml`: `ee-gcc2.9-991111`, `ee-gcc2.96-no-strict-aliasing`, and `ee-gcc2.96-stl`.

The full merged build ran in the foreground with `python tools/build.py --jobs 2`, following the newly added project skill's maximum parallel-job guidance. It exited zero. Its log is ignored `build/upstream-merge/merged-build.log`.

- Code segment matched exactly: SHA-1 `28422e7e20a6298224294255355487b9a22cef31`.
- Data segment matched exactly; constants from 155 source functions supplied 1,882 bytes.
- 17,412 functions linked directly from source, covering 1,604,528 of the main loaded segment's 5,339,668 bytes (30.05%).
- All eight original contribution addresses are `linked`: six through retained local sources and two through upstream replacements.
- The regenerated local progress report counted 17,728/30,964 matching targets (57.25% of functions), 31.69% of counted function-code bytes matched and 30.29% linked. These denominators differ from the complete loaded-segment measure above.

Both checkouts retain the same six local sources and notes as uncommitted work. The merged Windows checkout was not built locally; full compiler/judge/build validation ran in the container using the verified original executable. SOCOM remained untouched.
