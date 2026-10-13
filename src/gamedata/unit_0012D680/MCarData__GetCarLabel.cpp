typedef int s32;

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
    char pad[0xC];
};

struct Handle {
    void *p;
    char pad[0xC];
};

extern Rep D_00659FA8;
extern char D_0068E7F8[];
extern char D_0068E800[];

extern "C" void func_00312318(void *arg0, int arg1);
extern "C" void func_00312370(void *arg0, void *arg1);
extern "C" Str *func_00314920(void *arg0);
extern "C" void func_00314B20(void *arg0, void *arg1);
extern "C" const char *func_00447E18(const char *s);
extern "C" void func_003285A8(void *p);
extern "C" void func_003285F8(void *p);
extern "C" char *func_005C2560(Rep *r);
extern "C" s32 func_0057F260(const char *s);
extern "C" void *func_005C2630(Str *s, s32 pos, s32 n, const char *src, s32 len);
extern "C" struct S00659988 *func_005C11A8(void);
extern "C" void func_00326798(void *p, s32 size, s32 align, const char *name);

static inline void str_release(Str *s) {
    Rep *q = (Rep *)(s->p - 0x10);
    if (--q->ref == 0) {
        s32 size = q->cap + 0x10;
        func_00326798(q, size, 4, func_005C11A8()->name);
    }
}

static inline const char *c_str(Str *t) {
    s32 len = *(s32 *)(t->p - 0x10);
    if (len == 0) return D_0068E7F8;
    t->p[len] = 0;
    return t->p;
}

extern "C" void func_0012D7A8(void **arg0, s32 arg1, void *arg2) {
    if (arg1 > 0) {
        Handle h0;
        Handle h;
        Str s;
        Str *ps;
        func_00312370(&h0, arg2);
        {
            Str *t = func_00314920(h0.p);
            const char *c = c_str(t);
            const char *name = func_00447E18(c);
            ps = &s;
            if (name == 0) {
                name = D_0068E800;
            }
            {
                char *d;
                if (D_00659FA8.sel != 0) {
                    d = func_005C2560(&D_00659FA8);
                } else {
                    d = (char *)(&D_00659FA8 + 1);
                    D_00659FA8.ref++;
                }
                ps->p = d;
            }
            func_005C2630(ps, 0, -1, name, func_0057F260(name));
            {
                Handle *ph = &h;
                func_00314B20(ph, ps);
                if ((void *)arg0 != (void *)ph) {
                    void *p = ph->p;
                    if (p != 0) {
                        func_003285A8(p);
                    }
                    if (*arg0 != 0) {
                        func_003285F8(*arg0);
                    }
                    *arg0 = p;
                }
                func_00312318(ph, 2);
            }
            str_release(ps);
        }
        func_00312318(&h0, 2);
    }
}
