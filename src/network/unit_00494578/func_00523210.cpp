extern int D_0064B444;
extern char D_00863EC0[], D_00863F00[];
extern "C" int func_00522480(void *) throw();
extern "C" int func_00570BB0(void *, void *, int, int, void *, int);
extern "C" int func_00523210(int arg0, int *arg1) {
    char sp[0x4c];
    if (!D_0064B444) return 5;
    if (arg0 < 0) return 2;
    if (func_00570BB0(D_00863EC0, D_00863F00, arg0, 1, sp, 0x4c) != 1) return 0xC350;
    *arg1 = func_00522480(sp + 0x24);
    return 0;
}
