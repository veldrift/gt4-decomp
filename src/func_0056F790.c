#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

s32 func_0056EA50(s32, M2C_UNK, void *, M2C_UNK, s32); /* extern */
s32 func_0056EB28(s32, s32, void *, M2C_UNK, s32);  /* extern */

s32 func_0056F790(s32 arg0, void *arg1, s32 arg2, s32 arg3, s32 arg4) {
    s32 var_v0;

    M2C_FIELD(arg1, s32 *, 4) = arg4;
    M2C_FIELD(arg1, s32 *, 0) = arg3;
    if (func_0056EA50(arg0, 0x11, arg1, 8, arg3 + 4) < 0) {
        return -0x21E;
    }
    var_v0 = func_0056EB28(arg0, arg2, arg1, 1, arg3);
    if (var_v0 >= 0) {
        var_v0 = M2C_FIELD(arg1, s32 *, 0);
    }
    return var_v0;
}
