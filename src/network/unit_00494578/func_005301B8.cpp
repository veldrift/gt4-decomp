typedef int s32;
struct S { char pad[0x74]; s32 f74; char f78[4]; };
extern S *D_0064B47C;
extern s32 D_0064B480;
extern "C" s32 func_00535780(s32);
extern "C" s32 func_00536E20(s32);
extern "C" s32 func_00539818(void *, s32);
extern "C" s32 func_00539990(void *, s32 *);
extern "C" s32 func_005301B8(s32 arg) {
    s32 st = D_0064B480;
    if (st != 1) return 0x11;
    if (D_0064B47C->f74 != st) return 0x2B;
    s32 r = func_00535780(func_00539818(D_0064B47C->f78, 0));
    if (r != 0) return r;
    s32 s0 = func_00536E20(arg);
    r = func_00535780(func_00539990(D_0064B47C->f78, 0));
    return r ? r : s0;
}
