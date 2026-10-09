# Car geometry interfaces

This independent contribution is based directly on upstream/master at 52c09e083d4a7720161a32a9b62a1971f8acf983. It adds 76 matching functions (4436 instruction bytes) from the previously verified 103-function batch. Upstream already provides 27 batch addresses; their upstream implementations are retained without modification. The ledger lists every added address, canonical source, SHA-256 and expected instruction size.

All added functions passed the unchanged upstream judge and the existing source-policy check with no unchecked-reference acceptance. The foreground full build used two jobs; every added source links directly with its expected size. There are no duplicate addresses or orphan sources. Rebuilt .text and .data equal the original byte for byte:

- .text SHA-1: 28422e7e20a6298224294255355487b9a22cef31
- .data SHA-1: c28c833f9716467545bf362f321e9acc876c3603

This branch contains only its own source batch and verification documents. Upstream tools, configuration, headers and compiler settings are unchanged. Full evidence remains ignored under build/auto/pr-separation/original/; no game input or rebuilt binary is committed.
