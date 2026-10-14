typedef int s32;
typedef short s16;
typedef float f32;

struct RefCounter;

struct Obj {
    char pad0[4];
    char *vtbl;
};

struct VEntry_60 {
    s16 delta;
    s16 index;
    f32 (*fn)(void *);
};

static inline f32 vcall_60(Obj *o) {
    VEntry_60 *e = (VEntry_60 *)(o->vtbl + 0x60);
    return e->fn((char *)o + e->delta);
}

extern "C" void func_00255110(void *arg0, void *arg1);
extern "C" void func_002550B8(void *arg0, int arg1);
extern "C" f32 func_00267DB0(Obj *arg0);
extern "C" void mWidget__setOpacity(Obj *arg0, f32 fparg0);
extern "C" void func_002F7B68(void *arg0, int arg1);
extern "C" void func_002F9360(void *arg0, float fparg0);
extern "C" void func_003285A8(RefCounter *p);
extern "C" void func_003285F8(RefCounter *p);

extern "C" void MWidget__get_opacity(s32 *arg0, void *arg1, s32 arg2, Obj **arg3) {
    s32 buf0[4];
    s32 buf1[4];
    s32 *p_s2;
    f32 t1;
    s32 newVal;
    s32 oldVal;
    func_00255110(buf0, arg1);
    if (arg2 == 0) {
        t1 = func_00267DB0((Obj *)buf0[0]);
        p_s2 = buf1;
        func_002F9360(p_s2, t1);
        if (arg0 != p_s2) {
            newVal = *p_s2;
            if (newVal != 0) {
                func_003285A8((RefCounter *)newVal);
            }
            oldVal = *arg0;
            if (oldVal != 0) {
                func_003285F8((RefCounter *)oldVal);
            }
            *arg0 = newVal;
        }
        func_002F7B68(p_s2, 0x2);
    } else if (arg2 == 1) {
        Obj *o = *arg3;
        Obj *s0 = (Obj *)buf0[0];
        mWidget__setOpacity(s0, vcall_60(o));
    }
    func_002550B8(buf0, 0x2);
}
