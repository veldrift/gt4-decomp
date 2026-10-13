typedef int s32;

struct VEntry {
    short delta;
    short index;
    void *fn;
};

struct Obj {
    VEntry *vtbl;
    char pad[0x18];
    s32 f1C;
    s32 f20;
};

extern "C" s32 func_003A1638(Obj *self, s32 arg1) {
    VEntry *e = &self->vtbl[35];
    ((void (*)(void *))e->fn)((char *)self + e->delta);

    VEntry *f = &self->vtbl[34];
    ((void (*)(void *, s32, s32, s32))f->fn)((char *)self + f->delta, self->f1C, self->f20, arg1);
    return 1;
}
