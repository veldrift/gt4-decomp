extern int D_0064B444;
extern char D_00863EC0[], D_00863F00[];
extern "C" int func_00522480(void *) throw();
extern "C" int func_0056ECF8(void *, void *, int, void *, int, int, int);
extern "C" int func_00523190(int arg0, int *arg1) {
    char sp[16];
    if (!D_0064B444) return 5;
    if (!arg0) return 2;
    if (func_0056ECF8(D_00863EC0, D_00863F00, 0, sp, arg0, 0, 0) < 0) return 0xC350;
    *arg1 = func_00522480(sp);
    return 0;
}
