struct Buf { char *p; unsigned n; };
extern "C" int func_0044C4D8(Buf *);
extern "C" int func_0044C7F8(Buf *);
extern "C" void func_0044C8E0(char *, char *);
extern "C" void *func_005A4724(void *, const void *, unsigned);
extern "C" void *func_005A48D8(void *, int, unsigned);

extern "C" unsigned func_0044C918(char *out, unsigned size, const void *src, unsigned n, int fill) {
    Buf b;
    unsigned i;
    unsigned cnt;
    b.p = (char *)__builtin_alloca(n);
    b.n = n;
    i = 0;
    func_005A4724(b.p, src, n);
    for (cnt = 0; func_0044C4D8(&b) == 0; ) {
        cnt++;
        out[i++] = func_0044C7F8(&b) + '0';
        if (i >= size) i = 0;
    }
    char *p = out + i;
    if (size < cnt) {
        func_0044C8E0(out, p - 1);
        func_0044C8E0(p, out + size - 1);
    } else if (fill >= 0) {
        func_005A48D8(out + cnt, fill, size - cnt);
        func_0044C8E0(out, out + size - 1);
        cnt = size;
    } else {
        func_0044C8E0(out, out + cnt - 1);
    }
    return cnt;
}
