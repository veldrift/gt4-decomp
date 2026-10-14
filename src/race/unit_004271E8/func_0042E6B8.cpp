/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef signed char s8;
extern "C" void func_0057DA20(int, int, ...);
extern "C" s32 func_0057F260(const char *) throw();
extern "C" void func_005A6AB0(void *, void *, s32) throw();
extern char D_006A4FE0[], D_006A4FD8[];
extern "C" int func_0042E440() throw();

extern "C" void func_0042E6B8(long value, s8 *buf, s32 size) {
    s8 tmp[0x80];
    if (value <= 0) {
        func_005A6AB0(buf, D_006A4FD8, size);
        return;
    }
    func_0057DA20((int)buf, (int)D_006A4FE0, value * func_0042E440());
    s32 n = func_0057F260((const char *)buf);
    s32 pos = 0x3E;
    s32 idx = n - 1;
    tmp[0x3F] = 0;
    s32 i = 0;
    if (n > 0) {
        do {
            i++;
            s32 ch = buf[idx--];
            tmp[pos--] = ch;
            if (i % 3 == 0 && i < n)
                tmp[pos--] = ',';
        } while (i < n);
    }
    func_005A6AB0(buf, tmp + pos + 1, size);
}
