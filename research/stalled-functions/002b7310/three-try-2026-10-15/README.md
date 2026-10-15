# 002B7310 three-try recovery

Lock guard, conditional-expression cleanup and default-length constructor all regress. Keep prior 2/104 candidate; original scheduling context remains missing.

- [002b7310-h1.cpp](002b7310-h1.cpp): **worse**, 106/107 differing rows. Three-try recovery H1: scoped LockGuard owns mutex through constructor and destructor, testing surrounding automatic-object lifetime instead of repeated String helper nesting. Materializes mutex stackslot,107 words106 differ; explicit lock source remains better.
- [002b7310-h2.cpp](002b7310-h2.cpp): **worse**, 103/108 differing rows. Three-try recovery H2: conditional assignment expression with fallback temporary in one arm changes full-expression cleanup across the predecessor/join, unlike prior unnamed temporary inside if. Emits conditional-destruction state in s3 and108 words,103 differ.
- [002b7310-h3.cpp](002b7310-h3.cpp): **worse**, 107/112 differing rows. Three-try recovery H3: literal constructor accepts optional npos length and resolves strlen in body, testing default-argument folding before inlining rather than helper nesting. Produces112 words107 differ; prior2/104 best retained.

Every try call counts, including preparation and compiler failures. Raw row scores may compare shortened or overlong bodies; none establishes full matching. The existing primary candidate is retained unless explicitly resolved. Sources are byte-for-byte copies of the remote tested files, verified by SHA-256. See the root manifest for original paths and hashes.
