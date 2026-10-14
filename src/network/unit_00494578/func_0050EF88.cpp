struct Obj {
    int m0, m4;
    int (*m8)(Obj *, int);
    int mC;
    void (*m10)(Obj *);
};
struct S1 {
    int a, b, c, d, e, f;
};
struct S2 {
    int a, b;
};
extern Obj *D_0064A550;
extern int D_0064A554;
extern S1 D_008537F8;
extern S2 D_00853810;
extern char D_006C1FC8[];
extern "C" int func_005109A0(S1 *, S2 *, Obj **) ;
extern "C" void func_0057D9C0(const char *fmt, ...);
extern "C" void func_0050F3A8(void);
extern "C" void func_0050F3C8(void);
extern "C" void func_0050F358(void);
extern "C" void func_0050F420(void);

extern "C" int func_0050EF88(int a0, int a1) {
    if (a0 == 0) {
        return -0xD;
    }
    D_008537F8.a = a0;
    D_008537F8.b = 0x134;
    D_008537F8.c = 0x66;
    D_008537F8.d = (int)func_0050F3A8;
    D_008537F8.e = (int)func_0050F3C8;
    D_008537F8.f = (int)func_0050F358;
    D_00853810.a = a1;
    D_0064A554 = 0;
    D_00853810.b = 0;
    int r = func_005109A0(&D_008537F8, &D_00853810, &D_0064A550);
    if (r != 0) {
        func_0057D9C0(D_006C1FC8, r);
        return -0xD;
    }
    r = D_0064A550->m8(D_0064A550, (int)func_0050F420);
    if (r != 0) {
        D_0064A550->m10(D_0064A550);
        D_0064A550 = 0;
        return -0xD;
    }
    return r;
}
