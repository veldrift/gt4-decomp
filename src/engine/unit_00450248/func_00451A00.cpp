typedef int s32;
typedef float f32;
extern "C" void func_00451D18(void *a, void *b, s32 c, s32 d, s32 e, f32 f);
extern "C" void func_00451AB0(void *self, void *object, s32 transform, s32 mode, s32 flags, f32 time);
extern "C" void func_00451A00(void *self, void *object, s32 a2, s32 a3, s32 mode, s32 flags, f32 time) {
    s32 nz = time != 0.0f;
    func_00451D18(self, object, a2, a3, nz, 0.0f);
    func_00451AB0(self, object, 1, mode, flags, time);
}
