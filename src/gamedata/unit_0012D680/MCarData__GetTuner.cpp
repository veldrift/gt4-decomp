typedef int s32;
typedef short s16;

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

struct Handle {
    void *p;
    char pad[0xC];
};

union U {
    Str s;
    Handle h;
    s32 w[4];
};

struct VEntry {
    s16 delta;
    s16 index;
    void (*fn)(void *, void *);
};

struct VObj {
    char pad[4];
    VEntry *vtbl;
};

extern Rep D_00659FA8;
extern char D_0068E7F8[];
extern char D_0068E830[];

extern "C" int func_00448738(const char *arg0, s32 *arg1, s32 *arg2);
extern "C" int func_00448DF0(int arg0);
extern "C" s32 func_0057F260(const char *s);
extern "C" char *func_005C2560(Rep *r);
extern "C" void *func_005C2630(Str *s, s32 pos, s32 n, const char *src, s32 len);
extern "C" struct S00659988 *func_005C11A8(void);
extern "C" void func_00326798(void *p, s32 size, s32 align, const char *name);
extern "C" void func_00312318(void *arg0, int arg1);
extern "C" void func_00314B20(void *arg0, void *arg1);
extern "C" void func_003285A8(void *p);
extern "C" void func_003285F8(void *p);

static inline void vcall(void *ret, VObj *o) {
    VEntry *e = (VEntry *)((char *)o->vtbl + 0x18);
    e->fn(ret, (char *)o + e->delta);
}

static inline const char *c_str(Str *s) {
    s32 len = ((Rep *)s->p)[-1].len;
    if (len == 0) {
        return D_0068E7F8;
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

extern "C" void func_0012EBA0(void **arg0, s32 arg1, VObj **arg2) {
    if (arg1 > 0) {
        s32 dest[4];
        U u;
        U *pu;
        s32 spare[4];
        Str s;
        Str *ps;
        const char *src;

        pu = &u;
        vcall(pu, *arg2);
        func_00448738(c_str(&pu->s), dest, &dest[1]);
        release(&pu->s);
        src = (const char *)func_00448DF0(dest[1]);
        ps = &s;
        if (src == 0) {
            src = D_0068E830;
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
        func_005C2630(ps, 0, -1, src, func_0057F260(src));
        func_00314B20(pu, ps);
        if ((void *)arg0 != (void *)pu) {
            void *p = pu->h.p;
            if (p != 0) {
                func_003285A8(p);
            }
            if (*arg0 != 0) {
                func_003285F8(*arg0);
            }
            *arg0 = p;
        }
        func_00312318(pu, 2);
        release(ps);
    }
}
