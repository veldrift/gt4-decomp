# TextFace matching verification

Checked 2026-10-14 on `feat/textface-verification`, based on `00331d2fe`.
The source-bearing upstream integration remains `fda714473`.

TextFace is already matched in the current decompilation tree. There are no
missing source entries among the 51 known function starts from `002435A0` up
to, but not including, `00246F18`. The fresh audit covers all 51 plus 11 nearby
style-support functions. This pass authored no new function match and changed
no compiled source, compiler configuration, headers or judge behavior.

## Verification

- All 62 existing sources freshly compile and pass the unchanged instruction
  judge on the approved native Linux Sony EE compiler setup.
- 61 pass independent complete-body, resolved-relocation and zero-padding checks.
- Destructor `002436C0` also has an exact complete body. Its own `RefCounter`
  literal initially leaves two relocations unresolved by the standalone check.
  The final check derives the literal placement from the original HI/LO pair,
  verifies every emitted literal byte against retail data, applies those
  relocations and compares all 248 body bytes. This is data-placement resolution,
  not an assembly fallback or a changed judge.
- All 62 are explicitly `linked` in the existing full-build report generated
  at `2026-10-15T02:55:04Z`. The existing full-build text/data files were reread
  and compared with the original image; both agree byte for byte. This pass
  did not rerun the full build, because compiled inputs did not change.
- Text SHA-1: `28422e7e20a6298224294255355487b9a22cef31`.
- Data SHA-1: `c28c833f9716467545bf362f321e9acc876c3603`.

The manifest pins every audited source with its LF-normalized SHA-256. Fresh
checks verify those hashes against the Linux snapshot. The detailed results
retain the destructor's initial unresolved-relocation result alongside its
subsequent `literal_verified_body` and full-build `linked` proof.

## Verified entry points for later host integration

| Address | Role | Complete body bytes | Source |
| --- | --- | ---: | --- |
| `00243650` | TextFace constructor | 112 | [constructor](../../src/ui/MintReader_MstringReader_mTextFace/mTextFace__structor_0.cpp) |
| `002436C0` | TextFace destructor | 248 | [destructor](../../src/ui/MintReader_MstringReader_mTextFace/mTextFace__structor_1.cpp) |
| `002437B8` | Script factory | 160 | [factory](../../src/ui/MintReader_MstringReader_mTextFace/MTextFace__global_0082F8C8.cpp) |
| `00244548` | Script member registration | See results | [registration](../../src/ui/MintReader_MstringReader_mTextFace/func_00244548.cpp) |
| `002463A0` | TextFace property reader | 976 | [reader, misleading recovered symbol name](../../src/ui/MintReader_MstringReader_mTextFace/MintReader__structor_4.cpp) |
| `00246770` | TextFace deep copy | 168 | [copy](../../src/ui/MintReader_MstringReader_mTextFace/mTextFace__deepCopy.cpp) |
| `00246F58` | Embedded text-style constructor | 264 | [style constructor](../../src/ui/MintReader_MstringReader_mTextFace/func_00246F58.cpp) |
| `00247768` | Text-style property reader | 3120 | [style reader, misleading recovered symbol name](../../src/ui/MintReader_MstringReader_mTextFace/MboolReader__structor_7.cpp) |
| `00248398` | Text-style assignment | 324, then four zero-padding bytes | [style assignment](../../src/ui/unit_00248398/func_00248398.cpp) |

Use native addresses to identify these bodies: several historical C++ symbol
names describe reader helpers rather than the actual containing method.

The constructor calls the Widget base constructor, installs the TextFace vtable,
constructs the style at `self+0xA0` and the localized-text reference at
`self+0x104`, sets the `+0x108` word to zero, initializes `+0x10C/+0x110` to
minus one and `+0x114/+0x118/+0x11C` to zero, and applies a 256-by-24 size.
The script factory allocates `0x120` bytes. These are PS2 layouts; host pointers
and virtual-call representations require explicit adapters.

The property reader tries the base reader, then the embedded style reader,
then `key`, `text` and `blend`. The style reader handles twelve keys:
`text_color`, `font`, `multiline`, `equalized`, `aligned`, `parse_enable`,
`align`, `clut`, `scale_x`, `scale_y`, `shadow` and `shadow_color`. The source
comment saying nine settings is stale; the actual body has twelve reads.
Property spelling was checked against the original string data.

Deep copy calls the Widget base copy, checks the source class, assigns the style,
copies the localized-text child through its virtual callback and copies the
`+0x108` word. It does not copy every trailing runtime word wholesale.

Additional existing dependencies include localized-text reference construction
`002B70B8`, localized-text operations, lookup `0025A7E0/0026A4D0`, font-manager
state and renderer setup `00247448`. These external dependencies are outside
the fresh 62-function body-check scope, except `00247448`, which is included.
This report does not claim host runtime coverage for them.

## Why Godot still stops

Read-only inspection of sibling Godot file
`native/gt4-menu/recovered/layout-properties/support.h`, function `load_record`,
finds an explicit class allowlist for RootWindow, Composite, MovieFace,
ColorFace, ImageFace, ScrollBox and SelectBox. TextFace is absent and therefore
throws `Native layout factory is not integrated for TextFace`.

This is an unimplemented host integration boundary, not a missing TextFace
matching body. The next menu implementation can reuse the verified constructor,
factory, copy and property bodies above with owned host storage and service
adapters. Font loading, lookup, text measurement/rendering, lifecycle and native
behavior still need their own evidence. No Godot files or runtime state were
changed, and no menu rendering success is claimed.

## Reproduction evidence

- [manifest.json](manifest.json): audited sources and normalized digests.
- [final-results.json](final-results.json): judge, body, padding and link results.
- [summary.json](summary.json): counts, original hashes and property strings.
- [verify.py](verify.py), [finalize.py](finalize.py): verification scripts.

Run the scripts from a prepared repository root with the existing original game
assets, compiler environment and validated upstream full-build snapshot. Copy
the scripts and manifest to `build/textface-review/`, run `verify.py`, then
`finalize.py`. The first script intentionally exits nonzero on the destructor's
unresolved literal; the second performs the additional literal placement check
and requires all 62 entries to be linked in the existing full build.
Raw game data and compiler outputs remain ignored under `build/`.
