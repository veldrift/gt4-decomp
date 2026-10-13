typedef int s32;

struct Blk36 {
    s32 w[9];
};

extern "C" void func_00576788(s32 a0);
extern "C" void func_005767C0(s32 a0);
extern "C" void func_0060EC88(void *self, int arg1);

extern "C" void *func_004F48E8(void *arg0, s32 arg1) {
    Blk36 b;
    Blk36 a;
    char *s2;
    char *base;
    char *e;
    s32 n;

    s2 = (char *)arg1 + 8;
    func_00576788((s32)s2);
    base = (char *)arg1 + 0x39A4;
    n = *(s32 *)(base + 4);
    e = base + n * 0x24;
    a = *(Blk36 *)(e + 0xC);
    func_0060EC88(base, 1);
    b = a;
    func_005767C0((s32)s2);
    *(Blk36 *)arg0 = b;
    return arg0;
}
