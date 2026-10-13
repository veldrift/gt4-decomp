typedef short s16;
typedef int s32;

struct VObj;

struct VEntryB {
    s16 delta;
    s16 index;
    int (*fn)(void *);
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
    char pad[0x9B8];
    s32 m9BC;
};

extern "C" void DevelopCamera__virtual_33(Obj *self) {
    VEntryA *e = self->vtbl + 27;
    VObj *o = e->fn((char *)self + e->delta, self->m9BC);
    if (o != 0) {
        VEntryB *f = o->vtbl + 22;
        f->fn((char *)o + f->delta);
    }
}
