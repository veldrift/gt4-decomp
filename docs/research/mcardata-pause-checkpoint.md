# MCarData pause checkpoint and follow-on candidates

Recorded 2026-10-09. Work paused at the user's request after read-only investigation of additional reconstruction targets. No new function implementations were made during this investigation.

**Publication checkpoint:** the 27 accepted additions were committed as `c792b68b` on `feat/mcardata-matches` and pushed to https://github.com/veldrift/gt4-decomp. All 27 passed a fresh judge check and source policy check. The final full build reproduces code and data, with all 27 directly linked. Project notes and the six earlier unrelated sources are tracked separately on `dev`. No PR has been opened. Statements about uncommitted work below refer to earlier checkpoints.

**Resumed later on 2026-10-09:** the user authorized all nine helper candidates and the six unfinished methods. Both checkouts were fast-forwarded to upstream `f0b3e403` (library matches and block-copy tooling), with no overlap with the CarData additions. Four new helper reconstructions now pass the individual judge: `001305A0`, `00447CA0`, `00448AD0`, and `004443A8`. The statements below describe the earlier pause unless updated explicitly. The expanded scope is 32 additional targets (23 methods plus nine helpers), alongside the original two-method pair.

**Latest recovery checkpoint:** GetCarLogoName also passes the judge, bringing the original expanded methods to 18/23. Seven helpers now pass: the four above plus `00130618`, `00447F48`, and `001307E8`. This is 25/32 additional targets, or 27 new sources including the original pair. IsExist, ShiftCarCode, GetDirtCarCode, GetSnowCarCode, PickUpEnemyCars, `00130690`, and `00447E38` remain unfinished. Dirt and snow are each down to six differences in their latest branch reconstructions; `00130690` is down to two. These are not accepted matches.

The latest full build after the upstream merge and provisioning its two newly required compiler configurations (`ee-gcc2.96-nsa-nosib`, `ee-gcc2.96-nosib`) reproduces both original loaded segments: `text_matches: true`, `data_matches: true`, code SHA-1 `28422e7e20a6298224294255355487b9a22cef31`. It links 17,573 functions. All 27 accepted additions are directly linked and pass the source assembly-policy check. They are present in both checkouts. No upstream compiler setting was changed; the two configurations use the same already installed ee-gcc archive. The log is `build/pr-mcardata-expanded-build.log`; the report is `build/full/report.json` in the container.

PickUpEnemyCars is now down to ten instruction differences in its best manual draft. Its bounded permuter experiment did not produce an accepted match. Seven targets remain unfinished; none has been added to `src/`.

Two analysis corrections from deeper reconstruction: `00447F48` masks the low 32 bits with `0xffffffffU`, rather than applying a `0xffff0000` mask; the intervening MIPS64 logical shift is essential. `001307E8` exits the entire function when identifier parsing fails. The earlier candidate descriptions were preliminary. See [the process explanation](mcardata-recovery-process.md) for how these deductions and exact checks work.

## Earlier pause state (historical)

Branch: `codex/first-matches`, based on upstream `8358a18de7dbc9a2f82365dc949dab46b6d1cb20`.

Windows checkout: `F:\_projects\gt4-decomp`. Container checkout: `/home/dev/gt4-decomp`. Access details are in [workspace-access.md](../workspace-access.md).

The expanded batch has **17 of 23 additional methods passing the individual exact-match judge**, plus the original NotForSell and RaceForbidden pair: 19 new MCarData sources in total. Accepted source files are present in both checkouts, under `src/gamedata/unit_0012D680/`. They remain uncommitted and unpushed. No PR has been opened.

The 17 additional methods are GetCarLabel, GetCarLabelByIndex, GetCarName, GetShortCarName, GetRaceCode, IsTireNormal, IsDirtRunnable, GetOpenModelType, GetCarNumericCode, GetCarNameByNumericCode, GetMaker, GetTuner, GetCountry, GetCategory, IsStrange, IsTestCar, and GetDescriptionID.

The remaining six are IsExist, GetCarLogoName, ShiftCarCode, GetDirtCarCode, GetSnowCarCode, and PickUpEnemyCars. IsExist's best draft has six instruction differences. The dirt/snow drafts still differ in branch merging, string lifetimes, and compiler register choices. ShiftCarCode and PickUpEnemyCars need more substantial manual reconstruction. Unmatched drafts remain outside `src/`.

The last full build validated the original two-method contribution, with matching code and data hashes. **The expanded 17-method addition has not yet received a full-build verification.** Individual MATCH results are not a substitute for that final check. Six older unrelated tiny matching additions remain separate from the intended CarData PR.

## Additional unmatched targets

The table comes from inspection of the container's original executable, `tools/match.py` disassembly, and `project.source_for()` inventory. Counts include internal/trailing padding retained by the judge's trimming rules; they describe scope, not difficulty or a guarantee of a match. Descriptions are inferred from assembly, not recovered original names.

| Address | Instructions | Observed behavior | Why investigate it |
| --- | ---: | --- | --- |
| `00130618` | 18 | Repeatedly bisects a range of 68-byte records, comparing the float at offset `0x40` against a target. | Smallest candidate; clarifies the score-range search in PickUpEnemyCars. |
| `001305A0` | 30 | Constructs a car record, looks it up by identifier, returns zero on failure, otherwise obtains a float through already recovered `00130540`, then destroys the record. | Small wrapper with existing constructor/destructor and score-helper sources; called by PickUpEnemyCars. |
| `00447CA0` | 22 | Looks up a code in the database, copies the returned string to the output buffer and returns success; otherwise writes an empty output string. | Shared directly by ShiftCarCode, GetDirtCarCode and GetSnowCarCode. Useful for confirming the code-to-label interface. |
| `00448AD0` | 30 | Tries two identifier lookups, rejects the `-1` sentinel, then delegates filling the output record to `00448B48`. | Shared by five batch methods, including the three code-conversion methods. Its two lookup helpers already have sources. |
| `004443A8` | 38 | Tries database lookup categories 0 and `0x26`, returning failure if both fail; otherwise delegates loading to `00444440`. | Direct dependency of IsExist and of the small `001305A0` candidate. |
| `00447F48` | 34 | Masks the input code, queries database category `0x22`, then copies a packed 24-byte result to the caller on success. | Direct ShiftCarCode dependency; clarifies the small record whose byte at offset `0x10` chooses conversion behavior. |
| `00447E38` | 52 | Resolves a label through categories 0/`0x26`, checks it, follows database references, and retrieves a string. | Direct GetCarLogoName dependency. More involved and less attractive as a first small target. |
| `00130690` | 86 | Initializes output indices to `-1`, selects distinct indices from a range, and excludes a supplied index. | Extracts a substantial piece of PickUpEnemyCars into a separately testable reconstruction. |
| `001307E8` | 56 | Walks selected candidate indices, parses their labels, tests the 64-bit field at record offset `0x38` against `-1`, and skips an excluded index. | Another isolated PickUpEnemyCars helper; the tested field is also used for dirt-car conversion. |

Suggested resumption order: `00130618`, `001305A0`, `00447CA0`; then `00448AD0` and `004443A8`. Investigate the larger selection helpers after those. None of these nine candidates was implemented or tested for a source match during this scan.

Some callees still lack sources: `00443E00`, `00443E60`, `00443F00`, `00443F40`, `00443ED0`, `00444440`, and `00448B48`. A missing callee implementation does not prevent matching its caller: existing tools can resolve a call to the original address. Recovering callees helps establish signatures, record layouts and behavior; it does not automatically fix inlined string cleanup or compiler scheduling in the six unresolved wrappers.

## Resume evidence and validation

- Container original references: `build/auto/mcardata/references/*.s`.
- Container unmatched manual drafts and judge comparisons: `build/auto/mcardata/manual/`.
- Local original references and experiment scripts: `build/pr-mcardata/`.
- Earlier full-build report: local `build/pr-mcardata/report.json`; container log `build/pr-mcardata-build.log`.
- Recheck new sources individually, run the assembly-policy check, then run one foreground full build with at most two jobs and verify code/data hashes and direct linkage before describing the expanded batch as fully validated.

SOCOM was not accessed or changed during this scan. Its directory remains explicitly read-only for this task.
