/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned int u32;
extern "C" int func_00430C28(int, int) throw();
extern "C" int func_00430E58(int, char *) throw();
extern "C" int func_005A5A30(char *, u32, const char *, ...);

extern "C" int func_004311A0(int self, int a, const char *fmt, int flag, int start, int limit) {
    char buf[0x40];
    int r = 0;
    int mask = flag & 0xFF;
    int i;
    if (limit < start) return r;
    for (i = start; i <= limit; i++) {
        func_005A5A30(buf, 0x40, fmt, a, i);
        r = func_00430E58(self, buf);
        if (r == 0) return r;
        r = func_00430C28(r, mask);
        if (r == 0) return r;
    }
    return 1;
}
