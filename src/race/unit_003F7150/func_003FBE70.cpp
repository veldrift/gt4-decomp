/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Q { char p0[0x6C8]; float f6C8; };
struct P { char p0[0x18]; Q *q; };
struct W { char p0[0x80]; void *f80; };
struct X {
    int i2C;
    float f30;
    float f34;
    float f38;
    int i3C;
    float c[3];
    float d[3];
    int j58;
    float k5C;
    float k60;
    float k64;
    int j68;
};
struct S {
    W *w;
    char p4[8];
    short h0C;
    char p0E[2];
    P *p;
    float a[3];
    float b[3];
    X x;
};

extern "C" void func_005F5040(float *, float *);
extern "C" int func_00343BC0(Q *);
extern "C" float func_00344798(Q *, float);
extern "C" float func_003447C8(Q *, float);
extern "C" float func_003447F8(Q *, float);
extern "C" float func_00344828(Q *, float);
extern "C" float func_00344858(Q *, float);
extern "C" float func_00344888(Q *, float);
extern "C" float func_003448B8(Q *, float);
extern "C" float RaceCourse__getCourseLength(void *);
extern "C" int func_00396118(void *);
extern "C" int func_003FCAB0(W *, int);

extern "C" void func_003FBE70(S *s)
{
    X *x = &s->x;
    func_005F5040(s->a, s->x.c);
    func_005F5040(s->b, s->x.d);
    x->j58 = x->i2C;
    x->k5C = x->f30;
    x->k60 = x->f34;
    x->k64 = x->f38;
    x->j68 = x->i3C;
    Q *q = s->p->q;
    int n = func_00343BC0(q);
    float f24 = func_003447C8(q, 0.0f);
    void *s7 = s->w->f80;
    int fp = func_003FCAB0(s->w, s->h0C);
    float a0 = func_00344798(q, 0.0f);
    float a1 = func_003447F8(q, 0.0f);
    float a2 = func_00344828(q, 0.0f);
    s->a[0] = a0;
    s->a[1] = a1;
    s->a[2] = a2;
    float b0 = func_003448B8(q, 0.0f);
    float b1 = func_00344858(q, 0.0f);
    float b2 = func_00344888(q, 0.0f);
    s->b[0] = b0;
    s->b[1] = b1;
    s->b[2] = b2;
    float c0 = func_00344798(q, 1.0f);
    float c1 = func_003447F8(q, 1.0f);
    float c2 = func_00344828(q, 1.0f);
    s->x.c[0] = c0;
    s->x.c[1] = c1;
    s->x.c[2] = c2;
    float d0 = func_003448B8(q, 1.0f);
    float d1 = func_00344858(q, 1.0f);
    float d2 = func_00344888(q, 1.0f);
    s->x.d[0] = d0;
    s->x.d[1] = d1;
    s->x.d[2] = d2;
    if (n > 0) {
        n = (n - 1) % func_00396118(s7) + 1;
    } else {
        n = 0;
    }
    s->x.i2C = n;
    s->x.f30 = f24;
    s->x.f34 = RaceCourse__getCourseLength(s7) * (float)n + f24;
    float f6c8 = q->f6C8;
    s->x.i3C = fp;
    s->x.f38 = f6c8;
}
