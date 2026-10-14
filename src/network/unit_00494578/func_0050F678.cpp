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
extern Obj *D_0064A55C;
extern Obj *D_0064A550;
extern int D_0064A560;
extern S1 D_00853818;
extern S2 D_00853830;
extern char D_006C2180[];
extern "C" int func_005109A0(S1 *, S2 *, Obj **) ;
extern "C" int func_0057D9C0(const char *fmt, ...);
extern "C" void func_0050FA98(void);
extern "C" void func_0050FAB8(void);
extern "C" void func_0050FA48(void);
extern "C" void func_0050FB10(void);

extern "C" int func_0050F678(int a0, int a1) {
    if (a0 == 0) {
        return -0xD;
    }
    D_00853818.a = a0;
    D_00853818.b = 0x16C;
    D_00853818.c = 0x66;
    D_00853818.d = (int)func_0050FA98;
    D_00853818.e = (int)func_0050FAB8;
    D_00853818.f = (int)func_0050FA48;
    D_00853830.a = a1;
    D_0064A560 = 0;
    D_00853830.b = 0;
    int r = func_005109A0(&D_00853818, &D_00853830, &D_0064A55C);
    if (r != 0) {
        func_0057D9C0(D_006C2180, r);
        D_0064A550->m10(D_0064A550);
        return -0xD;
    }
    r = D_0064A55C->m8(D_0064A55C, (int)func_0050FB10);
    if (r != 0) {
        D_0064A55C->m10(D_0064A55C);
        D_0064A55C = 0;
        return -0xD;
    }
    return r;
}
