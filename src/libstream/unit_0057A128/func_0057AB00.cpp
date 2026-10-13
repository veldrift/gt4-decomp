typedef int s32;
typedef unsigned char u8;

extern "C" s32 func_0057AB00(void **arg0, s32 arg1) {
    u8 *p = (u8 *)*arg0;
    s32 result = 0;
    if (p != 0) {
        s32 m = p[0] | (p[1] << 8) | (p[2] << 16) | (p[3] << 24);
        result = (arg1 ^ m) == 0;
    }
    return result;
}
