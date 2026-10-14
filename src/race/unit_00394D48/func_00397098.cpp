typedef int s32;
typedef float f32;

extern "C" void func_00396B80(void *a0, s32 a1, s32 a2, f32 f12, f32 f13);
extern "C" void CourseData__render_model(void *a0, s32 a1, s32 a2, f32 f12, f32 f13, f32 f14);

extern "C" void func_00397098(char *arg0, s32 arg1, f32 fparg0, f32 fparg1, f32 fparg2) {
    func_00396B80(arg0, *(s32 *)(arg0 + 0xC8), -1, 1.0f, 1000.0f);
    s32 a1 = *(s32 *)(arg0 + 0x24);
    s32 a2 = 0;
    if (arg1 != 0) {
        a2 = *(s32 *)(arg0 + 0x28);
    }
    CourseData__render_model(arg0, a1, a2, fparg0, fparg1, fparg2);
}
