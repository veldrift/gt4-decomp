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

struct Obj;

extern "C" void func_00291880(void *arg0, int arg1);
extern "C" void func_002918D8(void *arg0, void *arg1);
extern "C" void func_00293AE0(struct Obj *arg0, s32 arg1);

struct A {
    void *p;
    s32 pad[3];
};

extern "C" void func_00291F08(void *arg0, void *arg1, s32 arg2, char **arg3) {
    if (arg2 > 0) {
        A a;
        s32 v = vcall_58(*arg3) != 0;
        func_002918D8(&a, arg1);
        func_00293AE0((struct Obj *)a.p, v);
        func_00291880(&a, 2);
    }
}
