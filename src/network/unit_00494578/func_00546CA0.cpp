typedef int s32;
typedef unsigned int u32;

extern "C" void func_00546B50(s32, s32, s32, s32);

extern "C" s32 func_00546CA0(s32 arg0, s32 arg1, s32 arg2, s32 arg3, u32 arg4) {
    u32 var_s0;
    s32 var_s1;
    s32 var_s2;
    s32 var_s3;
    s32 temp_a2;
    s32 temp_a3;

    var_s0 = arg4;
    var_s2 = arg2;
    var_s3 = 0;
    var_s1 = arg3;
    if (var_s0 >= 0x40U) {
        do {
            temp_a2 = var_s2;
            var_s2 += 0x40;
            temp_a3 = var_s1;
            var_s1 += 0x40;
            func_00546B50(arg0, arg1, temp_a2, temp_a3);
            var_s0 -= 0x40;
            var_s3 += 0x40;
        } while (var_s0 >= 0x40U);
    }
    return var_s3;
}
