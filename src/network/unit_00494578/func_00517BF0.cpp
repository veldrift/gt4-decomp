struct R {
    char pad0[0xC];
    int mC;
    int m10;
    char pad14[0x2C - 0x14];
    char sub[8];
    int m34;
    char pad38[4];
    int m3C;
};
struct G {
    char pad[0x104];
    int m104;
};
extern G *D_00854150;
extern "C" R *func_00515EE8(unsigned int) throw();
extern "C" int func_00518620(int *, unsigned int);
extern "C" int func_00538228(char *, int, int);
extern "C" void func_00538418(char *, int);
extern "C" void *func_005A4724(int, int, int);

extern "C" int func_00517BF0(unsigned int a0, int a1, int a2) {
    int sp0;
    int r = 0x17;
    sp0 = 0;
    if (a0 >= 0x200) {
        return r;
    }
    if (a1 == 0) {
        return r;
    }
    if (a2 <= 0) {
        return r;
    }
    r = func_00518620(&sp0, a0);
    if (r != 0) {
        return r;
    }
    if (sp0 < a2) {
        return 0x1F;
    }
    R *p = func_00515EE8(a0);
    if (p == 0) {
        return 0x17;
    }
    G *g = D_00854150;
    if (g == 0) {
        return 8;
    }
    if (g->m104 != p->mC) {
        return 9;
    }
    char *s1 = p->sub;
    if (func_00538228(s1, a1, a2) != 0) {
        return 0x1F;
    }
    func_00538418(s1, 1);
    func_005A4724(p->m10, p->m3C, p->m34);
    return 0;
}
