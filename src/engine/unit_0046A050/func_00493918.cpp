extern unsigned long long D_00624998[];
extern "C" int func_00493628(int, int, int, int, int, int, int, char *, int, int);

extern "C" void func_00493918(int a0, int a1, int a2, int a3, int a4, int dec,
                              unsigned long long val, int fill, int flag) {
    char buf[32];
    int base = 10;
    int n, i, len, started;
    unsigned long long *p;
    n = flag;
    if (n) {
        n = 0x12 - dec;
        n = n < 0 ? 0x13 : n;
        if (dec < 0) n = 0x13;
    } else {
        n = 0x13;
    }
    started = 0;
    p = D_00624998;
    len = 0;
    for (i = 0; i < 0x13; i++, p++) {
        int d = 0;
        while (val >= *p) {
            val -= *p;
            d++;
        }
        int c = d + '0';
        if (started || d != 0 || i == n) {
            if (i == n) {
                buf[len++] = c;
                c = '.';
            }
            buf[len++] = c;
            started = 1;
        }
    }
    int fc = (fill << 24) >> 24;
    func_00493628(a0, a1, a2, a3, a4, dec, fc, buf, len, base);
}
