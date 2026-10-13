typedef int s32;
typedef float f32;

struct Vec4_00262038 {
    f32 x, y, z, w;
};

extern "C" void func_00261FF8(s32 arg0, Vec4_00262038 *out);

extern "C" void *func_00262038(Vec4_00262038 *self, s32 arg1) {
    Vec4_00262038 t;
    f32 zero = 0.0f;
    t.x = zero;
    t.y = zero;
    t.z = zero;
    t.w = zero;
    func_00261FF8(arg1, &t);
    self->x = t.x;
    self->y = t.y;
    self->z = t.z;
    self->w = t.w;
    return self;
}
