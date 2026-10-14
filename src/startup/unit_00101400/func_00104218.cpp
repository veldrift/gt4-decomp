/* compiler: ee-gcc2.96-no-strict-aliasing */
struct V { float x, y; };
struct Obj { void *vt; char p[0x2C]; V v; };
extern char D_00659D90[];
extern "C" void func_00104048(Obj *);
extern "C" void func_00104218(Obj *self) {
    func_00104048(self);
    V *v = &self->v;
    self->vt = D_00659D90;
    v->y = v->x = 0.0f;
}
