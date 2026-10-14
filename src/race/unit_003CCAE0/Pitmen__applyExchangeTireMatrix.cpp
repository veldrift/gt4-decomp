/* compiler: ee-gcc2.96-nogcse */
#include "types.h"
#include "m2c_macros.h"
extern char D_006A2F18[], D_006A2F20[];
extern "C" f32 func_00344DA8(s32, s32, f32);
extern "C" f32 func_00344DF8(s32, s32, f32);
extern "C" f32 func_00344E48(s32, s32, f32);
extern "C" s32 func_0034C190(s32, s32);
extern "C" s32 func_00359538(s32);
extern "C" void func_003C9F00(s32, s32) throw();
extern "C" void *func_003C9F18(char *) throw();
extern "C" s32 func_003CD900(s32, s32, s32) throw();
extern "C" void func_003D1488(s32, s32, s32, void *, s32, s32) throw();
extern "C" s32 func_003D3030(s32);
extern "C" void func_004A7988(f32);
extern "C" void func_004A79B0(f32);
extern "C" void func_004A79D8(f32);
extern "C" void Pitmen__applyExchangeTireMatrix(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    char *var_a0;
    f32 temp_f20;
    f32 temp_f21;
    f32 temp_f23;
    f32 temp_f24;
    f32 temp_f25;
    f32 var_f1;
    f32 var_f20;
    f32 var_f22;
    s32 temp_s1;
    s32 temp_s3;
    s32 temp_s5;
    s32 temp_s7;
    s32 var_a0_2;
    s32 var_fp;
    s32 var_v0;
    void *temp_s0;
    s32 temp_v1;

    if ((func_003D3030(arg0) == 0) && (arg1 >= 0)) {
        func_003C9F00((arg3 * 0xAA4) + arg0 + 0x38C8, arg3);
        if (arg4 == 0) {
            var_a0 = D_006A2F18;
        } else {
            var_a0 = D_006A2F20;
        }
        var_fp = 0;
        temp_s0 = func_003C9F18(var_a0);
        temp_s1 = M2C_FIELD(((arg3 * 4) + arg0), s32 *, 0xFC);
        temp_s5 = func_003CD900(arg0, arg1, arg3);
        temp_v1 = (arg1 * 0x8D0) + arg0;
        temp_v1 += arg3 * 0x178;
        temp_v1 += 0x3E4;
        var_a0_2 = 0;
        if ((M2C_FIELD(temp_v1, s32 *, 0x170) != 0) || (M2C_FIELD(temp_v1, s32 *, 0x174) != 0)) {
            var_a0_2 = 1;
        }
        if ((var_a0_2 != 0) || (temp_s1 >= 2)) {
            var_fp = 1;
            M2C_FIELD(temp_s0, f32 *, 0x34) = 0x1.d70a3ap-2f;
            M2C_FIELD(temp_s0, f32 *, 0x0) = 0x1p+0f;
            M2C_FIELD(temp_s0, f32 *, 0x10) = 0.0f;
            M2C_FIELD(temp_s0, f32 *, 0x20) = 0.0f;
            M2C_FIELD(temp_s0, f32 *, 0x30) = 0.0f;
            M2C_FIELD(temp_s0, f32 *, 0x4) = 0.0f;
            M2C_FIELD(temp_s0, f32 *, 0x14) = 0x1p+0f;
            M2C_FIELD(temp_s0, f32 *, 0x24) = 0.0f;
            M2C_FIELD(temp_s0, f32 *, 0x8) = 0.0f;
            M2C_FIELD(temp_s0, f32 *, 0x18) = 0.0f;
            M2C_FIELD(temp_s0, f32 *, 0x28) = 0x1p+0f;
            M2C_FIELD(temp_s0, f32 *, 0x38) = 0.0f;
            M2C_FIELD(temp_s0, f32 *, 0xC) = 0.0f;
            M2C_FIELD(temp_s0, f32 *, 0x1C) = 0.0f;
            M2C_FIELD(temp_s0, f32 *, 0x2C) = 0.0f;
            M2C_FIELD(temp_s0, f32 *, 0x3C) = 0x1p+0f;
        }
        temp_f25 = M2C_FIELD(temp_s0, f32 *, 0x38);
        if (arg4 == 1) {
            M2C_FIELD(temp_s0, f32 *, 0x38) = (f32) (temp_f25 * M2C_FIELD(((((arg1 * 4) + arg3) * 4) + arg0), f32 *, 0x91A0));
        }
        func_003D1488(arg0, arg1, arg2, temp_s0, arg3, arg4);
        temp_s1 = func_0034C190(arg2, arg1);
        temp_s7 = M2C_FIELD((temp_s5 + func_00359538(temp_s1)), u8 *, 0x1C) == 1;
        if (var_fp != 0) {
            var_f22 = func_00344E48(temp_s1, temp_s5, 0.0f);
            temp_f24 = func_00344DA8(temp_s1, temp_s5, 0.0f);
            temp_f23 = func_00344DF8(temp_s1, temp_s5, 0.0f);
            if (temp_s7 == 0) {
                var_f22 = -var_f22;
            }
            func_004A79B0((temp_f24 * 0x1.6800000000000p+7f) / 0x1.91eb840000000p+1f);
            func_004A79D8((temp_f23 * 0x1.6800000000000p+7f) / 0x1.91eb840000000p+1f);
            func_004A7988((var_f22 * 0x1.6800000000000p+7f) / 0x1.91eb840000000p+1f);
        } else {
            arg1 *= 4;
            if (arg4 == 0) {
                var_f20 = M2C_FIELD((((arg1 + arg3) * 4) + arg0), f32 *, 0x9520);
            } else {
                var_f20 = M2C_FIELD((((arg1 + arg3) * 4) + arg0), f32 *, 0x9580);
            }
            
            if (var_f20 > 0x0.0p+0f) {
                temp_f21 = var_f20 * func_00344DA8(temp_s1, temp_s5, 0.0f);
                temp_f20 = var_f20 * func_00344DF8(temp_s1, temp_s5, 0.0f);
                func_004A79B0((temp_f21 * 0x1.6800000000000p+7f) / 0x1.91eb840000000p+1f);
                func_004A79D8((temp_f20 * 0x1.6800000000000p+7f) / 0x1.91eb840000000p+1f);
                
            }
            var_f1 = M2C_FIELD((((arg1 + arg3) * 4) + arg0), f32 *, 0x95E0);
            if (temp_s7 == 0) {
                var_f1 = -var_f1;
            }
            func_004A7988((var_f1 * 0x1.6800000000000p+7f) / 0x1.91eb840000000p+1f);
        }
        M2C_FIELD(temp_s0, f32 *, 0x38) = temp_f25;
    }
}
