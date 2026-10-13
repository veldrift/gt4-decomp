typedef int s32;
typedef signed char s8;

extern char D_0082E550[];

extern "C" s32 func_003284E8(s32);
extern "C" void func_005769F0(void *p);
extern "C" void func_00576A28(void *p);

extern "C" s32 func_0022F0F8(s8 *arg0) {
    s32 val;
    s32 *h = (s32 *)(arg0 + 0x7C);
    s32 bad = 0;
    func_005769F0(D_0082E550);
    if (*h == 0 || func_003284E8(*h) == 0) {
        bad = 1;
    }
    val = 0;
    if (bad == 0) {
        val = *h;
    }
    func_00576A28(D_0082E550);
    return val;
}
