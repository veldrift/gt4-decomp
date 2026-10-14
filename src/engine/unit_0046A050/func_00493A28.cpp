/* compiler: ee-gcc2.96-nogcse */
extern "C" void func_00493628(int, int, int, int, int, int, char, char *, int, int);
static inline int oct(char *out, unsigned long long v) {
    int len = 1;
    int started = 0;
    int sh;
    for (sh = 63; sh >= 0; sh -= 3) {
        int dig = (int)((v >> sh) & 7);
        if (started || dig != 0) {
            out[len] = dig + '0';
            started = 1;
            len++;
        }
    }
    return len;
}
extern "C" void func_00493A28(int a, int b, int c, int d, int e, int f, unsigned long long v, char sign) {
    char buf[0x20];
    char *bp = buf;
    *bp = sign;
    int len = oct(bp, v);
    func_00493628(a, b, c, d, e, f, buf[0], buf + 1, len - 1, 8);
}
