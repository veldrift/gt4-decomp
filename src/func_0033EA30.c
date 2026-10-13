/* compiler: ee-gcc2.96-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

M2C_UNK func_001054D8(s32, s32, s32, s32, s32);     /* extern */

void func_0033EA30(void *arg0, s32 arg1) {
    if (M2C_FIELD(arg0, s32 *, 0xE304) != 0) {
        func_001054D8(arg1, (s32) M2C_FIELD(arg0, f32 *, 0xE2F4), (s32) M2C_FIELD(arg0, f32 *, 0xE2F8), (s32) M2C_FIELD(arg0, f32 *, 0xE2FC), (s32) M2C_FIELD(arg0, f32 *, 0xE300));
    }
}
