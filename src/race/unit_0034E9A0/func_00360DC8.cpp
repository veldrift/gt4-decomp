/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned char u8;
typedef short s16;
struct Self;
extern "C" char *func_00359510(Self *) throw();

struct Self { char pad[0x40]; float lim[2]; char p1[0x2c4-0x48]; float a[2]; char p2[0x1040-0x2cc]; float b[2]; };
struct O {
    float f0, f4, f8, fC, f10, f14;
    char pad[0x3C - 0x18];
    float f3C;
};

static inline char *offset(void *p, int n) { return (char *)p + n; }
struct Bytes { u8 pad[2]; u8 a[2]; u8 b[2]; };
static inline float getA(Bytes *p, int i) { return p->a[i] * 0.001f; }
static inline float getB(Bytes *p, int i) { return p->b[i] * 0.001f; }
extern "C" void func_00360DC8(Self *self, O *o, int p, int idx) {
    int i4;
    if (o->f14 != 0.0f) {
        u8 d = func_00359510(self)[idx + 4];
        i4 = idx * 4;
        o->f10 = (-self->b[idx] * (1.0f / (float)d)) / o->f14;
    } else {
        i4 = idx * 4;
    }
    float *lim = (float *)offset(self, idx * 4 + 0x40);
    int k = idx + 0x90;
    float f3 = o->f10;
    o->fC = (self->a[idx] - *lim) + f3;
    float f1 = *lim;
    float f2 = getA((Bytes *)p, k);
    float f5 = f3 - f1;
    if (f1 < f2) f2 = f1;
    o->f4 = f5 + f2;
    s16 v = *(s16 *)(p + idx * 0x18 + 0x66);
    float f1b = *lim;
    float f0 = (float)v * 0.001f;
    if (f1b < f0) f0 = f1b;
    if (v != 0 && f0 <= f2) {
        f0 = 0.0f;
        v = 0;
    }
    float r;
    if (v == 0) r = o->f4;
    else r = f5 + f0;
    o->f0 = r;
    float t = f3 + getB((Bytes *)p, k);
    o->f8 = t;
    float f1c = o->f3C / o->f14;
    if (f1c < t) o->f8 = f1c;
}
