typedef int s32;

extern int D_0064A308;
extern int D_0064A30C;
extern int D_0064A350;
extern char D_008A01B0[];
extern char D_008A03D8[];

extern "C" int func_0050B460(int arg0, int arg1, int arg2, int arg3);

extern "C" s32 func_0050BFB0(char *arg0, s32 arg1, s32 arg2) {
    char *self = arg0;
    self[0x14] = 0;
    self[0x25] = 0;
    self[0x45] = 0;
    self[0x65] = 0;
    s32 t = D_0064A308;
    s32 r = -0xF;
    if (t != 1)
        return r;
    r = -0x10;
    if (D_0064A30C == 0)
        return r;
    r = -0x14;
    if (D_0064A350 == t)
        return r;
    *(s32 *)D_008A03D8 = arg1;
    *(s32 *)D_008A01B0 = arg2;
    s32 c = func_0050B460(1, 0xF, 0x1B0, (int)self);
    s32 x = -5;
    if (c == 0)
        x = 0;
    return x;
}
