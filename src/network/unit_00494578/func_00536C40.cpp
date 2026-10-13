typedef int s32;

struct Ctx {
    char pad0[0x158];
    s32 mode;
};

struct Obj {
    char pad0[0xE4];
    void (*fn)(void *, s32);
    char pad1[0x20];
    s32 f108;
};

extern struct Obj *D_0064B4B4;

extern "C" void func_00536C40(s32 arg0, s32 arg1, struct Ctx *arg2) {
    s32 m = arg0 & 0xFFFF;

    if (arg2->mode == 2) {
        struct Obj *o = D_0064B4B4;
        if (o != 0 && arg1 != 0 && o->f108 != 0 && arg2 != 0) {
            o->fn(arg2, m);
        }
    }
}
