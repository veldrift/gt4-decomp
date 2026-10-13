typedef int s32;
typedef short s16;

struct VEntry {
    s16 delta;
    s16 index;
    void (*fn)(void *, s32);
};

struct Obj {
    s32 pad0;
    VEntry *vtbl;
};

extern "C" s32 func_00265F38(Obj *arg0);
extern "C" void func_00265F48(Obj *arg0, s32 arg1);

extern "C" void func_00263A08(Obj *arg0, s32 arg1) {
    if (func_00265F38(arg0) != 0) {
        VEntry *e = (VEntry *)((char *)arg0->vtbl + 0x228);
        e->fn((char *)arg0 + e->delta, arg1);
        func_00265F48(arg0, 0);
    }
}
