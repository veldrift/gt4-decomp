/* compiler: ee-gcc2.96-no-strict-aliasing */
extern "C" void func_0048C228(float *, float *, float *) throw();
extern "C" void func_0048ABF0(float *, const float *, float) throw();
extern "C" void func_0048A3B8(float *, float *, float *) throw();
extern "C" void func_0048C358(float *, float *, float *) throw();
extern "C" void func_0048AC80(float *, float *, float) throw();
extern "C" float func_0059D2A0(float);

static inline float rsq(float x) {
    float r;
    __asm__("rsqrt.s %0, %1, %2" : "=f"(r) : "f"(1.0f), "f"(x));
    return r;
}
static inline float fmaxs(float a, float b) {
    float r;
    __asm__("max.s %0, %1, %2" : "=f"(r) : "f"(a), "f"(b));
    return r;
}
static inline float fmins(float a, float b) {
    float r;
    __asm__("min.s %0, %1, %2" : "=f"(r) : "f"(a), "f"(b));
    return r;
}

static inline float dot3(const float *a,const float *b) {
    const float &x=b[0], &y=b[1], &z=b[2];
    float bx=x, ax=a[0];
    float by=y, ay=a[1];
    float bz=z, az=a[2];
    return ax*bx + ay*by + az*bz;
}
extern "C" void func_0048C690(float *q, float *a, float *b, float *c, float *d) {
    float t[3];
    float u[3];
    float w[3];
    float x[3];
    float *up = u;
    t[0] = a[1] * b[2] - a[2] * b[1];
    t[1] = a[2] * b[0] - a[0] * b[2];
    t[2] = a[0] * b[1] - a[1] * b[0];
    up[0] = c[1] * d[2] - c[2] * d[1];
    u[1] = c[2] * d[0] - c[0] * d[2];
    u[2] = c[0] * d[1] - c[1] * d[0];
    float r = rsq(t[0] * t[0] + t[1] * t[1] + t[2] * t[2]);
    t[0] *= r;
    t[1] *= r;
    t[2] *= r;
    float r2 = rsq(up[0] * up[0] + u[1] * u[1] + u[2] * u[2]);
    up[0] *= r2;
    u[1] *= r2;
    u[2] *= r2;
    if (dot3(t,up) > -0.5f) {
        func_0048C228(q, t, up);
    } else {
        func_0048ABF0(q, a, 1.5707963f);
        float *wp = w;
        func_0048A3B8(q, wp, t);
        func_0048C358(q, wp, up);
    }
    float *xp = x;
    func_0048A3B8(q, xp, a);
    float *c1 = c + 1;
    float *c2 = c + 2;
    float cs = fmins(fmaxs(dot3(xp,c), -1.0f), 1.0f);
    float ang = 1.5707963f - func_0059D2A0(cs);
    float *wp = w;
    float *x1 = x + 1;
    float *x2 = x + 2;
    wp[0] = *x1 * *c2 - *x2 * *c1;
    w[1] = *x2 * c[0] - xp[0] * *c2;
    w[2] = xp[0] * *c1 - *x1 * c[0];
    if (dot3(u,wp) < 0.0f)
        ang = 0x1.921fb4p+2f - ang;
    func_0048AC80(q, up, ang);
}
