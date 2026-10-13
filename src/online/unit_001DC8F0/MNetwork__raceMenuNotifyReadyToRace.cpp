typedef int s32;

struct VEntry_58 {
    short delta;
    short index;
    s32 (*fn)(void *);
};

struct VObj_58 {
    char pad0[4];
    VEntry_58 *vtbl;
};

static inline s32 vcall_58(char *o) {
    VEntry_58 *e = (VEntry_58 *)((char *)((VObj_58 *)o)->vtbl + 0x58);
    return e->fn(o + e->delta);
}

struct S00293B10;

extern "C" void func_001DC5F8(void *arg0, int arg1);
extern "C" void func_001DC650(void *arg0, void *arg1);
extern "C" void func_001F7118(struct S00293B10 *arg0, s32 arg1);

struct A {
    void *p;
    s32 pad[3];
};

extern "C" void MNetwork__raceMenuNotifyReadyToRace(void *arg0, void *arg1, s32 arg2, void **arg3) {
    A a;
    if (arg2 > 0) {
        s32 v = vcall_58((char *)*arg3) != 0;
        func_001DC650(&a, arg1);
        func_001F7118((S00293B10 *)a.p, v);
        func_001DC5F8(&a, 2);
    }
}
