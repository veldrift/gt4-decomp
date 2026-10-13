typedef int s32;
typedef float f32;

extern "C" void *func_00326750(unsigned int size, int align, const char *name);
extern "C" s32 func_002BF9A8(void *arg0, void *arg1, void *arg2, f32 fparg0, f32 fparg1);
extern "C" void func_0026B9E0(void *arg0, void *arg1);

extern "C" void func_002BFA70(void *arg0, void *arg1, void *arg2, f32 fparg0, f32 fparg1) {
    void *s3 = arg0;
    void *s2 = arg1;
    void *s1 = arg2;
    void *s0 = func_00326750(0x28, 4, "RefCounter");
    func_002BF9A8(s0, s2, s1, fparg0, fparg1);
    void *local = s0;
    func_0026B9E0(s3, &local);
}
