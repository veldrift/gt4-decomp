# 00448B48 three-try recovery

C frontend and assignment-member reconstruction retain 9/51 differences; shared boolean return is worse.

- [00448b48-h1.c](00448b48-h1.c): **no-change**, 9/51 differing rows. Three-try recovery H1: C frontend with scalar native64 status and conditional copy; distinguish C result expansion from prior C++ bool/long results. Same9/51 redundant-zero epilogue.
- [00448b48-h2.cpp](00448b48-h2.cpp): **worse**, 26/50 differing rows. Three-try recovery H2: copy conditionally, then normalize actual nonboolean row-size status at shared return instead of successful early true return; eliminates extra zero branch but extends status lifetime into t3,26/50.
- [00448b48-h3.cpp](00448b48-h3.cpp): **no-change**, 9/51 differing rows. Three-try recovery H3: native Destination assignment operator from Source retains record-copy helper boundary and reference return; same9/51 redundant-zero epilogue. Retain prior best after three.

Every try call counts, including preparation and compiler failures. Raw row scores may compare shortened or overlong bodies; none establishes full matching. The existing primary candidate is retained unless explicitly resolved. Sources are byte-for-byte copies of the remote tested files, verified by SHA-256. See the root manifest for original paths and hashes.
