# 00449F80 three-try recovery

Native-width bitfield and volatile-byte access did not recover the missing extension. TI-mode return was rejected by the compiler. Full body remains shorter than the inventory.

- [00449f80-h1.cpp](00449f80-h1.cpp): **no-change**, 2/5 differing rows. Three-try recovery H1: native64 unsigned eight-bit bitfield backing unit, rather than prior signed32 backing unit; test retained SI-to-DI widening after bitfield extraction. Still shortened five-word body.
- [00449f80-h2.cpp](00449f80-h2.cpp): **worse**, 3/6 differing rows. Three-try recovery H2: volatile byte member prevents load reuse across inline getter, testing whether widening provenance survives; emits extra address add and still omits extension, six words.
- [00449f80-h3.cpp](00449f80-h3.cpp): **no-compile**, no instruction comparison. Three-try recovery H3: test EE TI-mode native scalar return ABI as reason for otherwise redundant widening pair. Compiler rejects byte-to-TI conversion as unsupported wide integer operation; budget exhausted.

Every try call counts, including preparation and compiler failures. Raw row scores may compare shortened or overlong bodies; none establishes full matching. The existing primary candidate is retained unless explicitly resolved. Sources are byte-for-byte copies of the remote tested files, verified by SHA-256. See the root manifest for original paths and hashes.
