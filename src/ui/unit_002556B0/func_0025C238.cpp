struct Ent { short delta; short pad; void *(*fn)(void *); };
struct Obj { char pad0[4]; char *vt; char pad8[0x54-8]; Obj *parent; };
extern "C" void *mWidget__getRootWindow(Obj *) throw();
extern "C" void *func_0025C238(Obj *self) {
    Ent *e = (Ent *)(self->vt + 0x1a0);
    void *r = e->fn((char *)self + e->delta);
    if (r) return self;
    if (self->parent) return mWidget__getRootWindow(self->parent);
    return r;
}
