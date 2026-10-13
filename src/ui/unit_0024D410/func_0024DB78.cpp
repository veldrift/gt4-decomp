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

struct Reader;

struct Obj {
    char *vtbl;
};

struct VEntry1 {
    short delta;
    short index;
    void (*fn)(void *, s32);
};

struct VEntry2 {
    short delta;
    short index;
    void (*fn)(void *, void *, s32);
};

struct VEntry3 {
    short delta;
    short index;
    void (*fn)(void *, void *, void *);
};

extern Rep D_00659FA8;
extern char D_006995B8[];

extern "C" s32 func_0020EEA0(Reader *r, Str *s);
extern "C" void func_0020FC58(Reader *r, int depth);
extern "C" void func_00326798(void *p, s32 size, s32 align, const char *name);
extern "C" s32 func_005A2F88(const char *s);
extern "C" struct S00659988 *func_005C11A8(void);
extern "C" char *func_005C2560(Rep *r);

static inline const char *c_str(Str *s) {
    s32 len = ((Rep *)s->p)[-1].len;
    if (len == 0) {
        return D_006995B8;
    }
    s->p[len] = 0;
    return s->p;
}

static inline void release(Str *s) {
    Rep *q = (Rep *)(s->p - 0x10);
    if (--q->ref == 0) {
        s32 cap = q->cap + 0x10;
        func_00326798(q, cap, 4, func_005C11A8()->name);
    }
}

extern "C" s32 func_0024DB78(Obj *arg0, Reader *arg1) {
    Str s;
    s32 r;
    s32 cnt;
    s32 i;

    {
        Rep *rep = &D_00659FA8;
        char *d;
        if (rep->sel != 0) {
            d = func_005C2560(rep);
        } else {
            d = (char *)(rep + 1);
            rep->ref++;
        }
        s.p = d;
    }

    r = func_0020EEA0(arg1, &s);
    if (r == 0x100) {
        VEntry3 *e = (VEntry3 *)(arg0->vtbl + 0x20);
        e->fn((char *)arg0 + e->delta, arg1, &s);
    } else if (r == 0x5B) {
        func_0020EEA0(arg1, &s);
        cnt = func_005A2F88(c_str(&s));
        func_0020EEA0(arg1, &s);
        func_0020EEA0(arg1, &s);
        if (cnt > 0) {
            i = 0;
            {
                VEntry1 *e = (VEntry1 *)(arg0->vtbl + 0x10);
                e->fn((char *)arg0 + e->delta, cnt);
            }
            for (; i < cnt; i++) {
                VEntry2 *e = (VEntry2 *)(arg0->vtbl + 0x18);
                e->fn((char *)arg0 + e->delta, arg1, i);
            }
        }
        func_0020FC58(arg1, 1);
    }

    release(&s);
    return r;
}
