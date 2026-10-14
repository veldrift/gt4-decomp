/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef float f32;
struct Q { f32 x, y, z, w; };
struct S { char pad[0x10]; Q q; };
extern "C" int func_00414DC0(S *);

extern "C" int func_00414D88(S *arg0) {
    f32 zero = 0.0f;
    f32 one = 1.0f;
    Q *q = &arg0->q;
    q->w = one;
    q->x = zero;
    q->y = zero;
    q->z = zero;
    return func_00414DC0(arg0);
}
