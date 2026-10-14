typedef int s32;
extern "C" s32 func_00147D80(s32);extern "C" s32 func_0013F528(s32);extern "C" s32 func_00441248(s32);extern "C" s32 func_00445650(s32);


extern "C" void func_0013BD68(s32 *arg0, s32 arg1);
extern "C" void func_0013BDC0(s32 *arg0, void *arg1);
extern "C" s32 func_00146758(s32 arg0);
extern "C" void func_002FC870(s32 *arg0, s32 arg1);
extern "C" void func_002FE278(s32 *arg0, s32 arg1);
extern "C" void func_003285A8(s32 arg0);
extern "C" void func_003285F8(s32 arg0);

extern "C" void MCarGarage__isNAtune(s32 *arg0,void *arg1) {
    s32 sp[4];
    s32 sp10[4];
    s32 *p1;
    s32 temp_a0;
    s32 temp_s0;

    func_0013BDC0(sp,arg1);
    {
        s32 car=func_00147D80(sp[0]);s32 super=func_0013F528(car);s32 turbo=func_00445650(func_00441248(car));s32 t=super?0:!turbo;
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
