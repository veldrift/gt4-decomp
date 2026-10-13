typedef int s32;
typedef float f32;

extern char D_006A06B0[];

extern "C" void func_003A4E48(char *, f32);
extern "C" void func_003A4D80(char *, char *, s32);
extern "C" void func_003A4CF0(char *, char *, f32, f32);

extern "C" void func_0039F018(char *arg0, char *arg1, s32 arg2, s32 arg3, f32 fparg0) {
    char *temp_s0;
    f32 k;

    func_003A4E48(arg0 + 0x2A6C, 0x1.333332p-3f);
    temp_s0 = arg0 + 0x2BBC;
    func_003A4D80(temp_s0, D_006A06B0, 0);
    k = 0x1p-2f;
    *(s32 *)(temp_s0 + 0x20) = arg2;
    *(f32 *)(temp_s0 + 0x18) = k;
    *(f32 *)(temp_s0 + 0x1C) = k;
    *(s32 *)(temp_s0 + 0x154) = arg3;
    func_003A4CF0(temp_s0, arg1, fparg0, 0.0f);
}
