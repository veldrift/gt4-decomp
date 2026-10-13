typedef int s32;

extern int D_0064A308;
extern int D_0064A30C;

extern "C" int func_0050B460(int arg0, int arg1, int arg2, int arg3);

extern "C" s32 func_0050CDC8(char *arg0) {
    char *self = arg0;
    self[0x14] = 0;
    self[0x2C] = 0;
    s32 r = -0xF;
    if (D_0064A308 != 1)
        return r;
    r = -0x10;
    if (D_0064A30C == 0)
        return r;
    s32 c = func_0050B460(4, 7, 0x38, (int)self);
    s32 x = -5;
    if (c == 0)
        x = 0;
    return x;
}
