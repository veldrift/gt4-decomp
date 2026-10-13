typedef int s32;
typedef float f32;
typedef unsigned char s8;

extern char D_006A1860[];

extern "C" void func_003A4D80(void *arg0, s32 arg1, s32 arg2);
extern "C" void func_003A4DA0(void *self);
extern "C" void func_003A4E00(void *arg0, f32 fparg0, f32 fparg1);
extern "C" void func_003A4F00(void *arg0, f32 fparg0);
extern "C" void func_003A5268(void *arg0, s32 arg1, s32 arg2);
extern "C" void func_003A99A8(void *arg0);
extern "C" void func_003AECA0(void *arg0, s8 arg1, s8 arg2);

extern "C" void func_003ADF00(char *arg0) {
    f32 z = 0.0f;
    char *s1 = arg0 + 0x3C;
    s32 str = (s32)D_006A1860;

    *(f32 *)(arg0 + 0x18) = z;
    *(f32 *)(arg0 + 0x1C) = z;
    func_003A99A8(arg0 + 0x20);
    arg0 += 0x18C;
    func_003A4DA0(s1);
    func_003A4E00(s1, z, z);
    *(s32 *)s1 = (*(s32 *)s1 & -0x100) | 1;
    func_003A4D80(s1, str, 0);
    func_003AECA0(s1, 2, 1);
    func_003A4F00(arg0, z);
    func_003A5268(arg0, str, 0);
    func_003AECA0(arg0, 2, 1);
}
