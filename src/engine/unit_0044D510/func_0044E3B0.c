#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

union AliasAny { s8 b; u8 ub; s16 h; u16 uh; s32 w; u32 uw; s64 d; f32 f; };
extern char PDISTD__global_font_manager[];
M2C_UNK func_0044E3B0(void *arg0, s32 arg1, s32 arg2) {
    void *temp_v1;

    M2C_FIELD(arg0, union AliasAny *, 0x30).w = arg1;
    M2C_FIELD(arg0, union AliasAny *, 0x34).w = arg2;
    temp_v1 = *(void **)PDISTD__global_font_manager;
    M2C_FIELD(temp_v1, f32 *, 0x1C) = (f32) arg1;
    M2C_FIELD(temp_v1, f32 *, 0x20) = (f32) arg2;
}
