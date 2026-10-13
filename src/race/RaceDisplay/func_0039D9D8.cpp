typedef int s32;
typedef unsigned char u8;
typedef float f32;

extern char D_006A0470[];

extern "C" void func_003A4D80(char *, char *, s32);
extern "C" void func_003A9738(void *, s32, s32);
extern "C" void func_003A96F8(void *, f32, f32);
extern "C" void func_003A4CF0(char *, char *, f32, f32);

extern "C" void func_0039D9D8(char *arg0, char *arg1, s32 arg2) {
    char *temp_s1;

    temp_s1 = arg0 + 0x228C;
    func_003A4D80(temp_s1, D_006A0470, arg2 != 0);
    *(s32 *)(temp_s1 + 0x20) = 0x80C8C8C8;
    func_003A9738(arg0 + 0x22C0, -1, 1);
    func_003A96F8(arg0 + 0x22C0, 1.0f, 1.0f);
    func_003A4CF0(temp_s1, arg1, 0x1.47AE14p-5f, 0.0f);
}
