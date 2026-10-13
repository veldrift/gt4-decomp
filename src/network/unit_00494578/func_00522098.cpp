/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;

extern "C" s32 func_00538BF8(s32 *arg0, s32 arg1);

extern "C" s32 *func_00522098(void) {
    s32 *p = 0;

    func_00538BF8((s32 *)&p, 0x20);
    if (p != 0) {
        *p = 1;
        return p;
    }
    return 0;
}
