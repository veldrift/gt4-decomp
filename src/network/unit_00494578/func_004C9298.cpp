typedef unsigned char u8;
typedef int s32;

s32 func_004C9298(u8 *arg0, u8 *arg1) {
    while (*arg0 == *arg1) {
        if (*arg0 == 0) {
            return 0;
        }
        arg0 += 1;
        arg1 += 1;
    }
    return *arg0 - *arg1;
}
