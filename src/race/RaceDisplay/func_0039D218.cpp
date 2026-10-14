/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef short s16;
typedef float f32;
typedef unsigned int u32;

struct VEnt { s16 delta; s16 idx; void *fn; };
struct Widget {
    char pad0[0x14];
    char *vtbl;
    u32 flags;
};
struct Holder {
    char pad0[4];
    char *p4;
    char pad8[0xC];
    Widget *w;
};
struct Src { char pad[0x10]; char *p10; char pad14[4]; Src *p18; };

extern s32 D_006244E8;
extern "C" void func_0036CED0(void *, void *, void *, void *, void *);
extern "C" s32 func_003F1F78(void *);
extern "C" s32 func_003F3790(void *);

static inline void vc_ff(Widget *o, int off, f32 a, f32 b) {
    VEnt *e = (VEnt *)(o->vtbl + off);
    ((void (*)(void *, f32, f32))e->fn)((char *)o + e->delta, a, b);
}
static inline void vc_i(Widget *o, int off, s32 a) {
    VEnt *e = (VEnt *)(o->vtbl + off);
    ((void (*)(void *, s32))e->fn)((char *)o + e->delta, a);
}
static inline void vc_if(Widget *o, int off, s32 a, f32 b) {
    VEnt *e = (VEnt *)(o->vtbl + off);
    ((void (*)(void *, s32, f32))e->fn)((char *)o + e->delta, a, b);
}
static inline void vc_0(Widget *o, int off) {
    VEnt *e = (VEnt *)(o->vtbl + off);
    ((void (*)(void *))e->fn)((char *)o + e->delta);
}

extern "C" void func_0039D218(Holder *self, s32 idx) {
    s32 sp0, sp4, sp8, spC;
    Src **tbl = *(Src ***)(*(char **)(self->p4 + 0x60) + 8);
    Src *s2 = tbl[idx]->p18;
    func_0036CED0(s2, &sp0, &sp4, &spC, &sp8);
    s32 nz = sp0 != 0;
    if (self->w) {
        vc_ff(self->w, 0x80, 0.0f, (f32)sp8);
        vc_i(self->w, 0x88, spC);
        vc_if(self->w, 0x70, nz, (f32)sp4);
        Widget *s0 = self->w;
        s0->flags = (s0->flags & 0xFF00FFFF) | ((func_003F3790(s2) & 0xFF) << 16);
        vc_i(self->w, 0x128, D_006244E8);
        s32 r = func_003F1F78(s2->p10 + 0x234);
        vc_i(self->w, 0xA8, r);
        vc_0(self->w, 0x60);
    }
}
