/* compiler: ee-gcc2.96-no-strict-aliasing */
struct VEntry { short delta; short index; int (*fn)(void *); };
struct Sub { char pad0[0x64]; char *vt; };
struct Context { char pad0[0x60]; int *mode; char pad64[0x20]; Sub *sub; };
struct Obj { int pad0; Context *ctx; char pad8[0x18]; int mode; };
extern "C" int RaceDisplay__get_aspec_point_available(Obj *self) {
    int result = 0;
    if (self->mode != 0) return result;
    Context *ctx = self->ctx;
    if (*ctx->mode < 2) return result;
    Sub *sub = ctx->sub;
    if (sub == 0) return result;
    VEntry *e = (VEntry *)(sub->vt + 0x2f8);
    switch (e->fn((char *)sub + e->delta)) {
    case 1:
    case 10:
    case 13:
    case 14: return 1;
    default: return 0;
    }
    return result;
}
