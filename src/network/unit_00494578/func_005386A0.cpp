struct O { int a,b,c,d,e; };
extern "C" int func_005385B0(O *, int *) throw();
extern "C" int func_005386A0(O *o, int *out) {
    int r = 2;
    int v = 0;
    if (o == 0) return r;
    if (out == 0) return r;
    r = func_005385B0(o, &v);
    if (r != 0) return r;
    if (v != 0) {
        int v_b = o->b;
        *out = o->e + v_b;
    } else {
        return 200;
    }
    return 0;
}
