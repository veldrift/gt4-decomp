/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef short s16;

struct VEntry_0020E670 {
    s16 delta;
    s16 index;
    s32 (*fn)(void *self);
};

struct Inner_0020E670 {
    char pad0[4];
    char *vt;
};

struct Range_0020E670 {
    s32 pad;
    s32 begin;
    s32 end;
};

struct Owner_0020E670 {
    char pad0[4];
    s32 count;
    Inner_0020E670 *inner;
    char pad1[4];
    Range_0020E670 range;
};

extern "C" s32 func_0020E670(Owner_0020E670 *self) {
    Range_0020E670 *r = &self->range;
    s32 end = r->end;
    s32 *last = (s32 *)(end - 4);
    s32 v;
    if (((end - r->begin) >> 2) != 0) {
        v = *last;
        r->end = (s32)last;
    } else {
        Inner_0020E670 *in = self->inner;
        VEntry_0020E670 *e = (VEntry_0020E670 *)(in->vt + 0x1B8);
        v = e->fn((char *)in + e->delta);
    }
    if (v == 0xA) {
        self->count = self->count + 1;
    }
    return v;
}
