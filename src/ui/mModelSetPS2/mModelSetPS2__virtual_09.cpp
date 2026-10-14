#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

extern "C" {
s32 ModelSet2__render(s32, s32);                    /* extern */
s32 ModelSet2__texLOD(s32);                     /* extern */
s32 ModelSet2__texLevel(s32);                     /* extern */
s32 func_00456918(f32);                         /* extern */
s32 func_004A1638(s32);                     /* extern */
s32 func_004A19B0(s32);                     /* extern */
s32 pglFrontFace(s32);                     /* extern */
s32 func_004AB040(s32);                     /* extern */

struct mModelSetPS2__virtual_09_arg0 {
    char pad0[0x8];
    s32 unk8;
};

void mModelSetPS2__virtual_09(struct mModelSetPS2__virtual_09_arg0 *arg0, s32 arg1) {
    func_00456918(0x1.0000000000000p+0f);
    ModelSet2__texLOD(1);
    ModelSet2__texLevel(0);
    func_004A1638(0xF);
    pglFrontFace(arg1 != 0);
    func_004A19B0(2);
    ModelSet2__render(arg0->unk8, 0);
    func_004AB040(0xF);
}

}
