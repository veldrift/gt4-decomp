# 00449AF8 three-try recovery

Direct address arithmetic and guarded record iteration still differ structurally; some candidates have shortened bodies.

- [00449af8-h1.cpp](00449af8-h1.cpp): **differs**, 35/35 differing rows. Three-try recovery H1: pure unsigned32 integer address/index arithmetic removes wide scaling conversion; compiler strength-reduces lookup into cursor and outlines return path,35/35.
- [00449af8-h2.cpp](00449af8-h2.cpp): **differs**, 25/27 differing rows. Three-try recovery H2: retain Header directly throughout search and return instead of keeping Table wrapper live and reloading it; head base now correct and27-word body, but loop still strength-reduced and nonzero original tail omitted.
- [00449af8-h3.cpp](00449af8-h3.cpp): **differs**, 30/35 differing rows. Three-try recovery H3: native64 loop index in direct-Header form, testing whether indexed addressing survives loop reduction without explicit widened offset. Indexing survives but adds SI/DI conversions and daddiu,30/35; not original.

Every try call counts, including preparation and compiler failures. Raw row scores may compare shortened or overlong bodies; none establishes full matching. The existing primary candidate is retained unless explicitly resolved. Sources are byte-for-byte copies of the remote tested files, verified by SHA-256. See the root manifest for original paths and hashes.
