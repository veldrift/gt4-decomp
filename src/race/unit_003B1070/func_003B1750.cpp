typedef int s32;
typedef float f32;

extern "C" void func_003B1648(void *self, f32 *a, f32 *b, s32 c, s32 d, s32 e);

extern "C" void func_003B1750(char *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {
    f32 lim[4];
    f32 sp10;
    f32 sp14;
    s32 v;
    s32 flag;

    lim[0] = *(f32 *)(arg0 + 0x708);
    lim[1] = *(f32 *)(arg0 + 0x70C);
    func_003B1648(arg0, &sp10, &sp14, arg1, arg2, arg3);
    if (sp10 < 0x1.999998p-6f) {
        v = 3;
    } else if (sp10 < lim[1]) {
        v = 2;
    } else if (sp10 < lim[0]) {
        v = 1;
    } else {
        v = 0;
    }
    if (sp14 >= 0x1.B33332p-1f) {
        if (v < arg4) {
            v = arg4;
        }
    }
    flag = arg5 < v;
    if (flag) {
        v = arg5;
    }
    if (v < arg6) {
        v = arg6;
    }
    *(s32 *)(arg0 + 0x6A0) = v;
}
