extern "C" void func_00576788(void *m);
extern "C" void func_005767C0(void *m);
extern "C" void func_00574EE8(void *m);

struct VEntry {
    short delta;
    short index;
    void (*fn)(void *self);
};

struct Sub {
    int pad0;
    char *vt;
};

struct Obj {
    char pad0[0x60];
    int f60;
    char *vt64;
    char pad68[8];
    Sub *sub;
    char lock[8];
};

extern "C" void func_00109BA8(Obj *self)
{
    void *m = self->lock;
    func_00576788(m);
    Sub *s = self->sub;
    if (s != 0) {
        VEntry *e = (VEntry *)(s->vt + 0x208);
        e->fn((char *)s + e->delta);
    }
    func_005767C0(m);
    func_00574EE8(m);
    if (self->f60 != 0) {
        VEntry *e = (VEntry *)(self->vt64 + 0x48);
        e->fn((char *)self + e->delta);
    }
}
