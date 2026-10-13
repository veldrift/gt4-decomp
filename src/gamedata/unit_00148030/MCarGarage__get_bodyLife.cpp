typedef int s32;
typedef float f32;

struct RefCounter;

struct Setting {
    char pad0[16];
    f32 f16;
};

struct Obj {
    char pad0[4];
    char *vtbl;
};

struct VEntry {
    short delta;
    short index;
    f32 (*fn)(void *);
};

extern "C" void func_0013BDC0(void *arg0, void *arg1);
extern "C" void func_0013BD68(void *arg0, int arg1);
extern "C" s32 func_00147D80(s32 arg0);
extern "C" void func_002F7B68(void *arg0, int arg1);
extern "C" void func_002F9360(void *arg0, f32 fparg0);
extern "C" void func_003285A8(RefCounter *p);
extern "C" void func_003285F8(RefCounter *p);
extern "C" void func_00343978(Obj *o, f32 v);

static inline f32 vcall_60(Obj *o) {
    VEntry *e = (VEntry *)(o->vtbl + 0x60);
    return e->fn((char *)o + e->delta);
}

extern "C" void func_0014ECF8(s32 *arg0, void *arg1, s32 n, Obj **args) {
    s32 buf[4];
    s32 newVal;
    s32 oldVal;
    Setting *s2;

    func_0013BDC0(buf, arg1);
    s2 = (Setting *)(func_00147D80(buf[0]) + 0x4A0);
    func_0013BD68(buf, 2);
    if (n > 0) {
        Obj *o = args[0];
        VEntry *e = (VEntry *)(o->vtbl + 0x60);
        f32 v = e->fn((char *)o + e->delta);
        func_00343978((Obj *)s2, v);
        return;
    }
    func_002F9360(buf, s2->f16);
    if (arg0 != buf) {
        newVal = buf[0];
        if (newVal != 0) {
            func_003285A8((RefCounter *)newVal);
        }
        oldVal = *arg0;
        if (oldVal != 0) {
            func_003285F8((RefCounter *)oldVal);
        }
        *arg0 = newVal;
    }
    func_002F7B68(buf, 2);
}
