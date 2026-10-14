/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Rep { int len, cap, ref, sel; };
struct Str { int p; char pad[12]; };
struct Info { const char *name; };
extern "C" char *func_005C2560(Rep *);
extern "C" Info *func_005C11A8();
extern "C" void func_00326798(void *, int, int, const char *);
static inline void copy(Str *dst, const Str *src) {
    int q = src->p;
    Rep *r = (Rep *)(q - 16);
    int d = q;
    if (r->sel != 0) d = (int)func_005C2560(r);
    else r->ref = r->ref + 1;
    dst->p = d;
}
static inline void release(Str *s) {
    Rep *r = (Rep *)(s->p - 16);
    if (--r->ref == 0) {
        int size = r->cap + 16;
        func_00326798(r, size, 4, func_005C11A8()->name);
    }
}
extern "C" Str *func_0020FE28(Str *dst, int unused, const Str *src) {
    Str temp;
    copy(&temp, src);
    copy(dst, &temp);
    release(&temp);
    return dst;
}
