/* compiler: ee-gcc2.96-no-strict-aliasing */
struct W { void *a0; int a4; void *a8; int ac; int *a10; void *a14; void *a18; char pad[0xf4]; float dt; float rate; };
struct Info { char pad[0x6a]; unsigned short kind; };
struct Car { char pad[0x50]; Info *info; };
extern "C" float func_00385478(void *, int);
extern "C" float *func_00385BA8(void *);
extern "C" float *func_00386468(void *, int);
extern "C" int func_00386480(void *);
extern "C" Car *func_0038DC18(void *);
extern "C" int func_00402270(void *, int) throw();
extern "C" float func_0040CD10(void *);
extern "C" void *DRIVERSUPPORT_NAME__GetMotoristDynamicParameter();
extern "C" float func_0044FAA0(void *);
struct St { float acc; float *vel; float *pos; };
static inline float maximum(float a, float b) { float r; __asm__("max.s %0, %1, %2" : "=f"(r) : "f"(a), "f"(b)); return r; }
static inline float minimum(float a, float b) { float r; __asm__("min.s %0, %1, %2" : "=f"(r) : "f"(a), "f"(b)); return r; }
static inline float minr(const float &a, const float &b) { return minimum(a, b); }
static inline float maxr(const float &a, const float &b) { return maximum(a, b); }
static inline float clamp(const float &v, const float &lo, const float &hi) { return minimum(maximum(v, lo), hi); }
static inline void init(St *s, float *v, float *p, float z) { s->acc = z; s->vel = v; s->pos = p; }
static inline void step(St *s, float target, float dt) {
    s->acc += (target - *s->pos)*400.0f;
    s->acc -= *s->vel * 40.0f;
    *s->vel += s->acc * dt;
    float v = *s->vel;
    float limit = 0x1.f6a7a0p+4f;
    if (v*v > 0x1.ed7aeap+9f) {
        if (v > 0.0f) *s->vel = limit;
        else *s->vel = -limit;
    }
    *s->pos += *s->vel * dt;
    s->acc = 0.0f;
}
extern "C" float func_00403F90(W *w, int arg) {
    float target = 0.0f;
    float vel = *func_00386468(w->a8, 0);
    St s;
    init(&s, &vel, func_00385BA8(w->a0), 0.0f);
    switch (func_00402270(w->a14, *w->a10)) {
    case 3: {
        target = -func_0040CD10(w->a18)*540.0f/30.0f;
        float hi = 0x1.921fb4p+1f; float lo = -0x1.921fb4p+1f;
        target = clamp(target, lo, hi);
        step(&s, target, w->dt);
        break;
    }
    case 4: case 5: {
        target = -func_0040CD10(w->a18)*135.0f/30.0f;
        float hi = 0x1.2d97c6p+1f; float lo = -0x1.2d97c6p+1f;
        target = clamp(target, lo, hi);
        step(&s, target, w->dt);
        break;
    }
    default:
        target = func_00385478(w->a18, arg);
        float hi = func_0044FAA0(DRIVERSUPPORT_NAME__GetMotoristDynamicParameter());
        float lo = -func_0044FAA0(DRIVERSUPPORT_NAME__GetMotoristDynamicParameter());
        Car *car = func_0038DC18(w->a14);
        if (car && car->info && car->info->kind == 1) {
            hi = minr(0x1.921fb4p+0f, hi);
            lo = maxr(-0x1.921fb4p+0f, lo);
        }
        target = clamp(target, lo, hi);
        *s.vel = (target - *func_00385BA8(w->a0)) * w->rate;
        *s.pos = target;
        break;
    }
    float sum = 0.0f;
    for (int i = func_00386480(w->a8)-1; i > 0; --i) {
        float *p = func_00386468(w->a8, i);
        float v = *func_00386468(w->a8, i-1);
        *p = v;
        sum += v;
    }
    float *out = func_00386468(w->a8, 0);
    float last = *s.vel;
    *out = last;
    sum += last;
    return sum/(float)func_00386480(w->a8);
}
