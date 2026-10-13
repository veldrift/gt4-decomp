typedef int s32;
typedef float f32;

extern "C" s32 func_00355D48(char *arg0);
extern "C" void func_00355D68(char *arg0, f32 fparg0);

extern "C" void func_00355DC8(char *arg0) {
    s32 ok = func_00355D48(arg0);
    char *p = arg0 + 0x788;
    if (ok != 0) {
        func_00355D68(arg0, 1.0f);
        p[4] = 0;
        p[5] = 0;
    }
}
