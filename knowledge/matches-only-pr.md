# Consolidated dev and matches-only PR branch

2026-10-14: all pre-existing local branch tips are ancestors of consolidated
`dev`, including geometry, CarData, menu play-data and wheel-helper work.
Commit `80f5e1f78` additionally preserves the final CarData/menu attempt diary
and recovery notes. Existing ignored drafts and binary validation evidence
remain local; no game data is added to Git.

`feat/matched-functions` starts at current upstream master `b59952917` and has
one commit, `984fc333c`, containing only source for 29 verified function matches
or replacements. It includes removal of the superseded C source at `0030B358`
when adding its C++ replacement. There are no tooling, shared-header,
configuration, research-note or unmatched-menu changes in that branch.

The work is AI-assisted. The batch covers native operator/runtime and wheel
helpers; photo, calendar and playlist operations; CarData code selection and
enemy pickup; garage range/wing/sorting methods; option mappings; and packed
race database helpers.

## Verification

All 29 sources passed a fresh unchanged-judge MATCH. A separate relocated-object
comparison confirmed the complete emitted body and zero unresolved relocations;
any original suffix omitted from the object's function size contains only zero
padding. No shortened-prefix match was accepted.

The full source inventory agrees between the local PR branch and the validation
snapshot: 28,337 sources, normalized source-tree SHA-256
`ab53365505e3e68867306346e116ea32bf4f7b8a86082c7338c68dd0eb83589d`.
The compile/link tools, compiler configuration, headers and symbols used for
validation agree with the PR branch.

The fresh foreground full build used two jobs, passed both original hashes,
and explicitly marks all 29 PR functions `linked`:

- Text SHA-1: `28422e7e20a6298224294255355487b9a22cef31`.
- Data SHA-1: `c28c833f9716467545bf362f321e9acc876c3603`.
- 27,636 functions linked from source; no duplicate or orphan sources.

Ignored reproduction evidence is under `build/pr-functions/`: manifest, all
29 verdicts, relocated-object proof, full report/log and source-tree digest.
The remote build has no Git metadata, so its report commit is null; the source
digest and per-file hashes bind its evidence to the local branch content.

The six newly investigated menu functions remain unmatched and are documented
only on dev. Godot was left unchanged. Preserve the existing branches and local
evidence; this consolidation does not delete experimental work.
