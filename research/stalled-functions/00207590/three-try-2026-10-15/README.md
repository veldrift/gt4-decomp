# 00207590 three-try recovery

Native-width return and normalized predicate fail to recover the missing return-island word; helper lifetime form retains 16/209.

- [00207590-h1.cpp](00207590-h1.cpp): **worse**, 196/207 differing rows. Three-try recovery H1: native64 base-reader result specifically combined with retained likely-hint candidate, to remove int-to-long result copy. Copy disappears but return island disappears too;196/207 shifted rows.
- [00207590-h2.cpp](00207590-h2.cpp): **differs**, 20/209 differing rows. Three-try recovery H2: hint normalized nonzero predicate rather than raw int result, to separate probability note from SI-to-DI copy. Adds sltu/shift and exchanges saved node/Rep homes,20/209; still not full840 bytes.
- [00207590-h3.cpp](00207590-h3.cpp): **no-change**, 16/209 differing rows. Three-try recovery H3: bool-returning release_count layer inside cleanup on likely-base scaffold, testing refcount predicate lifetime and backward return merge; same16/209 as prior hinted best, missing full-span proof.

Every try call counts, including preparation and compiler failures. Raw row scores may compare shortened or overlong bodies; none establishes full matching. The existing primary candidate is retained unless explicitly resolved. Sources are byte-for-byte copies of the remote tested files, verified by SHA-256. See the root manifest for original paths and hashes.
