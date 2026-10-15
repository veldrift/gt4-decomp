# Third bounded pass: 002B7310

2026-10-15. **No MATCH. Ten failed novel hypotheses; best remains 2/104.** The pass also logged one source-preparation compile failure: the base-class declaration replacement missed LF line endings. It was corrected before judging that hypothesis. Eleven judge events therefore represent ten valid source experiments plus one preparation failure. All eleven sources are retained under `candidates/pass3/`, with SHA-256 hashes in the parent manifest. `h04.cpp` is the failed preparation; `h04-fixed.cpp` is the valid experiment. First-pass `best.cpp` is unchanged.

The pass began from clean matching `b56a49441` and viewer `5257db2`. The private Linux snapshot was owned by `dev`, no compiler/full-build process was running, and available memory exceeded 9 GB. Work used the provisioned venv, documented SSH executable, unchanged judge and original no-strict-aliasing profile. No full build, emulator, push or viewer edit occurred.

| Hypothesis | Result |
| --- | --- |
| H1: Actual one-space string literal instead of external symbol | 2/104; constant-pool classification did not change the schedule |
| H2: Grab accepts data pointer and recovers Rep | 90/106; extra address arithmetic and padding |
| H3: Constructor accepts const pointer reference | 89/106; addressable argument adds stack store/reload |
| H4: Base class owns pointer and empty-Rep construction | 12/104; literal changes register and fills branch slot; saved temporary pointer disappears |
| H5: Base constructor also performs literal assignment | 2/104; restoring saved temporary pointer restores baseline residual |
| H6: Unnamed assignment temporary | 3/104; original residual plus reversed equality operands |
| H7: BasicString<char> template instantiation | 2/104 |
| H8: Conditional/comma return expression in grab | 2/104 |
| H9: Inline literal constructor throw() specification | 2/104 |
| H10: Separate inline initialization helper | 2/104 |

## Compiler evidence and limits

The retained baseline's `.17.sched` and `.25.sched2` agree: in constructor block 1, the Rep and literal high halves issue at clock 0, both low halves at clock 1, and the selfish load plus temporary-address move at clock 2. The branch follows at clock 4. Delay-slot processing moves the temporary-address instruction into the branch slot; the literal low half stays before the selfish load. This ordering is already present before register allocation, not an assembly transport problem.

H4 initially appears to fix load order in the emitted body, but its `.25.sched2` still pairs the two low halves at clock 1. The later delay-slot pass moves the literal low half past the load into the branch slot, because the saved temporary-address instruction is absent. The output also changes the literal register, temporary store, assignment arguments and padding. H5 restores that saved pointer and returns to 2/104. Observing a load before the literal in a regressed candidate is therefore not evidence of the correct scheduler solution.

This identifies the decisions producing the candidate residual, but **does not establish the original source-level cause**. Missing evidence: the original constructor/header translation-unit context or a genuine matched sibling reproducing both the saved temporary pointer and desired instruction order. Original compiler RTL is unavailable. Do not repeat the listed transformations, force assembly, alter scheduling flags or accept H4's isolated load order as a match.

## Preserved evidence and validation

Remote scratch: `/home/dev/gt4-localized-text-matching/build/swarm/localized-text-pass3/`, including judge logs and `rtl-h01/`, `rtl-h04/`. Local ignored mirror: `build/localized-text-pass3-evidence/remote-scratch/`; baseline RTL remains in the earlier remote scratch. Raw compiler dumps, object files and disassembly stay ignored.

Checks actually run: eleven unchanged judge invocations (ten valid hypotheses, one preparation failure), two diagnostic RTL compilations, diary/event reconciliation and SHA-256 verification of every retained target candidate. No unchanged expensive viewer suites were rerun. Previous viewer proof and layout results in README.md remain historical baseline evidence, not new validation. No TextFace integration occurred, and no later layout gate was reached. Full-body/relocation/padding and linked-image acceptance remain pending a genuine MATCH.
