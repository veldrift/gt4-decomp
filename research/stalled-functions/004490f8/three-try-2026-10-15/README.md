# 004490F8 three-try recovery

End-store ownership and Section value-object helpers did not recover the missing instruction/scheduling context.

- [004490f8-h1.cpp](004490f8-h1.cpp): **differs**, 27/28 differing rows. Three-try recovery H1: static inline initializer takes base/flag before Table output and stores branch-local endpoints itself; restores28-word body and ushort narrowing but output remains a2 and base copy missing,27/28.
- [004490f8-h2.cpp](004490f8-h2.cpp): **no-change**, 27/28 differing rows. Three-try recovery H2: native Section::next inline accessor for both relative links, keeping endpoint stores in initializer; tests missing section-view helper layers. Identical27/28 residual.
- [004490f8-h3.cpp](004490f8-h3.cpp): **no-change**, 20/26 differing rows. Three-try recovery H3: small SectionEnd pointer value object returned by inline initializer, testing native result-object lifetime instead of prior hidden whole-Table aggregate return. Same20/26 as retained best; original split tail still missing.

Every try call counts, including preparation and compiler failures. Raw row scores may compare shortened or overlong bodies; none establishes full matching. The existing primary candidate is retained unless explicitly resolved. Sources are byte-for-byte copies of the remote tested files, verified by SHA-256. See the root manifest for original paths and hashes.
