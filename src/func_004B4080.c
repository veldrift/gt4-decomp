#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_004B9978(s32, s32, void *);              /* extern */
s32 func_004BA700(s32, void *, s32, u8);            /* extern */

s32 func_004B4080(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s8 sp[0x100];
    s32 temp_s0;

    temp_s0 = func_004BA700(arg0, sp, 0x100, arg3 & 0xFF);
    func_004B9978(arg1, arg2, sp);
    return temp_s0;
}
