/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned char u8;
typedef float f32;

struct Ent {
    char pad0[0x440];
    u8 b440, b441;
    char pad442[0x24];
    u8 b466, b467;
    char pad468[0x3C];
    f32 f4A4;
    char pad4A8[0xA];
    u8 b4B2;
    char pad4B3[0x161];
    int i614;
};
struct Ctx {
    char pad0[0xCBDE];
    u8 bCBDE;
    char padCBDF[0xF81A - 0xCBDF];
    u8 bF81A;
};

extern "C" f32 func_003447C8(void *, f32);
extern "C" void *func_0034C190(Ctx *, int);
extern "C" int gtbPenaltiedNumLaps(Ent *) throw();

extern "C" int func_003659E8(Ctx *ctx, Ent *a, Ent *b) {
    u8 state = a->b441;
    if (state && ((unsigned)(a->b466 - 1) < 2 || a->b467))
        return -1;
    if (b->b441) {
        if ((unsigned)(b->b466 - 1) < 2 || b->b467) return 1;
    }
    f32 fa = a->f4A4;
    f32 fb = b->f4A4;
    if (state == 2)
        fa = func_003447C8(func_0034C190(ctx, a->b440), 0.0f);
    if (b->b441 == 2)
        fb = func_003447C8(func_0034C190(ctx, b->b440), 0.0f);
    int sa = gtbPenaltiedNumLaps(a);
    int sb = gtbPenaltiedNumLaps(b);
    int d;
    if (sb < sa)
        return 1;
    if (sa < sb)
        return -1;
    if ((b->b4B2 | a->b4B2) == 0) {
        if (fb < fa) goto positive;
        if (fa < fb) return -1;
        goto equal;
    }
    if (b->b4B2 && a->b4B2) {
        d = b->i614 - a->i614;
        if (d < 0) return -1;
        if (d > 0) {
positive:
            return 1;
        }
equal:
        return 0;
    }
    if (ctx->bF81A == 2 || ctx->bCBDE == 1)
        return b->b4B2 != 0 ? -1 : 1;
    return b->b4B2 != 0 ? 1 : -1;
}
