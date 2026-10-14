/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef struct Blk { char c[64]; } Blk;
typedef struct Ctx { char pad0[0x10]; unsigned int lo; unsigned int hi; Blk buf; } Ctx;
extern "C" void *func_005A4724(void *, const void *, unsigned int);
extern "C" void func_006C7520(Ctx *);

extern "C" void *func_00547200(Ctx *c, const char *p, unsigned int n) {
    unsigned int old = c->lo;
    unsigned int idx = old & 0x3F;
    unsigned int left;
    c->lo = old + n;
    if (c->lo < n) c->hi = c->hi + 1;
    left = 0x40 - idx;
    if (n >= left) {
        func_005A4724(c->buf.c + idx, p, left);
        idx = 0;
        func_006C7520(c);
        n -= left;
        p += left;
        while (n >= 0x40) {
            c->buf = *(Blk *)p;
            n -= 0x40;
            p += 0x40;
            func_006C7520(c);
        }
    }
    return func_005A4724(c->buf.c + idx, p, n);
}
