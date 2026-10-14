/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef float f32;

struct Item { char pad[0x30]; s32 f30; char pad34[0x3C - 0x34]; };
struct Tbl {
    Item items[2];
    s32 cur;
};
struct Disp {
    char hdr[0x3C];
    Tbl t;
};
struct Cfg { s32 f0; s32 f4; s32 f8; s32 fC; f32 f10; s32 f14; };
struct Game {
    char pad[0x1E634];
    volatile s32 f1E634;
    Cfg cfg;
    void *f1E650;
    char pad1E654[0x1E668 - 0x1E654];
    s32 f1E668;
    f32 f1E66C;
    f32 f1E670;
    f32 f1E674;
    f32 f1E678;
    f32 f1E67C;
};
struct Sub {
    char pad[0x118];
    s32 f118;
    char pad11C[8];
    s32 f124;
    s32 f128;
    f32 f12C;
    f32 f130;
    f32 f134;
    f32 f138;
    f32 f13C;
};
struct Self {
    char pad[0xA8];
    Game *game;
    Sub sub;
    char pad140[0x218 - 0xAC - sizeof(Sub)];
    s32 f218;
    s32 f21C;
};

extern Disp D_006184D0;
extern "C" void func_001056A0(void *);
extern "C" void func_00106A68(void *, s32, s32, s32);
extern "C" void func_001074D0(void *, s32, s32, s32, s32);
extern "C" void func_00109BA8(void);
extern "C" s32 func_00333560(void *, void *, s32, s32, s32, s32, f32, s32);
extern "C" s32 func_00333A00(void *, s32);
extern "C" void func_003355F0(void *);
extern "C" void func_003C7D60(void *, s32);
extern "C" void func_004A2980(s32);
extern "C" void func_004A3078(s32);
extern "C" void func_004A3230(s32);

extern "C" void func_001C89F0(Self *self) {
    if (self->game->f1E634 != 0) {
        if (self->f218 == 0) {
            func_00106A68(&D_006184D0, 2, 0x100, 0x180);
            func_004A3078(0);
            func_004A2980(-1);
            Tbl *t = &D_006184D0.t;
            func_001056A0(&t->items[t->cur]);
            func_004A3230(1);
            func_001056A0(&t->items[1 - t->cur]);
            func_004A3230(1);
            self->f218 = 1;
            Game *g = self->game;
            Cfg *c = &g->cfg;
            f32 asp = c->f10;
            s32 lt = 1;
            if (!(asp < 1.0f)) lt = 0;
            Sub *sub = &self->sub;
            s32 ia = c->f0, ib = c->f4, ic = c->f8, id = c->fC;
            f32 f12;
            if (lt) f12 = 1.0f / asp;
            else f12 = asp;
            func_00333560(sub, g, ia, ib, ic, id, f12, lt);
            s32 val = c->f14;
            sub->f124 = 0;
            sub->f118 = val;
            sub->f128 = self->game->f1E668;
            sub->f134 = self->game->f1E674;
            sub->f130 = self->game->f1E670;
            sub->f138 = self->game->f1E678;
            sub->f13C = self->game->f1E67C;
            sub->f12C = self->game->f1E66C;
            func_003C7D60(self->game, 1);
            self->f21C = 0;
        
        } else {
            Sub *sub = &self->sub;
            if (func_00333A00(sub, self->f21C++) != 0) return;
            {
                func_001074D0(&D_006184D0, 1, 2, 0x280, 0x1C0);
                Tbl *t = &D_006184D0.t;
                t->items[t->cur].f30 = 0;
                t->items[1 - t->cur].f30 = 0;
                self->game->f1E650 = (char *)self + 0xC8;
                Game *g = self->game;
                g->f1E634 = 0;
                (void)g->f1E634;
                func_003C7D60(self->game, 0);
                func_003355F0(sub);
                self->f218 = 0;
            }
        }
    } else {
        func_00109BA8();
    }
}
