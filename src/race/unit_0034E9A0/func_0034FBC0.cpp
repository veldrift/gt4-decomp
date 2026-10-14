/* compiler: ee-gcc2.96-no-strict-aliasing */
struct G { char p[0x18]; float f18, f1C, f20, f24, f28, f2C; };
struct D10 { char p[0x1064]; float f1064; };
struct Self { char p[0x10]; D10 *m10; };
extern G D_00843630;
extern "C" int Automobile__getDrawMode(Self *);

extern "C" float func_0034FBC0(Self *self, float *out) {
    if (Automobile__getDrawMode(self) != 3) return 0.0f;
    {
        char *b = (char *)self + 0x104;
        G *g = &D_00843630;
        float a = *(float *)(b + 0x53C);
        float r = g->f18 * self->m10->f1064 * a * a;
        r *= (1.0f - *(float *)(b + 0x5A0));
        float x = a;
        if (x < 0.0f) x = -x;
        float lo = g->f1C;
        float v;
        if (x < lo) v = g->f24;
        else {
            float hi = g->f20;
            if (hi < x) v = g->f28;
            else {
                float t = g->f24;
                v = t + (x - lo) * (g->f28 - t) / (hi - lo);
            }
        }
        *out = v;
        if (g->f2C < r) r = g->f2C;
        return r;
    }
}
