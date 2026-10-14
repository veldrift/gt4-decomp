/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
struct V4 { float x, y, z, w; };
struct O;
struct Self {
    char pad0[0x34];
    float f34;
    s32 f38;
    V4 v;
    s32 pad4C;
    float f50;
    s32 f54;
    s32 *f58;
    s32 *f5C;
    s32 *f60;
    float f64;
};

extern V4 D_006DE938;

extern "C" void func_00102D90(V4 *arg0) throw();
extern "C" void func_00103018(void *self, V4 *f, O *o, s32 *a, s32 *b, s32 idx) throw();

extern "C" void func_00104848(Self *self, int unused, void *arg2) {
    V4 t = self->v;
    t.w = self->f34;
    func_00102D90(&t);
    if (self->f38 != 0) {
        if (self->f50 != 0.0f) {
            float s = self->f64;
            V4 c = D_006DE938;
            c.w = self->f50;
            c.x *= s;
            c.y *= s;
            c.z *= s;
            func_00103018(arg2, &c, (O *)self->f58, self->f5C, self->f60, self->f54);
        }
    }
}
