typedef int s32;
typedef short s16;

struct VEntry_50 {
    s16 delta;
    s16 index;
    s32 (*fn)(void *);
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

extern char D_0069AF38[];
extern char D_0069AF40[];
extern char D_0069AF58[];

extern "C" void func_005D4AD8(const char *fmt, ...);
extern "C" const char *func_00305570(struct S00305570 *arg0);
extern "C" s32 func_0028EA08(void *arg0);
extern "C" s32 func_0028EA18(void *arg0);
extern "C" s32 func_0028E858(void *arg0, s32 arg1, s32 arg2);

static inline s32 vcall_50(char *o) {
    VEntry_50 *e = (VEntry_50 *)(((ObjAct *)o)->vtbl + 0x50);
    return e->fn(o + e->delta);
}

extern "C" s32 func_0028B3E0(char *arg0) {
    ObjAct *o = (ObjAct *)arg0;
    s32 r = 1;
    const char *name;

    func_005D4AD8(D_0069AF38);
    name = func_00305570((struct S00305570 *)vcall_50(arg0));
    func_005D4AD8(D_0069AF40, name, o->f14, o->f10);
    if (func_0028EA18(arg0) != 0) {
        s32 t1 = func_0028EA08(arg0);
        r = func_0028E858(arg0, t1, func_0028EA18(arg0));
    }
    func_005D4AD8(D_0069AF58);
    return r;
}
