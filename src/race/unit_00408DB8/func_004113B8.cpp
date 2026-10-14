/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Entry { short d; short i; void *fn; };
struct Iface { Entry *tab; };
struct Holder { char p[0x18]; int f18; };
struct Self {
    void *f0;
    char p4[8];
    Holder **fC;
    char p10[4];
    Iface *f14;
    char p18[0x110 - 0x18];
    float f110;
};
extern "C" float *func_00385B48(void *);
extern "C" float *func_00385CF8(void *);
extern "C" float *func_00385D08(void *);
extern "C" float *func_00385DD8(void *);
extern "C" int func_00385EE0(Holder *);
extern "C" int func_00385EE8(Holder *);
extern "C" int func_00385F00(Holder **);
extern "C" float func_004104B8(int, int, float, float, float, float) throw();

inline int vcallI(Iface *o, int idx) { Entry *e = o->tab + idx; return ((int (*)(void *))e->fn)((char *)o + e->d); }
inline float vcallF(Iface *o, int idx, float a) { Entry *e = o->tab + idx; return ((float (*)(void *, float))e->fn)((char *)o + e->d, a); }

extern "C" void func_004113B8(Self *self) {
    int sp[2];
    if (vcallI(self->f14, 33) != 1) {
        sp[0] = 0;
        sp[1] = 0;
    } else {
        float f21 = vcallF(self->f14, 18, 0.0f);
        if (f21 < vcallF(self->f14, 11, 0.0f)) {
            sp[0] = func_00385F00(self->fC);
            sp[1] = 0;
        } else {
            sp[0] = 0;
            sp[1] = func_00385F00(self->fC);
        }
    }
    float *s3 = func_00385CF8(self->f0);
    int s2 = func_00385EE0(*self->fC);
    float *s1 = func_00385B48(self->f0);
    float *s0 = func_00385DD8(self->f0);
    *s3 = func_004104B8(s2, sp[0], *s1, *s0, *func_00385CF8(self->f0), self->f110);
    float *t3 = func_00385D08(self->f0);
    int t2 = func_00385EE8(*self->fC);
    float *t1 = func_00385B48(self->f0);
    float *t0 = func_00385DD8(self->f0);
    *t3 = func_004104B8(t2, sp[1], *t1, *t0, *func_00385D08(self->f0), self->f110);
}
