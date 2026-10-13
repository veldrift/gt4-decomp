typedef int s32;
typedef short s16;

struct VEntryV {
    s16 delta;
    s16 index;
    void (*fn)(void *self);
};

struct VEntryVA {
    s16 delta;
    s16 index;
    void (*fn)(void *self, void *a1);
};

struct Obj {
    char pad0[4];
    char *vtbl;
};

struct Arg {
    char pad0[0x10];
    void *m10;
};

extern "C" void func_0025C2D8(void *arg0, s32 arg1);
extern "C" void func_003285F8(void *p);

extern "C" void func_002B4F40(void *arg0, Arg *arg1, Obj *arg2) {
    if (arg1 != 0) {
        VEntryV *e1 = (VEntryV *)(arg2->vtbl + 0x2D8);
        e1->fn((char *)arg2 + e1->delta);
        VEntryVA *e2 = (VEntryVA *)(arg2->vtbl + 0x2C8);
        e2->fn((char *)arg2 + e2->delta, arg1->m10);
        VEntryVA *e3 = (VEntryVA *)(arg2->vtbl + 0x2B8);
        e3->fn((char *)arg2 + e3->delta, arg1->m10);
    }
    func_0025C2D8(arg2, 0);
    func_003285F8(arg2);
}
