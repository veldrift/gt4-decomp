# Car geometry interface matches

Recovered 2026-10-09 on `codex/car-geometry-virtual-wrappers`, renamed from
`feat/easy-function-batches` without changing its base. The branch starts at `dev`
commit `cc47baf51d274bf6f6eb314c979488ca793fdd0f`, which already contains the
separate 27-function CarData contribution, six earlier matches and project notes.
These 38 new sources are a separate contribution, verified before the first
checkpoint commit. The user subsequently authorized commits and extending the work
to the remaining CarGeometry methods. No push or PR was made.

Proposed contribution title: **Car geometry: recover forwarding, interface queries
and initialization methods**. The work is AI-assisted reconstruction from the
local executable and existing matching siblings, checked with the original compiler.
It does not recover the underlying geometry-processing algorithms.

## Accepted scope

The initial 32 targets all passed the exact-match judge:

- 29 CarGeometry forwarding wrappers: virtual slots 00, 04–09, 20–23, 27–30,
  32–44 and 47.
- Three SpecialCarGeometry forwarding wrappers: virtual slots 04, 05 and 06,
  at `0038C8B0`, `0038C8E0` and `0038C910`.

After the user requested additional related work, six more methods matched:

| Address | Canonical symbol | Behavior observed in the executable |
| --- | --- | --- |
| `0038C868` | `SpecialCarGeometry__virtual_03` | Returns a fixed float, or an underlying query result plus that float. |
| `0038CB48` | `SpecialCarGeometry__virtual_27` | Same query pattern with a different callee and float. |
| `0038D0D8` | `NormalCarGeometry__virtual_00` | Maps two byte fields to an integer result with two conditional query calls. |
| `0038DA08` | `NormalCarGeometry__virtual_32` | Tests a byte field against five values and returns 0 or 1. |
| `0038DB30` | `CarGeometry__structor_0` | Initializes embedded objects and forwards to `0038DC30`. |
| `0038DB98` | `CarGeometry__structor_1` | Same initialization with a different arrangement of forwarded arguments. |

The initialization addresses have aliases for CarGeometry, NormalCarGeometry and
SpecialCarGeometry. They count once each, using the canonical paths from
`tools/layout.py`. No duplicate propagation was performed. All sources are under
`src/race/CarGeometry_NormalCarGeometry/` or `src/race/SpecialCarGeometry/`.

The accepted methods contain 2,048 judged instruction bytes, including the initial
1,536-byte forwarding batch. Inventory sizes can include trailing alignment nops;
they should not be substituted for the judge's instruction counts.

## Reconstruction notes

The forwarding pattern uses an eight-byte virtual-table entry: signed 16-bit
object adjustment, a second 16-bit field, then the function pointer. CarGeometry
loads its implementation pointer at object offset `0x1C`; SpecialCarGeometry
dispatches through its own virtual table. Use the original entry offset for each
method rather than inferring it solely from the recovered slot label.

The existing CarGeometry slots 01–03 and SpecialCarGeometry slot 21 supplied the
matching source shapes. CarGeometry slots 00, 23, 32 and 47 matched with an integer
return propagated from the virtual call. Slots 07–09 preserve an additional
argument; declaring and forwarding that argument reproduces the implementation
pointer's register allocation. The other initial wrappers use the void-call shape.

SpecialCarGeometry slots 03 and 27 use float bit patterns `3DCCCCCC` and `3F8A7068`;
their sources use exact hexadecimal float literals. NormalCarGeometry slot 00
requires the switch form to reproduce its comparison and conditional-move sequence.
The two initializers use explicit embedded layouts and external table declarations.
The second initializer matched when the zero-initialized field at offset 8 was
modeled as a pointer. Names and types remain provisional where the executable does
not establish their full meaning; byte identity does not prove a complete class API.

## Verification and checkpoints

Every accepted file passed `tools/agent_step.py try`, then a separate
`tools/match.py check` at its canonical path. Source-policy checks found no forbidden
assembly or pinned registers. The judge checked the initialization methods' table
relocations against the original addresses. `git diff --check` also passed.

Both the initial 32-function build and the expanded 38-function build passed.
The expanded build linked all 38 functions directly and reproduced both original
segment hashes. Its report counts 2,048 bytes linked from the new sources.

Full-build acceptance requires both original segments to match and every one of
the 38 addresses to have status exactly `linked` in `build/full/report.json`, not
raw-byte fallback or linkage through another source. Run:

```sh
source ~/.local/share/gt4/venv/bin/activate
python tools/build.py --keep-going --jobs 2
```

Expected original SHA-1 values:

- `.text`: `28422e7e20a6298224294255355487b9a22cef31`
- `.data`: `c28c833f9716467545bf362f321e9acc876c3603`

Ignored checkpoints live in `build/auto/geometry-wrappers/`: per-attempt judge
records, drafts, reconstruction scripts, `verified-results.json` with source hashes,
the initial 32-function build proof, the expanded build log and `build-proof.json`.
Accepted sources and useful non-game checkpoints are synchronized between Windows
and `/home/dev/gt4-decomp`. No game files, assembly dumps or build binaries belong
in the contribution.

## Remaining work and review boundary

None of the initial 32 or the six additions remain unresolved. A fresh class-wide
scan leaves CarGeometry slots 24, 25 and 26 at `0038E158`, `0038E228` and `0038E300`
(208, 216 and 216 inventory bytes). They are outside this contribution; this batch
does not claim to have solved or attempted them.

The future PR should contain only these 38 sources and this focused note. Because
the requested branch retains `dev` ancestry, an upstream-base diff also includes
the earlier pending contributions. Review the intended base or isolate the batch
for an independent upstream PR without losing the preserved development history.
