/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef float f32;

struct Quat {
    f32 x, y, z, w;
};

struct Vec4 {
    f32 x, y, z, w;
};

extern "C" void func_0048A630(const Quat *q, Vec4 *out, f32 w4) {
    f32 x = q->x;
    f32 y = q->y;
    f32 z = q->z;
    f32 w = q->w;
    f32 xx = x * x;
    f32 zz = z * z;
    f32 yw = y * w;
    f32 zw = z * w;
    f32 xy = x * y;
    f32 xz = x * z;
    out->w = w4;
    out->x = 2.0f * (0.5f - (y * y) - zz);
    out->y = 2.0f * (xy + zw);
    out->z = 2.0f * (xz - yw);
}
