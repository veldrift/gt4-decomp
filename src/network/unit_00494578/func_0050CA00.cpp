typedef int s32;

extern int D_0064A308;
extern int D_0064A30C;
extern char D_008A01F8[];
extern char D_008A0420[];

extern "C" int func_0050B460(int arg0, int arg1, int arg2, int arg3);

extern "C" s32 func_0050CA00(char *arg0, s32 arg1, s32 arg2) {
    char *self = arg0;
    self[0x14] = 0;
    self[0x25] = 0;
    self[0x4F] = 0;
    s32 r = -0xF;
    if (D_0064A308 != 1)
        return r;
    r = -0x10;
    if (D_0064A30C == 0)
        return r;
    *(s32 *)D_008A0420 = arg1;
    *(s32 *)D_008A01F8 = arg2;
    s32 c = func_0050B460(1, 0x39, 0x50, (int)self);
    s32 x = -5;
    if (c == 0)
        x = 0;
    return x;
}
