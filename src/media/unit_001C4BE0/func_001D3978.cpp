/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Blk { long q[8]; };
struct Ent { short off; short pad; int (*fn)(void *); };
struct VT { char p[0x38]; Ent e; };
struct Sub { VT *vptr; };
struct Arg1 { char p[0x30]; Sub *sub; };
struct Res { long pad; Blk b; };
extern "C" int func_001CD860(void *);
extern "C" int func_001D2B50(void *, int) throw();
extern "C" Res *func_001D3800(int) throw();

struct H { Res *p; H() {} H(const H &h) : p(h.p) {} };
static inline int test(Sub *s) { Ent *e = &s->vptr->e; return e->fn((char *)s + e->off); }

extern "C" H func_001D3978(Arg1 *a1, char *a2) {
    int kind = 0x44;
    if (test(a1->sub) == 0)
        kind = func_001CD860(a2 + 0x1C);
    Res *r = 0;
    if (func_001D2B50(a1, kind) != 0) {
        r = func_001D3800(kind);
        if (r != 0)
            r->b = *(Blk *)a2;
    }
    H h;
    h.p = r;
    return h;
}
