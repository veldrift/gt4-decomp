typedef int s32;
typedef short s16;

struct VEntry {
    s16 delta;
    s16 index;
    void *fn;
};

struct Obj {
    char pad0[0x64];
    VEntry *vtbl;
};

typedef void (*Fn0)(void *self);
typedef void (*Fn1)(void *self, int value);

extern "C" void func_0010AF40(int ms);
extern "C" void func_0010AF98(void);

extern "C" void func_00387EF0(Obj *self, int arg1, int arg2) {
    if (arg2 != 0) {
        func_0010AF40(0);
    }
    VEntry *e = &self->vtbl[38];
    ((Fn1)e->fn)((char *)self + e->delta, arg1);
    VEntry *f = &self->vtbl[40];
    ((Fn0)f->fn)((char *)self + f->delta);
    VEntry *g = &self->vtbl[48];
    ((Fn0)g->fn)((char *)self + g->delta);
    VEntry *h = &self->vtbl[89];
    ((Fn0)h->fn)((char *)self + h->delta);
    if (arg2 != 0) {
        func_0010AF98();
    }
}
