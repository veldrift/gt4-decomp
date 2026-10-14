extern "C" void func_00530E08(void);
extern "C" int func_00535680(void);
extern "C" int func_00535780(int);
extern "C" int func_00536CF8(void);
extern "C" int func_00536D38(void);
extern "C" int func_005397D0(unsigned char *);
struct Q {
    char pad[0x74];
    int m74;
};
extern unsigned int D_0064B484;
extern int D_0064B480;
extern Q *D_0064B47C;

extern "C" int func_0052E6D8(void) {
    unsigned int n = D_0064B484;
    if (n == 0) {
        return 0x11;
    }
    if (n >= 2) {
        D_0064B484 = n - 1;
        return 0;
    }
    int r = func_00535780(func_00536CF8());
    if (r != 0) {
        return r;
    }
    int s1 = func_00535680();
    r = func_00535780(func_00536D38());
    if (r != 0) {
        return r;
    }
    if (s1 == 0) {
        r = func_00535780(func_005397D0((unsigned char *)D_0064B47C + 0x78));
        if (r != 0) {
            return r;
        }
        D_0064B47C->m74 = 0;
        D_0064B480 = 0;
        D_0064B484 = 0;
    }
    func_00530E08();
    return s1;
}
