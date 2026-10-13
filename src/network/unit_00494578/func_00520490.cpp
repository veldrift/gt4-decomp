typedef int s32;

extern "C" s32 func_005ADBA0(s32, s32 *);

extern "C" s32 func_00520490(s32 *arg0) {
    s32 buf0[4];
    s32 pad[8];
    s32 cnt = 0;
    s32 i;

    if (arg0 == 0) {
        return 2;
    }
    *arg0 = 0;
    for (i = 0; i < 0x100; i++) {
        s32 r = func_005ADBA0(i, buf0);
        if (r != -1 && buf0[0] != 0) {
            cnt = cnt + 1;
        }
    }
    *arg0 = cnt;
    return 0;
}
