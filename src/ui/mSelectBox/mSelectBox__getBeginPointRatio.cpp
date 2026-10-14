typedef int s32;
typedef float f32;
extern "C" f32 mWidget__getWindowW(void *);
extern "C" f32 mWidget__getWindowH(void *);
extern "C" f32 func_002D4980(void *);
extern "C" s32 func_0057CE60(void *);
extern "C" f32 mSelectBox__getBeginPointRatio(char *arg0) {
    f32 a;
    f32 var_f0_2;
    f32 var_f21;
    f32 temp_f2;
    f32 neg;
    s32 temp_v0;

    temp_v0 = *(s32 *)(arg0 + 0xB0);
    if (temp_v0 == 0) var_f21 = *(f32 *)(arg0 + 0xE4); else var_f21 = *(f32 *)(arg0 + 0xE8);
    if (temp_v0 == 0) {
        var_f0_2 = mWidget__getWindowW(arg0);
    } else {
        var_f0_2 = mWidget__getWindowH(arg0);
    }
    a = var_f21 + func_002D4980(arg0);
    temp_f2 = (a * (f32) (func_0057CE60(arg0 + 0xBC) - 1)) + (var_f21 * *(f32 *)(arg0 + 0xD4));
    neg = -*(f32 *)(arg0 + 0xEC);
    if (neg < 0.0f) return 0.0f;
    {
        f32 r = neg / temp_f2;
        f32 s = 1.0f - (var_f0_2 / temp_f2);
        if (s <= r) return s;
        return r;
    }
}
