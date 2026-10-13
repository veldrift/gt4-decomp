/* compiler: ee-gcc2.96-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

M2C_UNK func_00145FE8(s32, s32, s32, s32);          /* extern */
f32 func_001465D8();                                /* extern */
f32 func_004729A0(M2C_UNK, f32);                    /* extern */

extern char D_006244D8[];
void func_00146128(s32 arg0, s32 arg1, s32 arg2) {
    func_00145FE8(arg0, arg1, arg2, (s32) (func_004729A0((s32)D_006244D8, func_001465D8()) + 0x1.0000000000000p-1f));
}
