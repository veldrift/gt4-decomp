typedef int s32;
typedef short s16;

struct VEntry89 {
    s16 delta;
    s16 index;
    void (*fn)(void *, s32);
};

struct Obj89 {
    char pad0[4];
    char *vtbl;
};

extern "C" s32 func_00265F38(Obj89 *arg0);
extern "C" void func_00265F48(Obj89 *arg0, s32 arg1);

extern "C" void func_002639A8(Obj89 *arg0, s32 arg1) {
    if (func_00265F38(arg0) == 0) {
        VEntry89 *e = (VEntry89 *)(arg0->vtbl + 0x220);
        e->fn((char *)arg0 + e->delta, arg1);
        func_00265F48(arg0, 1);
    }
}
