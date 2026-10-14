typedef int s32;
extern s32 D_0064A308;
extern s32 D_0064A30C;
extern "C" s32 func_0052FBD8(s32);
extern "C" s32 func_0050B5F8(void) {
    if (D_0064A308 != 1) return -15;
    if (D_0064A30C == 0) return -16;
    s32 r = func_0052FBD8(D_0064A30C) ? -3 : 0;
    D_0064A30C = 0;
    return r;
}
