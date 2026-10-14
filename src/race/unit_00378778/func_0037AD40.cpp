/* compiler: ee-gcc2.96-no-strict-aliasing */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

extern "C" s32 Automobile__isFullManualTransmission(void *);                             /* extern */
extern "C" s32 func_0037ACD0(s32) throw();                             /* extern */
extern "C" s32 func_0037AD10(s32, s32) throw();                         /* extern */
extern "C" void func_0037BC20(void *, s32);                 /* extern */

struct VEntry { s16 delta; s16 index; s32 (*fn)(void *); };
static inline s32 gettype(char *p) { VEntry *e = (VEntry *)(M2C_FIELD(p, char **, 0) + 0xB8); return e->fn(p + e->delta); }

extern "C" s32 func_0037AD40(char *arg0, char *arg1) {
    f32 temp_f4;
    f32 var_f3;
    s64 temp_a0;
    s32 temp_s3;
    s32 temp_v0;
    s32 temp_v0_2;
    s32 var_a1;
    s32 var_s4;
    s32 var_v1;
    s32 var_v1_2;
    s64 temp_v1;
    s8 temp_s0;
    s32 temp_s0_2;
    void *temp_v1_2;
    void *temp_v1_3;

    var_s4 = 0;
    temp_s0 = M2C_FIELD(arg1, s8 *, 0x19);
    temp_s3 = Automobile__isFullManualTransmission(M2C_FIELD(M2C_FIELD(arg0, void **, 0x18C), void **, 0x18)) == 0;
    temp_s0_2 = (M2C_FIELD(arg0, u8 *, 0x26A) == 0) ? 0 : temp_s0;
    if (temp_s0_2 != 0) {
        var_s4 = 1;
        func_0037BC20(arg0, func_0037AD10(func_0037ACD0(M2C_FIELD(arg0, s32 *, 0x180)), temp_s0_2));
        s64 cleared = M2C_FIELD(arg0, s64 *, 0x168) & (~(0xFFLL << 24));
        M2C_FIELD(arg0, f32 *, 0x274) = 0x0.0p+0f;
        M2C_FIELD(arg0, s64 *, 0x168) = cleared;
    }
    if (M2C_FIELD(arg0, u8 *, 0x26A) != 0) {
        var_a1 = 0;
        if ((M2C_FIELD(arg0, u8 *, 0x26B) != 0) || (M2C_FIELD(arg0, u8 *, 0x269) != 0)) {
            var_a1 = 1;
        }
        temp_a0 = (~(0xFFLL << 24));
        temp_v1 = M2C_FIELD(arg0, s64 *, 0x268) & temp_a0;
        M2C_FIELD(arg0, s64 *, 0x268) = temp_v1;
        if (M2C_FIELD(arg1, u8 *, 0x18) != 0) {
            M2C_FIELD(arg0, s64 *, 0x268) = (s64) ((temp_v1 & temp_a0) | 0x01000000);
        }
        if ((temp_s3 != 0) && (M2C_FIELD(arg1, u8 *, 0x1D) != 0)) {
            M2C_FIELD(arg0, s64 *, 0x268) = (s64) ((M2C_FIELD(arg0, s64 *, 0x268) & temp_a0) | 0x01000000);
        }
        var_v1 = 0;
        if ((M2C_FIELD(arg0, u8 *, 0x26B) != 0) || (M2C_FIELD(arg0, u8 *, 0x269) != 0)) {
            var_v1 = 1;
        }
        if (var_a1 != var_v1) {
            M2C_FIELD(arg0, f32 *, 0x274) = 0x0.0p+0f;
            var_s4 = 1;
            M2C_FIELD(arg0, s64 *, 0x168) = (s64) (M2C_FIELD(arg0, s64 *, 0x168) & (~(0xFFLL << 24)));
        }
    }
    M2C_FIELD(arg0, s64 *, 0x268) = (s64) (M2C_FIELD(arg0, s64 *, 0x268) & (~(0xFFLL << 40)));
    temp_v0 = gettype(arg0);
    if ((temp_v0 == 0) || (temp_v0 == 0x19)) {
        var_v1_2 = 0;
        if ((M2C_FIELD(arg0, u8 *, 0x26B) != 0) || (M2C_FIELD(arg0, u8 *, 0x269) != 0)) {
            var_v1_2 = 1;
        }
        if (var_v1_2 == 0) {
            M2C_FIELD(arg0, s64 *, 0x268) = (s64) ((M2C_FIELD(arg0, s64 *, 0x268) & (~(0xFFLL << 40))) | (0x8000LL << 0x19));
        }
    }
    if ((temp_s3 != 0) && (M2C_FIELD(arg0, u8 *, 0x26A) != 0) && ((temp_v0_2 = gettype(arg0), (temp_v0_2 == 0)) || (temp_v0_2 == 0x19))) {
        var_f3 = 0x0.0p+0f;
        temp_f4 = M2C_FIELD(arg0, f32 *, 0x274);
        if (M2C_FIELD(arg1, u8 *, 0x1A) != 0) {
            var_f3 = -0x1.e000000000000p+5f;
        }
        if (M2C_FIELD(arg1, u8 *, 0x1B) != 0) {
            var_f3 = 0x1.e000000000000p+5f;
        }
        M2C_FIELD(arg0, f32 *, 0x274) = (f32) (temp_f4 + ((var_f3 - temp_f4) * 0x1.9999960000000p-3f));
        if (var_f3 != 0x0.0p+0f) {
            M2C_FIELD(arg0, s64 *, 0x268) = (s64) (M2C_FIELD(arg0, s64 *, 0x268) & (~(0xFFLL << 40)));
        }
    }
    return var_s4;
}
