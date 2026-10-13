typedef int s32;

extern "C" s32 func_005ADBA0(s32, void *);

extern "C" s32 func_00520518(s32 *arg0) {
    s32 buf0[12];
    s32 cnt = 0;
    s32 i;

    if (arg0 == 0) {
        return 2;
    }
    *arg0 = 0;
    i = 0;
    do {
        s32 prev = i;
        i += 1;
        if (func_005ADBA0(prev, buf0) != -1 && buf0[0] == 0 &&
            (buf0[6] != 0 || buf0[3] != 0)) {
            cnt = cnt + 1;
        }
    } while (i < 0x100);
    *arg0 = cnt;
    return 0;
}
