/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef short s16;
typedef unsigned char u8;

struct Entry {
    char pad0[0x3444];
    s32 f3444;
};

struct Tab {
    char pad0[8];
    Entry **ents;
};

struct Mid {
    char pad0[0x60];
    Tab *tab;
};

struct VEnt0 {
    short adj;
    short pad;
    s32 (*fn)(void *, s32);
};
struct VEnt {
    short adj;
    short pad;
    s32 (*fn)(void *, s32);
};

struct VTab {
    char pad[0x118];
    VEnt0 e118;
    VEnt e120;
};

struct Obj {
    Mid *mid;
    char pad0[0xF884 - 4];
    s16 fF884;
    u8 fF886;
    u8 fF887;
    char pad1[0xF8A0 - 0xF888];
    s32 fF8A0;
    char pad2[0x10140 - 0xF8A4];
    VTab *vt;
};

extern "C" s32 DynamicsConductor__GetStartVOffsetBySectionSet(Obj *);
extern "C" s32 DynamicsConductor__getSpecialStart_Handicap(Obj *, s32, s32 *, s32 *, s32 *);
extern "C" s32 DynamicsConductor__getSpecialStart_Launch(Obj *, s32, s32 *, s32 *, s32 *);

extern "C" void DynamicsConductorSinglePlayer__getSpecialStart(Obj *self, s32 arg1, s32 *a2, s32 *a3, s32 *a4) {
    VEnt0 *e0 = &self->vt->e118;
    s32 s1 = e0->fn((char *)self + e0->adj, arg1);
    VEnt *e1 = &self->vt->e120;
    s32 s5 = e1->fn((char *)self + e1->adj, arg1);
    if (s1 != 0 && s5 > 0) {
        if (s1 > 0) *a2 = 1;
        else *a2 = 2;
        *a3 = s1;
        *a3 += DynamicsConductor__GetStartVOffsetBySectionSet(self);
        *a4 = s5;
        return;
    }
    DynamicsConductor__getSpecialStart_Handicap(self, arg1, a2, a3, a4);
    if (DynamicsConductor__getSpecialStart_Launch(self, arg1, a2, a3, a4) == 0 && *a3 == 0) {
        s32 x = self->fF884;
        s32 y = self->fF886;
        s32 z = self->fF887;
        if (x < 0 && y > 0) {
            x += (self->fF8A0 - self->mid->tab->ents[arg1]->f3444 - 1) * z;
            if (x < 0) *a2 = 2;
            else *a2 = 1;
            *a3 = x;
            *a4 = y;
        }
    }
}
