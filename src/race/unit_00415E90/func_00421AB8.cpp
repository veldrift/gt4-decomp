typedef float f32;

struct Vec3 {
    f32 x;
    f32 y;
    f32 z;
};

extern "C" struct Vec3 *func_00421AB8(struct Vec3 *arg0, const struct Vec3 *arg1, f32 fparg0) {
    f32 zt = arg1->z * fparg0;
    f32 yt = arg1->y * fparg0;
    arg0->x = arg1->x;
    arg0->y = yt;
    arg0->z = zt * fparg0;
    return arg0;
}
