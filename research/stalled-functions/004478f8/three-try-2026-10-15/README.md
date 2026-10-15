# 004478F8 three-try recovery

Fixed-end iteration, narrow index and cached-byte loop forms did not solve index/count allocation and loop structure.

- [004478f8-h1.cpp](004478f8-h1.cpp): **differs**, 34/40 differing rows. Three-try recovery H1: fixed-end input iterator plus output cursor and count, testing STL-style bounded byte traversal instead of index induction. Forty-word body, no native peel,34/40.
- [004478f8-h2.cpp](004478f8-h2.cpp): **worse**, 37/47 differing rows. Three-try recovery H2: native ushort row index separates index from returned int count, valid for ten-byte range. Emits extra mask/unsigned guard and47 words,37 differ.
- [004478f8-h3.cpp](004478f8-h3.cpp): **differs**, 32/42 differing rows. Three-try recovery H3: cache byte in original zero-based short-circuit condition and use cached value for store, eliminating repeated load without previous minus-one/preincrement index experiment. Rotated42-word loop remains,32/42.

Every try call counts, including preparation and compiler failures. Raw row scores may compare shortened or overlong bodies; none establishes full matching. The existing primary candidate is retained unless explicitly resolved. Sources are byte-for-byte copies of the remote tested files, verified by SHA-256. See the root manifest for original paths and hashes.
