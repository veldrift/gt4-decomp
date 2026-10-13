typedef int s32;
typedef short s16;
typedef signed char s8;

extern short D_0064A164;
extern s32 D_0064A150;
extern char D_006C12D8[];

extern "C" s32 func_00506278(s8 *arg0, s32 arg1);
extern "C" s32 func_0052EAF8(s8 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6);
extern "C" void func_0057D9C0(const char *fmt, ...);

extern "C" s32 func_00506158(s32 arg0) {
    func_00506278((s8 *)arg0 + 8, 0x11);
    if (D_0064A164 != 1)
        return -0xC;
    s32 c = func_0052EAF8(0x40, D_0064A150, 0xFFFF, 3, 0x1C, 0x1C, arg0);
    if (c == 0)
        return c;
    func_0057D9C0(D_006C12D8, c);
    return -5;
}
