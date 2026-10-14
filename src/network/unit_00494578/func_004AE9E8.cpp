/* compiler: ee-gcc2.96-no-strict-aliasing */
extern "C" const signed char *func_004AE888(const signed char *) throw();
extern "C" const signed char *func_004AE8C8(const signed char *) throw();
extern "C" unsigned int func_0057F260(const signed char *) throw();
extern "C" int func_00594470(const signed char *, const signed char *, unsigned int);

extern "C" int func_004AE9E8(const signed char *a, const signed char *b) {
    if (a == 0 || b == 0) {
        return 0;
    }
    if (*a != '/') {
        return 0;
    }
    unsigned int la = func_0057F260(a);
    unsigned int lb = func_0057F260(b);
    if (la == 1) {
        return 1;
    }
    if (lb < la) {
        return 0;
    }
    const signed char *p = func_004AE888(a);
    const signed char *q = func_004AE888(b);
    while (*p != 0) {
        const signed char *e1 = func_004AE8C8(p);
        const signed char *e2 = func_004AE8C8(q);
        if (e1 - p != e2 - q) {
            return 0;
        }
        if (func_00594470(p, q, e1 - p) != 0) {
            return 0;
        }
        p = func_004AE888(e1);
        q = func_004AE888(e2);
    }
    return 1;
}
