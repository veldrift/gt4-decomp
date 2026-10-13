typedef int s32;
typedef unsigned short u16;

extern "C" s32 func_004C8D88(u16 *arg0, u16 *arg1) {
    u16 *p = arg0;
    u16 *q = arg1;
    s32 c = *p;
    while ((c & 0xFFFF) != 0 && (c & 0xFFFF) == *q) {
        p++;
        q++;
        c = *p;
    }
    return c == 0;
}
