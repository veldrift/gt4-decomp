/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned char u8;
typedef unsigned short u16;
extern "C" void func_004C9030(u16 *dst, u8 *src, int n) {
    unsigned short c;
    int hi, lo;
    while (n > 0 && (c = *src) != 0) {
        if ((int)(c << 24) >= 0) {
            hi = 0;
            lo = *src;
            src++;
            n--;
        } else {
            hi = *src;
            src++;
            lo = *src;
            src++;
            hi <<= 8;
            n -= 2;
        }
        *dst = hi | lo;
        dst++;
    }
    *dst = 0;
}
