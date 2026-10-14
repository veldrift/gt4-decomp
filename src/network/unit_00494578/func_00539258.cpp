typedef int s32;
typedef unsigned int u32;
typedef unsigned char u8;
extern "C" s32 func_00539258(u8 *p, u32 v) {
    if (p == 0) return 2;
    *p++ = v >> 24;
    *p++ = v >> 16;
    p[0] = v >> 8;
    p[1] = v;
    return 0;
}
