typedef int s32;
typedef unsigned int u32;
typedef unsigned char u8;

extern u8 D_0064C0F4;
extern s32 D_0064C0FC;
extern s32 D_0064C100;
extern u32 D_0086B3DC;
extern u32 D_0086B3D8;

extern "C" s32 func_0053A228(u32 arg0, u32 arg1, s32 arg2) {
    s32 *cell;
    s32 *slot;
    s32 base;
    u32 off;
    u32 idx;

    if (D_0064C0F4 != 1) {
        return 5;
    }
    if (D_0064C0FC == 0) {
        return 5;
    }
    base = D_0064C100;
    if (base == 0) {
        return 5;
    }
    if (arg0 >= 0x100) {
        return 2;
    }
    if (arg1 >= D_0086B3DC) {
        return 2;
    }
    off = arg1 * 4;
    cell = (s32 *)(off + (u32)base);
    if ((u32)D_0086B3D8 < (u32)*cell) {
        return 0x3EB;
    }
    if (arg0 >= (u32)*cell) {
        *cell = arg0;
        *(s32 *)(off + (u32)D_0064C100) += 1;
    }
    idx = arg1 * D_0086B3D8 + arg0;
    slot = (s32 *)(idx * 4 + (u32)D_0064C0FC);
    if (*slot != 0) {
        return 0x3EA;
    }
    *slot = arg2;
    return 0;
}
