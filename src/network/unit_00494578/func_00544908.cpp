#include "types.h"
#define NULL 0

s32 func_00544908(s32 arg0, s32 arg1) {
    s32 temp_v0;
    s32 var_a3;

    var_a3 = 0;
    do {
        temp_v0 = var_a3 * 4;
        var_a3 += 1;
        if (*(s32 *)(temp_v0 + arg0) != *(s32 *)(temp_v0 + arg1)) {
            return 0;
        }
    } while (var_a3 < 0x20);
    return 1;
}
