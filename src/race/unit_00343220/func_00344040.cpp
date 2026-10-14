/* compiler: ee-gcc2.96-no-strict-aliasing */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

extern "C" u8 *func_00359510(void *);                          /* extern */
extern "C" void *func_00359F50(void *);                        /* extern */
extern "C" s32 func_0035A080(void *);                          /* extern */
extern "C" f32 func_0035A540(void *, M2C_UNK);                 /* extern */
extern "C" void func_0035A618(void *, s32, f32);        /* extern */

extern float D_0062075C, D_00620760;
struct Coeff { char pad[0x2C0]; float values[256]; };
static inline float *angle(char *p, int offset) { return (float *)((int)(p + 0x10) + offset); }
extern "C" void func_00344040(char *arg0) {
    f32 *temp_v0;
    f32 *temp_v0_2;
    f32 temp_f1;
    f32 temp_f1_2;
    f32 temp_f1_3;
    f32 temp_f20;
    f32 temp_f2;
    f32 var_f0;
    f32 var_f0_2;
    f32 var_f0_3;
    f32 var_f1;
    f32 var_f1_2;
    f32 var_f2;
    f32 var_f2_2;
    s32 var_a2;
    s32 var_a3;
    s32 var_a4;
    s32 var_v0;
    u8 *temp_a5;
    u8 *var_a1;
    u8 temp_v1;
    u8 var_v1;
    char *temp_s1;
    char *temp_s2;
    char *var_a0;

    temp_s1 = arg0 + 0x104;
    temp_s2 = M2C_FIELD(arg0, char **, 0x10);
    temp_a5 = func_00359510(temp_s2);
    float dt = M2C_FIELD(arg0, f32 *, 0x54C);
    temp_f1 = M2C_FIELD(temp_s1, f32 *, 0x570);
    if (temp_f1 >= 0x1.921fb40000000p+2f) {
        temp_f1 -= 0x1.921fb40000000p+2f;
        M2C_FIELD(temp_s1, f32 *, 0x570) = temp_f1;
        var_f0 = M2C_FIELD(arg0, f32 *, 0x8C4) - 0x1.921fb40000000p+2f;
        M2C_FIELD(arg0, f32 *, 0x8C4) = var_f0;
    }
    else if (temp_f1 <= -0x1.921fb40000000p+2f) {
        temp_f1 += 0x1.921fb40000000p+2f;
        M2C_FIELD(temp_s1, f32 *, 0x570) = temp_f1;
        var_f0 = M2C_FIELD(arg0, f32 *, 0x8C4) + 0x1.921fb40000000p+2f;
        M2C_FIELD(arg0, f32 *, 0x8C4) = var_f0;
    }
    temp_v1 = M2C_FIELD(temp_a5, u8 *, 1);
    var_a2 = 0;
    if (temp_v1 != 0) {
        Coeff *coeff = (Coeff *)(temp_s2 + 0xC);
        var_a4 = 0x900;
        var_a3 = 0x900;
        var_a1 = temp_a5 + 0x14;
        var_a0 = arg0 + 0x164;
        var_v0 = (s32) temp_v1 > 0;
        do {
            var_v1 = 0;
            if (var_a2 < (s32)temp_a5[1]) {
                var_v1 = *var_a1;
            }
            var_f1 = M2C_FIELD(var_a0, f32 *, 0x20) * coeff->values[var_v1] * dt;
            if (M2C_FIELD(temp_s1, u8 *, 0x4BC) != 0) {
                var_f1 = 0x0.0p+0f;
            }
            var_f0_2 = M2C_FIELD(var_a0, f32 *, 0x24) + var_f1;
            while (var_f0_2 >= 0x1.921fb40000000p+2f) {
                var_f0_2 -= 0x1.921fb40000000p+2f;
                *angle(arg0, var_a3) -= 0x1.921fb40000000p+2f;
            }
            while (var_f0_2 <= -0x1.921fb40000000p+2f) {
                var_f0_2 += 0x1.921fb40000000p+2f;
                *angle(arg0, var_a4) += 0x1.921fb40000000p+2f;
            }
            M2C_FIELD(var_a0, f32 *, 0x24) = var_f0_2;
            var_a0 += 0xEC;
            var_a2 += 1;
            var_a4 += 4;
            var_a3 += 4;
            var_v0 = var_a2 < (s32) M2C_FIELD(temp_a5, u8 *, 1);
            var_a1 += 1;
        } while (var_v0 != 0);
    }
    temp_f20 = M2C_FIELD(temp_s2, f32 *, 0x50);
    M2C_FIELD(arg0, f32 *, 0x8A4) = (f32) M2C_FIELD(arg0, f32 *, 0x888);
    M2C_FIELD(arg0, f32 *, 0x8A8) = (f32) M2C_FIELD(arg0, f32 *, 0x88C);
    M2C_FIELD(arg0, f32 *, 0x8AC) = (f32) M2C_FIELD(arg0, f32 *, 0x890);
    M2C_FIELD(arg0, f32 *, 0x888) = (f32) (M2C_FIELD(temp_s1, f32 *, 0) - (temp_f20 * M2C_FIELD(temp_s1, f32 *, 0xC)));
    M2C_FIELD(arg0, f32 *, 0x88C) = (f32) (M2C_FIELD(temp_s1, f32 *, 8) - (temp_f20 * M2C_FIELD(temp_s1, f32 *, 0x14)));
    M2C_FIELD(arg0, f32 *, 0x890) = (f32) -(M2C_FIELD(temp_s1, f32 *, 4) - (temp_f20 * M2C_FIELD(temp_s1, f32 *, 0x10)));
    if (func_0035A080(temp_s2) != 0) {
        temp_f1_2 = (M2C_FIELD(temp_s2, f32 *, 0x2C8) - M2C_FIELD(func_00359F50(arg0), f32 *, 0x10)) - M2C_FIELD(temp_s2, f32 *, 0x3C);
        M2C_FIELD(arg0, f32 *, 0x888) = (f32) (M2C_FIELD(arg0, f32 *, 0x888) + (temp_f1_2 * M2C_FIELD(temp_s1, f32 *, 0x24)));
        M2C_FIELD(arg0, f32 *, 0x88C) = (f32) (M2C_FIELD(arg0, f32 *, 0x88C) + (temp_f1_2 * M2C_FIELD(temp_s1, f32 *, 0x2C)));
        M2C_FIELD(arg0, f32 *, 0x890) = (f32) (M2C_FIELD(arg0, f32 *, 0x890) + (temp_f1_2 * M2C_FIELD(temp_s1, f32 *, 0x28)));
    }
    M2C_FIELD(arg0, f32 *, 0x8B0) = (f32) M2C_FIELD(arg0, f32 *, 0x894);
    M2C_FIELD(arg0, f32 *, 0x8B4) = (f32) M2C_FIELD(arg0, f32 *, 0x898);
    M2C_FIELD(arg0, f32 *, 0x8B8) = (f32) M2C_FIELD(arg0, f32 *, 0x89C);
    M2C_FIELD(arg0, f32 *, 0x894) = (f32) (M2C_FIELD(temp_s1, f32 *, 0x30) - (temp_f20 * M2C_FIELD(temp_s1, f32 *, 0x3C)));
    M2C_FIELD(arg0, f32 *, 0x898) = (f32) (M2C_FIELD(temp_s1, f32 *, 0x38) - (temp_f20 * M2C_FIELD(temp_s1, f32 *, 0x44)));
    M2C_FIELD(arg0, f32 *, 0x89C) = (f32) -(M2C_FIELD(temp_s1, f32 *, 0x34) - (temp_f20 * M2C_FIELD(temp_s1, f32 *, 0x40)));
    M2C_FIELD(arg0, f32 *, 0x990) = (f32) M2C_FIELD(arg0, f32 *, 0x8A0);
    if (*func_00359510(temp_s2) == 1) {
        var_f1_2 = 0.5f - (M2C_FIELD(temp_s1, f32 *, 0x65C) * 0.5f);
    } else {
        var_f1_2 = 0.5f - ((M2C_FIELD(temp_s1, f32 *, 0x468) / M2C_FIELD(temp_s2, f32 *, 0x54)) * 0.5f);
    }
    var_f0_3 = 0x0.0p+0f;
    if ((var_f1_2 < 0x0.0p+0f) || (var_f0_3 = 0x1.0000000000000p+0f, (var_f1_2 > 0x1.0000000000000p+0f))) {
        var_f1_2 = var_f0_3;
    }
    M2C_FIELD(arg0, f32 *, 0x8A0) = var_f1_2;
    temp_f20 = 1.0f;
    float old2 = func_0035A540(arg0, 2);
    temp_f2 = D_0062075C;
    func_0035A618(arg0, 2, (M2C_FIELD(temp_s1, f32 *, 0x494) * temp_f2) + (old2 * (temp_f20 - temp_f2)));
    float old3 = func_0035A540(arg0, 3);
    float target3 = M2C_FIELD(temp_s1, f32 *, 0x48C);
    temp_f1_3 = D_00620760;
    temp_f20 -= temp_f1_3;
    func_0035A618(arg0, 3, (target3 * temp_f1_3) + (old3 * temp_f20));
}
