/* compiler: ee-gcc2.96-no-strict-aliasing */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

extern "C" f32 func_00344798(void *, f32);                    /* extern */
extern "C" f32 func_003447F8(void *, f32);                    /* extern */
extern "C" f32 func_00344828(void *, f32);                    /* extern */
extern "C" f32 func_00344858(void *, f32);                    /* extern */
extern "C" f32 func_00344888(void *, f32);                    /* extern */
extern "C" f32 func_003448B8(void *, f32);                    /* extern */
extern "C" f32 func_00384B28(void *);                          /* extern */
extern "C" f32 func_00384BC8(void *);                          /* extern */
extern "C" void func_004A7844(f32, f32, f32);               /* extern */
extern "C" void func_004A7988(f32);                         /* extern */
extern "C" void func_004A79B0(f32);                         /* extern */
extern "C" void func_004A79D8(f32);                         /* extern */
extern "C" f32 func_0057D008(f32);                             /* extern */

struct VEntry { short delta; short index; int (*fn)(void *); };
struct PEntry { short delta; short index; void *(*fn)(void *); };
struct Obj { char pad[0xC]; float value; char pad2[0x260-0x10]; s64 flags; };
static inline int kind(char *o) {
    VEntry *e = (VEntry *)(*(char **)o + 0xB8);
    return e->fn(o + e->delta);
}
static inline void set_value(char *p, float v) {
    Obj *o = (Obj *)p;
    float *dst = &o->value;
    *dst = v;
    s64 bits = 0x8000LL << 33;
    s64 mask = ~(0xFFLL << 48);
    o->flags = (o->flags & mask) | bits;
}
extern "C" void func_0037B580(char *arg0) {
    f32 sp0;
    f32 temp_f20;
    f32 temp_f21;
    f32 temp_f29;
    f32 temp_f30;
    f32 temp_f31;
    f32 var_f23;
    f32 var_f24;
    f32 var_f25;
    f32 var_f26;
    f32 var_f27;
    f32 var_f28;
    s64 temp_a2;
    void *temp_s2;
    s32 var_v1;
    s64 temp_a1_2;
    char *temp_a1;
    void *temp_s0;
    char *temp_s0_2;
    void *temp_v0;
    void *temp_v1;
    void *temp_v1_2;
    void *temp_v1_3;

    var_f28 = 0x0.0p+0f;
    temp_v0 = M2C_FIELD(arg0, void **, 0x18C);
    temp_a1 = M2C_FIELD(temp_v0, char **, 0x2880);
    temp_s2 = M2C_FIELD(temp_v0, void **, 0x18);
    PEntry *pe = (PEntry *)(M2C_FIELD(temp_a1, char **, 8) + 0x50);
    temp_s0 = pe->fn(temp_a1 + pe->delta);
    temp_s0_2 = M2C_FIELD(temp_s0, char **, 0x44) + (kind(arg0) << 5);
    var_f26 = M2C_FIELD(temp_s0_2, f32 *, 0);
    var_f27 = M2C_FIELD(temp_s0_2, f32 *, 4);
    sp0 = M2C_FIELD(temp_s0_2, f32 *, 8);
    var_f24 = M2C_FIELD(temp_s0_2, f32 *, 0xC);
    var_f23 = M2C_FIELD(temp_s0_2, f32 *, 0x10);
    var_f25 = M2C_FIELD(temp_s0_2, f32 *, 0x14);
    temp_f31 = func_00344888(temp_s2, 0) * 0x1.ca5dc00000000p+5f;
    temp_f30 = -func_00344858(temp_s2, 0) * 0x1.ca5dc00000000p+5f;
    temp_f29 = -func_003448B8(temp_s2, 0) * 0x1.ca5dc00000000p+5f;
    if (!(M2C_FIELD(temp_s0_2, s32 *, 0x1C) & 4) || (M2C_FIELD(arg0, u8 *, 0x265) != 0)) {
        func_004A7988(func_00384B28(arg0 + 0x1B8) * 0x1.6666660000000p-1f);
        func_004A79B0(func_00384B28(arg0 + 0x1C4) * 0x1.6666660000000p-1f);
        var_f26 += 0x1.0000000000000p+1f * func_00384BC8(arg0 + 0x1D0);
        var_f27 += 0x1.0000000000000p+1f * func_00384BC8(arg0 + 0x1DC);
    }
    var_v1 = 0;
    if ((M2C_FIELD(arg0, u8 *, 0x26B) != 0) || (M2C_FIELD(arg0, u8 *, 0x269) != 0)) {
        var_v1 = 1;
    }
    if (var_v1 != 0) {
        if (kind(arg0) == 6) {
            var_f24 = -var_f24;
            var_f25 = -var_f25;
            var_f23 += 0x1.6800000000000p+7f;
            var_f28 = 0x1.6800000000000p+7f;
        }
    }
    func_004A79D8(var_f25);
    func_004A7988(var_f24);
    func_004A79B0(var_f23);
    func_004A7844(var_f26, var_f27, sp0);
    func_004A79D8(temp_f31);
    func_004A7988(temp_f30);
    func_004A79B0(temp_f29);
    temp_f21 = -func_00344798(temp_s2, 0);
    temp_f20 = -func_003447F8(temp_s2, 0);
    func_004A7844(temp_f21, temp_f20, -func_00344828(temp_s2, 0));
    M2C_FIELD(arg0, f32 *, 0x4C) = var_f23;
    M2C_FIELD(arg0, f32 *, 0x50) = var_f24;
    M2C_FIELD(arg0, f32 *, 0x54) = var_f25;
    M2C_FIELD(arg0, f32 *, 0x40) = var_f26;
    M2C_FIELD(arg0, f32 *, 0x44) = var_f27;
    M2C_FIELD(arg0, f32 *, 0x48) = sp0;
    M2C_FIELD(arg0, f32 *, 0x34) = temp_f29;
    M2C_FIELD(arg0, f32 *, 0x38) = temp_f30;
    M2C_FIELD(arg0, f32 *, 0x3C) = temp_f31;
    M2C_FIELD(arg0, f32 *, 0x28) = (f32) -func_00344798(temp_s2, 0);
    M2C_FIELD(arg0, f32 *, 0x2C) = (f32) -func_003447F8(temp_s2, 0);
    M2C_FIELD(arg0, f32 *, 0x30) = (f32) -func_00344828(temp_s2, 0);
    float angle = M2C_FIELD(temp_s0_2, f32 *, 0x10) + var_f28;
    M2C_FIELD(arg0, f32 *, 8) = 0x1.9000000000000p+6f;
    M2C_FIELD(arg0, f32 *, 0x278) = angle;
    set_value(arg0, (2.0f * func_0057D008(1.0f / M2C_FIELD(temp_s0_2, f32 *, 0x18))) / 0x1.1df468p-6f);
    if (M2C_FIELD(arg0, u8 *, 0x267) != 0) {
        set_value(arg0, M2C_FIELD(arg0, f32 *, 0x188));
    }
}
