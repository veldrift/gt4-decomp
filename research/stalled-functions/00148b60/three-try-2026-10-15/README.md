# 00148B60 three-try recovery

Countdown variant ties the previous 32/340 result; an extra inner loop guard and branch/register differences remain.

- [00148b60-h1.cpp](00148b60-h1.cpp): **worse**, 241/336 differing rows. Three-try recovery H1: signed indexed graph loops terminate on equality, valid for ushort count, to avoid redundant positive-count entry test. Loop loses native countdown transform and shrinks336 words,241 raw differences; relocation warnings reflect shifted code, not changed callees.
- [00148b60-h2.cpp](00148b60-h2.cpp): **differs**, 35/340 differing rows. Three-try recovery H2: preserve native ushort count while keeping signed indexed loop, unlike prior jointly unsigned count/index. Inner duplicate guard persists as beqz and final count predicate changes,35/340.
- [00148b60-h3.cpp](00148b60-h3.cpp): **differs**, 32/340 differing rows. Three-try recovery H3: countdown loop with derived forward array index, letting loop optimization recover cursors while preserving scalar count domain;32/340 ties prior best, inner positive guard and register order still differ.

Every try call counts, including preparation and compiler failures. Raw row scores may compare shortened or overlong bodies; none establishes full matching. The existing primary candidate is retained unless explicitly resolved. Sources are byte-for-byte copies of the remote tested files, verified by SHA-256. See the root manifest for original paths and hashes.
