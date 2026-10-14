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
    char pad[0xC];
};

struct Handle {
    void *p;
    char pad[0xC];
};

union W {
    s32 i;
    char *p;
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
extern char D_0069B650[];

extern "C" void func_0029E7F0(void *arg0, int arg1);
extern "C" void *func_0029E848(void *arg0, void *arg1);
extern "C" int func_0029EB10(int arg0);
extern "C" int func_0029EB38(int arg0);
extern "C" void func_00312318(void *arg0, int arg1);
extern "C" void func_00314B20(void *arg0, void *arg1);
extern "C" void func_003285A8(void *p);
extern "C" void func_003285F8(void *p);
extern "C" s32 func_0057F260(const char *s);
extern "C" struct S00659988 *func_005C11A8(void);
extern "C" char *func_005C2560(Rep *r);
extern "C" void *func_005C2630(void *s, s32 pos, s32 n, const char *src, s32 len);
extern "C" void func_00326798(void *p, s32 size, s32 align, const char *name);

static inline void vcall(void *ret, VObj *o) {
    VEntry *e = (VEntry *)((char *)o->vtbl + 0x18);
    e->fn(ret, (char *)o + e->delta);
}

static inline const char *c_str(Str *s) {
    s32 len = ((Rep *)s->p)[-1].len;
    if (len == 0) {
        return D_0069B650;
    }
    s->p[len] = 0;
    return s->p;
}

static inline void release(Str *s) {
    Rep *q = (Rep *)(s->p - 0x10);
    if (--q->ref == 0) {
        s32 size = q->cap + 0x10;
        func_00326798(q, size, 4, func_005C11A8()->name);
    }
}

extern "C" void MGraphFace__get_type(void **arg0, void *arg1, s32 arg2, VObj **arg3) {
    Handle h;
    Str t;
    s32 spare[4];
    Str s;
    Handle sp40;
    if (arg2 > 0) {
        VObj *o;
        Str *pt;
        char *obj;
        func_0029E848(&h, arg1);
        o = *arg3;
        pt = &t;
        obj = (char *)h.p;
        vcall(pt, o);
        ((W *)(obj + 0xB8))->i = func_0029EB10((int)c_str(pt));
        release(pt);
        func_0029E7F0(&h, 2);
    } else {
        Handle *p40 = &sp40;
        Str *ps = &s;
        const char *src;
        Rep *r;
        char *d;
        func_0029E848(p40, arg1);
        src = (const char *)func_0029EB38(*(s32 *)((char *)p40->p + 0xB8));
        r = &D_00659FA8;
        if (r->sel != 0) {
            d = func_005C2560(r);
        } else {
            d = (char *)(r + 1);
            r->ref++;
        }
        ps->p = d;
        func_005C2630(ps, 0, -1, src, func_0057F260(src));
        func_00314B20(&h, ps);
        if ((void *)arg0 != (void *)&h) {
            void *p = h.p;
            if (p != 0) {
                func_003285A8(p);
            }
            if (*arg0 != 0) {
                func_003285F8(*arg0);
            }
            *arg0 = p;
        }
        func_00312318(&h, 2);
        release(ps);
        func_0029E7F0(p40, 2);
    }
}
