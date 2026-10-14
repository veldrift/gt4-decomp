typedef int s32;
typedef float f32;

extern s32 D_00622A18;
extern char D_00845C10[];

extern "C" s32 func_00400F38(void *a0);
extern "C" void func_00400F70(void *a0, f32 f);

extern "C" void func_00400FA0(f32 fparg0) {
    s32 *flag = &D_00622A18;
    if (*flag == 0) {
        func_00400F38(D_00845C10);
        *flag = 1;
    }
    return func_00400F70(D_00845C10, fparg0);
}
