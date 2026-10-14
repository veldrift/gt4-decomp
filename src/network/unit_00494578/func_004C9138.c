/* compiler: ee-gcc2.96-no-strict-aliasing */
extern void func_004C9138(unsigned char *out, const unsigned short *src, int n) {
    while (n-- != 0 && *src != 0) {
        unsigned c = *src++;
        if (c >= 0x100) {
            *out++ = c >> 8;
            *out++ = c;
        } else {
            *out++ = c;
        }
    }
    *out = 0;
}
