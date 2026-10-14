#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_004F0C88();                                /* extern */
s32 func_004F0CD0(s32, s32);                    /* extern */

s32 func_004F1630(s32 arg0) {
    s32 var_v0;

    if (func_004F0C88() != 0) {
        var_v0 = func_004F0CD0(arg0, 5) != 0;
    } else {
        var_v0 = 0;
    }
    return var_v0;
}
