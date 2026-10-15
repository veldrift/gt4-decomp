# 0020EEB8 three-try recovery

String member operations slightly change the raw score but remain 60 words short; native-width character locals overshoot, nogcse does not recover the body.

- [0020eeb8-h1.cpp](0020eeb8-h1.cpp): **worse**, 817/828 differing rows. Three-try recovery H1: keep character temporaries in native64 signed long after int reader calls; tests sign-extension lifetimes suggested by decompiler long values. Expands to828 words vs776 inventory,817 differ, reject.
- [0020eeb8-h2.cpp](0020eeb8-h2.cpp): **differs**, 635/716 differing rows. Three-try recovery H2: reconstruct String length/append/clear inline member chain instead of raw replacement calls; restores this and char argument expansion. 635/716 vsbaseline638/716, still60 words short.
- [0020eeb8-h3.cpp](0020eeb8-h3.cpp): **worse**, 686/718 differing rows. Three-try recovery H3: use supported nogcse profile on reconstructed member chain; original repeated classification/address work suggests global expression sharing may explain missing words. 686/718, only2 added words and worse registers; remains short.

Every try call counts, including preparation and compiler failures. Raw row scores may compare shortened or overlong bodies; none establishes full matching. The existing primary candidate is retained unless explicitly resolved. Sources are byte-for-byte copies of the remote tested files, verified by SHA-256. See the root manifest for original paths and hashes.
