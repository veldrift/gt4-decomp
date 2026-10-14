typedef int (*OutFn)(int, int, int);
extern "C" int func_00493438(void *, int *);
extern "C" int func_0057F260(const char *);

extern "C" int func_00493468(OutFn out, int *cnt, int ctx, int flags, int width, int prec, const char *str) {
    int total = 0;
    int lpad = 0;
    int len = func_0057F260(str);
    int rpad = 0;
    if (prec >= 0 && prec < len) len = prec;
    width -= len;
    if (width < 0) width = 0;
    if ((flags ^ 1) & 1) lpad = width; else rpad = width;
    int padc = (flags & 4) ? 0x30 : 0x20;
    int i;
    for (i = 0; i < lpad; i++) {
        if (out(padc, *cnt, ctx)) return -1;
        if (*cnt) *cnt = *cnt + 1;
        total++;
    }
    int n;
    for (i = 0; i < len; ) {
        int c = func_00493438(&str, &n);
        i += n;
        total += n;
        if (out(c, *cnt, ctx)) return -1;
        if (*cnt) *cnt = *cnt + 1;
    }
    for (i = 0; i < rpad; i++) {
        if (out(0x20, *cnt, ctx)) return -1;
        if (*cnt) *cnt = *cnt + 1;
        total++;
    }
    return total;
}
