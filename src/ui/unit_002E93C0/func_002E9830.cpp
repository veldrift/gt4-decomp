typedef int s32;
typedef float f32;

struct func_002E9830_arg0 {
    char pad0[0xC4];
    s32 unkC4;
};

extern "C" void func_0025B538(s32 c, f32 f0, f32 f1, f32 f2, f32 f3);

extern "C" void func_002E9830(struct func_002E9830_arg0 *arg0, s32 arg1, f32 fparg0, f32 fparg1, f32 fparg2, f32 fparg3) {
    if (arg0->unkC4 != 0) {
        return func_0025B538(arg1, fparg0, fparg1, fparg2, fparg3);
    }
    func_0025B538(arg1, fparg1, fparg0, fparg3, fparg2);
}
