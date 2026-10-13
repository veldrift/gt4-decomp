typedef int s32;
typedef short s16;
typedef signed char s8;

extern short D_0064A164;
extern s32 D_0064A150;

extern "C" s32 func_00506278(s8 *arg0, s32 arg1);
extern "C" s32 func_0052EAF8(s8 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6);

extern "C" s32 func_00505CD0(s32 arg0) {
    s32 r = -0xC;
    if (D_0064A164 != 1)
        return r;
    func_00506278((s8 *)arg0, 0x15);
    s32 c = func_0052EAF8(0x40, D_0064A150, 0xFFFF, 3, 0x1B, 0x24, arg0);
    s32 x = -5;
    if (c == 0)
        x = 0;
    return x;
}
