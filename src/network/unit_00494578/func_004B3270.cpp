/* compiler: ee-gcc2.96-no-strict-aliasing */
struct L {
    int w0;
    int w4;
    char pad[0x20 - 8];
    unsigned char c20;
};
extern "C" void func_004B2A18(int) throw();
extern "C" void func_004B2A40(int, void *) throw();
extern "C" void func_004B30B8(void *, int, int, signed char *, int) throw();

extern "C" int func_004B3270(int a0, int a1, int a2, signed char *a3) {
    L l;
    signed char *s;
    for (;;) {
        s = a3;
        if (*s != 0 && *s != 0x2F) {
            do {
                s++;
            } while (*s != 0 && *s != 0x2F);
        }
        func_004B30B8(&l, a1, a2, a3, s - a3);
        if (*s == 0) {
            func_004B2A40(a0, &l);
            return a0;
        }
        a3 = s + 1;
        if ((l.c20 & 1) == 0) {
            func_004B2A18(a0);
            return a0;
        }
        a2 = l.w4;
    }
}
