/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Rep { int len, cap, ref; bool selfish;
    char *grab();
};
extern Rep D_00659FA8;
extern char mToolTipFace__vtable[];
extern "C" char *func_005C2560(Rep *);
inline char *Rep::grab() { if (selfish) return func_005C2560(this); ++ref; return (char *)(this + 1); }
struct Str { char *p; };
union Vec { struct { float x,y,z; } v; float a[3]; };
struct Style { char pad[0x18]; int a18,a1c,a20; char rest[0x40]; };
struct Obj {
    int a0; void *vt; char pad[0x98]; Style style;
    Str s104; int a108,a10c,a110,a114; char a118; char p119[3];
    float f11c,f120,f124,f128,f12c; Vec v130,v13c; float f148,f14c; int a150;
};
extern "C" void *mWidget__structor_0(void *);
extern "C" void *func_00246F58(Style *);
static inline void init_str(Str *s) { s->p = D_00659FA8.grab(); }
static inline void init_vec(Vec *v, float f) { v->v.x=f; v->v.y=f; v->v.z=f; }
extern "C" void mToolTipFace__structor_0(Obj *self) {
    Style *s = &self->style;
    Str *text = &self->s104;
    mWidget__structor_0(self);
    self->vt = mToolTipFace__vtable;
    func_00246F58(s);
    Rep *r = &D_00659FA8;
    char *d = (char *)(r + 1);
    if (r->selfish) d = func_005C2560(r);
    else ++r->ref;
    text->p = d;
    self->f11c=0.0f;
    float f = self->f11c;
    self->a108=0; self->a10c=1; self->a110=0; self->a114=0; self->a118=0;
    self->f120=f; self->f124=f; self->f128=f; self->f12c=f;
    init_vec(&self->v130,f);
    init_vec(&self->v13c,f);
    self->f148=8.0f; self->f14c=10.0f; self->a150=0;
    s->a18=0; s->a1c=0; s->a20=0;
}
