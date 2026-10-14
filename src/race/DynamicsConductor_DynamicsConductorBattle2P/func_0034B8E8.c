#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

M2C_UNK func_00343490(M2C_UNK *);                   /* extern */
M2C_UNK func_0034ACA8(s32, void *, M2C_UNK *, M2C_UNK); /* extern */
M2C_UNK func_0034B808(void *, M2C_UNK *, s32);      /* extern */
M2C_UNK func_0034EF30(M2C_UNK *, s32, M2C_UNK, M2C_UNK); /* extern */

void func_0034B8E8(s32 arg0, s32 arg1) {
    struct StackFrame_0034B8E8 { s8 pad0[0xE0]; s32 spE0; s8 pad1[0xFC]; s32 sp1E0; s8 pad2[0x1C]; } sp_;

    func_00343490(&sp_.sp1E0);
    func_0034EF30(&sp_.spE0, arg0, 0, 0);
    func_0034ACA8(arg0, ((s8 *)&sp_), &sp_.spE0, 0);
    func_0034B808(((s8 *)&sp_), &sp_.spE0, arg1);
}
