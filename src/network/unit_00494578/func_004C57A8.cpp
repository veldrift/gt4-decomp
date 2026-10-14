/* compiler: ee-gcc2.96-no-strict-aliasing */
extern "C" int func_004C5958(unsigned short *, int, void *);
extern "C" int func_004C57A8(unsigned short *s, int n) {
    char buf[32];
    int last = s[n-1];
    int test = last & 0xffff;
    if (test == 0x30 || test == 0xa3b0) return -1;
    int result = (unsigned short)(last - 0xa3b1) < 9;
    if (n < 17) {
        int i;
        for (i = 0; i < n; ++i) {
            unsigned short *p = s + i;
            unsigned short c = *p;
            if (!((unsigned short)(c - 0x30) < 10 || (unsigned short)(c - 0xa3b0) < 10)) break;
        }
        if (i == n) return result;
    }
    return func_004C5958(s,n,buf) != n ? -1 : 2;
}
