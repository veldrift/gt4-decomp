typedef int s32;

extern "C" void func_005720F0(void *arg0, s32 arg1, s32 arg2);
extern "C" void func_005A48D8(void *arg0, s32 arg1, s32 arg2);

extern s32 D_0065586C;
extern s32 D_00655870;
extern char D_008744D0[];

extern "C" void func_00575C78(void) {
    s32 s0 = (D_0065586C + 0xF) & -0x10;
    s32 s1 = (D_00655870 - s0) & -0x10;
    func_005A48D8((void *)s0, 0, s1);
    if (D_008744D0 != 0) {
        return func_005720F0(D_008744D0, s0, s1);
    }
}
