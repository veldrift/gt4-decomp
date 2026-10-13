typedef int s32;
typedef unsigned char u8;

extern "C" void func_002FC870(void *arg0, int arg1);
extern "C" void func_002FE278(void *arg0, s32 arg1);
extern "C" void func_003041B8(void *arg0, int arg1);
extern "C" void func_00304210(void *arg0, void *arg1);
extern "C" s32 func_00305CF8(s32 arg0, s32 arg1);
extern "C" void func_00312318(void *arg0, int arg1);
extern "C" void func_00312370(void *arg0, s32 arg1);
extern "C" s32 func_00314920(s32 arg0);
extern "C" void func_003285A8(s32 p);
extern "C" void func_003285F8(s32 p);

extern "C" void func_00304398(s32 *arg0, void *arg1, s32 arg2, s32 arg3) {
    s32 buf0[4];
    s32 buf1[4];
    s32 *p0;
    s32 *p1;
    s32 sp0;
    s32 r;
    s32 newVal;
    s32 oldVal;

    r = 0;
    p0 = buf0;
    if (arg2 == 1) {
        func_00304210(p0, arg1);
        p1 = buf1;
        func_00312370(p1, arg3);
        sp0 = buf0[0];
        r = func_00305CF8(sp0, func_00314920(p1[0]));
        func_00312318(p1, 2);
        func_003041B8(p0, 2);
    }
    func_002FE278(p0, r != 0);
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
    func_002FC870(p0, 2);
}
