extern int D_0064B444;
extern char D_00863EC0[], D_00863F00[];
extern "C" int func_00570900(void *, void *, int, int, int *, int);
extern "C" int func_00522C48(int a, int b, int *out) {
    int local = 0;
    if (!D_0064B444) return 5;
    if (a < 0) return 2;
    *out = 0;
    int r = func_00570900(D_00863EC0, D_00863F00, a, b, &local, 0);
    if (r < 0) return 0xC350;
    *out = r;
    return 0;
}
