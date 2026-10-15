# 00443518 three-try recovery

Typed Directory layout and LanguageNames member wrapper remain 59/148; selected-language helper is worse.

- [00443518-h1.cpp](00443518-h1.cpp): **no-change**, 59/148 differing rows. Three-try recovery H1: reconstruct Directory as128-byte path plus43 secondary Table pointers, matching native secondary base+0x80 and primary offset134. Typed secondary access leaves59/148 unchanged, confirming layout but not allocation fix.
- [00443518-h2.cpp](00443518-h2.cpp): **worse**, 69/148 differing rows. Three-try recovery H2: inline loadSelectedLanguage(selected,self) separates language search from loading, giving selected its own formal lifetime before self; changed saved homes and first search guard,69/148.
- [00443518-h3.cpp](00443518-h3.cpp): **no-change**, 59/148 differing rows. Three-try recovery H3: final language lookup through native LanguageNames object/member accessor, explicitly exposing table this before index arithmetic. Same59/148; address folding and saved-home exchange unresolved.

Every try call counts, including preparation and compiler failures. Raw row scores may compare shortened or overlong bodies; none establishes full matching. The existing primary candidate is retained unless explicitly resolved. Sources are byte-for-byte copies of the remote tested files, verified by SHA-256. See the root manifest for original paths and hashes.
