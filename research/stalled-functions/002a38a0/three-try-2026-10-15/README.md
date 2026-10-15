# 002A38A0 three-try recovery

Embedded UV setters recover frame30 but not corner address generation; native coordinate wrappers spill heavily.

- [002a38a0-h1.cpp](002a38a0-h1.cpp): **worse**, 43/70 differing rows. Three-try recovery H1: established nogcse profile tests whether common-subexpression elimination removes native duplicate index/product copies. Still70 words with missing tail and clamp regression,43/70.
- [002a38a0-h2.cpp](002a38a0-h2.cpp): **differs**, 40/74 differing rows. Three-try recovery H2: direct member setters on embedded UV objects, avoiding previously spilled standalone Vec2 temporaries. Frame stays30 but produces separate corner address registers and74 words,40 differ.
- [002a38a0-h3.cpp](002a38a0-h3.cpp): **worse**, 51/79 differing rows. Three-try recovery H3: scalar Coordinate value wrappers with inline construction/conversion, testing product-copy lifetimes without Vec2 pair objects. Compiler still materializes wrappers, frame70 and79 words; reject.

Every try call counts, including preparation and compiler failures. Raw row scores may compare shortened or overlong bodies; none establishes full matching. The existing primary candidate is retained unless explicitly resolved. Sources are byte-for-byte copies of the remote tested files, verified by SHA-256. See the root manifest for original paths and hashes.
