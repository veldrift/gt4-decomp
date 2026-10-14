/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned char u8;
extern "C" u8 *func_004C9228(u8 *dst, u8 *src, int n) {
    u8 *p = dst;
    if (n != 0) {
        do {
            if ((*p++ = *src++) == 0) {
                if (--n == 0) return dst;
                do {
                    *p++ = 0;
                } while (--n != 0);
                return dst;
            }
        } while (--n != 0);
    }
    return dst;
}
