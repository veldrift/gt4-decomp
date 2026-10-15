# 00449190 three-try recovery

Native-width bounds and loop-carried midpoint did not beat the old candidate. H1 was rejected for the retained semantic function name before compilation; H2 corrected that preparation error.

- [00449190-h1.cpp](00449190-h1.cpp): **no-compile**, no instruction comparison. Three-try recovery H1: native64 high bound with signed32 midpoint truncation to alter bound/result allocation priority. Preparation rejected: retained source used semantic function name, while swarm requires func_00449190; no compiler verdict.
- [00449190-h2.cpp](00449190-h2.cpp): **worse**, 27/33 differing rows. Three-try recovery H2: corrected required symbol for native64 high-bound experiment; explicit signed32 midpoint adds two widening shifts and retains a2/a3 exchange, 27/33.
- [00449190-h3.cpp](00449190-h3.cpp): **worse**, 25/31 differing rows. Three-try recovery H3: loop-carried midpoint initialized before do-loop and recomputed at latch, reflecting native next-iteration sum in delay slot; high obtains a2 but midpoint/low lifetimes disturb head and body, 25/31. Retain prior best.

Every try call counts, including preparation and compiler failures. Raw row scores may compare shortened or overlong bodies; none establishes full matching. The existing primary candidate is retained unless explicitly resolved. Sources are byte-for-byte copies of the remote tested files, verified by SHA-256. See the root manifest for original paths and hashes.
