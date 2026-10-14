/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef float f32;

static inline float sqrt_s(float x) { float r; __asm__("sqrt.s %0, %1" : "=f"(r) : "f"(x)); return r; }

struct Inner { char pad[0x18]; void *unk18; };
struct Obj { char pad[0x10]; Inner *unk10; };

extern "C" f32 func_0036EA50(void *) throw();
extern "C" f32 func_0036EA98(void *) throw();
extern "C" f32 func_0036EB98(f32, f32) throw();
extern "C" void func_003FCE70(char *);
extern "C" void func_003FCEA8(void *, void *, void *, float);
extern "C" f32 func_005F5010(f32 *);
extern "C" void func_005F5040(float *, float *);
extern "C" void func_005F5268(void *, void *);

extern "C" void func_0037F4E0(Obj *self, void *m, f32 *vin, f32 *len0, f32 *len1, f32 *out) {
    f32 A[4];
    f32 B[4];
    char buf[0x20];
    char *pbuf = buf;
    f32 *pB = B;
    void *o = self->unk10->unk18;
    func_003FCE70(pbuf);
    func_005F5040(vin, A);
    func_003FCEA8(pbuf, A, o, 0.0f);
    func_005F5040(vin, pB);
    func_003FCEA8(pbuf, pB, o, 1.0f);
    func_005F5268(A, m);
    func_005F5268(pB, m);
    *len0 = sqrt_s(func_005F5010(A));
    *len1 = sqrt_s(func_005F5010(pB));
    f32 t = func_0036EA50(pB);
    out[1] = func_0036EB98(t, func_0036EA50(A));
    f32 u = func_0036EA98(pB);
    f32 r = func_0036EB98(u, func_0036EA98(A));
    out[2] = 0.0f;
    out[0] = r;
}
