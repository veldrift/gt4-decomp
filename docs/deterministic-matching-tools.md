# Deterministic matching tools

These tools automate repeated source attempts using the original compiler and judge.
They make no model calls. A generated candidate is not an accepted function: source
policy and a fully checked MATCH are required, followed by batch linkage/hash proof.

The implementation branch is `feat/deterministic-matching-tools`, created after the
103-function batch was merged into `dev`. The function contribution remains on
`feat/car-geometry-matches` for a future PR. Neither branch has been pushed by this work.

## Solver improvements

Activate the container environment and run from `/home/dev/gt4-decomp`:

```sh
source ~/.local/share/gt4/venv/bin/activate
python tools/cpu_solve.py --jobs 2 --limit 50 --max-bytes 64 --draft-only
```

The solver tries C first, then C++ with C linkage, and bounded source variants.
`--frontends c` selects the cheaper C-only path; `--frontends cpp` selects C++.
The default is `both`. The normal command accepts exact matches; `--draft-only`
keeps all candidates outside `src/`. Draft-only result records do not prevent a
later normal run from accepting the function. Existing result fields used by
near-fix/permuter tools remain available, and unsuccessful runs retain the nearest
C draft; a useful C++ draft can be retained separately.

Variants reuse `fragments.py`'s ignored-callee-return transformation. New guarded
rules cover explicit void tail returns, an explicit integer clamp/select, splitting
chained stores and swapping independent stores. Store rules only support simple
flat layouts with known non-overlapping four-byte fields and one base object.
Unknown layouts, possible aliasing, volatile fields, calls and side-effecting
expressions decline. Callee prototype changes remain local source hypotheses.

Each input draft produces at most 16 distinct new candidates. File extension and
source hash deduplicate attempts; ordering is fixed. The CPU solver defaults to
two workers and permits only one or two. Promotion occurs in the coordinator.
Do not overlap it with another solver or a full build.

`tools/matching_candidates.py` supplies the shared acceptance boundary used by the
CPU solver, wrapper generator and `agent_step.py try`. It requires explicit MATCH,
successful judge exit and no unchecked-reference note. Policy failures and
unsupported m2c operations are rejected; unused placeholder macro definitions
are distinguished from actual uses. Compiler markers remain on the first line.
Accepted files use `layout.path_for` and the winning `.c`/`.cpp` extension. Existing
sources are never overwritten. The canonical file is judged again after creation;
failure removes only the file created by that attempt.

This strict automatic route intentionally declines unresolved relocation cases.
Those cases remain available for separate investigation and full-link analysis;
the underlying judge is unchanged.

## Virtual forwarding wrappers

```sh
python tools/virtual_forwarders.py 0038DCD8 0038C8B0
```

This command generates and judges drafts. Add `--apply` to save a fully checked
match at its canonical path. It does not overwrite an existing source.

The recognizer decodes R5900 instruction words and follows object/table/entry
data flow, including call and return delay slots. It supports small direct-object,
implementation-pointer and observed global-root wrappers, signed 16-bit object
adjustments and bounded forwarded arguments. It tries return-shape candidates
rather than deriving a return type from the indirect-call target register.

Additional memory writes, unfamiliar control flow, other calls, incomplete stack
restoration and unknown object origins are refused or left unmatched. There are
no hard-coded function addresses in the recognizer. The larger repeated-query
CarGeometry slots 24–26 are outside this generator's first supported grammar.

## Local replay and comparison

```sh
python tools/matching_replay.py prepare
python tools/matching_replay.py run --suite known --baseline
python tools/matching_replay.py run --suite known
python tools/matching_replay.py run --suite fresh --baseline
python tools/matching_replay.py run --suite fresh
```

Preparation needs the saved local `build/auto/geometry-wrappers/` checkpoints and
the configured game input. It freezes pre-success drafts and a stable 50-address
fresh race sample. Accepted sources are never used as candidate answers and are
never moved or removed to make replay possible. One historical tail-call input
is reconstructed from the original manual script and marked accordingly.

The fresh baseline uses the original m2c draft variants; the improved run adds
frontend/prototype/correction attempts. Both runs exclude initial draft-generation
cost from their comparison timings. Historical wrappers are a separate generator
coverage check, not a measured baseline CPU-solver comparison.

Reports record match/unresolved state, rules, candidate hashes, extension,
instruction differences, judge log, compiler-call counts and milliseconds.
Completed cases are written atomically. Re-running resumes verified inputs without
repeating completed cases. `--limit N` stops after the first N selected cases;
removing it continues the same report. Executable, tools, configuration, compiler
programs and input-manifest hashes invalidate stale replay caches. Modified input
drafts fail their recorded hash check. Interrupting a run preserves completed
cases; incomplete cases are retried.

All real drafts, game-derived evidence and reports stay in ignored
`build/auto/deterministic/`. Tracked tests use hand-authored synthetic data.

## Observed results, 2026-10-09

| Experiment | Baseline | Improved |
| --- | --- | --- |
| 13 saved frontend/prototype/correction drafts | 1 MATCH | 13 MATCH |
| Generic generation of the 32 initial wrappers | Not benchmarked | 32 MATCH |
| 50 fresh unmatched race candidates | 0 MATCH | 1 MATCH |

The reconstructed void-tail-return input already matched in the baseline; it is
a compatibility check and does not count as an additional win. The fresh match
is at `00349F48`, produced by a C++ frontend variant, and remains a draft. No new
function source was accepted during this tooling contribution.

The fresh comparison used 74 judge/compiler calls in roughly 9 seconds for the
baseline and 217 calls in roughly 26 seconds for the improved run. These are local
measurements, not a general speed claim. Automatic attempts cost more CPU time
but remove manual retries for supported patterns. Use `--frontends c` when that
tradeoff is undesirable; unfamiliar functions still need investigation.

The real integrated `cpu_solve.attempt(..., apply=False)` entrypoint also recovered
all seven saved frontend cases and both prototype cases from regenerated m2c
drafts. The 14 synthetic behavioral tests cover strict acceptance, linkage
markers, unsafe stores, wrapper refusals, existing-source protection, failed
canonical promotion cleanup, legacy C-near-miss compatibility, interrupted replay,
stale proof, direct linkage/hash/size failures and unsafe package members.

Run them with:

```sh
python -m unittest discover -s tests -p test_matching_tools.py -v
```

## Full batch verification and packaging

```sh
python tools/verify_batch.py --base cc47baf51d274bf6f6eb314c979488ca793fdd0f --build
```

Alternatively select the existing 103-function manifest and produce a sync package:

```sh
python tools/verify_batch.py --manifest build/auto/geometry-wrappers/verified-results.json --build --package build/auto/deterministic/verified-tooling.zip
```

The verifier independently judges each selected canonical source, rejects duplicate
or ambiguous selection, and checks source policy. It requires more than 4 GB
available RAM and refuses to start a build while another supported build/solver
process is active. It runs one foreground build with two jobs. `--keep-going` exit
success is insufficient: the report must have both match flags, every selected
address must be exactly `linked`, and linked byte sizes must agree with the judge.
Original and rebuilt code/data bytes are compared directly and hashed.

Proofs record source hashes, all relevant source/tool/configuration/compiler/game
input fingerprints, report hash, segment hashes and revision. Without `--build`,
the command requires a current proof and independently rechecks the current report
and segment bytes. Any input mismatch requires a fresh build.

The package allowlists accepted sources, Markdown documentation and safe local
checkpoints. It rejects traversal, out-of-root paths, symlinks, game inputs,
assembly dumps and generated binaries. Its destination must be an ignored
`build/auto/*.zip`. Packaging is local; transfer to the other checkout is explicit.
It never stages files, commits, pushes or opens a PR.

The implementation/handoff record is
[the execution plan](plans/deterministic-matching-tools.md).
