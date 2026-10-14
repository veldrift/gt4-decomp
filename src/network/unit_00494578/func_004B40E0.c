#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

M2C_UNK func_004B9978(s32, s32, void *);            /* extern */
s32 func_004BAA70(M2C_UNK, M2C_UNK, void *, M2C_UNK);                 /* extern */

s32 func_004B40E0(M2C_UNK arg0, M2C_UNK arg1, s32 arg2, s32 arg3) {
    struct StackFrame_004B40E0 { s8 pad0[0x100]; } sp_;
    s32 temp_s2;

    temp_s2 = func_004BAA70(arg0, arg1, ((s8 *)&sp_), 0x100);
    func_004B9978(arg2, arg3, ((s8 *)&sp_));
    return temp_s2;
}
