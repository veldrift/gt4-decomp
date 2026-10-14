typedef int s32;
typedef short s16;
typedef float f32;

struct VEntryD8 {
    s16 delta;
    s16 index;
    void *(*fn)(void *, void *);
};

struct VEntry130 {
    s16 delta;
    s16 index;
    f32 (*fn)(void *);
};

extern "C" f32 SceneCameraBase__getComposition(void);

extern "C" f32 DevelopCamera__virtual_17(char *arg0) {
    f32 temp_f20;
    void *obj;
    VEntryD8 *e;
    void *r;

    temp_f20 = SceneCameraBase__getComposition();
    obj = *(void **)(arg0 + 0x9BC);
    e = (VEntryD8 *)(*(char **)arg0 + 0xD8);
    r = e->fn(arg0 + e->delta, obj);
    if (r != 0) {
        VEntry130 *e2 = (VEntry130 *)(*(char **)r + 0x130);
        temp_f20 = e2->fn((char *)r + e2->delta);
    }
    return temp_f20;
}
