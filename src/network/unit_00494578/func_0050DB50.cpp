struct O {
    int f0; int f4; char s8[0x10]; int f18; int f1c; char f20; char pad21[0xF]; int f30; int f34;
    char buf38[0x40]; char s78[0x11]; char f89; char pad8a[0x12]; char b9c[0x68]; int f104; int f108; int f10c; int f110;
};
extern "C" int func_00533650(unsigned char *);
extern "C" int func_0057F260(const char *);
extern "C" void *func_005A4724(void *, const void *, unsigned int);
extern "C" void *func_005A48D8(void *, int, unsigned int);
extern "C" void func_005A6AB0(void *, const char *, int);

extern "C" void func_0050DB50(O *o, const char *a1, const char *a2, int a3, int t0) {
    unsigned char sp[0x140];
    func_005A48D8(o, 0, 0x114);
    func_00533650(sp);
    func_005A4724(o->b9c, sp + 0xCC, 0x68);
    o->f34 = t0;
    o->f0 = 1;
    if (a1 != 0) func_005A6AB0(o->s78, a1, func_0057F260(a1) + 1);
    else o->s78[0] = 0;
    o->f104 = 0x40;
    func_005A48D8(o->buf38, 0, 0x40);
    o->f89 = 0;
    o->f4 = 1;
    func_005A6AB0(o->s8, a2, func_0057F260(a2) + 1);
    o->f18 = a3;
    o->f1c = 0;
    o->f20 = 0;
    o->f30 = 0;
    o->f108 = 0;
    o->f10c = 0;
    o->f110 = 0;
}
