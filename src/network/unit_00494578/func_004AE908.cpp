/* compiler: ee-gcc2.96-no-strict-aliasing */
extern "C" const signed char *func_004AE888(const signed char *) throw();
extern "C" const signed char *func_004AE8C8(const signed char *) throw();
extern "C" int func_00594470(const signed char *, const signed char *, unsigned int);

extern "C" const signed char *func_004AE908(const signed char *a, const signed char *b) {
    if (a == 0) {
        return b;
    }
    const signed char *p = func_004AE888(a);
    const signed char *q = func_004AE888(b);
    while (*p != 0) {
        const signed char *e1 = func_004AE8C8(p);
        const signed char *e2 = func_004AE8C8(q);
        if (e1 - p != e2 - q) {
            break;
        }
        if (func_00594470(p, q, e1 - p) != 0) {
            break;
        }
        p = func_004AE888(e1);
        q = func_004AE888(e2);
    }
    return func_004AE888(q);
}
