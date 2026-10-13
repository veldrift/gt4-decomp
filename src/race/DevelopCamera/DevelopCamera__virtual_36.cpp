typedef short s16;
typedef int s32;
typedef float f32;

struct VObj;

struct VEntryB {
    s16 delta;
    s16 index;
    f32 (*fn)(void *);
};

struct VObj {
    VEntryB *vtbl;
};

struct VEntryA {
    s16 delta;
    s16 index;
    VObj *(*fn)(void *, s32);
};

struct Obj {
    VEntryA *vtbl;
    char pad[0x9BC - 4];
    s32 m9BC;
};

extern "C" f32 DevelopCamera__virtual_36(Obj *self) {
    VEntryA *e = self->vtbl + 27;
    VObj *o = e->fn((char *)self + e->delta, self->m9BC);
    f32 r = 0.0f;
    if (o != 0) {
        VEntryB *f = o->vtbl + 24;
        r = f->fn((char *)o + f->delta) * 0x1.1DF46Ap-6f;
    }
    return r;
}
