typedef int s32;

struct Blk40 {
    s32 w[10];
};

extern "C" void func_00576788(s32 a0);
extern "C" void func_005767C0(s32 a0);
extern "C" void func_0060ECB0(void *self, int arg1);

extern "C" void *func_004F4B00(void *arg0, s32 arg1) {
    Blk40 b;
    Blk40 a;
    char *s2;
    char *base;
    char *e;
    s32 n;

    s2 = (char *)arg1 + 8;
    func_00576788((s32)s2);
    base = (char *)arg1 + 0x3BF4;
    n = *(s32 *)(base + 4);
    e = base + n * 0x28;
    a = *(Blk40 *)(e + 0xC);
    func_0060ECB0(base, 1);
    b = a;
    func_005767C0((s32)s2);
    *(Blk40 *)arg0 = b;
    return arg0;
}
