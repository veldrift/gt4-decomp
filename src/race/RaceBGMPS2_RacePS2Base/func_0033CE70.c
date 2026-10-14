#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

union AliasAny { s8 b; u8 ub; s16 h; u16 uh; s32 w; u32 uw; s64 d; f32 f; };
M2C_UNK func_0033CE70(void *arg0, s32 arg1, s32 arg2) {
    M2C_FIELD(arg0, union AliasAny *, 0xCF34).w = arg2;
    M2C_FIELD(M2C_FIELD(M2C_FIELD(arg0, void **, 0x6C), void **, 0x80), s32 *, 0xB4) = arg1;
}
