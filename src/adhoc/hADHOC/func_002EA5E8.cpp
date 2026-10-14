/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;

struct Rep { s32 len; s32 cap; s32 ref; s32 sel; };
struct Str { char *p; char pad[0xC]; };
struct Ref { char *p; int pad[3]; };
struct S00659988 { const char *name; };

extern Rep D_00659FA8;
extern char D_0069D298[];
extern "C" char *func_005C2560(Rep *);
extern "C" s32 func_0057F260(const char *) throw();
extern "C" void func_005CE388(Str *, s32, s32, Str *, s32, s32);
extern "C" s32 func_005CD320(Str *, const char *, s32, s32);
extern "C" struct S00659988 *func_005C11A8(void);
extern "C" void func_00326798(void *, s32, s32, const char *);
extern "C" void *func_002F41E0(Ref *, const s32 &);
extern "C" void func_002F4210(Ref *, s32);
extern "C" void func_002EA7D0(Ref *, s32, Str *);
extern "C" void func_002EC430(void *, s32, Ref *, s32);
extern "C" void func_003285A8(void *);
extern "C" void func_003285F8(void *);

static inline void str_release(Str *s) {
    Rep *q = (Rep *)(s->p - 0x10);
    if (--q->ref == 0) {
        s32 size = q->cap + 0x10;
        func_00326798(q, size, 4, func_005C11A8()->name);
    }
}

static inline void assign(Ref *d, Ref *s) {
    if (d != s) {
        char *q = s->p;
        if (q) func_003285A8(q);
        if (d->p) func_003285F8(d->p);
        d->p = q;
    }
}

extern "C" void *func_002EA5E8(void *a0, s32 a1, Str *a2, s32 a3) {
    Ref t;
    func_002F41E0(&t, 0);
    {
        Rep *sr = (Rep *)(a2->p - 0x10);
        s32 n = sr->len;
        if (n >= 4) {
            s32 m = n - 4;
            Str s;
            Str *ps = &s;
            Rep *r = &D_00659FA8;
            char *d;
            if (r->sel != 0) {
                d = func_005C2560(r);
            } else {
                d = (char *)(r + 1);
                r->ref++;
            }
            ps->p = d;
            func_005CE388(ps, 0, -1, a2, m, 4);
            s32 cmp = func_005CD320(ps, D_0069D298, 0, func_0057F260(D_0069D298)) == 0;
            str_release(ps);
            if (cmp) {
                Ref u;
                func_002EA7D0(&u, a1, a2);
                assign(&t, &u);
                func_002F4210(&u, 2);
            }
        }
    }
    func_002EC430(a0, a1, &t, a3);
    func_002F4210(&t, 2);
    return a0;
}
