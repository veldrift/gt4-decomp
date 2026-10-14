/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef short s16;
typedef float f32;
typedef unsigned char u8;

struct VEnt { s16 delta; s16 idx; void *fn; };
struct Comp {
    u8 flag;
    char pad1[0xB];
    f32 f0C;
    char pad10[4];
    char *vtbl;
};
struct Self {
    char pad0[0xBC];
    f32 fBC;
    char pad_c0[0x1398 - 0xC0];
    Comp c1398;
    char pad_13b[0x13BC - 0x1398 - sizeof(Comp)];
    f32 f13BC;
    char pad13c0[0x1668 - 0x13C0];
    Comp c1668;
};

static inline void vc(Comp *o, s32 off) {
    VEnt *e = (VEnt *)(o->vtbl + off);
    ((void (*)(void *))e->fn)((char *)o + e->delta);
}

static inline void vc_arg(Comp *o, s32 off, s32 arg) {
    VEnt *e = (VEnt *)(o->vtbl + off);
    ((void (*)(void *,s32))e->fn)((char *)o + e->delta,arg);
}

extern "C" void func_0039FCB0(Self *self, s32 arg) {
    Comp *a = &self->c1398;
    if (a->flag != 0) vc_arg(a, 0x30,arg);
    Comp *b = &self->c1668;
    b->f0C = self->fBC * self->f13BC;
    if (b->flag != 0) vc(b, 0x28);
}
