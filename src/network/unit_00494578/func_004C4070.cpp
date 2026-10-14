/* compiler: ee-gcc2.96-no-strict-aliasing */
extern "C" void *func_004C4070(void *dst, const void *src, unsigned length) {
    unsigned char *d = (unsigned char *)dst;
    const unsigned char *s = (const unsigned char *)src;
    unsigned t;
    unsigned wsize = 4;
    if (d == s || length == 0) return dst;
    if (d < s) {
        t = (unsigned)s;
        if ((t | (unsigned)d) & 3) {
            if ((t ^ (unsigned)d) & 3 || length < wsize) t = length;
            else t = wsize - (t & 3);
            length -= t;
            do { *d++ = *s++; } while (--t);
        }
        t = length / wsize;
        if (t) {
            do {
                *(unsigned *)d = *(const unsigned *)s;
                s += wsize; d += wsize;
            } while (--t);
        }
        t = length & 3;
        if (t) do { *d++ = *s++; } while (--t);
    } else {
        s += length;
        d += length;
        t = (unsigned)s;
        if ((t | (unsigned)d) & 3) {
            if ((t ^ (unsigned)d) & 3 || length <= wsize) t = length;
            else t &= 3;
            length -= t;
            do { *--d = *--s; } while (--t);
        }
        t = length / wsize;
        if (t) {
            do {
                s -= wsize; d -= wsize;
                *(unsigned *)d = *(const unsigned *)s;
            } while (--t);
        }
        t = length & 3;
        if (t) do { *--d = *--s; } while (--t);
    }
    return dst;
}
