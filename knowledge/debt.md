# Known debt

Matches that are byte-exact but rely on something we would rather replace once the original form
is understood. Each entry says what it is, how many sources depend on it, and the lead to follow.
A source in this list still matches and links; the debt is about how faithful the C is, not about
the bytes.

## Scratchpad base as an opaque `li` (`include/spr.h`)

- **What:** `spr_base()` returns 0x70002000 through one inline-asm `li`, which the assembler
  expands to an adjacent `lui`/`ori` pair the compiler cannot see into.
- **Why:** in `unit_00494578` (the network library) all 186 loads of the scratchpad base are such
  adjacent pairs, while 545 of the unit's 898 other 32-bit constants are split and scheduled apart.
  A plain `(T *)0x70002000` cast gives the folded form (`lui 0x7000; lw 0x2110(reg)`), which retail
  also has in 25 places; those use the cast.
- **Depends on it:** 73 sources (`git grep -l spr_base -- src`), added in #10.
- **Lead:** the network library may have been built with other options than the rest of the game
  (the experimental `-nosched1` profiles, a possible `-O1`), or the original source used an asm
  macro of its own. Find the compile that keeps the pair adjacent without asm and drop the helper.
- **For a PC port:** the helper is the one place to change (return the emulated scratchpad).

## Other open items

- **Unresolved base constructor:** sources that call `__19hObject__structor_0` match but do not
  link until that constructor has an address (seven at the time of #5, including
  `mDnasInst__structor_0`).
- **Does not compile in the full build:** 00543338 declares `memcpy` twice with conflicting
  prototypes and passes an `s32` to it. (19 others failed because `include/shim/stdlib.h`
  declared `free` with C++ linkage; its `extern "C"` guard fixed them, found by Ganitzsh in #10.)
- **Jump-table boundaries:** 001d2aa8, 0039f160 and 00587c08 have wrong function boundaries in the
  inventory, so they cannot link from source yet.
