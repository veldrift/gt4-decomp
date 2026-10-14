/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef short s16;
typedef unsigned char u8;
typedef unsigned int u32;

struct VEnt { s16 delta; s16 idx; void *fn; };
struct Comp {
    u8 flag;
    char pad1[0x13];
    char *vtbl;
};
struct Self {
    char pad0[0x3C];
    u8 b3C;
    u8 b3D;
    char pad3e[0x58 - 0x3E];
    u32 w58;
    char pad5c[0x11B0 - 0x5C];
    Comp c11B0;
    char pad11b0[0x2BBC - 0x11B0 - sizeof(Comp)];
    Comp c2BBC;
};

extern "C" void func_0039FC50(Self *);
extern "C" void func_003A0178(Self *);
extern "C" void RaceMessageDisplay__render_main(void *);
extern "C" void RaceMusicDisplay__render_main(void *);

static inline void vc(Comp *o) {
    VEnt *e = (VEnt *)(o->vtbl + 0x28);
    ((void (*)(void *))e->fn)((char *)o + e->delta);
}

extern "C" void func_0039FA10(Self *self) {
    Comp *a = &self->c11B0;
    if (a->flag != 0) vc(a);
    Comp *b = &self->c2BBC;
    if (b->flag != 0) vc(b);
    if (self->b3C != 0) {
        func_0039FC50(self);
        RaceMusicDisplay__render_main((char *)self + 0x3EEC);
        if (self->b3D != 0 || (self->w58 & 0x80) != 0) {
            func_003A0178(self);
        }
    }
    RaceMessageDisplay__render_main((char *)self + 0x267C);
    RaceMessageDisplay__render_main((char *)self + 0x27CC);
}
