typedef int s32;
typedef float f32;

struct Vec4 {
    f32 x;
    f32 y;
    f32 z;
    f32 w;
};

struct Obj {
    char pad0[0x14];
    void *unk14;
};

extern "C" s32 func_00145BE8(Obj *arg0);
extern "C" void func_00202C48(void *, s32);
extern "C" void *func_002030E8(Vec4 *, void *);
extern "C" void func_00203118(void *, s32);
extern "C" s32 func_00441248(void *);
extern "C" s32 func_00445AB8(s32, s32);

extern "C" void func_00145C30(Obj *arg0, Vec4 *arg1) {
    s32 sp[4];
    Vec4 *var_s0 = arg1;
    s32 var_s1 = 0;
    s32 temp_v0 = func_00145BE8(arg0);
    s32 res;
    s32 temp_a1;

    if (temp_v0 > 0) {
        f32 k = 0x1.599998p0f;
        f32 one = 1.0f;
        do {
            temp_a1 = var_s1;
            res = func_00445AB8(func_00441248(arg0->unk14), temp_a1);
            var_s1 += 1;
            func_00202C48(sp, res);
            func_002030E8(var_s0, sp);
            func_00203118(sp, 2);
            f32 a = var_s0->x;
            f32 b = var_s0->y;
            f32 c = var_s0->z;
            var_s0->w = one;
            var_s0->x = a * k;
            var_s0->y = b * k;
            var_s0->z = c * k;
            var_s0 += 1;
        } while (var_s1 < temp_v0);
    }
}
