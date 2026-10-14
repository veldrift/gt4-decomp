typedef int s32;
typedef short s16;

struct VEntry {
    s16 delta;
    s16 index;
    void (*fn)(void *, s32);
};

struct Obj {
    char p0[0x84];
    s32 f84;
    s32 f88;
    char p1[0xB4 - 0x8C];
    s32 fB4;
    char p2[0xDC - 0xB8];
    s32 fDC;
    s32 fE0;
    char p3[0x408 - 0xE4];
    s32 vt;
};

extern "C" void func_001FD4F8(Obj *arg0);
extern "C" void func_001FD5A8(Obj *arg0);
extern "C" void func_001FE510(Obj *arg0);

extern "C" void func_001FD418(Obj *arg0) {
    if (arg0->fE0 > 0) {
        do {
            func_001FE510(arg0);
        } while (arg0->fE0 > 0);
    }
    if (arg0->fDC != 0) {
        func_001FD4F8(arg0);
    }
    func_001FD5A8(arg0);
    arg0->f88 = 0;
    Obj *a2 = (Obj *)arg0->fB4;
    arg0->f84 = 0;
    if (a2 != 0) {
        arg0->fB4 = 0;
        VEntry *e = (VEntry *)(a2->vt + 8);
        e->fn((char *)a2 + e->delta, 3);
    }
}
