struct Hold { char pad0[0x6C]; int f6C; int f70; int f74; char f78[1]; };
struct Out { int f0; int f4; };
extern Hold *D_0064B47C;
extern int D_0064B480;
extern int D_0064B484;
extern "C" int func_005328D0(int *, Out *);
extern "C" int func_00535780(int);
extern "C" int func_00536CF8();
extern "C" int func_00536D38();
extern "C" int func_00539788(void *);
extern "C" void func_005397D0(void *);

extern "C" int func_0052E568(int *a0, Out *a1) {
    Hold *h = D_0064B47C;
    h->f6C = 0xE4A;
    h->f74 = 0;
    h->f70 = 0;
    if (a1 == 0) return 0x17;
    a1->f4 = 0x12;
    a1->f0 = 1;
    if (a0 == 0) {
        a1->f4 = 0x17;
        return 0x17;
    }
    int s1 = *a0;
    if (s1 != 1) {
        a1->f4 = 0x26;
        return 0x17;
    }
    if (D_0064B484 != 0) {
        D_0064B484++;
        a1->f4 = 0;
        return 0;
    }
    if (h->f74 != 0 || func_00539788(h->f78) != 0) {
        a1->f4 = 0x2B;
        return 0x2B;
    }
    D_0064B47C->f74 = s1;
    D_0064B480 = s1;
    int r = func_00535780(func_00536CF8());
    if (r != 0) return r;
    int s0 = func_005328D0(a0, a1);
    r = func_00535780(func_00536D38());
    if (r != 0) return r;
    if (s0 != 0) {
        func_005397D0(D_0064B47C->f78);
        D_0064B47C->f74 = 0;
        D_0064B480 = 0;
        return s0;
    }
    D_0064B484 = s1;
    D_0064B480 = s1;
    return r;
}
