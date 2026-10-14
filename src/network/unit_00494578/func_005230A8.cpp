typedef int s32;
typedef unsigned int u32;
extern s32 D_0064B444;
extern "C" s32 func_00570BE0(s32, s32 *);
extern "C" s32 func_005230A8(s32 a, s32 *out) {
    s32 local = 0;
    if (D_0064B444 == 0) return 5;
    if (a < 0) return 2;
    *out = 0;
    s32 r = func_00570BE0(a, &local);
    if (r < 0) return ((u32)(r + 0x1FE) < 3) ? 0xC356 : 0xC350;
    if (local & 4) return 0xC356;
    *out = r;
    return 0;
}
