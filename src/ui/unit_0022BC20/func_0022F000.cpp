typedef int s32;
typedef signed char s8;

extern char D_0082E550[];

extern "C" s32 func_003284E8(s32);
extern "C" void func_005769F0(s32 arg0);
extern "C" void func_00576A28(s32 arg0);

extern "C" s32 func_0022F000(s8 *arg0) {
    s32 bad = 0;
    s32 r;
    s32 *h;

    func_005769F0((s32)D_0082E550);
    h = (s32 *)(arg0 + 0x78);
    if (*h == 0 || func_003284E8(*h) == 0) {
        bad = 1;
    }
    r = 0;
    if (bad == 0) {
        r = *h;
    }
    func_00576A28((s32)D_0082E550);
    return r;
}
