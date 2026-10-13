#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

M2C_UNK func_00612B48(void *, s32, s32, s32);       /* extern */

s32 func_00612A98(void *arg0, s32 arg1, s32 arg2) {
    s32 temp_a3;
    s32 temp_s0;

    temp_a3 = M2C_FIELD(arg0, s32 *, 8);
    temp_s0 = (temp_a3 < arg2) ? temp_a3 : arg2;
    func_00612B48(arg0, arg1, M2C_FIELD(arg0, s32 *, 0x1C), temp_s0);
    return temp_s0;
}
