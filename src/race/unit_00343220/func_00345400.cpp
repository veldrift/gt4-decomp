typedef int s32;
typedef unsigned char u8;
typedef signed char s8;

extern "C" s32 func_00463C28(void *arg0, s32 arg1, s32 arg2);

extern "C" s32 func_00345400(void *arg0) {
    char *t = (char *)arg0 + 0x104;
    s32 r;

    if (*(s8 *)(t + 0x466) == 4) {
        return 0;
    }
    r = func_00463C28((char *)arg0 + 0x14, 4, 1);
    if (r != 0) {
        *(u8 *)(t + 0x467) = 3;
        return 1;
    }
    return r;
}
