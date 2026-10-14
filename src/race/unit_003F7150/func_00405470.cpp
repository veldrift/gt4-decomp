union I { int i; float f; };
struct W { I a0; char p[4]; I a8; char p1[0xc]; I a18; char p2[0xf4]; float k; };
extern "C" float func_003446A8(int);
extern "C" float *func_00385B28(int);
extern "C" float *func_00386208(int);
union P { float *p; int i; };
struct St { float acc; P vel; P pos; };
static inline void fix(St *s, float a, float v, float p) { s->acc = a; *s->vel.p = v; *s->pos.p = p; }
static inline void clampp(St *s, float zero)
{
    float p = *s->pos.p;
    if (p > 1.0f) fix(s, zero, zero, 1.0f);
    else if (p < zero) fix(s, zero, zero, zero);
}

extern "C" void func_00405470(W *w)
{
    St s;
    float z = 0.0f;
    float target = func_003446A8(w->a18.i);
    float *vel = func_00386208(w->a8.i);
    float *pos = func_00385B28(w->a0.i);
    s.vel.p = vel;
    s.pos.p = pos;
    s.acc = z;
    s.acc = (target - *pos) * 23.0f + s.acc;
    s.acc = s.acc - *vel * 10.0f;
    float k = w->k;
    *vel += s.acc * k;
    *pos += *vel * k;
    s.acc = z;
    if ((*func_00386208(w->a8.i) > z && target < *func_00385B28(w->a0.i)) ||
        (*func_00386208(w->a8.i) < z && *func_00385B28(w->a0.i) < target)) {
        s.acc = 0.0f;
        float a = s.acc;
        float k2 = w->k;
        s.acc = (target - *s.pos.p) * 69.0f + a;
        s.acc = s.acc - *s.vel.p * 17.32f;
        *s.vel.p += s.acc * k2;
        *s.pos.p += *s.vel.p * k2;
        s.acc = a;
    }
    clampp(&s, 0.0f);
}
