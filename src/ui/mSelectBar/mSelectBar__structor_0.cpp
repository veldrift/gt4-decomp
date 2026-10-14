/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Range { int index, low, high, wrap, flags; };
struct Obj { int zero; void *vt; char pad8[0xB4]; Range r; float speed; float scale; int d8, dc, e0; float width, height; int offset; void *disabled; };
extern char mSelectBar__vtable[];
extern "C" void mScrollable__structor_0(Obj *);
extern "C" void func_00265F10(Obj *, int);
static inline void init(Range *r) {
    r->index = 0;
    r->low = 0;
    r->high = 1;
    r->wrap = 1;
    r->flags = 0;
}
extern "C" void mSelectBar__structor_0(Obj *self) {
    mScrollable__structor_0(self);
    self->vt = mSelectBar__vtable;
    init(&self->r);
    self->speed = 0.2f;
    self->scale = 1.5f;
    self->d8 = 0;
    self->dc = 0;
    self->e0 = 0;
    self->width = 16.0f;
    self->height = 16.0f;
    self->offset = 0;
    self->disabled = 0;
    return func_00265F10(self, 1);
}
