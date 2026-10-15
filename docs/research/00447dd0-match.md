# Identifier conversion match: 00447DD0

Transferred from `feat/stalled-functions` commit `7607dcdaf` to `feat/matched-functions`.

When the identifier has a zero upper half, the function returns the original identifier. The old draft returned zero. Correcting that return with the established `ee-gcc2.96-nsa-nosib` profile gave `swarm.py try` MATCH on the first attempt.

[Accepted source](../../src/func_00447DD0.cpp) and [validation metadata](00447dd0-validation.json).

Validation on the source branch: all 68 emitted bytes and three resolved relocations match; the four remaining bytes in the 72-byte inventory span are original zero padding. The nonpartial full build produced the original text SHA-1 `28422e7e20a6298224294255355487b9a22cef31` and data SHA-1 `c28c833f9716467545bf362f321e9acc876c3603`, with `00447dd0` explicitly linked and no duplicate/orphan source registrations.

The transferred source is unchanged after line-ending normalization. The compiler profile, judge, compiler wrapper and alignment tool are identical between the branches. This document preserves the prior full-build evidence; it does not claim a new full build of the destination branch. Failed candidates and the full recovery checkpoint remain on `feat/stalled-functions`.
