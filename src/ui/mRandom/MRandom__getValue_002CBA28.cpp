typedef int s32;
typedef float f32;

extern "C" void func_002FC870(void *arg0, s32 arg1);
extern "C" void func_002FC8C8(void *arg0, s32 arg1);
extern "C" s32 func_002FE250(s32 arg0);
extern "C" void func_002FE278(void *arg0, s32 arg1);
extern "C" void func_003285A8(s32 p);
extern "C" void func_003285F8(s32 p);
extern "C" f32 func_00579398(f32 fparg0);

extern "C" void func_002CBA28(s32 *arg0, s32 unused1, s32 arg2, s32 arg3) {
    s32 buf0[4];
    s32 s0;
    s32 s1;
    s32 newVal;
    s32 oldVal;
    if (arg2 >= 2) {
        func_002FC8C8(buf0, arg3);
        s1 = func_002FE250(buf0[0]);
        func_002FC870(buf0, 2);
        func_002FC8C8(buf0, arg3 + 4);
        s0 = func_002FE250(buf0[0]);
        func_002FC870(buf0, 2);
        s0 = s0 - s1;
        f32 r = func_00579398((f32)s0);
        s32 sum = (s32)(r + (f32)s1);
        func_002FE278(buf0, sum);
        if (arg0 != buf0) {
            newVal = buf0[0];
            if (newVal != 0) {
                func_003285A8(newVal);
            }
            oldVal = *arg0;
            if (oldVal != 0) {
                func_003285F8(oldVal);
            }
            *arg0 = newVal;
        }
        func_002FC870(buf0, 2);
    }
}
