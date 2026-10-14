typedef int s32;
typedef unsigned int u32;
typedef float f32;

struct Vec3 {
    f32 x;
    f32 y;
    f32 z;
};

extern "C" f32 func_00344798(void *ctx, f32 angle);
extern "C" f32 func_003447F8(void *ctx, f32 angle);
extern "C" f32 func_00344828(void *ctx, f32 angle);
extern "C" s32 func_0049B330(const Vec3 *a, const Vec3 *b);

extern "C" s32 func_003405E8(void *ctx, f32 angle) {
    Vec3 low;
    Vec3 high;
    f32 t1, t2, t3;

    t1 = func_00344798(ctx, angle);
    t2 = func_003447F8(ctx, angle);
    t3 = func_00344828(ctx, angle);
    low.x = t1 - 4.0f;
    low.y = t2 - 4.0f;
    low.z = t3 - 4.0f;
    high.x = t1 + 4.0f;
    high.y = t2 + 4.0f;
    high.z = t3 + 4.0f;
    return func_0049B330(&low, &high) != 0;
}
