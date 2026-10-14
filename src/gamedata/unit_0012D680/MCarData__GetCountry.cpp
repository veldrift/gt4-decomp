typedef int s32;
typedef unsigned char u8;

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

union U {
    Str s;
    s32 h[4];
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
extern char D_0068E7F8[];

extern "C" void func_003285A8(void *p);
extern "C" void func_003285F8(void *p);
extern "C" void func_00312318(void *arg0, int arg1);
extern "C" void func_00314B20(void *arg0, void *arg1);
extern "C" int func_004487D8(const char *arg0, s32 *dest);
extern "C" u8 func_004488A8(s32 *a0);
extern "C" int func_00448E50(int arg0);
extern "C" s32 func_0057F260(const char *s);
extern "C" char *func_005C2560(Rep *r);
extern "C" void *func_005C2630(Str *s, s32 pos, s32 n, const char *src, s32 len);
extern "C" struct S00659988 *func_005C11A8(void);
extern "C" void func_00326798(void *p, s32 size, s32 align, const char *name);

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
        s32 size = q->cap + 0x10;
        func_00326798(q, size, 4, func_005C11A8()->name);
    }
}

extern "C" void MCarData__GetCountry(void **arg0, s32 arg1, VObj **arg2) {
    if (arg1 > 0) {
        s32 dest[8];
        U u;
        s32 spare[4];
        Str s;
        Str *ps;
        const char *src;
        U *pu;
        s32 newVal;
        s32 oldVal;

        pu = &u;
        vcall(&u.s, *arg2);
        func_004487D8(c_str(&u.s), dest);
        release(&u.s);
        src = (const char *)func_00448E50(func_004488A8(dest));
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
        func_005C2630(ps, 0, -1, src, func_0057F260(src));
        func_00314B20(pu, ps);
        if ((void *)arg0 != (void *)pu) {
            void *p = pu->s.p;
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
