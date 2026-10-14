/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Rep { int len; int cap; int ref; int sel; };
struct Str { char *p; char pad[0xC]; };
struct S00659988 { const char *name; };
extern char D_0069C110[];
extern "C" void func_002B74B0(Str *, int) throw();
extern "C" int func_004B9930(const char *);
extern "C" void func_00326798(void *, int, int, const char *);
extern "C" S00659988 *func_005C11A8(void);

static inline void str_release(Str *s) {
    Rep *q = (Rep *)(s->p - 0x10);
    if (--q->ref == 0) {
        int size = q->cap + 0x10;
        func_00326798(q, size, 4, func_005C11A8()->name);
    }
}

extern "C" int func_002B77D8(int a) {
    Str s;
    func_002B74B0(&s, a);
    const char *v = D_0069C110;
    Rep *r = (Rep *)(s.p - 0x10);
    if (r->len) {
        s.p[r->len] = 0;
        v = s.p;
    }
    int res = func_004B9930(v);
    str_release(&s);
    return res;
}
