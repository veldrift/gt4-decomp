/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef float f32;

struct R {
    s32 u0, u4, u8, uC;
    s32 x, y, w, h;
    char pad[0x20];
};
struct Obj {
    char pad0[4];
    s32 u4;
    char pad8[0x28 - 8];
    s32 u28;
};

extern "C" void func_00105280(void *, s32);
extern "C" s32 func_001052E0(void *, s32, s32, s32);
extern "C" void func_001056A0(void *);
extern "C" void func_00105728(void *);
extern "C" void func_001059F8(void *, s32, s32);
extern "C" void func_004A29A8(s32);
extern "C" void func_004A4550(s32, s32);
extern "C" void func_004A6668( f32, f32, f32, f32, f32, f32, f32, f32);
extern "C" void func_004AA168(s32);
extern "C" void func_004AB040(s32);

extern "C" void func_00330AE8(Obj *arg0, R *arg1, s32 arg2) {
    R a;
    R b;
    f32 c, d, z, e, e2;
    s32 h1, h2;

    func_001052E0(&a, 0, 0x80, 0x80);
    func_001052E0(&b, 2, 0x40, 0x40);
    func_004AA168(0x80FFFFFF);
    func_004A4550(3, 1);
    func_004A4550(2, 1);
    func_004AB040(5);
    func_004AB040(4);
    func_004A29A8(0);
    func_004AB040(6);
    func_00105728(arg1);
    func_001056A0(&a);
    c = (f32)(arg1->x + arg1->w) * 0.5f;
    e = (f32)(arg1->y + arg1->h);
    d = c;
    if (arg2 != 0) {
        d = c * 0.75f;
    }
    z = 0.0f;
    func_004A6668( z, z, 128.0f, 128.0f, c - d, z, c + d, e);
    func_00105728(&a);
    func_001056A0(&b);
    func_004A6668( z, z, 64.0f, 64.0f, z, z, (f32)(a.x + a.w), (f32)(a.y + a.h));
    func_001059F8(&b, arg0->u4, 2);
    arg0->u28 = 1;
    func_00105280(&b, 2);
    func_00105280(&a, 2);
}
