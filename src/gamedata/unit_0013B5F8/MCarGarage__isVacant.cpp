typedef int s32;
extern "C" s32 func_00147D80(s32);extern "C" void *func_00441248(s32);


extern "C" void func_0013BD68(s32 *arg0, s32 arg1);
extern "C" void func_0013BDC0(s32 *arg0, void *arg1);
extern "C" s32 func_00146758(s32 arg0);
extern "C" void func_002FC870(s32 *arg0, s32 arg1);
extern "C" void func_002FE278(s32 *arg0, s32 arg1);
extern "C" void func_003285A8(s32 arg0);
extern "C" void func_003285F8(s32 arg0);

extern "C" void func_0013F7B0(s32 *arg0,void *arg1) {
    s32 sp10[4];
    s32 sp[4];
    s32 *p1;
    s32 temp_a0;
    s32 temp_s0;

    s32 *garage=sp;func_0013BDC0(garage,arg1);
    {
        s32 t = *(long long *)func_00441248(func_00147D80(*garage)) == (long long)-1;
        p1 = sp10;
        func_002FE278(p1, t);
    }
    if (arg0 != p1) {
        temp_s0 = *p1;
        if (temp_s0 != 0) {
            func_003285A8(temp_s0);
        }
        temp_a0 = *arg0;
        if (temp_a0 != 0) {
            func_003285F8(temp_a0);
        }
        *arg0 = temp_s0;
    }
    func_002FC870(p1, 2);
    func_0013BD68(sp, 2);
}
