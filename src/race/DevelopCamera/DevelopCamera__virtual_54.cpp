typedef short s16;
typedef int s32;

struct VObj;

struct VEntryB {
    s16 delta;
    s16 index;
    s32 (*fn)(void *);
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
    char pad4[0x9B8];
    s32 arg;
};

extern "C" void DevelopCamera__virtual_54(Obj *self) {
    VEntryA *e = self->vtbl + 27;
    VObj *o = e->fn((char *)self + e->delta, self->arg);
    if (o != 0) {
        VEntryB *f = o->vtbl + 32;
        f->fn((char *)o + f->delta);
    }
}
