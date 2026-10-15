# Three-try recovery of the stalled branch

Date: 2026-10-15. Branch: `feat/stalled-functions`.

All 18 unresolved targets listed at the start of this pass were investigated. Each received three `swarm.py try` calls, except `00447DD0`, which matched on its first call. There were 52 calls: one source-name rejection, one compiler failure, 49 compiled mismatches and one compiled match. Calls that fail before a comparison still count against the repository attempt budget. Thus the byte getter had two compiled hypotheses, and the binary search had two compiled comparisons after correcting its function name. No function exceeded three calls in this pass or the ten-failure ceiling.

## Result

`00447DD0` fixes a real return-value error in the retained draft: when the upper 32 bits of the identifier are zero, return the original identifier, not the extracted upper half (zero). The original copies the identifier to the return register before the branch and skips the later result-copy instruction on that path. Keeping the established `ee-gcc2.96-nsa-nosib` context then gives judge MATCH, 17 compared instructions.

Full-span validation: 68 emitted bytes, all three relocations resolved and exact, plus four original zero-padding bytes, covering the full 72-byte inventory span. Full-image validation passed; see the evidence below.

The other 17 targets remain unmatched. Packed-control member ownership improves the retained current candidate from 140/313 to 136/313 raw differing rows, but this is far from acceptance. The tokenizer's member chain changes 638/716 to 635/716 while remaining 60 words short. Neither raw-score change establishes a better complete reconstruction. Existing unmatched primary candidates remain unchanged.

## Per-target attempts

Numbers below are differing rows / compared rows from the unchanged judge, not normalized distances or authoritative function lengths. In particular, the judge can print equal original/mine counts after choosing a candidate-sized window. Shortened bodies and candidates extending beyond the target are rejected as matches regardless of their row scores.

| Address | Role | H1 | H2 | H3 | Result |
| --- | --- | --- | --- | --- | --- |
| [00148B60](../../research/stalled-functions/00148b60/three-try-2026-10-15/README.md) | Engine curve data | 241/336 | 35/340 | 32/340 | Unmatched |
| [00449190](../../research/stalled-functions/00449190/three-try-2026-10-15/README.md) | DatabaseTable searchNumber | source-name rejection | 27/33 | 25/31 | Unmatched |
| [00449F80](../../research/stalled-functions/00449f80/three-try-2026-10-15/README.md) | Byte getter | 2/5 | 3/6 | compiler failure | Unmatched |
| [004490F8](../../research/stalled-functions/004490f8/three-try-2026-10-15/README.md) | Table initialization | 27/28 | 27/28 | 20/26 | Unmatched |
| [004478F8](../../research/stalled-functions/004478f8/three-try-2026-10-15/README.md) | Tuner-code extraction | 34/40 | 37/47 | 32/42 | Unmatched |
| [00448B48](../../research/stalled-functions/00448b48/three-try-2026-10-15/README.md) | Specification copy | 9/51 | 26/50 | 9/51 | Unmatched |
| [0043BBC0](../../research/stalled-functions/0043bbc0/three-try-2026-10-15/README.md) | Packed controls / selector update | 207/353 | 136/313 | 136/313 | Unmatched |
| [00449AF8](../../research/stalled-functions/00449af8/three-try-2026-10-15/README.md) | Table lookup helper | 35/35 | 25/27 | 30/35 | Unmatched |
| [00443518](../../research/stalled-functions/00443518/three-try-2026-10-15/README.md) | Language-table loading | 59/148 | 69/148 | 59/148 | Unmatched |
| [00445B88](../../research/stalled-functions/00445b88/three-try-2026-10-15/README.md) | Specification comparison | 111/128 | 111/128 | 111/128 | Unmatched |
| [00447DD0](../../research/stalled-functions/00447dd0/three-try-2026-10-15/README.md) | DisabledInfo searchInfo / identifier conversion | MATCH | — | — | Match; validation below |
| [00440FB8](../../research/stalled-functions/00440fb8/three-try-2026-10-15/README.md) | Randomization bounds helper | 33/92 | 33/92 | 33/92 | Unmatched |
| [00207590](../../research/stalled-functions/00207590/three-try-2026-10-15/README.md) | Composite property reader | 196/207 | 20/209 | 16/209 | Unmatched |
| [00233E38](../../research/stalled-functions/00233e38/three-try-2026-10-15/README.md) | RootWindow property reader | 110/469 | 459/485 | 459/485 | Unmatched |
| [002A29F0](../../research/stalled-functions/002a29f0/three-try-2026-10-15/README.md) | ImageFace property reader | 629/639 | 629/639 | 612/619 | Unmatched |
| [002A38A0](../../research/stalled-functions/002a38a0/three-try-2026-10-15/README.md) | ImageFace pattern coordinates | 43/70 | 40/74 | 51/79 | Unmatched |
| [0020EEB8](../../research/stalled-functions/0020eeb8/three-try-2026-10-15/README.md) | Layout tokenizer | 817/828 | 635/716 | 686/718 | Unmatched |
| [002B7310](../../research/stalled-functions/002b7310/three-try-2026-10-15/README.md) | Localized literal text setter | 106/107 | 103/108 | 107/112 | Unmatched |

## What the experiments established

- The identifier conversion was blocked by logic, not register allocation. It is the only source eligible for promotion in this pass.
- ImageFace's raw independent locals were being passed as though they formed contiguous vector and callback objects. Actual aggregates make their fields observable, but do not recover the original stack frame or full body. These candidates remain research, not safe replacement implementations.
- RootWindow's POD callback factories produce real extra copies and a larger frame. Scoped string construction alone does not recover the missing lifetime/layout behavior. Artificial padding was not used.
- The composite reader remains one word short in the best retained shape; the native-width return experiment removes more than the unwanted copy.
- `002B7310`'s three surrounding-context experiments all regress: LockGuard materializes a mutex slot, conditional-expression cleanup adds a live destruction flag, and a default-length constructor changes the body and register allocation. The prior 2/104 source and header-chain evidence remain the best starting point. No further constructor statement permutations are justified by this pass.

## Preservation and reproducibility

Every hypothesis is logged in canonical `knowledge/attempts.jsonl`. Each target's `three-try-2026-10-15/` directory contains the tested source copies, pass diary and available reduced judge events. The per-target README gives each change and outcome; the root manifest records SHA-256 hashes, original local paths and remote scratch paths. The 52 source copies were verified byte-for-byte against hashes of the uploaded files. The manifest also records LF-normalized SHA-256 digests because Git may convert line endings on checkout. The rejected source-name call has no automatic judge event; its diary preserves the error. The accepted source has a separate automatic match event.

Remote workspace: `/home/dev/gt4-localized-text-matching`; remote scratch: `build/swarm/stalled-three/`; local ignored evidence: `build/stalled-three-evidence/`. Judge invocation: `python tools/swarm.py try ADDR build/swarm/stalled-three/ADDR-hN.cpp --worker stalled-three` (H1 of `00448B48` uses `.c`). No brute-force sweeps, inline assembly, judge edits, compiler-profile edits, symbol-map edits or unmatched source promotions were used. Native64, volatile and compiler-failure experiments are retained as failed hypotheses, not endorsed implementations.

The full build runs in the private Linux snapshot with `python tools/build.py --keep-going --jobs 2`, with no concurrent build and over 4 GB available RAM. Raw binary data, disassembly, compiler dumps, caches and full build outputs remain ignored. No viewer/host integration or push is part of this request.

## Final acceptance evidence

Accepted source: [src/func_00447DD0.cpp](../../src/func_00447DD0.cpp). [Validation metadata](../../research/stalled-functions/00447dd0/three-try-2026-10-15/validation.json) records the source SHA-256, full span comparison, full-build summary and build-input parity.

The nonpartial build completed at `2026-10-15T16:19:19Z`:

- `.text` matches original SHA-1 `28422e7e20a6298224294255355487b9a22cef31`.
- `.data` matches original SHA-1 `c28c833f9716467545bf362f321e9acc876c3603`.
- `functions["00447dd0"] == "linked"`; 68 source bytes, within the 72-byte inventory span.
- No orphan or duplicate source registrations; 28,435 source functions considered, 27,721 linked.
- 29,123 build-input files, including the new accepted source, match the Linux snapshot after CRLF-to-LF normalization; no extra remote source files.

The build snapshot has no Git commit metadata, so this proof is tied to the explicitly verified input parity and source digest rather than a claimed remote commit. Other pre-existing source exclusions remain in the full report; the full image uses original fallback bytes for those, while the newly recovered target is explicitly linked from source. Local source registration was also checked for duplicates and orphans before adding the sole new target source.

`git diff --check` reports inherited trailing whitespace/extra EOF blank lines in exact tested source copies (including the accepted source's extra EOF blank line). These were preserved to keep the tested inputs and their hashes unchanged; documentation and metadata have no whitespace findings.
