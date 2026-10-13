#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_0056EA50(s32, s32, void *, s32, s32);   /* extern */

s32 func_0056F868(s32 arg0, s32 *arg1, s32 arg2) {
    s32 var_v0;

    *arg1 = arg2;
    var_v0 = func_0056EA50(arg0, 0x32, arg1, 4, 4);
    if (var_v0 < 0) {
        return -0x21E;
    }
    return *arg1;
}
