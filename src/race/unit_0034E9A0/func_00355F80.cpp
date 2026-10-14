/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Sub {
    char p0[0x494];
    float f494;
    char p1[0x4E8 - 0x498];
    float f4E8;
    float f4EC;
    char p3[0x4FA - 0x4F0];
    short h4FA;
};
struct Obj {
    char p0[0x104];
    Sub sub;
};
extern float D_008438E8;
extern float D_008438EC;
extern float D_008438F0;
extern float D_008438F4;
extern "C" float func_003554A0(void *, float) throw();
extern "C" float func_00355D88(void *) throw();
extern "C" float func_00355E88(void *, float) throw();

extern "C" float func_00355F80(Obj *o) {
    Sub *s = &o->sub;
    float x = (float)s->h4FA;
    float lo = s->f494;
    if (func_00355D88(o) >= 1.0f)
        return func_003554A0(o, lo);
    float a = s->f4E8;
    float g = a * D_008438F0;
    float h = (D_008438F4 * 9542.84f) / x;
    float p = (D_008438E8 - x) * D_008438EC;
    if (h < g)
        g = h;
    float b = s->f4EC;
    p += (g + b) / (a + b);
    if (p < 0.0f)
        p = 0.0f;
    if (lo < p)
        lo = p;
    if (lo > 1.0f)
        lo = 1.0f;
    s->f494 = lo;
    float t = func_003554A0(o, lo) - g;
    float k = *(float *)((char *)o + 0x54C);
    func_00355E88(o, g * x * 0x1.B7860Ep-14f * k);
    return t;
}
