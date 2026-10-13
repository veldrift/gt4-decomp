typedef int s32;
typedef unsigned int u32;
typedef unsigned char u8;

extern u8 D_0064C0F4;
extern s32 D_0064C0FC;
extern s32 D_0064C100;
extern u32 D_0086B3DC;
extern u32 D_0086B3D8;

extern "C" s32 func_0053A510(u32 arg0, u32 arg1, s32 *arg2) {
    u32 n0 = arg0;
    u32 n1 = arg1;
    s32 base;
    u32 lim;
    u32 mul;
    s32 v;

    if (arg2 == 0) {
        return 2;
    }
    *arg2 = 0;
    if (D_0064C0F4 != 1) {
        return 5;
    }
    base = D_0064C0FC;
    if (base == 0) {
        return 5;
    }
    if (D_0064C100 == 0) {
        return 5;
    }
    lim = D_0086B3DC;
    if (n0 >= lim) {
        return 2;
    }
    mul = D_0086B3D8;
    if (n1 >= mul) {
        return 2;
    }
    v = *(s32 *)((((n0 * mul) + n1) * 4) + base);
    *arg2 = v;
    return (v != 0) ? 0 : 2;
}
