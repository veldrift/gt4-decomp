# 00233E38 three-try recovery

Scoped string names retain frame A0; POD callback copies create frame D0 and extra words. Real object lifetimes/stack placement remain unresolved.

- [00233e38-h1.cpp](00233e38-h1.cpp): **differs**, 110/469 differing rows. Three-try recovery H1: real scoped Name construction/destruction around each property read, keeping callback carriers explicit; distinguishes string RAII from prior callback-only RAII. Frame remainsA0,110/469.
- [00233e38-h2.cpp](00233e38-h2.cpp): **worse**, 459/485 differing rows. Three-try recovery H2: POD callback factory assigned to first two carriers, rather than previous nontrivial factory with implicit destructors; tests observable copied temporary storage. Two materialized copies enlarge frameD0 and485 words,459 differ.
- [00233e38-h3.cpp](00233e38-h3.cpp): **no-change**, 459/485 differing rows. Three-try recovery H3: scoped inline initCb owns POD factory assignment, testing whether temporary lifetime ends inside helper and storage can be reused. SameD0 frame/459of485; no padding or source promotion.

Every try call counts, including preparation and compiler failures. Raw row scores may compare shortened or overlong bodies; none establishes full matching. The existing primary candidate is retained unless explicitly resolved. Sources are byte-for-byte copies of the remote tested files, verified by SHA-256. See the root manifest for original paths and hashes.
