/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Dat { float f0, f4, f8; };
struct Inner { char p[0x4A4]; float f4a4; char q[0x650 - 0x4A8]; float f650; };
struct Obj { char p[4]; Obj *f4; char q[8]; Dat *d; char r[0x104 - 0x14]; Inner s; };
extern "C" float DynamicsConductor__GetCourseLength(Obj *);

extern "C" int func_003F42D0(Obj *a, Obj *b, float *o1, float *o2, float unused, float p)
{
    Inner *s1 = &a->s;
    Inner *s0 = &b->s;
    Dat *da = a->d;
    float f21 = da->f0;
    Dat *db = b->d;
    float f20 = db->f4;
    float f24 = db->f8;
    float f23 = da->f8;
    *(int *)o1 = 0;
    *(int *)o2 = 0;
    float len = DynamicsConductor__GetCourseLength(a->f4);
    int r = 0;
    float f2 = s1->f4a4;
    float f1 = s0->f4a4;
    float v;
    if (len * 0.75f < f2 && f1 < len * 0.25f)
        v = (f1 + len) - f2;
    else
        v = f1 - f2;
    float d = (v - f20) - f21;
    if (d <= 0.0f) return r;
    float g = s0->f650 - s1->f650;
    if (d < 20.0f) {
        float w = (f23 + f24) * 0.5f;
        if (w < p)
            return 0;
        if (p < -w)
            return 0;
    }
    *o1 = d;
    r = 1;
    *o2 = -g;
    return r;
}
