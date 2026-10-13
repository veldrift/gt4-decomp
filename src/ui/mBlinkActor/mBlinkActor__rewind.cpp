typedef short s16;
typedef int s32;
typedef float f32;

struct Tgt;

struct VEntryC {
    s16 delta;
    s16 index;
    void (*fn)(void *, f32);
};

struct Tgt {
    s32 pad;
    char *vt;
};

struct Self {
    char pad0[0x14];
    Tgt *p14;
    f32 f18;
    f32 f1C;
    char pad2[0x18];
    f32 f38;
};

extern "C" void mBlinkActor__rewind(Self *self) {
    Tgt *t = self->p14;
    self->f18 = self->f38;
    if (t != 0) {
        VEntryC *e = (VEntryC *)(t->vt + 0x1D0);
        e->fn((char *)t + e->delta, self->f1C);
    }
}
