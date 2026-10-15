# 00447DD0 three-try recovery

Resolved: judge MATCH, full 72-byte span and original full-build hashes verified; target explicitly linked.

- [00447dd0-h1.cpp](00447dd0-h1.cpp): **match**, 0/17 differing rows. Three-try recovery H1: original zero-high-word branch jumps directly to epilogue after v0 receives identifier, bypassing v1-to-v0 tail. Return identifier on that path, not high/zero. Fix semantic misreading underlying prior register-only attempts.

Every try call counts, including preparation and compiler failures. Raw row scores may compare shortened or overlong bodies; none establishes full matching. The existing primary candidate is retained unless explicitly resolved. Sources are byte-for-byte copies of the remote tested files, verified by SHA-256. See the root manifest for original paths and hashes.

Accepted source: [func_00447DD0.cpp](../../../../src/func_00447DD0.cpp). [Validation metadata](validation.json).
