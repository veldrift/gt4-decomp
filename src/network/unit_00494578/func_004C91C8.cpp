/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned char u8;
extern "C" u8 *func_004C91C8(u8 *dst, u8 *src) {
    u8 *r = dst;
    if (*r != 0) {
        do {
            dst++;
        } while (*dst != 0);
    }
    while ((*dst++ = *src++) != 0) ;
    return r;
}
