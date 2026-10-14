typedef int s32;
struct A { char pad0[0x74]; s32 unk74; char data[8]; };
struct Vt { char pad0[0xE0]; s32 (*fE0)(s32); };
extern s32 D_0064B480;
extern A *D_0064B47C;
extern Vt *D_0064B4B4;
extern "C" s32 func_00535780(s32);
extern "C" s32 func_00539818(void *, s32);
extern "C" s32 func_00539990(void *, s32 *);
extern "C" s32 func_005300C8(s32 arg0) {
    s32 f = D_0064B480;
    if (f != 1) return 0x11;
    A *a = D_0064B47C;
    if (a->unk74 != f) return 0x2B;
    if (D_0064B4B4 == 0) return 0x11;
    s32 r = func_00535780(func_00539818(a->data - 0 + 0, 0));
    if (r != 0) return r;
    s32 s0 = D_0064B4B4->fE0(arg0);
    s32 r2 = func_00535780(func_00539990(D_0064B47C->data, 0));
    return r2 == 0 ? s0 : r2;
}
