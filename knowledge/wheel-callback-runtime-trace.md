# Wheel callback runtime trace (original, car select screen)

Date: 2026-10-14. Emulator: single visible PCSX2-MCP instance, DebugServer +
Pine both connected. Game: Gran Turismo 4 SCUS-97328 v1.01, CRC 77E61C8A,
car select screen, resumed + paused via MCP only (no memory written).
Replayable snapshot: save slot 1 (slot 0 startup-logo state untouched).
Breakpoints cleared and game resumed after capture.

## Current checkpoint — matching and fresh helper capture

Continuation on 2026-10-14 supersedes the older unmatched status below.
`func_004535A0.cpp` is now committed at `bc162b862` on
`feat/wheel-callback-helper`: the original compiler reports MATCH for all 55
instructions. The existing Linux checkout at `82b44d3` with its unrelated
uncommitted work preserved also rebuilt with `.text OK` and `.data OK`, and
reports this helper as linked. This is not a full-build claim for the current
Windows checkout's entire source revision.

A fresh read-only capture recorded all four helper invocations, including
request 12. At entry and at `00453604` (after original division), it saved exact
corner fields, VU registers, and the just-produced helper stack vector. At
`0045380C` it saved the actual helper return. Raw evidence stays ignored in
`build/wheel-recovery/original-helper-capture.json`.

| Request | Odd | Original transformed viewpoint xyz | Helper return |
| --- | --- | --- | --- |
| 11 | 0 | 8.85429859, 0.966920018, -3.10289264 | 0 |
| 12 | 1 | 7.14930058, 0.966920435, -3.10289335 | 1 |
| 13 | 0 | 8.85179996, 0.966920018, -5.71789360 | 0 |
| 14 | 1 | 7.15180111, 0.966920495, -5.71789408 | 1 |

These samples use f20 approximately 0.312649965 and f84=0. The quotient in
original f01 is `0x7F7FFFFF`, the largest finite float. This disproves the
historical IEEE +Inf explanation for this capture. Callback expectations
1/0/1/0 follow the original `sltiu v0,v0,1` at `00453810`; these normalized
returns/branch destinations were not independently recaptured in this pass.
Differences from earlier request-14 samples do not imply inconsistency: this
test depends on the current view matrix.

The capture found the emulator already paused, restored that pause state and
removed its own breakpoints. Before a further callback-return capture, the
emulator process closed; two subsequent connections were refused. No restart
or input manipulation was attempted. Slot 1 was not overwritten.

Original `004A7350` also closes rotation input units as degrees: it uses 90,
approximately 1/180, pi/180 (`0x3C8EFA35`) and pi (`0x40490FDB`) in its angle
reduction. This does not validate a host trigonometric implementation against
the original VU microprogram for nonzero angles.

## 1. Session 1 runtime observations

- Loaded helper at `0x004535A0`: full 55 instructions match the handoff's
  original column (`div.s f01`, `neg/c.lt/mul f13`); `D_006AA8D0` = (0,0,0,1).
- Opcode-6 dispatch, model A, stream `0x01747FD3`: request 11, count 2,
  table `[0x0006, 0x001D]`. Instance `s7 = 0x017479C0`.
- Callback `0x00453698` live invocations (via `ra = 0x00455CFC`,
  vtable slot `0x00688638` = vtable `0x00688628` + `0x10`):
  request 11 (this `0x00FC1018`), 12, 13, 14, and also 16 and 37 on the
  same callback entry. So this callback serves more than requests 11-14.
- Request 11 (k=0) full chain, Data `0x00FC1018`:
  header words: `+0x00 = 0x00688628` (vtable), `+0x04 = 0x00FC1014`
  (inner base back-pointer), `+0x08 = 0x006885F0`, `+0x0C = 0x00FC1014`,
  `+0x14/0x18/0x1C` = model pointers `0x006DDF40/80/C0`.
  Helper inputs: odd `a0 = 0`, `f12 (a) = 0.25585`, `f13 (b) = 0.0`
  (`ra = 0x0045380C`, only call site `0x00453804`).
  Helper returned `v0 = 0`.
- Request 13 (k=2): odd 0, a 0.25585, b 0.0. Request 14 (k=3): odd
  `a0 = 1`, a 0.25585, b 0.0. Request 12 observed at entry.
- Caller mapping (from `0x00453798` case + live regs): `s0 = [s2+4] +
  k*0x38 + 0x94`, `s1 = k & 1`; `f12 = [s0+0x20]`, `f00 = [s0+0x1C]`,
  `f13 = [v0+0x84] * f00` with `v0 = [s2+4]` (`mul.s` in delay slot).
  With `[s2+4] = 0x00FC1014`: `f13-src = [0x00FC1098] = 0.0`, so b = 0.
  `a = [0x00FC10A8+0x20] = 0x3E82FEC4` = 0.255851 exact.
- Branch selection at `0x00456488`: index `v1 = 1`, count `s0 = 2`
  (in range); `v0 = 2` (index*2). Table base `s2 = 0x01747FD6`,
  entries `[0x0006, 0x001D]`; selected entry `0x01747FD8`,
  displacement `0x001D`; target `0x01747FD8 + 0x1D = 0x01747FF5`.
  Stepping confirmed dispatch continues at the entry-relative target and
  re-enters opcode-6/callback downstream (`0x00455900` loop,
  next event `s2 = 0x01747FFB`).
- Stale helper-stack vector at `0x006DDE00`: words `40E7D792 3F830944
  C0A76262 3F800000` (~(7.24, 1.03, -4.18, 1.0)), consistent with a
  camera-relative wheel origin on the select-screen carousel.
- Second model, stream `0x0174800D`: opcode 6, request 16, count 1,
  table `[0x0004]`.
- Producer `0x00450F50` breakpoint armed the whole session: never fired.
  It runs at load/update, not per frame.

## 2. Layout corrections to the handoff

- Callback `this` (`0x00FC1018`) is the object embedded at inner-Data + 4;
  inner base = `0x00FC1014` (`[s2+4]`). Corner/element array = inner +
  `0x94` + `k*0x38` (stride confirmed by `k*7*8` in `00450F50` and live
  `s0` for k=0). The handoff's "Data+0x94" holds for the inner base.
- `f84` field = `[inner+0x84]` = `[outer+0x80]` = `0.0` here, consistent
  with the "extension record absent -> f84 = 0" path of `00450D88`.
- Element corner fields (k=0, base `0x00FC10A8`): `+0x1C = 0.1639` (f1C),
  `+0x20 = 0.255851` (a/f20). Position/rotation semantics still need
  `004514A0`/`00451518` producer evidence, not asserted.

## 3. Compiler match status (honest)

Helper draft remains NOT compiler matched (best variant: 6 diffs,
register allocation + scheduling per `helper-match.log`). No new
`match.py` run was performed this session (remote judge untouched).
Runtime evidence above does not change match status. Do not integrate
`func_004535A0.cpp` into `src/`.

## 4. Session 1 inference (not proven)

These hypotheses are historical. Session 2 captured producers for the reused
slot; uniform corner values do not establish uninitialized data. The +Inf
explanation below is not verified against EE floating-point behavior, and the
stale stack vector is not a captured helper output.

- Helper returned 0 for (0, 0.25585, 0.0): b=0 takes the ratio=+Inf path;
  with the observed transformed vector the `t*t < y*y+z*z` comparison is
  false. Callback returns `(0 == 0) = 1` -> branch index 1 (non-default
  of count 2). Mechanism-level WHY (exact gate order, NaN/zero-edge
  polarity) is left to the instruction listing + judge; the handoff prose
  for step 5 simplifies the unconditional `(sp)` negation vs conditional
  `f13` negation and should be re-checked against the judge, not edited
  from this trace alone.
- Uniform a/b across k=0..3 corners fits an uninitialized/select-screen
  instance (producers not yet run for this slot); `f84 = 0` fits a slot
  without extension record `0x800000`.

## 5b. Session 2 — car switch, producer run, odd-corner return

Reloaded slot 1, re-armed 7 breakpoints (producers `00450D88`/`00450F50`,
callback, opcode-6, shapes 4/5, transform `00454110`).

- `00450D88` entry (after Tim switched cars): `a0 = 0x00FC1014` (same
  inner-Data slot reused), `a1 = 0x0096D020`, `a2 = 1`,
  `ra = 0x00450CE4` (caller `00450CB8`). First writes: zero to
  `+0x34`/`+0x44` (delay slot).
- `00450F50` k=0..3, same Data: all four corners `f12 (a) = 0.215`,
  `f13 (b) = 0.31265`, `f14 (c) = 0.09675`.
- Verified in memory after the run, corner0 `0x00FC10A8`: `+0x18 = 0.215`
  (`0x3E5C28F4`), `+0x1C = 0.2159` (`0x3E5D14E3` = b-c exact),
  `+0x20 = 0.3126` (`0x3EA013A8`); position also updated for the new car
  (`-0.745, 0.164, -1.31`), rotations `+0x0C/+0x10/+0x14 = 0`.
  `f84` word `[0x00FC1098]` still `0.0` (extension record absent again).
- Request 14, new dims: odd `a0 = 1`, `a = 0.31265`, `b = 0.0` →
  helper returns `v0 = 0` → callback returns 1 → branch index 1.
  Odd path confirmed live with the same index-1 outcome as k=0.
- Shape opcode-4 event: ModelSet `s6 = 0x01903980`, instance
  `0x01903A00`, stream `0x0190740A`, index byte `0xC1 = 193`,
  shape table `[s6+0x3C] = 0x01903AB0`,
  `shape[193] = [0x01903DB4] = 0x01913810`.
- Scratchpad at a mid-frame pause: `70002AF0` RGBA = (1.0, 1.0, 1.0,
  ~0.9999); `70002B00` scaled words still zero at that instant
  (`004A60E0` ran, `004A6100` scaling not yet visible — partial).
  Full VU0F register file captured raw (vf11-vf14 matrix rows,
  vf00 = (0,0,0,1)); uninterpreted, needs microcode follow-up.
- Callback also serves requests 16 and 37 (observed at entry); request 12
  entry observed, its helper return NOT captured.
- `00454110` transform internals and full draw order NOT captured
  (breakpoint armed, never sampled before cleanup).

## 5c. Session 3 — corner transforms, draw order, render state

Breakpoints: `00454110` (transform), shapes `004559A0`/`004559C0`,
callback `00453698`. `00454110` disasm confirms handoff order exactly:
translate xyz (`004A7844` with `[s0], +4, +8`), rotate Y (`004A79B0`
with `+0x10`), rotate Z (`004A79D8` with `+0x14`, negated iff `a1 =
s1 = k&1`), then translate X by `[s0+0x18]*(+0.5 odd / -0.5 even)`
(`0x3F008000` vs `0xBF008000` paths) via `004A7844` with y = z = 0.

- k=0, corner `0x00FC10A8`, `a1 = 0`: T(-0.745, 0.164, -1.31),
  RY 0, RZ 0, X-shift `0.215 * -0.5 = -0.1075`.
- k=1, corner `0x00FC10E0` (+0x38 stride), `a1 = 1`: RY 0, RZ -0.0,
  X-shift `+0.1075`.
- k=2, corner `0x00FC1118`, even: RY 0, RZ 0, X-shift `-0.1075`.
- k=3, corner `0x00FC1150`, odd: RY 0, RZ -0.0, X-shift `+0.1075`.
- All four corners unrotated (straight wheels, select screen);
  stride `+0x38`/corner confirmed live for k=0..3.
- Per-frame order observed: transform k=0..3 (each: `00454110`, then
  `004A6100`/`004A60E0` render-state writes, then helper, branch select)
  interleaved with shape draws; shape-4 events at ModelSet `0x01903980`
  (index `0xC1` -> shape `0x01913810`) and ModelSet `0x01918080`
  (stream `0x01918217`, index `0x00`).
- Render state: scratchpad `70002AF0` RGBA (1,1,1,~1.0) with `70002B00`
  scaled words zero at the sampled instant; full VU0F file captured raw
  (uninterpreted). No MCP tool exposes GS packets directly, so GS-level
  draw state stays inferred from scratchpad/VU0 + shape stream order.
- Degree units for `004A7350`/rotations still not established by this
  investigation (all observed angles are 0, which proves nothing).

## 5. Unresolved / next steps

- Producer execution and dimension stores are captured in session 2. The fresh
  capture above additionally closes request 12's helper return and samples both
  helper outcomes; complete callback-to-draw association remains open.
- Complete chronological draw sequence and per-draw matrix/state association
  remain open. Sessions 2/3 provide shape events and corner transforms, not a
  complete frame oracle. VU0 data remains uninterpreted; GS packets were not
  captured. Lack of a dedicated MCP GS tool alone does not establish that other
  capture approaches are impossible.
- Extension record bytes/search result and the causal f84 assignment are not
  reproduced in this report. The reported absent-record observation and f84=0
  should be tied to that evidence before treating the full f84 producer as closed.
- Physical length units/ranges and nonzero rotation numerical parity remain
  open; input degrees are now evidenced by `004A7350`. The session-3
  parenthetical constants `0x3F008000`/`0xBF008000` require rechecking: exact
  float +/-0.5 encodings are `0x3F000000`/`0xBF000000`.
- Owner/lifetime: trace `RaceCarModel+0x18` / `mCarModelPS2+0x2A4`
  embed through use; constructor `+0x5BC`/`+0x578` range vs `0x57C`
  provisional struct size.
- Integration readiness: NOT declared (producer/lifetime + render-state
  gaps per handoff criteria).
