/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Rot {
    char p0[0x18];
    float f18, f1c, f20, f24, f28;
    int f2c, f30;
};

extern "C" void func_002CDBE8(Rot *a) {
    float t;
    if (a->f2c != 0)
        t = a->f1c;
    else
        t = a->f18;
    float cur = a->f20;
    float d = t - cur;
    if (a->f30 != 0) {
        while (d < 0.0f)
            d += 360.0f;
    } else {
        while (d > 0.0f)
            d -= 360.0f;
    }
    d *= a->f28;
    float r = cur + d;
    a->f20 = r;
    if (r < 0.0f)
        a->f20 = r + 360.0f;
    if (a->f20 >= 360.0f)
        a->f20 = a->f20 - 360.0f;
}
