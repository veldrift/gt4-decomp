typedef int s32;
typedef short s16;

struct VEntry_50 {
    s16 delta;
    s16 index;
    s32 (*fn)(void *);
};

struct VEntry_2A8 {
    s16 delta;
    s16 index;
    s32 (*fn)(void *, s32, void *, s32);
};

struct ObjAct {
    char pad0[4];
    char *vtbl;
    char pad1[8];
    s32 f10;
    s32 f14;
};

struct S00305570 {
    char pad0[1];
};

extern char D_0069C420[];
extern char D_0069C428[];
extern char D_0069C440[];

extern "C" void func_005D4AD8(const char *fmt, ...);
extern "C" const char *func_00305570(struct S00305570 *arg0);
extern "C" s32 func_0028EA08(void *arg0);
extern "C" void *func_0028EA18(void *arg0);

static inline s32 vcall_50(char *o) {
    VEntry_50 *e = (VEntry_50 *)(((ObjAct *)o)->vtbl + 0x50);
    return e->fn(o + e->delta);
}

extern "C" s32 func_002BFB40(char *arg0) {
    ObjAct *o = (ObjAct *)arg0;
    s32 r = 1;
    const char *name;

    func_005D4AD8(D_0069C420);
    name = func_00305570((struct S00305570 *)vcall_50(arg0));
    func_005D4AD8(D_0069C428, name, o->f14, o->f10);
    if (func_0028EA18(arg0) != 0) {
        char *p = (char *)func_0028EA18(arg0);
        VEntry_2A8 *e = (VEntry_2A8 *)(*(char **)(p + 4) + 0x2A8);
        char *t = p + e->delta;
        s32 a1 = func_0028EA08(arg0);
        r = e->fn(t, a1, arg0, 1);
    }
    func_005D4AD8(D_0069C440);
    return r;
}
