/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Sub { int first, a, b, c; };
struct Settings { int first, a,b,c,d,e,f,g,h; float scale; };
struct Obj { int first; char *vt; char pad[0xA0-8]; int a0; Sub sub; int b4,b8,bc,c0; Settings settings; };
extern char mPhotoRenderFace__vtable[];
extern "C" int mWidget__structor_0(Obj *);
extern "C" int mPhotoRenderFace__structor_0(Obj *self) {
    int spare[4];
    mWidget__structor_0(self);
    self->vt = mPhotoRenderFace__vtable;
    self->a0 = 0;
    Sub *p = &self->sub;
    p->a = 0; p->b = 0; p->c = 0;
    self->b8 = 0;
    Settings *q = &self->settings;
    q->a = 0; q->b = 0; q->c = 0; q->d = 0; q->e = 0;
    q->f = 1; q->g = 1; q->h = 3; q->scale = 1.0f;
    spare[0] = 0;
}
