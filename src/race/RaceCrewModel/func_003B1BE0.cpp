typedef int s32;

extern s32 D_006219C4;
extern "C" s32 func_003B1848(void);
extern "C" s32 func_00578CF0(int a, int b);

extern "C" void func_003B1BE0(void) {
    s32 *done = &D_006219C4;
    if (*done == 0) {
        *done = func_00578CF0(0x40, func_003B1848());
    }
}
