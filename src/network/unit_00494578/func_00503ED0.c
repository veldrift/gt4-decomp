/* compiler: ee-gcc2.96-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

s32 func_005038F0();                        /* extern */

void func_00503ED0(s32 arg0, s32 arg1) {
    if (func_005038F0(arg0 + 0x3C) == 0) {
        func_005038F0(arg0 + 0x48, arg1);
    }
}
