extern int D_0064A274;
extern int D_0064A278;
extern "C" int func_00538BF8(int *, unsigned long long);
extern "C" int func_0050A338(int n) {
    int *p = &D_0064A274;
    if (*p == 0 && func_00538BF8(p, (unsigned int)(n * 4)) != 0) return -4;
    D_0064A278 = n;
    return 0;
}
