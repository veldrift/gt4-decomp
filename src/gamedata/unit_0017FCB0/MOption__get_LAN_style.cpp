typedef int s32;
typedef short s16;
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

struct HObj {
    char pad[0x10];
    char *f10;
};

struct HStr {
    HObj *p;
    char pad[0xC];
};

struct VEntryV {
    s16 delta;
    s16 index;
    void (*fn)(void *, void *);
};

struct VObj {
    char pad[4];
    char *vtbl;
};

extern Rep D_00659FA8;
extern char D_006915D0[];

extern "C" void func_0017FAD0(void *, int);
extern "C" void *func_0017FB28(void *, void *);
extern "C" void func_00312318(void *, int);
extern "C" void func_00314B20(void *, void *);
extern "C" void func_00326798(void *, s32, s32, const char *);
extern "C" void func_003285A8(void *);
extern "C" void func_003285F8(void *);
extern "C" const char *func_00438CB8(void *);
extern "C" void func_00438CF8(void *, const char *);
extern "C" s32 func_0057F260(const char *);
extern "C" struct S00659988 *func_005C11A8(void);
extern "C" char *func_005C2560(void *);
extern "C" void *func_005C2630(void *, u32, u32, const char *, u32);

static inline void str_release(Str *s) {
    Rep *q = (Rep *)(s->p - 0x10);
    if (--q->ref == 0) {
        s32 size = q->cap + 0x10;
        func_00326798(q, size, 4, func_005C11A8()->name);
    }
}

static inline const char *c_str(Str *t) {
    s32 len = *(s32 *)(t->p - 0x10);
    if (len == 0) return D_006915D0;
    t->p[len] = 0;
    return t->p;
}

static inline void vcall18(Str *ret, VObj *o) {
    VEntryV *e = (VEntryV *)(o->vtbl + 0x18);
    e->fn(ret, (char *)o + e->delta);
}

extern "C" void MOption__get_LAN_style(void **arg0, void *arg1, s32 arg2, VObj **arg3) {
    HStr h;
    if (arg2 > 0) {
        Str t;
        HObj *hp;
        func_0017FB28(&h, arg1);
        hp = h.p;
        vcall18(&t, arg3[0]);
        const char *n = c_str(&t);
        func_00438CF8(hp->f10 + 0x1344, n);
        str_release(&t);
        func_0017FAD0(&h, 2);
        return;
    }
    {
        Str res;
        Str s;
        func_0017FB28(&h, arg1);
        Str *ps = &s;
        const char *src = func_00438CB8(h.p->f10 + 0x1344);
        Rep *r = &D_00659FA8;
        char *d;
        if (r->sel != 0) {
            d = func_005C2560(r);
        } else {
            d = (char *)(r + 1);
            r->ref++;
        }
        ps->p = d;
        func_005C2630(ps, 0, -1, src, func_0057F260(src));
        Str *pr = &res;
        func_00314B20(pr, ps);
        if ((void *)arg0 != (void *)pr) {
            void *p = pr->p;
            if (p != 0) {
                func_003285A8(p);
            }
            if (*arg0 != 0) {
                func_003285F8(*arg0);
            }
            *arg0 = p;
        }
        func_00312318(pr, 2);
        str_release(ps);
        func_0017FAD0(&h, 2);
    }
}
