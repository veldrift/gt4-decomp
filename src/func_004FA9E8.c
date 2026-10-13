/* compiler: ee-gcc2.96-no-strict-aliasing */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

M2C_UNK func_004F9BD8(void *, s32, s32, u8, s32);   /* extern */
s32 func_00515998(void *, s32);                     /* extern */

void func_004FA9E8(void *arg0, s32 arg1, s32 arg2) {
    struct StackFrame_004FA9E8 { void * sp0; s8 pad0[0xC]; } sp_;
    u8 temp_a3;

    sp_.sp0 = NULL;
    M2C_FIELD(arg0, s32 *, 0xFD0) = (s32) (M2C_FIELD(arg0, s32 *, 0xFD0) + 1);
    if ((func_00515998(((s8 *)&sp_), arg2) == 0) && (sp_.sp0 != NULL)) {
        temp_a3 = M2C_FIELD(sp_.sp0, u8 *, 0);
        if ((temp_a3 == M2C_FIELD(arg0, s32 *, 0xCCC)) && (M2C_FIELD(arg0, s32 *, 0xCC0) == -1)) {
            M2C_FIELD(arg0, s32 *, 0xCC0) = arg2;
        }
        func_004F9BD8(arg0, arg2, arg1, temp_a3, M2C_FIELD(sp_.sp0, s32 *, 0x1C));
    }
}
