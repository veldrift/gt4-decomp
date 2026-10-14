/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned char u8;
typedef unsigned short u16;
extern "C" void func_004C8FD8(u16 *dst, u8 *src) {
    unsigned short c;
    int hi, lo;
    while ((c = *src) != 0) {
        if ((int)(c << 24) >= 0) {
            hi = 0;
            lo = *src;
            src++;
        } else {
            hi = *src;
            src++;
            lo = *src;
            src++;
            hi <<= 8;
        }
        *dst = hi | lo;
        dst++;
    }
    *dst = 0;
}
