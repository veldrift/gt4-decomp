typedef int s32;
typedef short s16;
typedef float f32;

struct VEntry_60 {
    s16 delta;
    s16 index;
    f32 (*fn)(void *);
};

struct VObj_60 {
    char pad0[4];
    VEntry_60 *vtbl;
};

static inline f32 vcall_60(void *o) {
    VObj_60 *obj = (VObj_60 *)o;
    VEntry_60 *e = (VEntry_60 *)((char *)obj->vtbl + 0x60);
    return e->fn((char *)obj + e->delta);
}

extern "C" void func_002366D8(void *arg0, void *arg1);
extern "C" f32 func_00238FA8(void *arg0);
extern "C" s32 func_00239098(void *arg0, f32 fparg0);
extern "C" void func_00236680(void *arg0, int arg1);

extern "C" void func_00237740(s32 arg0, void *arg1, s32 arg2, void **arg3) {
    s32 buf[4];
    f32 f;

    func_002366D8(buf, arg1);
    f = func_00238FA8((void *)buf[0]);
    if (arg2 > 0) {
        f = vcall_60(*arg3);
    }
    func_00239098((void *)buf[0], f);
    func_00236680(buf, 2);
}
