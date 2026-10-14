/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef float f32;

static inline float sqrt_s(float x) { float r; __asm__("sqrt.s %0, %1" : "=f"(r) : "f"(x)); return r; }

struct Obj {
    char pad0[8];
    f32 m8;
    f32 mC;
    char pad1[0xE8 - 0x10];
    s32 mE8;
    char pad2[0x140 - 0xEC];
    s32 m140;
    char pad3[0x184 - 0x144];
    f32 m184;
    f32 m188;
    f32 m18C;
    f32 m190[3];
    f32 m19C;
};

extern "C" f32 func_0036EA50(void *) throw();
extern "C" f32 func_0036EA98(void *) throw();
extern "C" void func_004A0690(void);
extern "C" void func_004A06F0(void);
extern "C" void func_004A53F8(void);
extern "C" void func_004A5400(void);
extern "C" void func_004A7454(void);
extern "C" void func_004A7550(void *);
extern "C" void func_004A7844(f32, f32, f32);
extern "C" void func_004A7988(f32);
extern "C" void func_004A79B0(float);
extern "C" void func_004A79D8(float);
extern "C" f32 func_005F5010(f32 *);
extern "C" void func_005F5040(float *, float *);
extern "C" void func_005F5268(void *, void *);

extern "C" s32 func_00384200(Obj *self) {
    f32 A[4];
    f32 ang[4];
    f32 *p184 = &self->m184;
    f32 *px = &ang[0];
    func_005F5040(self->m190, A);
    func_005F5268(A, p184);
    f32 len = sqrt_s(func_005F5010(A));
    f32 t = func_0036EA50(A);
    f32 *py = &ang[1];
    *py = t;
    *px = func_0036EA98(A);
    self->m8 = len;
    self->mC = self->m19C;
    f32 *pz = &ang[2];
    *pz = 0.0f;
    if ((f32)self->m140 / 60.0f >= 1.0f)
        self->mE8 = 3;
    func_004A0690();
    func_004A53F8();
    func_004A7454();
    func_004A79D8(*pz);
    func_004A7988(*py);
    func_004A79B0(*px);
    func_004A7844(-*p184, -self->m188, -self->m18C);
    func_004A7550((char *)self + 0x100);
    func_004A5400();
    func_004A06F0();
    return 1;
}
