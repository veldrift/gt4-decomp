/* compiler: ee-gcc2.96-no-strict-aliasing */
struct V3 { float x, y, z; V3(): x(0.0f), y(0.0f), z(0.0f) {} };
inline void *operator new(unsigned int, void *p) { return p; }
struct Sub { int a, b, c, d, e; };
struct S {
    char p0[4];
    void *vt;
    char p1[0xB8];
    int c0, c4, c8;
    char pCC[0xC];
    Sub s;
    V3 v;
    float f8;
    int fc, f100, f104;
    char p108[8];
    V3 w;
    char p11c0[0];
};

extern "C" S *mFBox__structor_0(S *s);
extern "C" void func_002FA120(void *p);
extern "C" void mWidget__setWindowW(S *s, float f);
extern "C" void mWidget__setWindowH(S *s, float f);
extern "C" void func_00265F10(S *s, int a);
extern "C" void func_00206858(S *s, int a);
extern char mOptionMenu__vtable[];

extern "C" void mOptionMenu__structor_0(S *self) {
    Sub *sp = &self->s;
    mFBox__structor_0(self);
    self->c0 = 0;
    self->c4 = 0;
    self->vt = mOptionMenu__vtable;
    self->c8 = 0;
    func_002FA120((char *)self + 0xCC);
    func_002FA120((char *)self + 0xD0);
    func_002FA120((char *)self + 0xD4);
    sp->a = 0;
    sp->b = 0;
    sp->c = 1;
    sp->d = 1;
    sp->e = 0;
    new (&self->v) V3;
    self->f8 = 0.0f;
    self->fc = 0;
    self->f100 = 0;
    self->f104 = 0;
    new (&self->w) V3;
    *(float *)((char *)self + 0x11C) = 0.0f;
    mWidget__setWindowW(self, 128.0f);
    mWidget__setWindowH(self, 24.0f);
    func_00265F10(self, 1);
    func_00206858(self, 0);
    sp->d = 0;
}
