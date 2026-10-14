/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
extern "C" signed char *func_004AE888(signed char *) throw();
extern "C" signed char *func_004AE8C8(signed char *) throw();
extern "C" s32 func_0057F260(const char *) throw();
extern "C" void func_005A6AB0(void *, void *, s32) throw();
extern "C" signed char *func_004AEBB8(signed char *arg0, signed char *arg1) {
    signed char *p = func_004AE888(arg1);
    signed char *dst = arg0 + func_0057F260((const char *)arg0);
    while (*p != 0) {
        signed char *e = func_004AE8C8(p);
        s32 n = e - p;
        if (n == 0) break;
        *dst = 0x2F;
        dst++;
        signed char *d = dst;
        dst += n;
        func_005A6AB0(d, p, n);
        p = func_004AE888(e);
    }
    *dst = 0;
    return arg0;
}
