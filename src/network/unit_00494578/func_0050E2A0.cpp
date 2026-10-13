typedef int s32;
typedef unsigned int u32;

extern int D_0064A308;
extern int D_0064A30C;
extern int D_008A04C0;
extern int D_008A0298;

extern "C" int func_0050B460(int arg0, int arg1, int arg2, int arg3);

extern "C" s32 func_0050E2A0(char *arg0, s32 arg1, s32 arg2) {
    char *self = arg0;
    self[0x14] = 0;
    s32 r = -0xF;
    if (D_0064A308 != 1)
        return r;
    r = -0x10;
    if (D_0064A30C == 0)
        return r;
    s32 v = *(s32 *)(self + 0x18);
    D_008A04C0 = arg1;
    D_008A0298 = arg2;
    if ((u32)v >= 0x64)
        *(s32 *)(self + 0x18) = 0;
    s32 c = func_0050B460(4, 0xF, 0x28, (int)self);
    s32 x = -5;
    if (c == 0)
        x = 0;
    return x;
}
