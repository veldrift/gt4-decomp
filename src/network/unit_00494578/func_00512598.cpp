typedef int s32;

extern char D_0064A318;
extern void (*D_008A03C0)(char *a, s32 b);
extern s32 D_008A0198;

s32 func_00512598(s32 arg0, s32 arg1, s32 arg2, char *arg3) {
    if (*(s32 *)(arg3 + 0x18) == 0) D_0064A318 = 0;
    if (D_008A03C0 != 0) D_008A03C0(arg3, D_008A0198);
    return 0x1C;
}
