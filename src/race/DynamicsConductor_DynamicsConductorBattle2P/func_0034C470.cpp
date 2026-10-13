typedef int s32;
typedef short s16;
typedef float f32;

struct Obj_0034C470 {
    char pad0[0x10140];
    char *vtbl;
};

struct VEntry_0034C470 {
    s16 delta;
    s16 index;
    f32 (*fn)(void *self);
};

extern "C" f32 func_0034C230(Obj_0034C470 *arg0);

static inline f32 vcall_0034C470(Obj_0034C470 *o) {
    VEntry_0034C470 *e = (VEntry_0034C470 *)(o->vtbl + 0x138);
    return e->fn((char *)o + e->delta);
}

extern "C" s32 func_0034C470(Obj_0034C470 *arg0) {
    f32 one = 1.0f;
    if (vcall_0034C470(arg0) < one)
        return 0;
    f32 t = vcall_0034C470(arg0);
    if ((func_0034C230(arg0) - one) < t)
        return 0;
    return 1;
}
