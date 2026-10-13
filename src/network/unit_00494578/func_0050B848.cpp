typedef int s32;

extern int D_0064A308;
extern int D_0064A30C;
extern int D_008A0194;
extern int D_008A03BC;

extern "C" int func_0050B460(int arg0, int arg1, int arg2, int arg3);

extern "C" s32 func_0050B848(char *arg0, s32 arg1, s32 arg2) {
    char *self = arg0;
    s32 r = -0xF;
    if (D_0064A308 != 1)
        return r;
    r = -0x10;
    if (D_0064A30C == 0)
        return r;
    self[0x14] = 0;
    D_008A03BC = arg1;
    D_008A0194 = arg2;
    s32 c = func_0050B460(1, 3, 0x1C, (int)self);
    s32 x = -5;
    if (c == 0)
        x = 0;
    return x;
}
