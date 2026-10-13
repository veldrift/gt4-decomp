typedef int s32;
typedef short s16;
typedef signed char s8;

extern short D_0064A164;
extern s32 D_0064A150;

extern "C" s32 func_00506278(s8 *arg0, s32 arg1);
extern "C" s32 func_0052EAF8(s8 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6);

extern "C" s32 func_00505C58(s8 *arg0) {
    s32 r = -0xC;
    func_00506278(arg0, 0x15);
    if (*(s32 *)(arg0 + 0x20) < 0)
        return r;
    if (D_0064A164 != 1)
        return r;
    s32 c = func_0052EAF8(0x40, D_0064A150, 0xFFFF, 3, 0xE, 0x28, (s32)arg0);
    s32 x = -5;
    if (c == 0)
        x = 0;
    return x;
}
