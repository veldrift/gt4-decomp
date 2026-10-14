/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef unsigned int u32;

struct Rep {
    s32 len;
    s32 cap;
    s32 ref;
    s32 sel;
};

struct S00659988 {
    const char *name;
};

struct Str {
    char *p;
};

extern Rep D_00659FA8;
extern char D_0069E1B0[];

extern "C" Str *func_00314920(void *arg0) throw();
extern "C" void func_00314B20(void *arg0, void *arg1) throw();
extern "C" char *func_005C2560(Rep *r);
extern "C" s32 func_0057F260(const char *s) throw();
extern "C" void func_005C2630(Str *s, s32 pos, s32 n, const char *src, s32 len);
extern "C" struct S00659988 *func_005C11A8(void);
extern "C" void func_00326798(void *p, s32 size, s32 align, const char *name);
extern "C" void func_005CB5A0(Str *s, s32 size, s32 save);

static inline char *str_at(Str *s, s32 i) {
    Rep *r = (Rep *)(s->p - 0x10);
    if ((u32)r->ref >= 2) {
        func_005CB5A0(s, r->len, 1);
    }
    ((Rep *)(s->p - 0x10))->sel = 1;
    return s->p + i;
}

extern "C" void *func_00314E38(void *arg0, void *arg1) {
    Str s;
    Str *ps = &s;
    Str *t = func_00314920(arg1);
    const char *c;
    s32 len = *(s32 *)(t->p - 0x10);
    if (len == 0) {
        c = D_0069E1B0;
    } else {
        t->p[len] = 0;
        c = t->p;
    }
    {
        Rep *r = &D_00659FA8;
        char *d;
        if (r->sel != 0) {
            d = func_005C2560(r);
        } else {
            d = (char *)(r + 1);
            r->ref++;
        }
        ps->p = d;
    }
    func_005C2630(ps, 0, -1, c, func_0057F260(c));
    {
        s32 n = *(s32 *)(s.p - 0x10);
        s32 i;
        for (i = 0; i < n; i++) {
            char ch = *str_at(&s, i);
            if ((u32)(ch - 0x61) < 0x1A) {
                ch -= 0x20;
                *str_at(&s, i) = ch;
            }
        }
    }
    func_00314B20(arg0, &s);
    {
        Rep *q = (Rep *)(s.p - 0x10);
        if (--q->ref == 0) {
            s32 size = q->cap + 0x10;
            func_00326798(q, size, 4, func_005C11A8()->name);
        }
    }
    return arg0;
}
