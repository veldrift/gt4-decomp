typedef int s32;

extern s32 D_0064A308;
extern s32 D_0064A30C;
extern s32 D_0064A350;
extern char D_008A01BC[];
extern char D_008A03E4[];

extern "C" int func_0050B460(int arg0, int arg1, int arg2, int arg3);

extern "C" s32 func_0050C170(s32 arg0, s32 arg1, s32 arg2) {
    s32 r = -0xF;
    s32 t = D_0064A308;
    if (t != 1)
        return r;
    r = -0x10;
    if (D_0064A30C == 0)
        return r;
    r = -0x14;
    if (D_0064A350 == t)
        return r;
    *(s32 *)D_008A03E4 = arg1;
    *(s32 *)D_008A01BC = arg2;
    s32 c = func_0050B460(1, 0x13, 0x46, arg0);
    s32 x = -5;
    if (c == 0)
        x = 0;
    return x;
}
