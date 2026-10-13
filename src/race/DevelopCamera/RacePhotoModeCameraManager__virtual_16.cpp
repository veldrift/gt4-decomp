typedef int s32;
typedef short s16;

struct VEntryA {
    s16 delta;
    s16 index;
    void *(*fn)(void *, s32);
};

struct VEntryB {
    s16 delta;
    s16 index;
    float (*fn)(void *);
};

struct Obj {
    char *vtbl;
    char pad[0x9BC - 4];
    s32 f9bc;
};

extern "C" float func_0044F460(void);

extern "C" float func_00371E30(Obj *arg0) {
    float r = func_0044F460();
    Obj *self = arg0;
    s32 a = self->f9bc;
    VEntryA *e = (VEntryA *)(self->vtbl + 0xD8);
    char *o = (char *)self + e->delta;
    char *r2 = (char *)e->fn(o, a);
    if (r2 != 0) {
        VEntryB *g = (VEntryB *)(*(char **)r2 + 0x128);
        r = g->fn(r2 + g->delta);
    }
    return r;
}
