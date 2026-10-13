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
    void *(*fn)(void *, s32);
};

struct Obj {
    VEntryA *vtbl;
    char pad[0x9BC - 4];
    s32 m9BC;
};

extern "C" s32 DevelopCamera__virtual_32(Obj *arg0) {
    VEntryA *e = arg0->vtbl + 27;
    VObj *o = (VObj *)e->fn((char *)arg0 + e->delta, arg0->m9BC);
    if (o == 0) {
        return 3;
    }
    VEntryB *f = o->vtbl + 21;
    return f->fn((char *)o + f->delta);
}
