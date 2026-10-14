typedef int s32;
struct A { char pad0[0x74]; s32 unk74; char data[8]; };
extern s32 D_0064B480;
extern A *D_0064B47C;
extern "C" s32 func_00535780(s32);
extern "C" s32 func_00536D60(s32, s32);
extern "C" s32 func_00539818(void *, s32);
extern "C" s32 func_00539990(void *, s32 *);
extern "C" s32 func_00530020(s32 arg0, s32 arg1) {
    s32 f = D_0064B480;
    if (f != 1) return 0x11;
    A *a = D_0064B47C;
    if (a->unk74 != f) return 0x2B;
    s32 r = func_00535780(func_00539818(a->data, 0));
    if (r != 0) return r;
    s32 s0 = func_00536D60(arg0, arg1);
    s32 r2 = func_00535780(func_00539990(D_0064B47C->data, 0));
    return r2 == 0 ? s0 : r2;
}
