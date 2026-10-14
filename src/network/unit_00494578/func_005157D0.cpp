struct V { char pad[0x7C]; int (*f7c)(int, int, int, int, int, int, int, int, int, int); };
extern "C" V *D_0064B4B4;
extern "C" int func_00535780(int);
extern "C" int func_00536CF8(void);
extern "C" int func_00536D38(void);

extern "C" int func_005157D0(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int s0, int s1) {
    int r = func_00535780(func_00536CF8());
    if (r == 0) {
        int t = D_0064B4B4->f7c(a0, a1, a2, a3, a4, a5, a6, a7, s0, s1);
        r = func_00535780(func_00536D38());
        if (r == 0) r = t;
    }
    return r;
}
