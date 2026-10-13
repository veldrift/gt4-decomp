typedef int s32;

extern int D_0064A308;
extern int D_0064A30C;
extern char D_008A01AC[];
extern char D_008A03D4[];

extern "C" int func_0050B460(int arg0, int arg1, int arg2, int arg3);

extern "C" s32 func_0050C0C0(char *arg0, s32 arg1, s32 arg2) {
    char *self = arg0;
    self[0x14] = 0;
    self[0x25] = 0;
    self[0x4B] = 0;
    self[0x6B] = 0;
    self[0x8B] = 0;
    self[0xAB] = 0;
    self[0xCB] = 0;
    self[0xEB] = 0;
    self[0x10B] = 0;
    self[0x10E] = 0;
    self[0x12E] = 0;
    self[0x14E] = 0;
    self[0x15E] = 0;
    self[0x1AE] = 0;
    s32 r = -0xF;
    if (D_0064A308 != 1)
        return r;
    r = -0x10;
    if (D_0064A30C == 0)
        return r;
    *(s32 *)D_008A03D4 = arg1;
    *(s32 *)D_008A01AC = arg2;
    s32 c = func_0050B460(1, 0xD, 0x1B0, (int)self);
    s32 x = -5;
    if (c == 0)
        x = 0;
    return x;
}
