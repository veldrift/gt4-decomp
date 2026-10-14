/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef float f32;

struct Obj {
    s32 u0;
    char pad4[0x124];
    s32 u128;
    char pad12C[4];
    f32 f130, f134, f138, f13C;
};

struct S0 {
    char pad0[0x14];
    s32 u14;
    char pad18[8];
};

struct S1 {
    f32 a, b, c, d, e, f;
    S1() { a = 1.0f; b = 1.0f; c = 1.0f; d = 0.0f; e = 1.0f; f = 1.0f; }
};

extern "C" void func_0033DE30(s32, void *);
extern "C" void func_003EFC10(void *, f32, f32, f32, f32, f32);
extern "C" void func_003EFCE8(void *, f32, f32, f32, f32, f32, f32);
extern "C" void func_003EFD80(void *, void *);

extern "C" void func_00334B28(Obj *arg0) {
    S0 s;
    func_003EFC10(&s, arg0->f134, arg0->f13C, arg0->f130, arg0->f138, 5500.0f);
    switch (arg0->u128) {
    case 2:
        s.u14 = 0;
        break;
    case 1: {
        S1 c;
        func_003EFCE8(&c, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f, 0.6f);
        func_003EFD80(&s, &c);
        break;
    }
    case 4: {
        S1 c;
        func_003EFCE8(&c, 1.5f, 0.95f, 0.6f, 0.0f, 1.0f, 0.3f);
        func_003EFD80(&s, &c);
        break;
    }
    }
    func_0033DE30(arg0->u0, &s);
}
