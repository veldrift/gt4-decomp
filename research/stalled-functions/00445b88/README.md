# 00445B88 - Specification comparison

Status: **unmatched**. Group: CarData.

24 native field pairs recovered; sentinel return/control flow remains unresolved. Undefined-return experiments are diagnostic only.

Retained starting point: [compare-defined-sentinel.cpp](candidates/build/cardata-untouched/compare-defined-sentinel.cpp). This is a diagnostic starting point, not a claim that it has the lowest complete-body difference.

`attempts.jsonl` is a snapshot of the append-only diary for this address. `candidates/` preserves available C/C++ inputs referenced by that diary plus named complementary drafts. Failed and rejected experiments are retained as historical evidence, not recommended approaches. Missing/nonlocal inputs are listed in the root manifest; they have not been reconstructed.

Judge scores are raw historical row comparisons and may be shifted or shortened. Require complete body, relocations, padding and an explicit linked full-build result before accepting any candidate.

2026-10-15: [Three-try recovery](three-try-2026-10-15/README.md): Volatile source reads, one nonthrowing declaration and explicit comparison enum all retain 111/128. No undefined return fallthrough was promoted.
