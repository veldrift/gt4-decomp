/* compiler: ee-gcc2.96-no-strict-aliasing */
struct E { int a; int b; };
struct H { char p0[4]; unsigned short f4; char p6[2]; unsigned int cnt; int size; E e[1]; };
struct T { H *h; char p[0x20]; int sub[1]; };
extern "C" int func_00449188(T *t) throw();
extern "C" void func_004493F8(T *t, int a, int b);
extern "C" void func_0044A908(int *s, int k, int i, int d);
extern "C" int func_0044AB20(int *s, int k, int i, int d);
extern "C" void *func_005A4724(int d, int s, unsigned n);
static inline int key_at(T *t, int idx) {
    if (idx < 0) return -1;
    if (idx >= (int)t->h->cnt) return -1;
    H *row = (H *)((char *)t->h + idx * 8);
    return row->e[0].a;
}
static inline int *cache(T *t) { return t->sub; }
static inline unsigned short flags(T *t) { return t->h->f4 & 1; }
extern "C" int SPEC_DATABASE__DatabaseTable__getRowN(T *t, unsigned int idx, int dst) {
    if (idx >= t->h->cnt) return 0;
    {
        int sz = t->h->size;
        int key = key_at(t, idx);
        int *sub = cache(t);
        if (func_0044AB20(sub, key, idx, dst) != 0) return sz;
        {
            H *row = (H *)((char *)t->h + idx * 8);
            int off = row->e[0].b;
            int src = func_00449188(t) + off;
            if (flags(t)) func_004493F8(t, src, dst);
            else func_005A4724(dst, src, sz);
            func_0044A908(sub, key, idx, dst);
        }
        return sz;
    }
}
