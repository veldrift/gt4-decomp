typedef signed char s8;
typedef int s32;

extern "C" s32 func_0035C7C8(char *arg0);

extern "C" void func_0035C7E0(char *arg0) {
    if (func_0035C7C8(arg0) != 0) {
        char *p = arg0 + 0x788;
        p[2] = 0x3C;
        p[1] = 0;
        p[3] = 0;
        p[4] = 0;
        p[5] = 0;
        p[6] = 0;
    }
}
