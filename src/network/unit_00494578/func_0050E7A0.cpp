typedef int s32;

extern int D_0064A308;
extern int D_0064A30C;
extern int D_0064A32C;
extern char D_008A05A8[];
extern char D_008A0380[];

extern "C" int func_0050B460(int arg0, int arg1, int arg2, int arg3);

extern "C" s32 func_0050E7A0(char *arg0, s32 arg1, s32 arg2) {
    char *self = arg0;
    self[0x14] = 0;
    s32 r = -0xF;
    s32 st = D_0064A308;
    if (st != 1)
        return r;
    r = -0x10;
    if (D_0064A30C == 0)
        return r;
    r = -0x14;
    if (D_0064A32C != st)
        return r;
    *(s32 *)D_008A05A8 = arg1;
    *(s32 *)D_008A0380 = arg2;
    s32 c = func_0050B460(4, 0x18, 0xDD, (int)self);
    s32 x = -5;
    if (c == 0)
        x = 0;
    return x;
}
