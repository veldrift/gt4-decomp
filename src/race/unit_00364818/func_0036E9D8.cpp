typedef float f32;

extern "C" f32 func_005F5010(f32 *arg0);

extern "C" void func_0036E9D8(f32 *arg0) {
    f32 len;
    f32 root;
    f32 *v;
    f32 *w;

    len = func_005F5010(arg0);
    __asm__("sqrt.s %0, %1" : "=f"(root) : "f"(len));
    v = arg0 + 1;
    w = arg0 + 2;
    if (!(root <= 0.0f)) {
        arg0[0] = arg0[0] / root;
        v[0] = v[0] / root;
        w[0] = w[0] / root;
    }
}
