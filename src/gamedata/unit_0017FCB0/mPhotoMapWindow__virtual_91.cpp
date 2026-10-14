/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef float f32;
struct V2 { short d, i; char *(*fn)(void *); };
struct Win {
    char pad0[0xC0];
    void *w_c0;
    char pad1[8];
    void *w_cc;
    char pad2[0xDC - 0xD0];
    void *w_dc;
    char pad3[0x13C - 0xE0];
    f32 f13C;
    char pad4[0x148 - 0x140];
    f32 f148;
    char pad5[0x154 - 0x14C];
    f32 f154;
    char pad6[0x160 - 0x158];
    f32 f160;
};
struct Ctx { char pad[0x64]; char *vtbl; };

extern "C" void *func_00192E20(void *) throw();
extern "C" void mBox__virtual_91(void *, void *);
extern "C" void mWidget__setWindowPosition(void *, f32, f32);
extern "C" void mWidget__getWindowSize(void *, f32 *, f32 *);
extern "C" f32 func_00370128(void *);
extern "C" f32 func_00370140(void *);

extern "C" void mPhotoMapWindow__virtual_91(Win *self, void *a1)
{
    f32 sz[4];
    mBox__virtual_91(self, a1);
    mWidget__getWindowSize(self, &sz[0], &sz[1]);
    char *o = (char *)func_00192E20(a1);
    V2 *v = (V2 *)(((Ctx *)o)->vtbl + 0x4B0);
    char *s0 = v->fn(o + v->d) + 0xE28;
    if (self->w_dc != 0) {
        f32 x = func_00370128(s0);
        f32 y = func_00370140(s0);
        mWidget__setWindowPosition(self->w_dc, x, y);
    }
    if (self->w_c0 != 0) {
        mWidget__getWindowSize(self->w_c0, &sz[2], &sz[3]);
        f32 px = self->f13C, py = self->f148;
        mWidget__setWindowPosition(self->w_c0, px - sz[2] * 0.5f, py - sz[3] * 0.5f);
    }
    if (self->w_cc != 0) {
        mWidget__getWindowSize(self->w_cc, &sz[3], &sz[2]);
        f32 px = self->f154, py = self->f160;
        mWidget__setWindowPosition(self->w_cc, px - sz[3] * 0.5f, py - sz[2] * 0.5f);
    }
}
