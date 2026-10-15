# Localized literal text setter 002B7310

2026-10-15. Recovery basis: matching revision `292769450387df81d4a51ec258ec2eee2afaab2f`; original NTSC-U v1.01 CORE.GT4. Target range `[002B7310,002B74B0)` is 416 bytes / 104 words. Unmatched source stays outside `src/`.

## Result and blocker

The unchanged Sony ee-gcc 2.96 judge reaches **2 differing instructions out of 104** with the no-strict-aliasing profile. All registers, branches, calls and body length match in the retained best candidate. At `002B7358` / `002B735C`, the original loads the empty Rep selfish flag before forming the one-space literal address; the candidate forms the address first. This is not `MATCH`. No complete resolved-body acceptance or new-source full linked build is claimed. No TextFace runtime integration was made.

Ten novel hypotheses were judged in this pass, plus a CRLF transport compile failure and one rerun after creating the missing private build/auto directory. [Canonical hypotheses](attempts.jsonl) and [judge events](judge-events.jsonl) distinguish events; the [best candidate](best.cpp) is the first two-difference form, not a rewritten guess. Every distinct judged source is retained in `candidates/`; SHA-256 digests and original paths are in the parent manifest. Earlier s1 best12 source was not found. Prior raw evidence and compiler RTL remain ignored in `build/localized-text-evidence/` and on the isolated Linux snapshot; do not commit game bytes, raw disassembly or object files.

## Recovered behavior and host integration implications

Direct original-executable inspection establishes the opaque `008386A8` lock, localized text member `+0xC`, and the one-space literal at `0069C118`. A nonzero input Rep length causes a trailing NUL write, strlen and basic_string assignment through `005C2630`. Zero length constructs a temporary string containing exactly one space, copy-assigns it to the text member and destroys it. Unlock follows both paths. The key member is unchanged. This setter does not perform translation lookup.

Reuse the complete accepted body once matched. Both viewer reader and localized copy must call a shared staged adapter; never retain reader-local or getter-temporary storage. Preserve destination-owned strings, arena cleanup, lock identity and existing serialized invocation boundaries. Meaningful coverage should observe literal text, empty-to-space normalization, prototype independence, repeated replacement and clone survival after source release. The current public TextFace snapshot exposes key but not text.

## Checks rerun

Viewer `feat/menu-text-literal-source` at `24fdd459f33b1f79da139a133aa54f48b45fd760`: strict `/std:c++17 /EHs /W4 /WX /O1` proof passed with `MENU_VM_PROOF_OK`. Layout property probes exited 1 at the same gates: arcade accepted TopRoot, MethodRoot, PregridRoot (3/17); boot accepted LoadRoot, MovieRoot (2/6). OptionPopup and LanguageRoot stop at the explicit missing `002B7310` integration. Separate remaining class gates include FrameImageFace, Button, ToolTipFace, FlashFace, CarFace and ColorChipFace. No render, manager registration or script/runtime acceptance is implied.

Ignored viewer logs: `local-data/menu/localized-text-build.log`, `localized-text-arcade.log`, `localized-text-boot.log`.

## Resume

Read the diary and candidates before a newly authorized bounded pass. Inspect the retained RTL scheduling block for the constructor; avoid repeating constructor body/member initialization, default-then-assign, const literal, strict-aliasing/default, Rep member grab, nsa-nosib, or unsigned/bool Rep type variants. Default-then-assign was 48/104, not an improvement. Do not force assembly or alter judge/compiler flags. Acceptance still requires `swarm.py try` MATCH, complete relocated-body/padding proof, original full-build text/data hashes and explicit `functions["002b7310"] == "linked"`.


## Second bounded pass — 2026-10-15

User explicitly authorized another ten-hypothesis pass. **No improvement: best remains 2/104; no MATCH or TextFace integration.** New checks covered constructor-to-assignment inline nesting, nogcse profile, a real member-function target, explicit temporary/literal locals, clone throw() context, early-return grab with explicit ref count, a selfish read written before literal preparation, a volatile selfish-field diagnostic, value-return target diagnostic and the same literal address expressed from its known pool base. Nogcse regressed to 105/108; all other checks retained the same adjacent mismatch. Rejected volatile/value-return forms are retained as failed diagnostics, not accepted source proposals.

The original first-pass `best.cpp` remains primary. Distinct judged drafts and judge event metadata were merged into this checkpoint; all new hypothesis records were appended to the canonical diary. No judge, compiler profile definition, runtime source or game input was modified. Full linked-image validation remains contingent on MATCH and was not claimed for an unmatched candidate.


Second-pass validation: strict viewer build passed again with `MENU_VM_PROOF_OK`; both original layout probes exited 1. Arcade accepted TopRoot, MethodRoot and PregridRoot (3/17); Boot accepted LoadRoot and MovieRoot (2/6). OptionPopup and LanguageRoot still stop at the explicit `002B7310` integration gate. Ignored current logs are `local-data/menu/localized-text-pass2-{build,arcade,boot}.log` in the viewer. This pass did not expose a later blocker on those pages.


## Third bounded pass - 2026-10-15

Ten further novel hypotheses failed; best remains 2/104. See [third-pass evidence](PASS3.md) for all hypotheses, scheduler versus delay-slot findings, retained source hashes and the remaining missing evidence. Eleven judge events include one corrected source-preparation compile failure. No MATCH, source promotion, viewer integration or new full-image validation occurred. Unchanged viewer suites were not rerun.


## Matched sibling and header investigation - 2026-10-15

Verified partial siblings 0021FC78, 00212DD0 and 002DA400 and compared their compiler dumps. The closest copy-assignment sibling takes runtime text; the literal siblings have different pre-branch pointer preparation. Inspected upstream basic_string headers at the documented 2000-10-03 date. See [research findings](../../../docs/research/localized-text-constructor-siblings.md). No new target hypothesis was judged; best remains 2/104 and the exact Sony/game header context remains unverified.

2026-10-15: [Three-try recovery](three-try-2026-10-15/README.md): Lock guard, conditional-expression cleanup and default-length constructor all regress. Keep prior 2/104 candidate; original scheduling context remains missing.
