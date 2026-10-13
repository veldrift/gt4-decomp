typedef int s32;
typedef short s16;
typedef float f32;

struct VEntryD8 {
    s16 delta;
    s16 index;
    void *(*fn)(void *, s32);
};

struct VEntry108 {
    s16 delta;
    s16 index;
    s32 (*fn)(void *);
};

extern "C" f32 func_0044F3E0(char *self);

extern "C" f32 func_00371D18(char *arg0) {
    f32 temp_f20;
    VEntryD8 *e;
    char *r;

    temp_f20 = func_0044F3E0(arg0);
    e = (VEntryD8 *)(*(char **)arg0 + 0xD8);
    r = (char *)e->fn(arg0 + e->delta, *(s32 *)(arg0 + 0x9BC));
    if (r != 0) {
        VEntry108 *g = (VEntry108 *)(*(char **)r + 0x108);
        s32 v = g->fn(r + g->delta);
        temp_f20 = (f32)v / 10.0f;
    }
    return temp_f20 / 1000.0f;
}
