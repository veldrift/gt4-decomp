# 0043BBC0 three-try recovery

The member setter improves the retained 140/313 raw score to 136/313; the missing historical 20-difference candidate is still unavailable. Full matching remains unresolved.

- [0043bbc0-h1.cpp](0043bbc0-h1.cpp): **worse**, 207/353 differing rows. Three-try recovery H1: bounded normalization helper clamps both zero and256, testing whether known nonnegative masked inputs eliminate lower tests and alter outer cap lifetime. Lower tests survive and body grows353 words,207 differences.
- [0043bbc0-h2.cpp](0043bbc0-h2.cpp): **differs**, 136/313 differing rows. Three-try recovery H2: Data::setAxis owns flag update, outer cap and packed store, passing percentage by value; tests native setter lifetime absent from free clamp probes. Improves140 to136/313 but still unmatched.
- [0043bbc0-h3.cpp](0043bbc0-h3.cpp): **no-change**, 136/313 differing rows. Three-try recovery H3: templated by-value upperLimit inside native Data setter, preserving independent bound argument while instantiating clamp; same136/313. Retain setter candidate alongside baseline.

Every try call counts, including preparation and compiler failures. Raw row scores may compare shortened or overlong bodies; none establishes full matching. The existing primary candidate is retained unless explicitly resolved. Sources are byte-for-byte copies of the remote tested files, verified by SHA-256. See the root manifest for original paths and hashes.
