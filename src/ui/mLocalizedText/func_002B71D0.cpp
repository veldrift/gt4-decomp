/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Rep { int len, cap, ref, sel; };
struct Str { char *p; char pad[12]; };
struct Obj { char pad[12]; Str s; };
struct Info { const char *name; };
extern Rep D_00659FA8;
extern char D_008386A8[], D_0069C110[];
extern "C" Info *func_005C11A8();
extern "C" void func_00326798(void *, int, int, const char *);
extern "C" char *func_005C2560(Rep *);
extern "C" void func_005769F0(void *);
extern "C" void func_00576A28(void *);
extern "C" int func_0057F260(const char *) throw();
extern "C" Str *func_005C2630(Str *, unsigned, unsigned, const char *, unsigned);
static inline Rep *rep(Str *s) { return (Rep *)(s->p - 16); }
static inline void release(Str *s) {
    Rep *r = rep(s);
    if (--r->ref == 0) {
        int size = r->cap + 16;
        func_00326798(r, size, 4, func_005C11A8()->name);
    }
}
static inline char *grab(Rep *r) {
    if (r->sel) return func_005C2560(r);
    char *d = (char *)(r + 1);
    int n = r->ref + 1; r->ref = n;
    return d;
}
static inline const char *c_str(Str *s) {
    Rep *r = rep(s);
    if (r->len == 0) return D_0069C110;
    s->p[r->len] = 0;
    return s->p;
}
extern "C" Str *func_002B71D0(Str *out, Obj *o) {
    Str s;
    s.p = grab(&D_00659FA8);
    func_005769F0(D_008386A8);
    const char *src = c_str(&o->s);
    func_005C2630(&s, 0, -1, src, func_0057F260(src));
    func_00576A28(D_008386A8);
    out->p = grab(rep(&s));
    release(&s);
    return out;
}
