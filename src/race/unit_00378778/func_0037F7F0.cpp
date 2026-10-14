/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef float f32;

static inline float sqrt_s(float x) { float r; __asm__("sqrt.s %0, %1" : "=f"(r) : "f"(x)); return r; }

struct Inner { char pad[0x18]; void *unk18; };
struct Obj { char pad[0x10]; Inner *unk10; };

extern "C" f32 func_0036EA50(void *) throw();
extern "C" f32 func_0036EA98(void *) throw();
extern "C" f32 func_0036EB98(f32, f32) throw();
extern "C" void func_003FC618(Obj *, f32 *);
extern "C" void func_003FC658(Obj *, f32 *);
extern "C" void func_003FCE70(char *);
struct CB { void run(void *, void *, float) __asm__("func_003FCEA8"); };
extern "C" void func_003FD0A0(char *, f32 *, void *, f32);
extern "C" float func_003FD260(Inner *, void *);
extern "C" void *func_005A48D8(void *, int, unsigned int);
extern "C" f32 func_005F5010(f32 *);
extern "C" void func_005F5040(float *, float *);
extern "C" void func_005F5230(f32 *, void *);

extern "C" int func_005F5268(void *, void *);

struct V3 { f32 x, y, z; };
static inline f32 &at(V3 &v, s32 i) { return (&v.x)[i]; }

extern "C" s32 func_0037F7F0(Obj *self, void *m, void *arg2, V3 *out) {
    V3 A;
    f32 Bv[4];
    f32 Cv[4];
    f32 Dv[4];
    f32 Ev[4];
    char buf[0x30];
    f32 *B = Bv;
    f32 *C = Cv;
    f32 *D = Dv;
    f32 *E = Ev;
    Inner *in = self->unk10;
    void *o = in->unk18;
    func_003FCE70(buf);
    func_005A48D8(&A, 0, 12);
    func_003FC618(self, B);
    func_003FC658(self, C);
    f32 d = func_003FD260(in, arg2);
    if (d < 0.01f)
        return 0;
    func_005F5040(B, &A.x);
    func_005F5268(&A, m);
    f32 len = sqrt_s(func_005F5010(&A.x));
    if (len <= d)
        return 0;
    f32 k = d / len;
    s32 iy = 1, iz = 2;
    A.x *= k;
    at(A, iy) *= k;
    at(A, iz) *= k;
    func_005F5230(&A.x, m);
    func_003FD0A0(buf, &A.x, o, 0.0f);
    func_005F5040(&A.x, D);
    ((CB *)buf)->run(D, o, 0.0f);
    func_005F5268(D, m);
    func_005F5040(&A.x, E);
    ((CB *)buf)->run(E, o, 1.0f);
    func_005F5268(E, m);
    f32 t = func_0036EA50(E);
    at(*out, iy) = func_0036EB98(t, func_0036EA50(D));
    f32 u = func_0036EA98(E);
    out->x = func_0036EB98(u, func_0036EA98(D));
    at(*out, iz) = 0.0f;
    return 1;
}
