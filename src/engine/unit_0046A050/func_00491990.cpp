struct E { char p[0x14]; };
struct O {
    int f0;
    E *f4;
    unsigned short f8, fA;
    char pad[4];
    unsigned char f10;
    char pad2[3];
    unsigned char f14;
    char pad3[3];
    int f18;
    int f1C;
};
extern "C" void func_00491B00(E *, int);
static inline void adj(int *p, int a) { if (*p) *p += a; }
extern "C" void func_00491990(O *o, int a, int b) {
    adj(&o->f0, a);
    adj((int *)&o->f4, a);
    if (o->f18) adj(&o->f18, a);
    if (o->f4) {
        int i = o->f8;
        while (o->fA >= i) {
            func_00491B00(o->f4 + (i - o->f8), a);
            i++;
        }
    }
    o->f1C = b;
    o->f14 = o->f10;
}
