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

struct VEntryV {
    s16 delta;
    s16 index;
    void (*fn)(void *, void *);
};

struct VObj {
    char pad[4];
    char *vtbl;
};

extern char D_006959D8[];
extern char D_006959E0[];

extern "C" void MNetwork__getPolicy(void);
extern "C" void func_0023B1D8(void *, int);
extern "C" void func_0023B478(void *);
extern "C" void func_0023CA78(void *, const char *, const char *);
extern "C" void func_002FC870(void *, int);
extern "C" void func_002FE278(void *, s32);
extern "C" void func_00326798(void *p, s32 size, s32 align, const char *name);
extern "C" void func_003285A8(void *p);
extern "C" void func_003285F8(void *p);
extern "C" struct S00659988 *func_005C11A8(void);

static inline void str_release(Str *s) {
    Rep *q = ((Rep **)s)[0] - 1;
    if (--q->ref == 0) {
        s32 size = q->cap + 0x10;
        func_00326798(q, size, 4, func_005C11A8()->name);
    }
}

static inline const char *c_str(Str *t) {
    s32 len = *(s32 *)(t->p - 0x10);
    if (len == 0) return D_006959D8;
    t->p[len] = 0;
    return t->p;
}

static inline void vcall18(Str *ret, VObj *o) {
    VEntryV *e = (VEntryV *)(o->vtbl + 0x18);
    e->fn(ret, (char *)o + e->delta);
}

extern "C" void MNetwork__showPolicy(void **arg0) {
    Str sp0;
    Str spare;
    Str t;
    MNetwork__getPolicy();
    if (*arg0 != 0) {
        Str *pt;
        const char *c;
        void *hp;
        func_0023B478(&sp0);
        pt = &t;
        hp = sp0.p;
        vcall18(pt, (VObj *)*arg0);
        c = c_str(pt);
        func_0023CA78(hp, c, D_006959E0);
        str_release(pt);
        func_0023B1D8(&sp0, 2);
        func_002FE278(&sp0, 1);
        if ((void *)arg0 != (void *)&sp0) {
            void *p = sp0.p;
            if (p != 0) {
                func_003285A8(p);
            }
            if (*arg0 != 0) {
                func_003285F8(*arg0);
            }
            *arg0 = p;
        }
        func_002FC870(&sp0, 2);
    } else {
        func_002FE278(&sp0, 0);
        if ((void *)arg0 != (void *)&sp0) {
            void *p = sp0.p;
            if (p != 0) {
                func_003285A8(p);
            }
            if (*arg0 != 0) {
                func_003285F8(*arg0);
            }
            *arg0 = p;
        }
        func_002FC870(&sp0, 2);
    }
}
