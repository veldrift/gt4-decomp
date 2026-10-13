typedef int s32;
typedef float f32;

extern "C" s32 func_005A5600(void);

extern "C" void func_00567F58(s32 *arg0, s32 arg1, f32 fparg0) {
    s32 *var_s0;
    s32 var_s1;

    if (arg1 > 0) {
        var_s0 = arg0;
        var_s1 = arg1;
        do {
            var_s1 -= 1;
            s32 r = func_005A5600();
            f32 v = (f32)*var_s0;
            f32 t = fparg0 * 0x1.8p15f;
            f32 w = (f32)r / 0x1.FFFFFEp30f - 0.5f;
            v = v + t * w;
            *var_s0 = (s32)v;
            var_s0 += 1;
        } while (var_s1 != 0);
    }
}
