#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

union AliasAny { s8 b; u8 ub; s16 h; u16 uh; s32 w; u32 uw; s64 d; f32 f; };
extern char D_006201C8[];
void func_00336338(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2, M2C_UNK arg3, M2C_UNK arg4, M2C_UNK arg5, M2C_UNK arg6) {
    M2C_FIELD(*(void **)(s32)D_006201C8, union AliasAny *, 0xE46C).w = 1;
    M2C_FIELD(*(void **)(s32)D_006201C8, s32 *, 0xE470) = 0;
}
