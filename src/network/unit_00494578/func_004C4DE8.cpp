/* compiler: ee-gcc2.96-no-strict-aliasing */
extern "C" int func_004C4CB8(unsigned short c) throw() __attribute__((const));

extern "C" int func_004C4DE8(unsigned short *s) {
    unsigned short *p = s;
    while (*p != 0) {
        if (func_004C4CB8(*p) < 0) {
            return -1 - (p - s);
        }
        p++;
    }
    return 0;
}
