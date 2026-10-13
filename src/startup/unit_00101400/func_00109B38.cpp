extern "C" void func_0021DF28(void);
extern "C" void func_00576788(void *);
extern "C" void func_005767C0(void *);

struct VEntry {
    short delta;
    short index;
    void (*fn)(void *);
};

struct Sub {
    int pad0;
    char *vt;
};

struct Obj {
    char pad0[0x70];
    Sub *sub;
    char lock[8];
};

extern "C" void func_00109B38(Obj *self)
{
    func_00576788(self->lock);
    if (self->sub != 0) {
        func_0021DF28();
        Sub *s = self->sub;
        VEntry *e = (VEntry *)(s->vt + 0x200);
        e->fn((char *)s + e->delta);
    }
    func_005767C0(self->lock);
}
