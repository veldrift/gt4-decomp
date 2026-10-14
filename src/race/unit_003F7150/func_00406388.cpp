/* compiler: ee-gcc2.96-no-strict-aliasing */
static inline float max_s(float a, float b) {
    float r;
    __asm__("max.s %0, %1, %2" : "=f"(r) : "f"(a), "f"(b));
    return r;
}
static inline float min_s(float a, float b) {
    float r;
    __asm__("min.s %0, %1, %2" : "=f"(r) : "f"(a), "f"(b));
    return r;
}

static inline float abs_s(float a) {
    float r;
    __asm__("abs.s %0, %1" : "=f"(r) : "f"(a));
    return r;
}

struct Obj { void *p0; char p4[4]; void *p8; char pC[0x104]; float f110; };

extern "C" float *func_00385BB8(void *);
extern "C" float *func_00385BC8(void *);
extern "C" float *func_003863D8(void *);
extern "C" float *func_003863E8(void *);
extern "C" void *DRIVERSUPPORT_NAME__GetMotoristDynamicParameter(void);
extern "C" float func_0044FA30(void *);
extern "C" float func_0044FA40(void *);
extern "C" float func_0044FA50(void *);
extern "C" float func_0044FA60(void *);

static inline void update_first(Obj *o, float a, float d0, float step)
{
    if (abs_s(d0) < step) {
        *func_00385BB8(o->p0) = a;
    } else {
        float *q;
        float v;
        if (d0 < 0.0f) {
            q = func_00385BB8(o->p0);
            v = *q - step;
        } else {
            q = func_00385BB8(o->p0);
            v = *q + step;
        }
        *q = v;
    }
}

extern "C" void func_00406388(Obj *o)
{
    float sp[4];
    const float k = 1.5707963f;

    float *s0 = func_003863D8(o->p8);
    sp[0] = (*s0 + k) * func_0044FA30(DRIVERSUPPORT_NAME__GetMotoristDynamicParameter());
    s0 = func_003863E8(o->p8);
    sp[1] = (k - *s0) * func_0044FA30(DRIVERSUPPORT_NAME__GetMotoristDynamicParameter());
    sp[2] = func_0044FA40(DRIVERSUPPORT_NAME__GetMotoristDynamicParameter());
    sp[3] = func_0044FA50(DRIVERSUPPORT_NAME__GetMotoristDynamicParameter());

    float *lo = &sp[2];
    float *hi = &sp[3];
    sp[0] = min_s(max_s(sp[0], *lo), *hi);
    float a = min_s(max_s(sp[0] / k, 0.0f), 1.0f);
    sp[1] = min_s(max_s(sp[1], *lo), *hi);
    float b = min_s(max_s(sp[1] / k, 0.0f), 1.0f);

    float step = func_0044FA60(DRIVERSUPPORT_NAME__GetMotoristDynamicParameter()) * o->f110 / k;
    float d0 = a - *func_00385BB8(o->p0);
    float d1 = b - *func_00385BC8(o->p0);
    update_first(o, a, d0, step);
    if (abs_s(d1) < step) {
        *func_00385BC8(o->p0) = b;
        return;
    }
    float *q;
    float v;
    if (d1 < 0.0f) {
        q = func_00385BC8(o->p0);
        v = *q - step;
    } else {
        q = func_00385BC8(o->p0);
        v = *q + step;
    }
    *q = v;
}
