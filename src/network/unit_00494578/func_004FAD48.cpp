/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef unsigned int u32;
struct Obj { char pad[0xFC4]; s32 unkFC4; s32 unkFC8; };
extern "C" void func_004F9AD0(void *) throw();
extern "C" void func_004F9B50(void *) throw();
extern "C" void func_0053A860(void *);
extern "C" s32 func_0053A890(void *, u32 *);
extern "C" void func_00578B10(s32);
extern "C" s32 func_004FAD48(Obj *arg0, s32 arg1, u32 arg2, void (*arg3)()) {
    char timer[16];
    u32 elapsed;
    s32 ret = 1;
    func_004F9AD0(arg0);
    elapsed = 0;
    func_0053A860(timer);
    while (arg0->unkFC8 < arg1 || arg0->unkFC4 != 2) {
        if (arg3) arg3();
        func_00578B10(0x2710);
        func_0053A890(timer, &elapsed);
        if (elapsed >= arg2) {
            ret = 0;
            break;
        }
    }
    func_004F9B50(arg0);
    return ret;
}
