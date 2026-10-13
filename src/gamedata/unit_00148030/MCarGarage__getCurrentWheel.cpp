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
    char pad[0xC];
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

struct Dflt {
    s32 w[2];
};

struct Pack {
    Dflt nm;
    s32 blob[14];
};

struct VEntry {
    short delta;
    short index;
    void (*fn)(void *, void *);
};

struct VObj {
    char pad[4];
    VEntry *vtbl;
};

extern Rep D_00659FA8;
extern char D_0068F788[];
extern Dflt D_0068F790;

extern "C" void func_0013BD68(void *arg0, int arg1);
extern "C" void func_0013BDC0(void *arg0, void *arg1);
extern "C" int func_00147D80(void *arg0);
extern "C" int func_0014D968(const char *arg0);
extern "C" void func_00312318(void *arg0, int arg1);
extern "C" void func_00314B20(void *arg0, void *arg1);
extern "C" void func_00326798(void *p, s32 size, s32 align, const char *name);
extern "C" void func_003285A8(void *p);
extern "C" void func_003285F8(void *p);
extern "C" int func_004409C8(int arg0, int arg1);
extern "C" void func_00446E60(s32 arg0, void *arg1);
extern "C" s32 func_0057F260(const char *s);
extern "C" void func_005A48D8(void *p, int c, u32 n);
extern "C" struct S00659988 *func_005C11A8(void);
extern "C" char *func_005C2560(Rep *r);
extern "C" void *func_005C2630(Str *s, s32 pos, s32 n, const char *src, s32 len);

static inline void vcall(void *ret, VObj *o) {
    VEntry *e = (VEntry *)((char *)o->vtbl + 0x18);
    e->fn(ret, (char *)o + e->delta);
}

static inline const char *c_str(Str *s) {
    s32 len = ((Rep *)s->p)[-1].len;
    if (len == 0) {
        return D_0068F788;
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

extern "C" void func_0014DD38(void **arg0, s32 arg1, s32 arg2, VObj **arg3) {
    if (arg2 > 0) {
        U u;
        Pack pk;
        s32 spare[4];
        Str s;
        Str *ps;
        int k;
        s32 s0;

        vcall(&u.s, *arg3);
        k = func_0014D968(c_str(&u.s));
        release(&u.s);
        func_0013BDC0(&u, (void *)arg1);
        s0 = func_004409C8(func_00147D80(u.s.p), k);
        func_0013BD68(&u, 2);
        pk.nm = D_0068F790;
        func_005A48D8(pk.blob, 0, 0x38);
        func_00446E60(s0, &pk.nm);
        ps = &s;
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
        func_005C2630(ps, 0, -1, (const char *)&pk.nm, func_0057F260((const char *)&pk.nm));
        func_00314B20(&u, ps);
        if ((void *)arg0 != (void *)&u) {
            void *p = u.s.p;
            if (p != 0) {
                func_003285A8(p);
            }
            if (*arg0 != 0) {
                func_003285F8(*arg0);
            }
            *arg0 = p;
        }
        func_00312318(&u, 2);
        release(ps);
    }
}
