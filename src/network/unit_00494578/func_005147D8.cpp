typedef int s32;

extern s32 D_0064A32C;
extern void (*D_008A05A8)(char *a, s32 b);
extern s32 D_008A0380;

s32 func_005147D8(s32 arg0, s32 arg1, s32 arg2, char *arg3) {
    void (*temp_v1)(char *a, s32 b);

    if (-0x3B6 == *(s32 *)(arg3 + 0x18)) {
        D_0064A32C = 0;
    }
    temp_v1 = D_008A05A8;
    if (temp_v1 != 0) {
        temp_v1(arg3, D_008A0380);
    }
    return 0x1C;
}
