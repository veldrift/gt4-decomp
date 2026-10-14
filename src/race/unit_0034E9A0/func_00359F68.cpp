/* compiler: ee-gcc2.96-no-strict-aliasing */
static inline float fsqrt(float x) {
    float r;
    __asm__("sqrt.s %0, %1" : "=f"(r) : "f"(x));
    return r;
}

struct S {
    char pad0[0x10];
    float f10, f14;
    char pad18[0x28 - 0x18];
    float f28, f2C, f30, f34, f38;
    char pad3C[0x68 - 0x3C];
    float f68, f6C, f70, f74;
};

extern "C" float func_0057D1F0(float);
extern "C" float func_0057D2B8(float) throw();

extern "C" void func_00359F68(S *s) {
    s->f68 = fsqrt(s->f10 * s->f10 + s->f14 * s->f14);
    float a = func_0057D1F0(s->f30);
    float b = func_0057D2B8(s->f30);
    float c = s->f34;
    float d = s->f38;
    float x = (s->f28 + (c * b)) - (d * a);
    float e = (s->f2C - (c * a)) - (d * b);
    s->f6C = x;
    s->f70 = e;
    s->f74 = s->f14 - e;
}
