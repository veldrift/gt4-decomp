# 002A29F0 three-try recovery

Real vector-header and list-callback aggregates repair unsafe independent-local layout assumptions but do not recover frame110 or complete body; single empty-Rep base also falls short.

- [002a29f0-h1.cpp](002a29f0-h1.cpp): **differs**, 629/639 differing rows. Three-try recovery H1: aggregate the four adjacent raw vector/callback header locals, making the passed header own begin/end/capacity; restores observable pointer field writes formerly optimized away. Frame100,629/639; still shorter than full inventory.
- [002a29f0-h2.cpp](002a29f0-h2.cpp): **no-change**, 629/639 differing rows. Three-try recovery H2: additionally aggregate list callback tag and value to make its output destination observable to the reader; removes reliance on adjacent independent locals. Same629/639 score, frame100.
- [002a29f0-h3.cpp](002a29f0-h3.cpp): **differs**, 612/619 differing rows. Three-try recovery H3: with real vector and callback aggregates, address emptyRep members through one Rep object instead of split globals; tests common base lifetime. 612/619 frame100, short body persists; no acceptance.

Every try call counts, including preparation and compiler failures. Raw row scores may compare shortened or overlong bodies; none establishes full matching. The existing primary candidate is retained unless explicitly resolved. Sources are byte-for-byte copies of the remote tested files, verified by SHA-256. See the root manifest for original paths and hashes.
