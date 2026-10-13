typedef int s32;
typedef float f32;

extern "C" void func_004212F0(s32 arg0, f32 *arg1, f32 fparg0);
extern "C" void func_004213A0(s32 arg0, f32 *arg1, f32 fparg0);

extern "C" s32 func_00421520(s32 arg0, s32 arg1, f32 *arg2, f32 fparg0, f32 fparg1) {
    f32 loc[4];

    func_004212F0(arg0, loc, fparg0);
    func_004213A0(arg1, &loc[2], fparg1);
    arg2[0] = loc[0];
    arg2[1] = loc[1];
    arg2[2] = loc[2];
    arg2[3] = loc[3];
    return 1;
}
