typedef int s32;
typedef float f32;

extern "C" s32 func_003C75D8(void *arg0);
extern "C" void func_003630C0(void *arg0, s32 arg1, f32 fparg0, f32 fparg1, f32 fparg2, f32 fparg3);
extern "C" void func_00344040(void *arg0);

extern "C" void func_003C75F0(void *arg0, f32 fparg0, f32 fparg1, f32 fparg2) {
    s32 temp_s0;

    temp_s0 = func_003C75D8(arg0);
    func_003630C0((void *)temp_s0, -1, fparg0, -fparg1, 0.0f, fparg2);
    func_00344040((void *)temp_s0);
    func_00344040((void *)temp_s0);
}
