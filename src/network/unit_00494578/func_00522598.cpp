extern int D_0064B444, D_0064B448, D_0064B44C, D_0064B450;
extern char D_00863EC0[64];
extern int D_00863F00;
extern "C" void func_00590978(int);
extern "C" int func_0056F9B8(void *, int, int, int);
extern "C" int func_0056FB10(void *, int *);
extern "C" long long func_00571788(void *, int *);
extern "C" int func_00523348();
extern "C" int func_00523498(int *);
extern "C" int func_00523510(int *);
extern "C" int func_00522598() {
    int *ready = &D_0064B444;
    if (*ready != 0) return 0xC351;
    func_00590978(0);
    func_0056F9B8(D_00863EC0, 0x800, 0x2000, 0x20);
    int *out = &D_00863F00;
    if (func_0056FB10(D_00863EC0, out) < 0) return 0xC350;
    func_00571788(D_00863EC0, out);
    int r = func_00523348();
    if (r != 0) return r;
    if (D_0064B450 < 0) return 0xC350;
    r = func_00523498(&D_0064B448);
    if (r != 0) return r;
    r = func_00523510(&D_0064B44C);
    if (r != 0) return r;
    *ready = 1;
    return r;
}
