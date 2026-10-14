/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef float f32;

struct Obj;

struct VEnt {
    short adj;
    short pad;
    void (*fn)(void *, s32, f32, f32);
};

struct VTab {
    char pad[0x2B8];
    VEnt e;
};

struct Sub {
    char pad0[0xC4];
    s32 fC4;
};

struct Obj {
    char pad00[0x64];
    VTab *vt;
    char pad0[4];
    Sub *sub;
    char pad1[0x22C38 - 0x70];
    s32 f22C38;
    s32 f22C3C;
};

struct G { char pad[0x2150]; s32 mode; };
extern G D_00645570;
extern char D_0069F298[];

extern "C" void func_0038BC98(Obj *, char *, s32, f32);
extern "C" void func_003C00B8(Sub *);
extern "C" void RaceNetSinglePlayer__virtual_72(Obj *);
extern "C" s32 func_004F23D8(G *);
extern "C" void func_004F8D50(G *, s32 *);

extern "C" void RaceNetRallyBattle__virtual_72(Obj *self) {
    s32 buf[12];
    if (self->f22C38 == 0) {
        G *g = &D_00645570;
        s32 mode = g->mode;
        switch (mode) {
        case 5: {
            self->f22C3C = 1;
            func_004F8D50(&D_00645570, buf);
            Sub *s = self->sub;
            s->fC4 = buf[1] - 5;
            func_003C00B8(s);
            break;
        }
        case 6:
            if (self->f22C3C == 0) {
                VEnt *e = &self->vt->e;
                e->fn((char *)self + e->adj, 6, 0.0f, 0.0f);
                self->f22C3C = 1;
            }
            break;
        case 7:
            break;
        }
    }
    if (func_004F23D8(&D_00645570) == 1) {
        VEnt *e;
        func_0038BC98(self, D_0069F298, 0, 5.0f);
        e = &self->vt->e;
        e->fn((char *)self + e->adj, 7, 5.0f, 0.5f);
    }
    RaceNetSinglePlayer__virtual_72(self);
}
