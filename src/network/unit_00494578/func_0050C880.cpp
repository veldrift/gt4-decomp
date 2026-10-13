typedef int s32;

extern int D_0064A308;
extern int D_0064A30C;
extern char D_008A01E8[];
extern char D_008A0410[];

extern "C" int func_0050B460(int arg0, int arg1, int arg2, int arg3);

extern "C" s32 func_0050C880(char *arg0, s32 arg1, s32 arg2) {
    char *self = arg0;
    self[0x14] = 0;
    self[0x25] = 0;
    s32 r = -0xF;
    if (D_0064A308 != 1)
        return r;
    r = -0x10;
    if (D_0064A30C == 0)
        return r;
    *(s32 *)D_008A0410 = arg1;
    *(s32 *)D_008A01E8 = arg2;
    s32 c = func_0050B460(1, 0x31, 0x2C, (int)self);
    s32 x = -5;
    if (c == 0)
        x = 0;
    return x;
}
