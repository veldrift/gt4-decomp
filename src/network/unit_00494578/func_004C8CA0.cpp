/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned short u16;
extern "C" u16 *func_004C8CA0(u16 *dst, const u16 *src, int n) {
    while (*dst++ != 0) ;
    dst--;
    while (n > 0 && (*dst++ = *src++) != 0) n--;
    if (n <= 0) {
        *dst = 0;
        return dst;
    }
    return dst - 1;
}
