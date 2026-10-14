# Deterministic matching-tool improvements

## 1. Identity and readiness

- **Plan ID:** GT4-DET-001. **Format:** 1. **Revision:** 2. **Updated:** 2026-10-09.
- **State:** complete. T001–T005 implemented and validated; synchronization/commit recorded in the implementation handoff.
- **Authorization:** the user requested implementation after merging the function batch into `dev`, preserving its branch and creating a new tooling branch. Both checkouts followed that order. Prior commit authorization remains applicable. No push or PR is authorized. The user subsequently made `feat/` the global branch prefix.
- **Workspace:** Windows `F:\_projects\gt4-decomp` (PowerShell); execution environment `/home/dev/gt4-decomp` (Linux shell). `ROOT` below means the relevant repository root, not an environment variable.
- **Runtime:** use the container's `~/.local/share/gt4/venv`. `project.toml` selects Sony ee-gcc `2.96-ee-001003-1`; record the actual Python/compiler versions in T001. No dependency upgrade is required.
- **Baseline:** `dev` fast-forwarded to `e4a78642f474453900f725bf0df5d11bd13aa248`; the function branch was preserved and renamed `feat/car-geometry-matches`. Implementation runs on `feat/deterministic-matching-tools`, created directly from updated `dev`. Ancestry from `cc47baf51d274bf6f6eb314c979488ca793fdd0f` and all accepted sources are preserved.
- **Next action:** use `docs/deterministic-matching-tools.md` for the actual entrypoints. Another source-recovery batch can evaluate the draft at `00349F48`; it was not promoted by this tooling work.

## 2. Outcome, requirements and exclusions

The outcome is a repeatable CPU-only pipeline that handles familiar patterns before an agent is asked to reason about a function. Measure its benefit using saved attempts and a fresh candidate sample; do not promise an unmeasured percentage reduction.

| ID | Requirement | Acceptance |
| --- | --- | --- |
| R001 | Extend the existing solver to try C/C++ and eligible ignored-callee-return variants in a fixed, bounded order. Preserve legacy result consumers and previously accepted sources. | A001, A002 |
| R002 | Recognize and generate source for the supported small virtual-forwarding patterns, without address-specific exceptions. Unsupported patterns must be declined explicitly. | A003 |
| R003 | Reuse existing correction tools and add/select only evidence-backed rules: void tail returns, independent store ordering and explicit clamp form. | A002, A004 |
| R004 | Centralize strict candidate acceptance: source policy, actual MATCH, resolved-address checks, correct language extension and canonical destination; never overwrite an existing source. | A001, A003, A005 |
| R005 | Provide reusable batch verification and a safe source/checkpoint package. Require both full-build segment identity and direct linkage of every selected address. | A005, A007 |
| R006 | Runs are resumable and reproducible for fixed inputs; record rule provenance, attempts, timings, skipped cases and failures. Use no model calls. | A002, A006 |
| R007 | Preserve game inputs, existing matches and Git ancestry. Foreground only; at most two jobs total; maintain more than 4 GB free RAM. | A006, A007 |

Selected decisions: default to C first, then C++, to preserve the existing solver's successful choice where possible. Put generated drafts, real replay inputs and outputs under ignored `build/auto/deterministic/`. Add only small synthetic behavioral tests to tracked files.

Excluded: general-purpose decompiler replacement, large-function automation, unrestricted permutation, speculative global type-database updates, changing the judge or compiler flags, automatic commits/pushes/PRs, background services and automatic SSH operations. Do not access `F:\_projects\SOCOM-OpenSource`. Fresh candidates are judged in draft mode for evaluation; accepting another source batch is separate work.

## 3. Verified context and inputs

Read these existing files at the baseline before changes:

- `tools/cpu_solve.py`: `variants`, `prepared`, `attempt`, `differs_by`, CLI and JSONL resumption. Currently produces `.c` drafts and flat `.c` accepted paths. The default is three jobs; the implementation must use a default of two for this workflow. `differs_by` currently relies partly on process success; strict acceptance must also require explicit MATCH and reject unchecked-reference notes.
- `tools/fragments.py`: `mut_callee_ret`, `mut_tailcall`, `mut_reorder` and related source transformations. Reuse applicable generators; do not duplicate the full mutation engine. Its textual dependency check alone does not prove two pointer stores cannot alias.
- `tools/near_fix.py`: existing literal-address and commutative-operand corrections. `tools/families.py`, `tools/siblings.py` and `tools/accessors.py` already handle related families; inspect their decoding/generation helpers before adding another recognizer.
- `tools/match.py`: existing `check`, instruction decoding/text access and relocation judge. A successful check can emit a note that references could not be checked; acceptance must distinguish that from a fully address-checked match.
- `tools/asm_policy.py`, `tools/layout.py` (`path_for`), `tools/project.py` (`source_for`, `sources`, compiler configuration): authoritative source policy, destinations, source discovery and compiler selection.
- `tools/agent_step.py`: currently writes a flat `.cpp` path on acceptance. Integrate the shared strict promotion path here as well as in the extended CPU solver; retain its user-visible MATCH/failure behavior.
- `tools/build.py`: full build report fields `text_matches`, `data_matches`, `functions`, `sizes`. With `--keep-going`, exit status alone does not prove hashes match. Parse the report and compare actual segment bytes.
- `knowledge/race-interface-matches.md` and `knowledge/car-geometry-interface-matches.md`: accepted scope, provisional type limits and unresolved cases.

Ignored evidence already produced in both checkouts:

- `build/auto/geometry-wrappers/verified-results.json`: 103 exact matched sources, addresses, source hashes and instruction counts.
- `race_cpp.py` and `race-small/cpp-results.json`: seven matches from trying saved C drafts as C++.
- `race_calls.py` and `race-small/call-results.json`: two matches from changing eligible ignored-result callee declarations.
- `race_forwarders.py`, forwarding inventories/results, `recover.py` and `finish.py`: pattern reconstruction evidence. These scripts have batch-specific assumptions and must not simply be copied into production.
- `manual_retry.py`, related judge logs and `easy_more.py`: store ordering, clamp and call-shape successes/failures.
- `verify_all.py`, `check_build.py`, `package_verified.py`: working prototypes for verification and transfer packaging. Remove hard-coded batch sizes/base revisions in the reusable tools.

Real inputs remain local: the configured executable is `orig/SCUS-97328/files/CORE.GT4`; analysis inventories are in `build/`. Access instructions are in `docs/workspace-access.md`. Use the existing Windows OpenSSH executables if PATH wrappers are blocked; activate the container environment before Python commands. Do not copy game contents into tracked fixtures or documents.

Observed baseline: all 103 judges and policy checks passed; all 103 linked directly; rebuilt `.text` and `.data` matched the original; both checkouts had identical source hashes and the same clean Git revision. This planning turn inspected source/configuration and Git status, but did not rerun judges or the build. Every new acceptance check below is **planned, not run**.

## 4. Design and boundaries

**D001 — Extend the existing tools.** Keep m2c, compiler selection, near-fix and fragment logic as the established engines. Add small shared candidate/acceptance helpers and bounded orchestration, not a new solver framework.

**D002 — Separate generation from promotion.** The ordered flow is: select address -> produce candidate -> judge candidate -> record attempt -> optionally promote a fully verified candidate -> independently verify selected sources and full linkage -> package proof. Replay and fresh evaluation use no-promotion mode.

Proposed new paths and interfaces (none exist yet):

- `tools/matching_candidates.py`: immutable candidate record containing address (integer), source text, `.c`/`.cpp` extension, ordered rule IDs and source hash. Shared judge-result parser and promotion helper. Return explicit states `match`, `differs`, `compile-error`, `rejected`, `unchecked-reference`, `unsupported`, `timeout`; a difference score is diagnostic only. Policy failure, missing MATCH or unchecked references forbids promotion. Preserve compiler markers as the first line when wrapping C++ declarations in `extern "C"`. Detect existing source at either extension; report a conflict/skip rather than replacing it. Judge the canonical file again after promotion; remove only the newly created file if that verification fails.
- `tools/virtual_forwarders.py`: explicit-address input or a stable, size-bounded inventory; default draft-only, optional explicit apply mode. Consume decoded instruction words, including delay slots, rather than matching printed text alone. Extract supported object acquisition, virtual-table/entry offsets, signed 16-bit adjustment and argument forwarding. Emit a bounded set of void/integer/float return candidates only where compatible with the observed data flow; do not infer return type from the `jalr` target register. Initially support direct objects, implementation-pointer objects and the observed global-root indirection, with 0–2 forwarded arguments. Reject unfamiliar calls, control flow, memory writes or side effects. The repeated-query CarGeometry slots 24–26 are excluded from this first recognizer.
- `tools/matching_replay.py`: read a versioned manifest, replay generated candidates without source writes, compare to baseline and write metrics. Known-good accepted source may be used as the oracle, never as the solver's candidate input.
- `tools/verify_batch.py`: proposed CLI inputs `--base REF` or an explicit address manifest, plus `--build` and `--package PATH`. Verify selected added/modified sources; reject ambiguous address/path mappings. With `--build`, run exactly one foreground `tools/build.py --keep-going --jobs 2` after checking for an active build and sufficient RAM. In verification-only mode, compare recorded source/configuration hashes and revision fingerprints to the proof; reject stale proof rather than trusting an old report. Recompute original/rebuilt segment equality and assert status exactly `linked` for each selected address. A package contains only enumerated accepted sources, documentation and safe checkpoints; reject paths outside ROOT, symlinks, `..`, `.git`, `orig`, assembly/dump files and generated binary artifacts.

Use one attempt directory per address and variant hash. A single coordinator writes deterministic result order and performs promotion; workers only generate/judge drafts. No worker may overwrite another's files. The two-job budget applies across the whole pipeline, not separately to each stage. On interruption, stop dispatching new jobs, let current foreground work settle and atomically record completed attempts. No build overlaps solver work.

Replay manifest proposal: `schema_version: 1`, baseline revision, rule version and ordered cases. Each case records address as eight uppercase hex digits, relative draft path, extension, draft SHA-256, family label and expected known-match source/hash where available. Attempt output records rule IDs, candidate hash, language, judge state, differing/total instructions where available, elapsed milliseconds and log path. Real drafts and logs stay ignored. Cache identity must include candidate, executable, compiler/configuration and rule fingerprints; otherwise rejudge. Deduplicate identical candidates and cap new variants at 16 per input draft initially. Changing this limit requires recording the runtime evidence.

**D003 — Bounded transformations.** Try original C, equivalent C++ wrapper, then eligible ignored-callee-return edits in both languages. Try known tail-return, store-order and clamp transformations only when their syntactic/data-flow preconditions hold. Preserve calls and their order. Never reorder volatile accesses, calls, reads feeding stores or stores through possibly aliasing bases. Initially allow store reordering only for distinct non-overlapping constant-offset fields of the same proven base. Treat prototype variants as local candidate hypotheses, not recovered global API facts.

**D004 — Measure before expansion.** Replaying this batch measures regression coverage. A stable sample of 50 fresh unmatched race functions of at most 64 trimmed instruction bytes measures generalization. Report baseline versus improved matches, total compiler calls, elapsed time and unresolved cases; no invented time-savings estimate.

## 5. Unknowns and discovery gates

| ID | Question and bounded discovery | Gate / outcome |
| --- | --- | --- |
| U001 | Are the seven frontend and two prototype successes backed by intact pre-success drafts? T001 inventories and hashes every referenced draft, using case/result records to distinguish pre-edit input from accepted output. | T002/T005 require genuine input. Missing cases are regenerated once using baseline m2c and recorded as regenerated; if reproduction fails, report it and revise the replay target instead of substituting the accepted source. |
| U002 | Which existing decoder and fragment interfaces can be reused without their promotion side effects? T001 reads those entrypoints and records a concrete call map. | T003/T004 use pure helpers or extract a small helper; do not invoke broad apply commands during replay. |
| U003 | Do all initial 32 wrappers fit the planned supported patterns? T001 classifies their instruction/data-flow shapes, including delay slots and return/argument variants. | Implement recognized families only. If a case needs a new family, document the bounded extension or report it unsupported; no address exceptions. |
| U004 | Which useful store/clamp fixes add coverage beyond current fragments/near-fix? T001 replays existing rules on the identified cases first. | T004 adds only missing coverage or bounded routing. If existing rules work, retain them and improve orchestration rather than cloning them. |

T001 writes one discovery report and either closes each gate or specifies the exact missing input and affected task. Stop after inventory, one baseline regeneration per missing case and one existing-rule comparison pass; do not turn discovery into an open-ended search.

## 6. Acceptance and validation

All A001–A007 checks passed on 2026-10-09. Evidence is under ignored `build/auto/deterministic/`. The procedures below describe the checks; observed results and limitations are recorded in section 9 and `docs/deterministic-matching-tools.md`.

- **A001 — Strict acceptance and compatibility (R001/R004).** Proposed synthetic test target `tests/test_matching_tools.py`, created by T002, run from ROOT with `python -m unittest discover -s tests -p 'test_matching_tools.py'`. Exercise C++ linkage/marker placement, old JSONL consumer fields, real judge-output parsing, unchecked-reference notes, nonzero exits, policy rejection and existing-path conflicts. A zero-exit message without MATCH must not be accepted. Tests use hand-authored synthetic inputs, not game dumps.
- **A002 — Recovered frontend/prototype wins (R001/R003/R006).** From activated Linux ROOT, invoke the replay entrypoint implemented by T001/T002 with its recorded manifest and no-promotion mode (exact CLI documented when created). Recover the seven known frontend wins and the two prototype wins from pre-success drafts. Preserve successful baseline candidates. Report reproducible failures honestly; do not change inputs to the answer or omit failed cases.
- **A003 — Wrapper generation and refusal (R002/R004).** Replay all 32 original wrappers through the generic recognizer/generator and unchanged exact judge. Goal: all supported initial shapes MATCH, canonical destinations correct, no existing source changed. Include synthetic negative shapes (extra store, unrecognized call/control flow, malformed entry, altered adjustment width) and confirm unsupported/rejected outcomes. Resolve U003 before making the coverage target final.
- **A004 — Targeted corrections (R003).** Replay saved pre-fix inputs for `0038FEB0` (void tail return), `003BC5A8`/`00390478` (stores) and `004386C8` (clamp). Require exact matches where the input is reproducible. Synthetic alias/volatile/call cases must yield no store-reorder candidate. Confirm the budget/deduplication limits with real generated candidates.
- **A005 — Batch proof and packaging (R004/R005).** Select the 103-address manifest or diff against `cc47baf51d274bf6f6eb314c979488ca793fdd0f`. Independently judge all sources and verify recorded hashes. Exercise a temporary synthetic report with an unlinked address, hash mismatch, missing function and stale source fingerprint; each must fail. Inspect package members and reject traversal/out-of-root/disallowed inputs. Do not modify the real build report for failure testing.
- **A006 — Reproducibility/resumption and fresh sample (R006/R007).** Run the fixed 50-candidate fresh sample in draft-only mode with baseline and improved tools. Record compiler calls/time/matches; rerun and compare normalized outputs excluding timings. Interrupt and resume a subset; completed candidates must not be lost or treated as unverified matches. Confirm no source writes, no model calls and job count <=2. If fresh gain is zero or runtime materially worsens, state that result and restrict defaults to the rules with demonstrated benefit.
- **A007 — Final preservation and full build (R005/R007).** After tools/tests are final, check Git diff/status and ancestry; all 103 source hashes must remain unchanged. In activated Linux ROOT run `python tools/build.py --keep-going --jobs 2` once, with no other build/solver and >4 GB free RAM. Then use the new batch verifier on that current build. All 103 must be `linked`; original/rebuilt SHA-1 must equal `.text` `28422e7e20a6298224294255355487b9a22cef31` and `.data` `c28c833f9716467545bf362f321e9acc876c3603`. Run `git diff --check`. Sync tools, documentation and safe evidence to Windows/container; do not transfer or commit game inputs/dumps/binaries. Tool changes alone do not justify counting any additional recovered function.

## 7. Ordered tasks

### T001 — Establish the replay corpus and reusable interfaces

- **Status:** done. **Depends on:** none; resolves U001–U004.
- **Inputs/read:** project rules, baseline tools and ignored evidence listed in section 3.
- **Changes/write:** proposed `tools/matching_replay.py` with baseline/no-promotion support; ignored manifest and discovery report in `build/auto/deterministic/`; update this plan with resolved gates.
- **Actions:** check runtime versions/revision/access; inventory pre-success drafts; freeze the seven frontend, two prototype, 32 wrapper and four-address correction cases; record existing-rule behavior and decoder/helper call map. Select the first 50 eligible unmatched race addresses in sorted order, excluding assembly-only and other-compiler functions, without accepting sources. Ensure baseline replay bypasses the solver's existing-source skip without removing or moving accepted files.
- **Outputs:** hashed replay inputs, fixed fresh sample, baseline measurements and explicit downstream interface choices.
- **Checks:** baseline portion of A002/A004/A006; verify no tracked source changes.
- **Failure/recovery:** follow the bounded discovery limits in section 5; retain evidence and block only tasks needing missing cases.
- **Completion evidence:** 2026-10-09; see section 9 and ignored discovery/replay/integration/verification reports.

### T002 — Extend the CPU solver with strict, bounded candidate handling

- **Status:** done. **Depends on:** T001; U001/U002 resolved for relevant cases.
- **Inputs/read:** `cpu_solve.py`, `agent_step.py`, policy/layout/project helpers, replay inputs and result consumers.
- **Changes/write:** existing `tools/cpu_solve.py`, `tools/agent_step.py`; proposed `tools/matching_candidates.py`, `tests/test_matching_tools.py`; replay integration.
- **Actions:** implement shared strict judge parsing and promotion; preserve legacy result keys; add frontend selection and draft-only/replay entrypoints. Keep compiler markers first and use the winning extension throughout. Add bounded eligible void-callee variants, deterministic candidate deduplication, default two jobs and rule provenance. Make any permitted source promotion canonical and conflict-safe.
- **Outputs:** reusable variant/acceptance contract and automatic frontend/prototype recovery.
- **Checks:** A001/A002; successful baseline C drafts remain available and unchanged.
- **Failure/recovery:** keep failed candidates/logs ignored; never promote on a parser exception; report compiler/context incompatibility rather than stripping declarations indiscriminately.
- **Completion evidence:** 2026-10-09; see section 9 and ignored discovery/replay/integration/verification reports.

### T003 — Generalize virtual-forwarding generation

- **Status:** done. **Depends on:** T001/T002; U003 resolved.
- **Inputs/read:** observed wrapper families, decoder call map, layout and strict candidate API.
- **Changes/write:** proposed `tools/virtual_forwarders.py`; wrapper replay integration and synthetic tests.
- **Actions:** implement complete supported-pattern recognition, extracting offsets/adjustments/arguments from decoded data flow. Account for delay slots. Generate source templates and bounded return variants; use the shared judge and apply gate. Replace batch-specific address exceptions with recognized structure or explicit refusal.
- **Outputs:** deterministic wrapper candidates, per-address recognized/unsupported reasons and measured family coverage.
- **Checks:** A003, relevant A001/A006.
- **Failure/recovery:** unsupported functions stay drafts/unresolved; a near match cannot expand the accepted count. Revise the family boundary from evidence before adding a new template.
- **Completion evidence:** 2026-10-09; see section 9 and ignored discovery/replay/integration/verification reports.

### T004 — Route proven source corrections through existing tools

- **Status:** done. **Depends on:** T001/T002; U004 resolved.
- **Inputs/read:** existing fragment/near-fix transformations and the correction replay cases.
- **Changes/write:** `tools/fragments.py`, `tools/near_fix.py` only where needed; CPU solver/replay routing; synthetic safety tests.
- **Actions:** reuse applicable generators, add the missing void-return tail-call and explicit-clamp cases only if needed, and restrict new store-order candidates to proven independent stores. Apply one rule then bounded combinations in recorded order, preserving call evaluation and the existing nearest-draft result contract. Respect the 16-variant cap.
- **Outputs:** evidence-backed correction stage with explicit preconditions and per-rule results.
- **Checks:** A004/A001/A002; note which wins were already covered by existing tools.
- **Failure/recovery:** reject uncertain alias/evaluation cases; keep unmatched attempts for later agent review instead of widening mutations without evidence.
- **Completion evidence:** 2026-10-09; see section 9 and ignored discovery/replay/integration/verification reports.

### T005 — Deliver batch verification, measured integration and documentation

- **Status:** done. **Depends on:** T002/T003/T004.
- **Inputs/read:** strict candidate contract; existing verification/package prototypes; all replay outcomes and current full-build interface.
- **Changes/write:** proposed `tools/verify_batch.py`, `docs/deterministic-matching-tools.md`; final replay integration/tests; this plan's observed results.
- **Actions:** replace hard-coded batch assumptions with explicit base/manifest selection, current-input fingerprints and strict report checks. Package only allowlisted source/document/checkpoint files. Run the complete replay and fresh comparison, then synthetic refusal/stale-proof tests. Run one final full build and verify all 103 existing matches. Document actual CLIs, rule limits, measured gains/costs and unresolved cases. Keep ignored historical batch scripts as evidence; route future usage to the new tools. Sync the implemented files and safe checkpoint evidence between checkouts without automatically changing branch history.
- **Outputs:** reusable verification/package command, measured baseline/improved report, user documentation and completed handoff.
- **Checks:** A005/A006/A007 and all earlier acceptance results reconciled.
- **Failure/recovery:** block final completion on failed acceptance or stale proof; document zero gains honestly and adjust defaults based on observed benefit. No push/PR.
- **Completion evidence:** 2026-10-09; see section 9 and ignored discovery/replay/integration/verification reports.

## 8. Recovery and scope control

At execution start recheck revision/status and preserve unrelated user work. Do not reset the branch, remove accepted sources or change original inputs to make replay possible. Resume from hashed completed attempt records; partial/unverified records must be retried rather than counted. Write manifests/reports atomically. Remove only the exact failed generated candidate or newly promoted file owned by the current attempt; never recursively clean `src/`, `orig/` or broad build directories.

Source promotion is optional and explicit; normal replay/fresh benchmarking is read-only for `src/`. Packages do not include private keys or game material. Commit decisions remain with the implementation session under the user's applicable authorization; no command in this plan pushes or opens a PR. If a discovery result invalidates a contract, record it, revise this same plan and continue independent tasks. Preserve the unchanged judge as the acceptance oracle.

## 9. Progress and handoff

Implementation complete on `feat/deterministic-matching-tools`. No accepted source changed. No independent agent review was performed; the implementation was checked against real judge/build boundaries and synthetic behavioral tests.

Observed evidence:

- U001–U004 resolved: genuine saved frontend/prototype drafts and three pre-fix correction drafts are available; the tail input was reconstructed from the historical manual script and already matched in the baseline. Decoder ownership is `match.words_at/load_text/trim_padding`, with a narrow symbolic wrapper interpreter. Existing `fragments.mut_callee_ret` is reused; additional guarded rules cover the observed missing source forms.
- A001/A004/A005: 14 synthetic behavioral tests passed, including unchecked references, unknown layouts/alias/volatile/calls, wrapper refusal, canonical rollback, legacy C-near-miss compatibility, build-link/hash/size failures, stale proof and unsafe package members.
- A002: seven frontend and two prototype cases recovered both by saved-input replay and the actual `cpu_solve.attempt(..., apply=False)` integration using regenerated drafts. Three pre-fix store/clamp cases also matched.
- A003: all 32 initial wrappers regenerated and judged MATCH without address-specific exceptions.
- A006: a two-case partial real replay resumed to all 45 cases; completed replay reruns used the cache. A synthetic KeyboardInterrupt test preserved the completed case and retried only the unfinished case. Fresh sample: baseline 0/50 (74 compiler calls, about 9 seconds), improved 1/50 (217 calls, about 26 seconds). The extra match `00349F48` remains a draft. Replay counts are not new accepted sources. Timings exclude initial draft preparation and are not a general speed estimate.
- A007: the final verifier independently checked all 103 existing sources, ran the two-job full build and verified 5,948 directly linked bytes and both original segment hashes. No source promotion occurred. Proof/package paths: `build/auto/deterministic/verification/proof.json` and `build/auto/deterministic/verified-tooling.zip`.
- A preprocessing bug initially rejected unused m2c macro definitions. It was corrected to distinguish definitions from actual unsupported operations, covered by tests, and the fresh comparison was rerun; the rejected run is not used as measured evidence.

The user guide is `docs/deterministic-matching-tools.md`. Future work should use these tools before escalating unfamiliar functions to an agent, measure new samples honestly and preserve the existing exact-match/full-build acceptance standard.
