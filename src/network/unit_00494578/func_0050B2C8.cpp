typedef int s32;

extern s32 D_0064A308;
extern s32 D_0064A30C;
extern s32 D_008A0234;
extern s32 D_008A045C;

extern "C" s32 func_0050B460(s32 arg0, s32 arg1, s32 arg2, s32 arg3);

extern "C" s32 func_0050B2C8(s32 arg0, s32 arg1, s32 arg2) {
    s32 r = -0xF;
    if (D_0064A308 != 1)
        return r;
    r = -0x10;
    if (D_0064A30C == 0)
        return r;
    D_008A045C = arg1;
    D_008A0234 = arg2;
    s32 c = func_0050B460(1, 0x86, 0x26, arg0);
    s32 x = -5;
    if (c == 0)
        x = 0;
    return x;
}
