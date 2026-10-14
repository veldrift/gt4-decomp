/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;

struct Sty { char p0[0x20]; s32 f20; s32 f24; char p28[0x28]; s32 f50; char p54[0x10]; };
struct Scroll { float x, y, z; };
struct V4 { float x, y, z, w; };
struct Self {
    char pad0[4];
    void *vtbl;
    char pad8[0x98];
    Sty sty;
    V4 c[6];
    s32 f164;
    s32 f168;
    char pad16C[0x400];
    s32 f56C;
    s32 f570;
    s32 f574;
    char sub[0x864];
    Scroll sc;
    s32 fDE8;
    s32 fDEC;
};

extern char mInputTextFace__vtable[];

extern "C" s32 mWidget__structor_0(void *);
extern "C" void func_00246F58(void *);
extern "C" void func_00203148(void *, float, float, float, float);
extern "C" s32 func_004B4378(void *);
extern "C" void func_0025B4C8(void *, float, float);
extern "C" void func_00265F10(void *, s32);
extern "C" void *func_004B4468(void *, s32);

extern "C" void *mInputTextFace__structor_0(Self *self) {
    void *sub = self->sub;
    Sty *sty = &self->sty;
    mWidget__structor_0(self);
    self->vtbl = mInputTextFace__vtable;
    func_00246F58(sty);
    func_00203148(&self->c[0], 0.25f, 1.0f, 0.25f, 1.0f);
    func_00203148(&self->c[1], 0.25f, 0.25f, 1.0f, 1.0f);
    func_00203148(&self->c[2], 0.25f, 1.0f, 1.0f, 1.0f);
    func_00203148(&self->c[3], 0.0f, 0.0f, 0.5f, 1.0f);
    func_00203148(&self->c[4], 0.25f, 1.0f, 1.0f, 1.0f);
    func_00203148(&self->c[5], 1.0f, 0.0f, 0.0f, 1.0f);
    self->f164 = 0;
    self->f56C = 0;
    self->f168 = -1;
    self->f570 = 0;
    self->f574 = 0;
    func_004B4378(sub);
    Scroll *sc = &self->sc;
    sc->x = 0.0f;
    sc->y = 0.0f;
    sc->z = 0.0f;
    self->fDE8 = 0;
    self->fDEC = 0;
    func_0025B4C8(self, 256.0f, 24.0f);
    func_00265F10(self, 1);
    sty->f20 = 0;
    sty->f24 = 0;
    sty->f50 = 0;
    return func_004B4468(sub, 0x400);
}
