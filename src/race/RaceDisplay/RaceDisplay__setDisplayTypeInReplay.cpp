typedef int s32;
typedef unsigned int u32;

/* RaceDisplay::setDisplayTypeInReplay (GT HD name) */
struct VE {
    short delta;
    short index;
    void (*fn)(void *, s32);
};

struct RD {
    char *vt;          /* vtable pointer at offset 0 */
    char pad4[0x1C];
    s32 f20;
    char pad24[0xC];
    u32 f30;
    char pad34[0x2C];
    s32 f60;
    s32 f64;
};

extern char *D_00622F4C;

extern "C" void RaceDisplay__setDisplayTypeInReplay(RD *self, s32 a1) {
    if (self->f64 == a1)
        return;
    self->f64 = a1;
    switch (a1) {
    case 0:
        self->f60 = *(s32 *)(D_00622F4C + 0x39DF0) & 0x80;
        break;
    case 1:
        self->f60 = *(s32 *)(D_00622F4C + 0x39DF0);
        break;
    case 2:
        self->f60 = 0x800003FE;
        break;
    }
    s32 t = self->f20;
    if ((u32)(t - 2) < 2U) {
        VE *e = (VE *)(self->vt + 0x108);
        e->fn((char *)self + e->delta, t);
        self->f30 = (self->f30 & 0xFFFF00FF) | 0x100;
    }
}
