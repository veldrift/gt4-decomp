# 00440FB8 three-try recovery

Reference-member bounds, reference-returning accessors and default compiler context remain 33/92.

- [00440fb8-h1.cpp](00440fb8-h1.cpp): **no-change**, 33/92 differing rows. Three-try recovery H1: BoundsView stores native const reference rather than pointer, testing view lifetime and alias metadata without copying bound values. Identical33/92 with enlarged70 frame.
- [00440fb8-h2.cpp](00440fb8-h2.cpp): **no-change**, 33/92 differing rows. Three-try recovery H2: reference-returning low/high accessors specifically on pointer-only BoundsView, unlike prior direct Limits references; identical33/92, pointer object still materialized.
- [00440fb8-h3.cpp](00440fb8-h3.cpp): **no-change**, 33/92 differing rows. Three-try recovery H3: default game alias profile on pointer-view candidate tests whether alias precision scalarizes stored row pointer; output stays33/92 with frame70. No improvement after three.

Every try call counts, including preparation and compiler failures. Raw row scores may compare shortened or overlong bodies; none establishes full matching. The existing primary candidate is retained unless explicitly resolved. Sources are byte-for-byte copies of the remote tested files, verified by SHA-256. See the root manifest for original paths and hashes.
