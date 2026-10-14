extern int D_0064B444;
extern "C" int func_00570E00(int, int *);
extern "C" int func_005232D0(int arg0, int *out) {
    int local = 0;
    int r = 5;
    if (D_0064B444 != 0) {
        r = 2;
        if (arg0 >= 0 && out != 0) {
            *out = 0;
            r = func_00570E00(arg0, &local);
            int value = local;
            if (r != 0) return 0xC350;
            if (value != 0) *out = 1;
            return r;
        }
    }
    return r;
}
