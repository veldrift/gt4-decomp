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

extern "C" void func_001DC5F8(void *arg0, int arg1);
extern "C" void func_001DC650(void *arg0, void *arg1);
extern "C" void func_001F7548(void *arg0, s32 arg1);

struct A {
    void *p;
    s32 pad[3];
};

extern "C" void MNetwork__setGameClosed(void *arg0, void *arg1, s32 arg2, void **arg3) {
    A a;
    s32 v = 1;
    if (arg2 > 0) {
        v = vcall_58((char *)*arg3) != 0;
    }
    func_001DC650(&a, arg1);
    func_001F7548(a.p, v);
    func_001DC5F8(&a, 2);
}
