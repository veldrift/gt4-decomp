typedef signed char s8;
typedef int s32;
typedef float f32;

extern "C" void func_003866D0(s8 *arg0, f32 fparg0);
extern "C" f32 func_00386B28(s8 *first, f32 t);
extern "C" void func_005F6380(s32 arg0);

extern "C" f32 func_00386A38(s8 *arg0, f32 fparg0) {
    s8 *var_s0 = arg0;
    s32 var_s1 = 1;
    do {
        s8 *temp_a0 = var_s0;
        var_s1 -= 1;
        var_s0 += 0x370;
        func_003866D0(temp_a0, 0.0f);
    } while (var_s1 != -1);
    func_005F6380((s32)(arg0 + 0x6E0));
    return func_00386B28(arg0, fparg0);
}
