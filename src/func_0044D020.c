#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

s32 func_0057F260(s32);                             /* extern */

extern char D_0062382C[];
s32 func_0044D020(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2, M2C_UNK arg3, M2C_UNK arg4, M2C_UNK arg5, M2C_UNK arg6) {
    return (func_0057F260(*(s32 *)D_0062382C) + 0x50) & ~0x3F;
}
