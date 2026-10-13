typedef int s32;
typedef unsigned char u8;

extern "C" s32 func_00539290(u8 *arg0, s32 *arg1) {
    s32 a;

    if (arg0 == 0) {
        return 2;
    }
    if (arg1 == 0) {
        return 2;
    }
    a = arg0[0] << 24;
    arg0 = arg0 + 1;
    *arg1 = a;
    a = a | (arg0[0] << 16);
    arg0 = arg0 + 1;
    *arg1 = a;
    a = a | (arg0[0] << 8);
    *arg1 = a;
    a = a | arg0[1];
    *arg1 = a;
    return 0;
}
