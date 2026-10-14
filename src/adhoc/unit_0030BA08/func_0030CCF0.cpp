/* compiler: ee-gcc2.96-no-strict-aliasing */
extern "C" void func_0030CCF0(char *dst, char *p, char *s2) {
    char *s1 = p;
    char *out = dst;
    char *q = s2;
    int n = 0;
    while (*p != 0 && *q != 0 && *p == *q) {
        if (*p == '/')
            n = p - s1;
        p++;
        q++;
    }
    if (*p == 0) {
        if (*q == 0) {
            *out++ = '.';
        } else {
            if (*q != '/')
                q = s2 + n;
            if (p > s1)
                q++;
        }
    } else {
        while (*p != 0) {
            if (*p == '/') {
                p++;
            } else {
                while (*p != 0 && *p != '/')
                    p++;
                *out++ = '.';
                *out++ = '.';
                *out++ = '/';
            }
            }
    }
    while (*q != 0) {
        *out++ = *q++;
    }
    if (dst < out) {
        char *prev = out - 1;
        if (*prev == '/')
            out = prev;
    }
    *out = 0;
}
