/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
extern "C" signed char *func_004AE888(signed char *) throw();
extern "C" signed char *func_004AE8C8(signed char *) throw();
extern "C" void func_005A6AB0(void *, void *, s32) throw();
extern "C" signed char *func_004AEAE8(signed char *arg0, signed char *arg1) {
    signed char *dst = arg0;
    signed char *p = arg1;
    s32 slash = *p == 0x2F;
    p = func_004AE888(p);
    while (*p != 0) {
        signed char *e = func_004AE8C8(p);
        s32 n = e - p;
        if (n == 0) break;
        if (slash) {
            *dst = 0x2F;
            dst++;
        }
        signed char *d = dst;
        dst += n;
        func_005A6AB0(d, p, n);
        p = func_004AE888(e);
        slash = 1;
    }
    *dst = 0;
    return arg0;
}
