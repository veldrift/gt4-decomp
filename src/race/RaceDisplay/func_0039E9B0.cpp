/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef short s16;
typedef unsigned char u8;
typedef unsigned int u32;

struct VEnt { s16 delta; s16 idx; void *fn; };
struct Table { s32 count; };
struct Ctx {
    char pad0[0x60];
    Table *tbl;
    char pad64[0xB8 - 0x64];
    s32 b8;
    char padbc[0xF4 - 0xBC];
    char queue[1];
    char padf5[0x900 - 0xF5];
    u8 n900;
    u8 n901;
};
struct Self {
    char *vtbl;
    Ctx *ctx;
    char pad8[8];
    s32 p10;
    char pad14[0x2F - 0x14];
    signed char id2F;
    char pad30[4];
    u8 u34;
    char pad35[0x3B - 0x35];
    u8 u3B;
    char pad3c[8];
    u32 w44;
    u8 u45_unused;
};

extern char D_00621514;
extern char D_00621515;
extern char D_00621516;

extern "C" s32 DynamicsConductor__GetCountDown(s32, s32);
extern "C" void func_003A13A0(Self *, s32);
extern "C" s32 RaceDisplay__is_play_mode(Self *);
extern "C" s32 RaceEventQueue__check(void *, s32, s32 *, s32);

static inline void vc0(Self *o, int off) {
    VEnt *e = (VEnt *)(o->vtbl + off);
    ((void (*)(void *))e->fn)((char *)o + e->delta);
}
static inline void vc3(Self *o, int off, void *a, s32 b, s32 c) {
    VEnt *e = (VEnt *)(o->vtbl + off);
    ((void (*)(void *, void *, s32, s32))e->fn)((char *)o + e->delta, a, b, c);
}

extern "C" void func_0039E9B0(Self *self) {
    s32 sp0;
    Ctx *ctx = self->ctx;
    s32 cd = DynamicsConductor__GetCountDown(self->p10, self->id2F);
    if (cd > 0 && ctx->b8 > 0 && cd < 0xF0 && cd % 60 == 0) {
        D_00621514 = 1;
    }
    u8 n = ctx->n900;
    {
        for (s32 i = 0; i < n; i++) {
            sp0 = 0;
            if (RaceEventQueue__check(ctx->queue, 4, &sp0, i) != 0) {
                s32 v = DynamicsConductor__GetCountDown(self->p10, self->id2F);
                if ((sp0 < 0 || sp0 == self->id2F) && v <= 0) {
                    vc0(self, 0x140);
                    D_00621515 = 1;
                } else if (RaceDisplay__is_play_mode(self) != 0) {
                    if (sp0 < 0) {
                        s32 cnt = 0, j = 0, last = 0;
                        if (ctx->tbl->count > 0) {
                            do {
                                if (DynamicsConductor__GetCountDown(self->p10, j) <= 0) {
                                    cnt++;
                                    last = j;
                                }
                                j++;
                            } while (j < ctx->tbl->count);
                        }
                        sp0 = ((cnt ^ 1) == 0) ? last : sp0;
                    }
                    if (sp0 >= 0) func_003A13A0(self, sp0);
                    D_00621516 = 1;
                }
            }
        }
    }
    if (self->u34 != 0 && *((u8 *)self + 0x45) == 0) {
        self->w44 = (self->w44 & 0xFFFF00FF) | 0x100;
        if (self->u3B != 0) vc0(self, 0x160);
    }
    u8 n2 = ctx->n901;
    if (n2 != 0) {
        s32 k = 0;
        do {
            s32 id = self->id2F;
            if (RaceEventQueue__check(ctx->queue, 5, &sp0, k) != 0) {
                vc3(self, 0x120, ctx, sp0, id);
            }
            k++;
        } while (k < n2);
    }
}
