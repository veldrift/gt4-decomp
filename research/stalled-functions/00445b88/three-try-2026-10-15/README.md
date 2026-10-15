# 00445B88 three-try recovery

Volatile source reads, one nonthrowing declaration and explicit comparison enum all retain 111/128. No undefined return fallthrough was promoted.

- [00445b88-h1.cpp](00445b88-h1.cpp): **no-change**, 111/128 differing rows. Three-try recovery H1: volatile input field view tests whether retained dead sentinel read reflects observable field accesses while preserving defined zero return. Same111/128 shifted compare chain and zero-status forwarding; no improvement.
- [00445b88-h2.cpp](00445b88-h2.cpp): **no-change**, 111/128 differing rows. Three-try recovery H2: only earlier-in-unit existence query declared throw(), testing failure-edge resource scan while keeping defined sentinel result. Same111/128.
- [00445b88-h3.cpp](00445b88-h3.cpp): **no-change**, 111/128 differing rows. Three-try recovery H3: explicit Comparison enum result with defined Different on every exit, testing native result-mode normalization without undefined fallthrough. Same111/128, prior field pairing remains correct but query/sentinel control flow unresolved.

Every try call counts, including preparation and compiler failures. Raw row scores may compare shortened or overlong bodies; none establishes full matching. The existing primary candidate is retained unless explicitly resolved. Sources are byte-for-byte copies of the remote tested files, verified by SHA-256. See the root manifest for original paths and hashes.
