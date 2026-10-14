/* compiler: ee-gcc2.96-nogcse */
typedef unsigned long u64;
typedef unsigned char u8;
struct E { u8 b0, b1, b2, b3; unsigned w; };
struct H { int pad; int n; };
struct T { char pad[0xC]; H *h; int pad2; E *e; };
extern "C" int func_00449558(T *t, unsigned arg, u8 *out) {
    H *h = t->h;
    E *tbl = t->e;
    int n = 9;
do {
    int hi = h->n;
    int lo = -1;
    long bits = n;
    u64 m = arg & ((1 << n) - 1);
inner:
    int mid = (lo + hi) >> 1;
    E *e = &tbl[mid];
    u8 result = e->b1;
    u64 v = ((u64)e->b0 << 32) + e->w;
    u64 key = ((u64)bits << 32) + m;
    if (v == key) { *out = result; return n; }
    if (v < key) lo = mid; else hi = mid;
    if (lo + 1 != hi) goto inner;
    n++;
    } while (n < 33);
    return 0;
}
