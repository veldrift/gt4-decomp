typedef int s32;
typedef unsigned int u32;

struct Rep {
    s32 len;
    s32 cap;
    s32 ref;
    s32 sel;
};

struct Str {
    char *p;
    char pad[0xC];
};

struct S00659988 {
    const char *name;
};

struct Holder {
    char pad[4];
    s32 *out;
};

extern Rep D_00659FA8;
extern char D_006995C0[];
extern char D_006995B8[];

extern "C" s32 func_0020EEA0(void *arg1, Str *s);
extern "C" void func_0020FC58(void *r, int depth);
extern "C" void func_00326798(void *p, s32 size, s32 align, const char *name);
extern "C" s32 func_0057F260(const char *s);
extern "C" s32 func_005A2F88(const char *s);
extern "C" struct S00659988 *func_005C11A8(void);
extern "C" char *func_005C2560(Rep *r);
extern "C" s32 func_005CD320(void *self, const char *s, u32 pos, u32 n);

static inline void str_release(Str *s) {
    Rep *q = (Rep *)(s->p - 0x10);
    if (--q->ref == 0) {
        s32 size = q->cap + 0x10;
        func_00326798(q, size, 4, func_005C11A8()->name);
    }
}

extern "C" void MintReader__virtual_03(Holder *arg0, void *arg1, void *arg2) {
    Str s;
    char *c;
    if (func_005CD320(arg2, D_006995C0, 0, func_0057F260(D_006995C0)) == 0) {
        Rep *r = &D_00659FA8;
        char *d;
        if (r->sel != 0) {
            d = func_005C2560(r);
        } else {
            d = (char *)(r + 1);
            r->ref++;
        }
        s.p = d;
        func_0020EEA0(arg1, &s);
        if (func_0020EEA0(arg1, &s) == 0x101) {
            Rep *q = (Rep *)(s.p - 0x10);
            if (q->len == 0) {
                c = D_006995B8;
            } else {
                s.p[q->len] = 0;
                c = s.p;
            }
            s32 v = func_005A2F88(c);
            *arg0->out = v;
        }
        func_0020FC58(arg1, 1);
        str_release(&s);
    }
}
