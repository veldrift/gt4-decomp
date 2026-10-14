struct V { char pad[0x7C]; int (*f7c)(int, double, V *); };
extern "C" V *D_0064B4B0;
extern "C" int func_00531040(double *) throw();

extern "C" int func_005318C0(int a) {
    double v;
    int r = 0x17;
    if (a != 0) {
        func_00531040(&v);
        V *vt = D_0064B4B0;
        vt->f7c(a, v, vt);
        r = 0;
    }
    return r;
}
