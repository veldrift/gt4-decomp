/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;

struct Self {
    char pad[0x7B4];
    s32 f7B4;
    s32 f7B8;
};

extern "C" float func_00344798(void *, float);
extern "C" float func_003447F8(void *, float);
extern "C" float func_00344828(void *, float);
extern "C" float func_00344858(void *, float);
extern "C" float func_00344888(void *, float);
extern "C" float func_003448B8(void *, float);
extern "C" s32 func_0038DC18(s32);
extern "C" s32 func_00459178(s32);
extern "C" s32 func_003B2708(Self *, s32, void *, s32, s32, s32, s32, float);
extern "C" s32 func_003B4040(Self *, s32, float, float, float, float, float, float, float);

extern "C" s32 func_003B2568(Self *self, s32 id, void *obj, s32 a3, s32 a4, s32 a5, s32 a6, float x) {
    self->f7B4 = 0;
    s32 t = func_00459178(func_0038DC18(id));
    if (t == 1 && a6 != 0) self->f7B4 = t;
    s32 r = 0;
    if (self->f7B4 != 0) {
        float f24 = func_00344798(obj, x);
        float f23 = func_003447F8(obj, x);
        float f22 = func_00344828(obj, x);
        float f21 = func_00344858(obj, x);
        float f20 = func_003448B8(obj, x);
        if (func_003B4040(self, id, f24, f23, f22, f21, f20, func_00344888(obj, x), x)) {
            self->f7B8 = 0;
            r = 1;
        }
    } else {
        s32 v = func_003B2708(self, id, obj, a3, a4, a5, a6, x);
        self->f7B8 = 1;
        r = v != 0;
    }
    return r;
}
