typedef int s32;
typedef short s16;
typedef float f32;

struct VEntry_0034C338 {
    s16 delta;
    s16 index;
    f32 (*fn)(void *self);
};

struct Obj_0034C338 {
    char pad0[0x10140];
    char *vtbl;
};

extern "C" f32 DynamicsConductor__GetCourseLength(Obj_0034C338 *arg0);

extern "C" s32 DynamicsConductor__IsExistStartV(Obj_0034C338 *self) {
    f32 k = 1.0f;
    VEntry_0034C338 *e = (VEntry_0034C338 *)(self->vtbl + 0x130);
    f32 v = e->fn((char *)self + e->delta);
    if (v < k) {
        return 0;
    }
    VEntry_0034C338 *e2 = (VEntry_0034C338 *)(self->vtbl + 0x130);
    f32 t = e2->fn((char *)self + e2->delta);
    if ((DynamicsConductor__GetCourseLength(self) - k) < t) {
        return 0;
    }
    return 1;
}
