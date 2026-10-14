/* compiler: ee-gcc2.96-no-strict-aliasing */
extern int D_0064C3E4;
extern "C" void func_005499E0(void *) throw();
extern "C" int func_0054A370(void) throw();
extern "C" int func_0054A4A0(int);
extern "C" void func_0054BEA0(void);
extern "C" void func_0054BEC8(void);
extern "C" int func_0054A400(int n) {
    if (func_0054A370() == 0) return 0;
    {
        func_0054BEA0();
        int base = D_0064C3E4;
        int q = n / 4;
        int r = n % 4;
        func_005499E0((void *)(((r * 0x1b + q * 0x6f) << 2) + base + 0x78));
        n = func_0054A4A0(n);
        func_0054BEC8();
    }
    return n;
}
