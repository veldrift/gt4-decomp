# Wheel callback recovery handoff

**Current continuation:** `func_004535A0` is now compiler matched (55/55) and
committed as `bc162b862` on `feat/wheel-callback-helper`. The existing Linux
checkout's full build retained matching `.text`/`.data` with the helper linked.
A fresh four-corner helper capture closes request 12's helper return and proves
the b=0 quotient saturates to `0x7F7FFFFF`; input rotations are degrees from
`004A7350`. Read the current checkpoint in
[the runtime report](wheel-callback-runtime-trace.md) before the historical
unmatched/pending statements below. Complete frame/draw-state evidence and
viewer replacement remain open.

## Objective and authorization

Continue recovery of `func_004535A0` at `0x004535A0`, called by
`func_00453698` at `0x00453698`, requests 11–14, with arguments
`(k & 1, elems[k].f20, data->f84 * elems[k].f1C)`.

Establish its body, callees and return semantics; trace callback dispatch through
`ModelSet2___render` at `0x00455708`; recover producers for all four corner records
and `Data.f84`, including layout, units, initialization and lifetime. Deliver
source/compiler/assembly evidence and an initialized non-default **original runtime
trace** of callback inputs/outputs, selected branches, draw order, transforms and
raw render state. Partial runtime evidence now exists; producer execution and the
complete draw/transform/render-state trace remain outstanding.

## Latest runtime checkpoint — 2026-10-14

Read [wheel-callback-runtime-trace.md](wheel-callback-runtime-trace.md) before
resuming. That report records a live original car-select-screen capture through
PCSX2 MCP. The game was resumed with breakpoints cleared; replay snapshot is in
slot 1. Slot 0's startup state was preserved. Do not restart from the startup
snapshot unnecessarily or assume the previous launch troubleshooting is current.

Request 11 has a captured causal chain: callback this `0x00FC1018`, owning inner
Data base `[this+4] = 0x00FC1014`, k=0, odd=0, a bits `0x3E82FEC4`
(approximately 0.255851), and b=0 because inner f84=0. Original helper returned
0; the dispatcher selected index 1 of count 2. Table base `0x01747FD6`, selected
entry `0x01747FD8`, displacement `0x001D`, target `0x01747FF5` confirm offsets
are relative to the selected entry. These are reported runtime observations,
not a new compiler match or a full draw oracle.

Requests 12, 13 and 14 were observed at callback entry, with helper inputs also
captured for 13/14. Requests 16 and 37 use this same callback entry; request 16
was observed on a second model. Requests 12/14 returns remain uncaptured.

Throughout this handoff, **Data means the inner owning base**, not callback this.
Thus elems start at inner+0x94 (callback this+0x90), and f84 is inner+0x84
(callback this+0x80). For the captured k=0, corner base is `0x00FC10A8`.

The armed `00450F50` breakpoint did not fire during this capture. This establishes
only that the producer was not observed during that interval; it does not prove
the corner data was uninitialized or identify the update cadence. Uniform fields
and f84=0 alone do not prove missing initialization or an absent extension record.
Likewise, a stale stack vector is not a captured helper-output or matrix snapshot.
Treat the report's IEEE +Inf explanation of b=0 as unverified for EE arithmetic;
the observed helper return stands independently of that explanation.

Next capture: re-arm the producer breakpoint and switch cars, record producer
arguments/writes and extension/f84 source, then capture callback returns, actual
shape order, transforms and raw render state from the same initialized instance.
Compiler status remains NOT matched; no `src/` integration has occurred.

### Superseding checkpoint — sessions 2/3

The next capture above was subsequently performed. Car switching reused inner
Data `0x00FC1014` and reached `00450D88` followed by `00450F50` for k=0..3.
Reported producer inputs were a=0.215, b=0.31265, c=0.09675; the report records
verified stores at corner+0x18/+0x1C/+0x20, including b-c. Request 14 with the
new dimensions returned helper=0, callback=1 and selected branch index 1.
Request 12's return remains missing. f84 stayed zero in both cars; absence of
the extension record is reported, but the record-search/assignment capture is
not reproduced in the written report.

All four corner transform entries were captured, with zero rotations and
parity-dependent half-width X shifts of -0.1075/+0.1075. Shape events include
ModelSet `0x01903980`, opcode 4, shape index 193 -> `0x01913810`, and another
ModelSet's shape index 0. Observed callback/shape interleaving is partial; it
does not enumerate a complete frame's draw order. Scratchpad RGBA and raw VU0
registers were sampled, but per-draw state association and VU interpretation
remain incomplete; GS packets were not captured.

The game is resumed, breakpoints cleared, and slot 1 preserved. This round is
finished. Remaining work is source/compiler matching, units/ranges (especially
nonzero rotations), owner/lifetime closure and complete draw/state evidence.
No new compiler check was run; the draft remains unaccepted in `src/`.

Tim authorizes running the original game and using the PCSX2 MCP debugger. He
explicitly requests launching the emulator normally, with a visible window. Use
your already configured MCP connection. Do not synthesize expected outputs from
the viewer, or patch fields and describe that as original initialization.

New Git branches must use `feat/`, never `codex/`.

## Workspace and original inputs

- Repository: `F:\_projects\gt4-decomp\gt4-decomp`
- Inspected baseline: `c6f4ccbcd0668a4a33e6777845fc197ea807e5b3`
- Disc: `F:\_projects\gt4-decomp\gt4-godot\local-data\iso\Gran Turismo 4 (USA) (v1.01).iso`
- Extracted disc: adjacent folder with the same name without `.iso`.
- Original CORE.GT4 SHA-256:
  `85d26aa8430154967b2633eede929286694ac39e99762527edcec365fd642ff9`
- Earlier scope/handoff rationale:
  `F:\_projects\gt4-decomp\gt4-godot\docs\research\model-evaluation-source-boundary.md`

Raw evidence and draft code are in the ignored directory:
`F:\_projects\gt4-decomp\gt4-decomp\build\wheel-recovery\`.
It contains per-function original assembly exports, `summary.json`,
`func_004535A0.cpp`, `helper-match.log`, `render.asm.txt`, `init.asm.txt`, and
`debug.py` (a small direct JSON/TCP DebugServer client). Do not commit original
game data, disassembly dumps, memory captures or save states.

No recovered source was integrated into `src/` during this investigation.

## Helper body and match status

Original instruction inspection establishes:

1. Return 1 immediately when the third argument `b < 0.0f`.
2. Call `004A53F8`, `004A7A54`, `004A7AA8`, then `004A5400`.
3. `D_006AA8D0` is the homogeneous vector `(0,0,0,1)`.
4. `004A7A54` transposes the current rotation and computes inverse translation
   in VU0 registers. `004A7AA8` transforms the fixed vector through that matrix.
   Interpret this as a view-dependent local-origin test; verify the enclosing
   matrix space in runtime evidence before asserting camera/world nomenclature.
5. After restoring the matrix, compute `ratio=a/b`; negate transformed X when
   `odd != 0`; compute `t=ratio*x+a`.
6. If `-b < x`, return the integer comparison
   `t*t < y*y + z*z`; otherwise return 1.

The source-known callback returns `helper_result == 0`, yielding branch index 0
when the helper returns 1 and branch index 1 when it returns 0.

Preserve single-precision operation order and strict comparisons. The original
has no `b==0` division guard. NaN/unordered behavior must follow the EE instructions;
do not replace the comparisons with mathematically equivalent non-strict tests.

Direct-call scan found only helper call site `00453804`. No direct `jal` calls to
the callback were found, consistent with virtual dispatch.

**The helper draft is NOT compiler matched.** Best tested variants differed only
in two register operands: the negation/comparison used f20 rather than original
f13. The current local draft/log can show six differences. Several variants remain
on the Linux machine. Do not claim MATCH or accept the draft into `src/` until
the judge passes. The instruction-derived semantics above are separate evidence.

## Callback dispatcher and branch offsets

The actual dispatcher is `ModelSet2___render` at `00455708`; command jump table
is `006AABD0`.

- Opcode 6 dispatches to `00455CC0`. It reads a signed little-endian 16-bit request
  followed by an unsigned byte branch count.
- Callback object is at instance `+0x14`. It invokes the GCC virtual entry at
  callback vtable `+0x10`: signed 16-bit this adjustment at entry+0, function
  pointer at entry+4.
- Null callback produces index 0.
- Selection tests unsigned `index < count`. In range, the selected signed 16-bit
  displacement is relative to the **selected table entry**, not the table start.
  The shared target calculation is at `00456488`.
- Out of range (including negative return interpreted unsigned), skip the full
  displacement table and execute fall-through. No other indexed branch runs.
- Opcodes 89/90 dispatch to `00455D28`/`00455D38`: byte/signed-short callback
  request with its returned value ignored.
- Opcode 7 is separate LOD selection, using virtual entry `+0x18`; do not
  conflate it with callback opcode 6.
- Shape opcodes 4/5 dispatch to `004559A0`/`004559C0`; model-set shape table is
  at `ModelSet+0x3C`.

`00453680` constructs the callback at Data+4: vtable `00688628` and owning Data
pointer at Data+8. Vtable+0x10 points to `00453698` with zero this adjustment.
Verify the live instance attachment and lifetime in the original run.

## Corner layout, initialization and producers

EE storage is little-endian; floats, ints and pointers in these observed fields
are 32-bit. Corner array starts at Data+0x94, four records, stride 0x38.

| Corner offset | Established use / producer |
| --- | --- |
| +0/+4/+8 | Position xyz; setter `004514A0` |
| +0xC | Rotation consumed by brake helper `004541A0`; setter `00451518` |
| +0x10 | Y rotation in wheel helper; setter `00451518` |
| +0x14 | Parity-adjusted Z rotation; setter `00451518` |
| +0x18 | Lateral dimension used for half-width X translation; `00450F50` stores a |
| +0x1C | Dimension/scale; `00450F50` stores b-c |
| +0x20 | Helper first float argument; `00450F50` stores b |
| +0x24 | Mode-dependent weight; setter `00451518` |
| +0x28 | Alpha input; setter `00451550` |
| +0x2C | Integer render flag; constructor/load path initializes to zero |

Exact source-level names, physical units, ranges and any remaining fields are
not fully proven. Keep offset names until producer evidence supports naming.

`00450980` constructs embedded callbacks at +4/+0xC, clears f84, and calls
`004540E0` on each corner. `004540E0` sets +0xC/+0x10/+0x14 to zero,
+0x18/+0x1C to one, and +0x24/+0x28/+0x2C to zero. It leaves position
+0/+4/+8 and f20 untouched. A zero-filled host fixture is not equivalent to
original initialization.

`00450CB8` calls `00450D88`, queries source virtual slots 11/12/13 for each
corner, then invokes `00450F50`. For unsigned k<4, `00450F50` writes
corner+0x18=a, +0x20=b, +0x1C=b-c and forwards values to `00458A30`.

`00450D88` resolves the model through `00451008`, searches extension key
`0x800000` with `00454B08`, and initializes f84:

- Record present, count byte >0: copy float at record+4.
- Record absent: set f84=0.
- Record present with count=0: leave prior f84 unchanged.

It also sets up model instances and attaches the callback object through their
owner field at +0x14. Follow the model-load chain and extension producer to close
the meaning/units of f84.

`004514A0` updates position, with conditional Y clamp from underlying model
configuration. `00451518` updates +0xC/+0x10/+0x14/+0x24.
`00451550` updates +0x28. `00451AB0` reads virtual scalar getters, then loops
over four corners: vector getter +0x50 supplies position; +0x48 supplies
orientation; setters populate the corner state. Its mode determines weight.
`00452008` performs similar vector updates with zero weight.

`00155990` updates front/rear pairs using `00364D78`, `00364D20`, `00364DD0`
and `00450F50`. These getters remap the index using data from `00359510`, then
read floats at source+0x8D4/+0x8C4/+0x8DC respectively.

Owners embed Data at RaceCarModel+0x18 and mCarModelPS2+0x2A4. The provisional
callback-local Data struct ends at 0x57C, but original constructor accesses
through +0x5BC and initializes a full 16-float matrix at +0x578. Its provisional
sizeof is NOT proof of owning allocation size, alignment or full layout.
Trace construction/load/update/destruction and ownership through callback use.

Relevant existing source is under `src/engine/unit_00450248/`,
`src/race/RaceCarModel/`, `src/race/unit_00364818/`, and
`src/gamedata/mCarModelPS2/`. Source presence is not fresh compiler verification.

## Transforms and raw render state

`00454110` performs, in order:

1. Translate by corner xyz.
2. Rotate Y by corner+0x10.
3. Rotate Z by corner+0x14, negated for odd corners.
4. Translate X by corner+0x18 times +0.5 for odd, -0.5 otherwise.

Confirm degree units by following `004A7350` and the VU microcode. Degrees are
plausible but not yet fully established by this investigation.

Requests 11–14 call `004A6100(0,0,0,0)` followed by
`004A60E0(1,1,1,corner+0x28)` before invoking the helper.

- `004A60E0` stores RGBA floats at scratchpad `70002AF0..70002AFC`.
- `004A6100` scales RGB by 255 and alpha by 128, then stores floats at
  `70002B00..70002B0C`.
- `004A53F8` / `004A5400` use VU microprograms 0x900 / 0x930 for the matrix
  push/pop path. The helper restores the callback-established current matrix.

Capture VU0 matrices and scratchpad state at callbacks and shape draw calls;
then follow downstream draw-state consumption rather than asserting these
scratchpad fields alone are complete GS state.

## Original compiler environment

SSH: `dev@192.168.0.42`, port 2225, identity
`C:\Users\timpa\.ssh\id_ed25519`; use BatchMode and IdentitiesOnly.
Linux checkout: `/home/dev/gt4-decomp`.
Activate `/home/dev/.local/share/gt4/venv/bin/activate`.

Use `python tools/match.py asm ADDRESS` and
`python tools/match.py check ADDRESS FILE`. Compiler is Sony ee-gcc 2.96,
project settings `-O2 -G0`. Remote drafts/evidence also reside under
`build/wheel-recovery/`. Preserve unrelated work and existing compiler profiles.

## PCSX2 state and launch troubleshooting

Installed MCP-enabled release:
`F:\_projects\pcsx2-mcp\PCSX2-MCP-v1.0.0-win64`
Repository: https://github.com/hkmodd/PCSX2-MCP
DebugServer: localhost:21512; Pine: localhost:28011.

An isolated runtime was created at
`F:\_projects\gt4-decomp\gt4-decomp\build\wheel-recovery\pcsx2` with copied
BIOS/memory cards and widescreen patches/cheats disabled. Do not overwrite Tim's
primary emulator settings or cards.

Earlier launch attempts used hidden windows. Tim explicitly requests visible
normal launch. Inspect current process and log before starting duplicates.
D3D12 failed with 887A0005; software renderer also selected that failing display
device. Latest attempt changed Renderer=3 (D3D11), but its outcome is unchecked.
Log: `build/wheel-recovery/pcsx2/logs/emulog.txt`.

Existing original save state:
`C:\Users\timpa\Documents\PCSX2\sstates\SCUS-97328 (77E61C8A).00.p2s`
Its screenshot shows the startup logo, before initialized car rendering. Preserve
it; it is not a non-default car-state oracle. The inspected MCP API has no
controller-input tool; arrange menu navigation with Tim if necessary.

## Remaining execution

1. Launch visibly, establish MCP status and reach an initialized car scene.
2. Verify loaded original code against the identified CORE image.
3. Capture producer execution, owner/instance pointers and initialized input
   memory without modifying game state. Preserve a replayable snapshot.
4. Break at callback entry, helper entry/return, callback return, branch target
   selection and shape calls. Record request IDs, input fields and actual outputs.
5. Capture at least one non-default branch/LOD choice, actual model/shape IDs,
   call order, matrices/transforms and raw render state from the same run.
6. Close producer units, extension semantics and ownership/lifetime gaps; finish
   source matching or report exact comparison status honestly.
7. Produce a durable research report separating runtime observations, matched
   source, instruction-derived semantics, inference and unresolved dependencies.

Do not declare integration readiness until the original non-default oracle and
producer/lifetime evidence exist.
