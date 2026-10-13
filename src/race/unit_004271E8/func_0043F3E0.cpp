#include "types.h"

s32 func_0043F3A8(s32, s32, s32);                   /* extern */
s32 func_0044A1B8(s32);                             /* extern */
s32 func_0044A208(s32);                             /* extern */

s32 func_0043F3E0(s32 arg0, s32 arg1, s32 arg2) {
    if (func_0044A208(arg1) == 0) {
        return 1;
    }
    if ((func_0044A1B8(arg1) == 0) < arg2) {
        return func_0043F3A8(arg0, arg1, arg2 - 1);
    }
    return 1;
}
