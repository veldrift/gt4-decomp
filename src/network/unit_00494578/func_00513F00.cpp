typedef int s32;

extern s32 D_0064A330;
extern void (*D_008A04A4)(char *a, s32 b);
extern s32 D_008A027C;

s32 func_00513F00(s32 arg0, s32 arg1, s32 arg2, char *arg3) {
    void (*temp_v1)(char *a, s32 b);
    s32 *p;

    if (arg3[0x11C] == 1) {
        p = (s32 *)&D_0064A330;
        *p = *p | 2;
    }
    temp_v1 = D_008A04A4;
    if (temp_v1 != 0) {
        temp_v1(arg3, D_008A027C);
    }
    return 0x120;
}
