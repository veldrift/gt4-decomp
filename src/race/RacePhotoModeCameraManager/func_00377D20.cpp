/* compiler: ee-gcc2.96-no-strict-aliasing */
struct VE { short delta; short index; void (*fn)(void *, int); };
struct Obj { VE *vt; };
struct Self { char *vt; char pad[0xC40 - 4]; Obj *a; Obj *b; };
extern char D_0067A250[];
extern "C" void func_0036FAB0(void *, int);
extern "C" void SceneCameraBase__structor_0(void *, void *) throw();
extern "C" void func_005C1628(int) throw();
static inline void destroy(Obj *o) {
    if (o != 0) {
        VE *e = o->vt + 1;
        e->fn((char *)o + e->delta, 3);
    }
}
extern "C" void func_00377D20(Self *self, int flags) {
    self->vt = D_0067A250;
    destroy(self->a);
    destroy(self->b);
    func_0036FAB0((char *)self + 0xE28, 2);
    SceneCameraBase__structor_0(self, 0);
    if (flags & 1) return func_005C1628((int)self);
}
