extern int D_0064B444;
extern char D_00863EC0[], D_00863F00[];
extern "C" int func_005706F0(void *, void *, int, int, int, int *, int);
extern "C" int func_00522AE0(int a, int b, int c, int *out) {
    int local = 0;
    if (!D_0064B444) return 5;
    if (a < 0) return 2;
    int r = func_005706F0(D_00863EC0, D_00863F00, a, b, c, &local, 0);
    if (r < 0) return 0xC350;
    *out = r;
    return 0;
}
