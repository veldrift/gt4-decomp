/* compiler: ee-gcc2.96-no-strict-aliasing */
#define CT(c) (((unsigned char *)0x6D0E79)[c])
extern "C" unsigned int func_0057F260(const char *s) throw();
extern "C" void func_005A5DC8(char *d, const char *s);

extern "C" void func_0030CE78(char *dst, const char *dir, const char *file) {
    const char *p = dir;
    const char *dp;
    char *out;
    char c;
    char c2;
    if (CT(*p) & 3) {
        p++;
        while (c = *p, (CT(c) & 7) && c != 0)
            p++;
        p = c == ':' ? p + 1 : dir;
    }
    dp = p;
    p = file;
    if (CT(*p) & 3) {
        p++;
        while (c2 = *p, (CT(c2) & 7) && c2 != 0)
            p++;
        p = c2 == ':' ? p + 1 : file;
    }
    out = dst;
    *out = 0;
    if (*p != '/') {
        func_005A5DC8(dst, dir);
        out += func_0057F260(dir);
        if (*dp != 0) {
            *out = '/';
            out++;
        }
        *out = 0;
    }
    func_005A5DC8(out, p);
}
