#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

M2C_UNK func_004F8820(s32, s32);                    /* extern */
s32 func_0052F7E8(void *);                          /* extern */

s32 func_004FB1E8(s32 arg0) {
    struct StackFrame_004FB1E8 { s32 sp0; s8 pad0[0xC]; } sp_;
    s32 temp_v0;

    temp_v0 = func_0052F7E8(((s8 *)&sp_));
    if (temp_v0 != 0) {
        func_004F8820(arg0, temp_v0);
        sp_.sp0 = 0;
    }
    return sp_.sp0;
}
