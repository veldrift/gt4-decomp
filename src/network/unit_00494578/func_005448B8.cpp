typedef int s32;

extern "C" s32 func_005448B8(s32 *arg0) {
    s32 i;
    if (*arg0 != 1) return 0;
    arg0++;
    for (i = 1; i < 0x20; i++) {
        if (*arg0++ != 0) return 0;
    }
    return 1;
}
