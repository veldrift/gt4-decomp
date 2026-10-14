typedef int s32;
extern "C" void func_002550B8(void *, int);
extern "C" void func_00255110(void *, void *);
extern "C" void mWidget__getWindowSize(void *, s32 *, s32 *);
extern "C" void *func_002B50F0(void *);
extern "C" void func_002B50F8(void *, void *, s32);
extern "C" void func_00309378(void *, s32);
extern "C" void func_0030BA08(void *, s32);

struct W {
    char pad[0xC0];
    s32 unkC0;
    s32 unkC4;
};

extern "C" void func_002B48F0(W *arg0, void *arg1, s32 arg2) {
    s32 sp0[8];
    s32 sp20[4];
    if (arg2 != 0) {
        func_0030BA08(sp20, arg2);
        func_00255110(sp0, sp20);
        func_00309378(sp20, 2);
        func_002B50F8(arg0, arg1, sp0[0]);
        mWidget__getWindowSize(func_002B50F0(arg0), &arg0->unkC0, &arg0->unkC4);
        func_002550B8(sp0, 2);
        return;
    }
    func_002B50F8(arg0, arg1, arg2);
}
