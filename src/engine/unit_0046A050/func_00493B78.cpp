typedef signed char s8;
typedef unsigned int u32;
typedef int s32;

extern "C" s32 func_00493B78(s8 **arg0) {
    s8 *p;
    s8 c;
    s32 n;
    s32 t;

    p = *arg0;
    n = 0;
    c = *p;
    while ((u32)(c - 0x30) < 0xA) {
        p += 1;
        t = (n * 0xA) + c;
        c = *p;
        n = t - 0x30;
    }
    *arg0 = p;
    return n;
}
