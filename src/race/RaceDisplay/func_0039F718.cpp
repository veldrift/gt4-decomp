/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef short s16;
typedef unsigned char u8;
typedef unsigned int u32;

struct VEnt1 { s16 delta; s16 idx; void (*fn)(void *); };
struct VEnt2 { s16 delta; s16 idx; void (*fn)(void *, s32); };
struct Comp {
    u8 flag;
    char pad1[0x13];
    char *vtbl;
};
struct Self {
    char *vtbl;
    char pad4[0x54];
    u32 w58;
    char pad5c[0x11B0 - 0x5C];
    Comp c11B0;
    char pad11b0[0x252C - 0x11B0 - sizeof(Comp)];
    Comp c252C;
    char pad2540[0x2D78 - 0x252C - sizeof(Comp)];
    Comp c2D78;
    char pad2d8c[0x2DA0 - 0x2D78 - sizeof(Comp)];
    Comp c2DA0;
};

extern "C" void func_0039D390(Self *) throw();
extern "C" void func_0039FC88(Self *);
extern "C" void func_0039FCB0(Self *, s32);
extern "C" void func_0039FD30(Self *, s32);
extern "C" void func_0039FF78(Self *);
extern "C" void func_0039FFF8(Self *, s32);
extern "C" void RaceMessageDisplay__render_main(void *);

static inline void vc0(Comp *o, s32 off) {
    VEnt1 *e = (VEnt1 *)(o->vtbl + off);
    e->fn((char *)o + e->delta);
}
static inline void vc1(Comp *o, s32 off, s32 a) {
    VEnt2 *e = (VEnt2 *)(o->vtbl + off);
    e->fn((char *)o + e->delta, a);
}

extern "C" void func_0039F718(Self *self, s32 arg1) {
    u32 f = self->w58;
    if (f & 2) func_0039FC88(self);
    if (f & 0x40) func_0039FCB0(self, arg1);
    if (f & 0x20) func_0039FD30(self, arg1);
    func_0039FFF8(self, arg1);
    if (f & 0x10) {
        VEnt1 *e = (VEnt1 *)(self->vtbl + 0xC8);
        e->fn((char *)self + e->delta);
    }
    func_0039FF78(self);
    Comp *a = &self->c2D78;
    if (a->flag != 0) vc1(a, 0x30, arg1);
    Comp *b = &self->c2DA0;
    if (b->flag != 0) vc1(b, 0x30, arg1);
    Comp *c = &self->c11B0;
    if (c->flag != 0) vc0(c, 0x28);
    Comp *d = &self->c252C;
    if (d->flag != 0) vc0(d, 0x28);
    RaceMessageDisplay__render_main((char *)self + 0x267C);
    RaceMessageDisplay__render_main((char *)self + 0x27CC);
    func_0039D390(self);
}
