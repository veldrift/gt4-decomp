typedef int s32;
typedef unsigned char u8;
extern "C" s32 func_005428E8(u8 *) throw();
extern "C" s32 func_005434B8(s32, s32, u8 *) throw();
extern "C" s32 func_00543548(s32 a0, s32 a1, u8 *a2) {
    u8 buf[0x40];
    s32 i;
    if (func_005428E8(a2) != 0) return -1;
    if (func_005434B8(a0, a1, buf) != 0) return 1;
    i = 0x3F;
    do {
        u8 x = a2[i];
        u8 y = buf[i];
        if (y < x) return 1;
        if (x < y) return -1;
    } while (i-- > 0);
    return 0;
}
