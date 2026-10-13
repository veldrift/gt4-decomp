/* compiler: ee-gcc2.96-nosib */
typedef int s32;
typedef unsigned int u32;

extern s32 D_00863770;

extern "C" void func_00531738(s32 *arg0);

extern "C" void func_0051B9B8(s32 arg0, u32 arg1) {
    if (arg1 < 0x40U && arg0 != 0) {
        func_00531738((s32 *)(D_00863770 + arg1 * 4));
    }
}
