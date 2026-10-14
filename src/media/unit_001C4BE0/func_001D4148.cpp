/* compiler: ee-gcc2.96-no-strict-aliasing */
extern "C" int func_001D40F0(short *p, short *end) throw();
extern "C" void *func_005A4724(void *, const void *, unsigned) throw();
extern "C" int func_001D4148(int *dst, short *src) {
    short *end = (short *)((char *)src + 0x8000);
    int more = src < end;
    short *out = (short *)(dst + 1);
    int lit = 0;
    int state = 0;
    unsigned short v;
    short *o;
    if (more) {
        do {
            int n = func_001D40F0(src, end);
            if (state == 0) {
                if (n < 2) {
                    src++;
                    lit = n;
                    state = 1;
                    more = src < end;
                } else {
                    *out++ = n;
                    v = *src;
                    src = (short *)((char *)src + n * 2);
                    more = src < end;
                    *out++ = v;
                }
            } else if (state == 1) {
                if (n >= 4 || (n == 3 && func_001D40F0(src + 3, end) >= 2)) {
                    int bytes = lit * 2;
                    *out++ = -lit;
                    o = out;
                    func_005A4724(o, (char *)src - bytes, bytes);
                    out = (short *)((char *)out + bytes);
                    state = 0;
                    *out++ = n;
                    v = *src;
                    src = (short *)((char *)src + n * 2);
                    lit = 0;
                    more = src < end;
                    *out++ = v;
                } else {
                    src++;
                    lit++;
                    more = src < end;
                }
            }
        } while (more);
    }
    if (lit != 0) {
        int bytes = lit * 2;
        *out++ = -lit;
        o = out;
        func_005A4724(o, (char *)src - bytes, bytes);
        out = (short *)((char *)out + bytes);
    }
    int size = (char *)out - (char *)dst;
    *dst = size - 4;
    return size;
}
