/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Blk { int m0; int len; int m8; };
struct V { short delta; short pad; int (*fn)(void *, Blk *); };
struct Obj { V *vt; char pad[0x20]; };
extern "C" char *func_0043A398(char *, int) throw();
extern "C" char *func_0043B168(void *, char *);
extern "C" char *func_004374A8(void *, char *);
extern "C" char *func_00430030(void *, char *);
extern "C" int func_0043A370(char *, int) throw();
extern "C" int func_0043AAF0(Obj *o, char *p) {
    char *a = func_0043B168((char *)o + 0x348, func_0043A398(p, 0x10));
    char *b = func_004374A8((char *)o + 0x38CB0, a);
    char *c = func_00430030((char *)o + 0x3A368, b);
    Blk *blk = (Blk *)p;
    char *q = p + 0x10;
    int d = q - c;
    blk->len = d;
    blk->m0 = 0xFF60BAD3;
    blk->m8 = func_0043A370(q, -d);
    V *v = o->vt + 4;
    return v->fn((char *)o + v->delta, blk);
}
