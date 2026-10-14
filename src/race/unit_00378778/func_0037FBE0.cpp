/* compiler: ee-gcc2.96-no-strict-aliasing */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

extern "C" f32 func_0036EA50(void *) throw();                       /* extern */
extern "C" f32 func_0036EA98(void *) throw();                       /* extern */
extern "C" f32 func_0036EB98(f32, f32) throw();                        /* extern */
extern "C" void func_00378CB8(void *) throw();                            /* extern */
extern "C" void func_003FC618(s32, void *);                 /* extern */
extern "C" void func_003FC658(s32, void *);                 /* extern */
extern "C" f32 func_0057D008(f32);                             /* extern */
extern "C" void func_005F5040(void *, void *);           /* extern */
extern "C" void func_005F5268(void *, void *);        /* extern */

struct Pair { unsigned char value, limit; };
static inline void init(Pair *p, int limit) { p->limit = limit; p->value = 0; }
static inline void init2(Pair *p, int limit) { p->value = 0; p->limit = limit; }
extern "C" void func_0037FBE0(char *arg0, s32 arg1, s32 arg2, char *arg3, f32 fparg0) {
    struct StackFrame_0037FBE0 { s8 pad0[0x10]; s32 sp10; s8 pad1[0xC]; s32 sp20; s8 pad2[0xC]; } sp_;
    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_f20;
    f32 temp_f20_2;
    s32 *var_a0;
    s32 var_a1;
    void *temp_s2;
    void *temp_s3;

    func_00378CB8(arg0);
    M2C_FIELD(arg0, s32 *, 0x148) = 0xB;
    temp_s2 = arg0 + 0x188;
    float f44 = M2C_FIELD(arg3, f32 *, 0x44);
    M2C_FIELD(arg3, s32 *, 0x6C) = (s32) (M2C_FIELD(arg3, s32 *, 0x6C) & 0xFFFFFF);
    M2C_FIELD(arg0, f32 *, 8) = f44;
    M2C_FIELD(arg0, f32 *, 0x74) = (f32) M2C_FIELD(arg3, f32 *, 0x44);
    M2C_FIELD(arg0, s32 *, 0x180) = arg2;
    func_003FC618(arg1, temp_s2);
    temp_s3 = arg0 + 0x194;
    func_003FC658(arg1, temp_s3);
    M2C_FIELD(arg0, void **, 0x184) = arg3;
    M2C_FIELD(arg0, f32 *, 0x1AC) = fparg0;
    void *p10 = &sp_.sp10;
    void *p20 = &sp_.sp20;
    func_005F5040(arg3 + 4, ((s8 *)&sp_));
    func_005F5040(temp_s2, p10);
    func_005F5268(p10, ((s8 *)&sp_));
    func_005F5040(temp_s3, p20);
    func_005F5268(p20, ((s8 *)&sp_));
    temp_f20 = func_0036EA98(p20);
    M2C_FIELD(arg0, f32 *, 0x1A0) = func_0036EB98(temp_f20, func_0036EA98(&sp_.sp10));
    temp_f20_2 = func_0036EA50(p20);
    temp_f0 = func_0036EB98(temp_f20_2, func_0036EA50(&sp_.sp10));
    M2C_FIELD(arg0, s32 *, 0x1A8) = 0;
    M2C_FIELD(arg0, f32 *, 0x1A4) = temp_f0;
    if (M2C_FIELD(arg3, u8 *, 0x6E) == 0) {
        temp_f0_2 = (0x1.0000000000000p+1f * func_0057D008(0x1.0000000000000p+0f / ((0x1.0000000000000p+1f * M2C_FIELD(arg3, f32 *, 0x20)) / 0x1.6666660000000p-1f))) / 0x1.1df4680000000p-6f;
        M2C_FIELD(arg3, f32 *, 0x68) = temp_f0_2;
        if (temp_f0_2 < 0x1.0000000000000p+1f) {
            M2C_FIELD(arg3, f32 *, 0x68) = 0x1.0000000000000p+1f;
        }
        M2C_FIELD(arg3, s32 *, 0x6C) = (s32) (M2C_FIELD(arg3, s32 *, 0x6C) & ~0xFF);
        M2C_FIELD(arg3, s8 *, 0x6D) = 0;
        M2C_FIELD(arg3, s32 *, 0x6C) = (s32) ((M2C_FIELD(arg3, s32 *, 0x6C) & 0xFF00FFFF) | 0x10000);
    }
    init2((Pair *)(arg0 + 0x1B0), 0x12);
    init2((Pair *)(arg0 + 0x1B2), 0x12);
    var_a0 = (s32 *)(arg0 + 0x1CC);
    init((Pair *)(arg0 + 0x1B4), 0x12);
    var_a1 = 3;
    init((Pair *)(arg0 + 0x1B6), 0x1E);
    M2C_FIELD(arg0, s8 *, 0x1B8) = 0;
    s64 flags = M2C_FIELD(arg0, s64 *, 0x1B8) & (s64)(s32)0xFFFF00FF;
    flags &= (s64)(s32)0xFF00FFFF;
    flags &= ((((-1LL << 16) | 0xFF) << 16) | 0xFFFF);
    flags &= ((((-0x100LL << 16) | 0xFFFF) << 16) | 0xFFFF);
    flags &= ((((0xFFFF00FFLL << 16) | 0xFFFF) << 16) | 0xFFFF);
    M2C_FIELD(arg0, s64 *, 0x1B8) = flags;
    do {
        var_a1 -= 1;
        *var_a0 = 0;
        var_a0--;
    } while (var_a1 >= 0);
    M2C_FIELD(arg0, s64 *, 0x168) = (M2C_FIELD(arg0, s64 *, 0x168) & (s64)(s32)0xFF00FFFF) | 0x10000;
    M2C_FIELD(arg0, s32 *, 0xEC) = 0x4000;
    M2C_FIELD(arg0, s32 *, 0x1E0) = 0;
    M2C_FIELD(arg0, s32 *, 0x1E4) = 0;
    M2C_FIELD(arg0, s32 *, 0x1E8) = 0;
    M2C_FIELD(arg0, s32 *, 0x1DC) = 1;
    M2C_FIELD(arg0, s32 *, 0xE8) = 1;
}
