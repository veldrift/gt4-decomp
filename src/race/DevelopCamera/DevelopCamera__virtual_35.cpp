typedef short s16;
typedef int s32;

struct VObj;
struct VEntryA {
    s16 delta;
    s16 index;
    VObj *(*fn)(void *, s32);
};
struct VObj {
    char *vtbl;
};
struct VEntryB {
    s16 delta;
    s16 index;
    s32 (*fn)(void *);
};

struct Obj {
    VEntryA *vtbl;
    char pad[0x9BC - 4];
    s32 arg;
};

struct Inner {
    char pad[0xB8];
    VEntryB *vtbl;
};

extern "C" s32 DevelopCamera__virtual_35(Obj *self) {
    VEntryA *e = self->vtbl + 27;
    VObj *o = e->fn((char *)self + e->delta, self->arg);
    if (o == 0)
        return -1;
    VEntryB *f = (VEntryB *)o->vtbl + 23;
    return f->fn((char *)o + f->delta);
}
