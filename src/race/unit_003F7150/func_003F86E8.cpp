/* compiler: ee-gcc2.96-no-strict-aliasing */
static inline float fsqrt(float x) {
    float r;
    __asm__("sqrt.s %0, %1" : "=f"(r) : "f"(x));
    return r;
}
struct Obj {
    char p0[0x48];
    float f48;
    char p4C[0x234 - 0x4C];
    char f234[0x418 - 0x234];
    float f418;
    char p41C[0xFD0 - 0x41C];
    float fFD0;
    float fFD4;
    char pFD8[0x103C - 0xFD8];
    float f103C;
    char p1040[0x1068 - 0x1040];
    float f1068;
    float f106C;
    float f1070;
    char p1074[3];
    unsigned char b1077;
    char p1078[0x1084 - 0x1078];
    float f1084;
};
struct In { float f0; float f4; };
extern "C" float func_00356EA8(void *);

extern "C" float func_003F86E8(Obj *o, In *in)
{
    float a = in->f0;
    a += func_00356EA8(o->f234);
    float p = (o->f106C + o->f1070) * 0.5f;
    float d = o->f1068;
    d = p - d;
    d += 1.0f;
    float q = (o->fFD0 + o->fFD4) * 0.5f;
    if (o->b1077 == 7) q *= o->f1084 / o->f103C + 1.0f;
    float k = o->f48;
    k *= fsqrt(k);
    p = o->f418 * o->f418 * a * a * fsqrt(in->f4);
    k = p / k;
    p = k * d * q;
    p = fsqrt(fsqrt(fsqrt(p))) / 2.5f;
    if (p > 1.0f) p = 1.0f;
    if (p < 0.0f) p = 0.01f;
    return p;
}
