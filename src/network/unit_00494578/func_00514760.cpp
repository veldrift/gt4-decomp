typedef int s32;
typedef short s16;
struct G { char p[0x10]; s32 f10; char p14[4]; s32 f18; };
struct Obj { char p[0x18]; s32 f18; };
extern G D_008A0398;
extern s16 D_0064A310;
extern void (*D_008A04D8)(Obj *, s32);
extern s32 D_008A02B0;
extern "C" s32 func_00514760(s32 a, s32 b, s32 c, Obj *o) {
    if (o->f18 == 0 && D_008A0398.f10 != 0) D_0064A310 = 1;
    if (D_008A0398.f18 == 1) {
        D_008A0398.f18 = 0;
    } else if (D_008A04D8 != 0) {
        D_008A04D8(o, D_008A02B0);
    }
    return 0x34;
}
