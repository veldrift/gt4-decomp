union I { int i; float f; };
struct W { I a0; char p[4]; I a8; char p1[0xa8]; float b4; char p2[0xc]; float c4; char p3[0x48]; float k; };
extern "C" float *func_00385B18(int);
extern "C" float *func_003861F8(int);
extern "C" float *func_00386338(int);
extern "C" float *DRIVERSUPPORT_NAME__GetMotoristDynamicParameter(void);
extern "C" float func_0044F8A0(float *);
union P { float *p; int i; };
struct St { float acc; P vel; P pos; };

extern "C" void func_004051E0(W *w)
{
    St s;
    float z = 0.0f;
    float *b4 = &w->b4;
    float *vel = func_003861F8(w->a8.i);
    float *pos = func_00386338(w->a8.i);
    s.vel.p = vel;
    s.pos.p = pos;
    s.acc = z;
    float *g = func_00385B18(w->a0.i);
    float r = *g / func_0044F8A0(DRIVERSUPPORT_NAME__GetMotoristDynamicParameter());
    s.acc = s.acc + ((1.0f - r) * -0x1.399998p+3f - r * 0x1.87fffep+5f);
    s.acc = s.acc - *s.vel.p * z;
    float k = w->k;
    *s.vel.p += s.acc * k;
    *s.pos.p += *s.vel.p * k;
    s.acc = z;
    if (*func_00386338(w->a8.i) <= *b4) {
        *func_00386338(w->a8.i) = *b4;
        *func_003861F8(w->a8.i) = w->c4;
    } else {
        float *p = func_00386338(w->a8.i);
        if (*b4 + func_0044F8A0(DRIVERSUPPORT_NAME__GetMotoristDynamicParameter()) < *p) {
            float *q = func_00386338(w->a8.i);
            *q = *b4 + func_0044F8A0(DRIVERSUPPORT_NAME__GetMotoristDynamicParameter());
        }
    }
    float *t = func_00385B18(w->a0.i);
    *t = *func_00386338(w->a8.i) - *b4;
}
