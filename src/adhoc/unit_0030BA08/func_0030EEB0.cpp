typedef int s32;

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

struct Vec {
    s32 pad;
    s32 *begin;
    s32 *end;
};

extern Rep D_00659FA8;

extern "C" void func_002FFC58(s32, s32);
extern "C" const char *HSymID__GetName(s32);
extern "C" s32 func_0057F260(const char *);
extern "C" char *func_005C2560(Rep *);
extern "C" void *func_005C2630(Str *, s32, s32, const char *, s32);
extern "C" void func_002FFCD8(s32, void *);
extern "C" struct S00659988 *func_005C11A8(void);
extern "C" void func_00326798(void *, s32, s32, const char *);

static inline void str_release(Str *s) {
    Rep *q = (Rep *)(s->p - 0x10);
    if (--q->ref == 0) {
        s32 size = q->cap + 0x10;
        func_00326798(q, size, 4, func_005C11A8()->name);
    }
}

extern "C" void func_0030EEB0(Vec *arg0, s32 arg1) {
    s32 i = 0;
    s32 n = arg0->end - arg0->begin;
    Str s;
    Str *ps;
    func_002FFC58(arg1, n);
    if (n > 0) {
        ps = &s;
        for (i = 0; i < n; i++) {
            s32 *e = arg0->begin + i;
            const char *s0 = HSymID__GetName(*e);
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
            func_005C2630(ps, 0, -1, s0, func_0057F260(s0));
            func_002FFCD8(arg1, &s);
            str_release(&s);
        }
    }
}
