#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

s32 func_0052F7E8(void *);                          /* extern */
M2C_UNK func_005D4AD8(M2C_UNK, M2C_UNK, s32);       /* extern */

extern char D_00696C70[];
extern char D_00696C80[];
s32 func_001F5258(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2, M2C_UNK arg3, M2C_UNK arg4, M2C_UNK arg5, M2C_UNK arg6) {
    struct StackFrame_001F5258 { s32 sp0; s8 pad0[0xC]; } sp_;
    s32 temp_v0;

    sp_.sp0 = 0;
    temp_v0 = func_0052F7E8(((s8 *)&sp_));
    if (temp_v0 == 0) {
        return sp_.sp0;
    }
    func_005D4AD8((s32)D_00696C80, (s32)D_00696C70, temp_v0);
    return -1;
}
