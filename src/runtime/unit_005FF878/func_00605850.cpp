typedef unsigned char u8;
typedef signed char s8;
typedef int s32;

extern u8 D_006D0E79[];

extern "C" s32 func_00605850(s8 arg0, s8 arg1) {
    s32 v = arg1;

    if (D_006D0E79[arg1] & 2) {
        v = arg1 - 0x20;
    }
    return arg0 < v;
}
