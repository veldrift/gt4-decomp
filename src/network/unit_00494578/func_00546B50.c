#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

M2C_UNK func_00545558(M2C_UNK *, M2C_UNK *, M2C_UNK *, M2C_UNK *); /* extern */
M2C_UNK func_005A4724(M2C_UNK *, M2C_UNK *, M2C_UNK); /* extern */
M2C_UNK func_005A48D8(M2C_UNK *, M2C_UNK, M2C_UNK); /* extern */

void func_00546B50(M2C_UNK *arg0, M2C_UNK *arg1, M2C_UNK *arg2, M2C_UNK *arg3) {
    struct StackFrame_00546B50 { s8 pad0[0x40]; s32 sp40; s8 pad1[0x3C]; s32 sp80; s8 pad2[0x3C]; s32 spC0; s8 pad3[0x3C]; s32 sp100; s8 pad4[0x3C]; s32 sp140; s8 pad5[0x3C]; s32 sp180; s8 pad6[0x7C]; } sp_;

    func_005A4724(((s8 *)&sp_), arg1, 0x40);
    func_005A48D8(&sp_.sp40, 0, 0x40);
    func_005A4724(&sp_.sp80, arg0, 0x40);
    func_005A48D8(&sp_.spC0, 0, 0x40);
    func_005A4724(&sp_.sp100, arg2, 0x40);
    func_005A48D8(&sp_.sp140, 0, 0x40);
    func_00545558(&sp_.sp180, &sp_.sp100, ((s8 *)&sp_), &sp_.sp80);
    func_005A4724(arg3, &sp_.sp180, 0x40);
}
