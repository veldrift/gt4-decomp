typedef int s32;
typedef short s16;
typedef float f32;

struct Obj {
    char pad0[4];
    char *vtbl;
};

struct VEntry {
    s16 delta;
    s16 index;
    f32 (*fn)(void *);
};

struct RefCounter;

extern "C" void func_0013BDC0(void *arg0, void *arg1);
extern "C" void func_0013BD68(void *arg0, int arg1);
extern "C" s32 func_00147D80(s32 arg0);
extern "C" void func_002F7B68(void *arg0, int arg1);
extern "C" void func_002F9360(void *arg0, f32 fparg0);
extern "C" void func_003285A8(RefCounter *p);
extern "C" void func_003285F8(RefCounter *p);
extern "C" void func_003438A0(struct Obj *arg0, f32 fparg0);

static inline f32 vcall_60(Obj *o) {
    VEntry *e = (VEntry *)(o->vtbl + 0x60);
    return e->fn((char *)o + e->delta);
}

extern "C" void MCarGarage__get_dirtiness(s32 *arg0, void *arg1, s32 arg2, Obj **arg3) {
    s32 buf[4];
    s32 newVal;
    s32 oldVal;
    char *w;

    func_0013BDC0(buf, arg1);
    w = (char *)func_00147D80(buf[0]) + 0x4A0;
    func_0013BD68(buf, 2);
    if (arg2 > 0) {
        func_003438A0((Obj *)w, vcall_60(*arg3));
    } else {
        func_002F9360(buf, *(f32 *)(w + 0xC));
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
}
