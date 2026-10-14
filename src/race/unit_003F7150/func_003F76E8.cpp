/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Q {
    char p0[0x4E8];
    float f4E8, f4EC;
    char p4F0[0x520 - 0x4F0];
    unsigned char f520;
    char p521[0x53C - 0x521];
    float f53C;
    char p540[0x5BC - 0x540];
    float f5BC;
};
struct Obj { char p0[0x10]; char *f10; char p14[0xF0]; Q q; };

extern "C" float func_003F76E8(Obj *o, float x)
{
    Q *q = &o->q;
    char *b = o->f10;
    x += 0x1.1c71c6p-3f;
    float f3 = q->f53C;
    if (q->f520 == 0) f3 = -f3;
    float f5 = q->f4EC;
    float f4 = q->f4E8 + f5;
    float r;
    if (f4 <= 0.0f) { r=1.0f; } else {
        float c = *(float *)(b + q->f520 * 4 + 0x29C);
        r = (q->f5BC + f5 * c) / (f4 * c) - (f3 - x) / 0x1.638e36p+0f;
        if (r > 1.0f) {
            r = 1.0f;
        } else if (r < 0.0f) {
            r = 0.0f;
        }
    }
    return r;
}
