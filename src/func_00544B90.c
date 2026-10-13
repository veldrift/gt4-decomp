#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

void func_00544830(M2C_UNK *, M2C_UNK);          /* extern */
M2C_UNK func_00544978(M2C_UNK *, s32);              /* extern */
u32 func_00545A54(M2C_UNK *);                       /* extern */
s32 func_00545BF0(M2C_UNK *, M2C_UNK *);            /* extern */
M2C_UNK func_00545C58(M2C_UNK *, s32);              /* extern */
M2C_UNK func_00545D7C(M2C_UNK *, s32);              /* extern */
M2C_UNK func_00545FC0(M2C_UNK *, M2C_UNK *);        /* extern */
M2C_UNK func_005A4724(M2C_UNK *, M2C_UNK *, M2C_UNK); /* extern */

void func_00544B90(M2C_UNK *arg0, M2C_UNK *arg1, M2C_UNK *arg2) {
    struct StackFrame_00544B90 { s8 pad0[0x80]; s32 sp80; s8 pad1[0x7C]; s32 sp100; s8 pad2[0x7C]; } sp_;
    s32 temp_a1;
    s32 temp_a1_2;
    s32 var_s3;
    s32 var_v0;
    u32 temp_s2;
    u32 var_s0;
    u32 var_s1;

    func_005A4724(((s8 *)&sp_), arg1, 0x80);
    func_005A4724(&sp_.sp80, arg2, 0x80);
    var_s1 = func_00545A54(((s8 *)&sp_));
    var_s0 = func_00545A54(&sp_.sp80);
    func_00544830(&sp_.sp100, 0);
    temp_s2 = var_s0;
    if (var_s0 < var_s1) {
        temp_a1 = var_s1 - var_s0;
        var_s0 = var_s1;
        func_00545D7C(&sp_.sp80, temp_a1);
    }
    var_s3 = var_s1 < temp_s2;
    if (var_s3 == 0) {
        var_v0 = var_s1 < var_s0;
loop_4:
        if (var_v0 != 0) {
            temp_a1_2 = var_s0 - var_s1;
            var_s0 = var_s1;
            func_00545C58(&sp_.sp80, temp_a1_2);
        }
        if (func_00545BF0(((s8 *)&sp_), &sp_.sp80) != 0) {
            func_00545FC0(((s8 *)&sp_), &sp_.sp80);
            var_s1 = func_00545A54(((s8 *)&sp_));
            func_00544978(&sp_.sp100, var_s0 - temp_s2);
            var_s3 = var_s1 < temp_s2;
            goto block_11;
        }
        if (temp_s2 < var_s0) {
            var_s0 -= 1;
            func_00545C58(&sp_.sp80, 1);
block_11:
            var_v0 = var_s1 < var_s0;
            if (var_s3 == 0) {
                goto loop_4;
            }
        }
    }
    func_005A4724(arg0, &sp_.sp100, 0x80);
}
