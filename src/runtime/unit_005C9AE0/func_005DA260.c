#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00328860(s32, s32);                /* extern */
s32 func_005C1628(s32 *);                       /* extern */

extern char D_00664018[];
void func_005DA260(s32 *arg0, s32 arg1) {
    s32 temp_a0;
    s32 var_s0;

    if (arg0 != (s32 *)-4) {
        var_s0 = arg0 + 0x191;
        if (arg0 + 1 != var_s0) {
            do {
                temp_a0 = var_s0 - 0x50;
                func_00328860(temp_a0, 2);
                var_s0 = temp_a0;
            } while (arg0 + 1 != var_s0);
        }
    }
    *arg0 = (s32)D_00664018;
    if (arg1 & 1) {
        func_005C1628(arg0);
    }
}
