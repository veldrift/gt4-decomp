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

struct VEntryI {
    s16 delta;
    s16 index;
    s32 (*fn)(void *);
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
extern char D_00695AD0[];
extern char D_006959E0[];

extern "C" void func_001F7CB8(void *, void *, const char *, s32, s32, s32, s32, s32);
extern "C" void func_001DC5F8(void *, int);
extern "C" void func_001DC650(void *, void *);
extern "C" void func_0023B1D8(void *, int);
extern "C" void func_0023B478(void *);
extern "C" void func_0023CA78(void *, const char *, const char *);
extern "C" void func_002ED5C0(void *, int);
extern "C" void func_002ED618(void *, void *);
extern "C" s32 hArray__size(void *);
extern "C" VObj **HArray__operator_index(void *, s32);
extern "C" void func_002FC870(void *, int);
extern "C" void func_002FE278(void *, s32);
extern "C" void func_00326798(void *p, s32 size, s32 align, const char *name);
extern "C" void func_003285A8(void *p);
extern "C" void func_003285F8(void *p);
extern "C" void func_0057DA20(void *, const char *, ...);
extern "C" struct S00659988 *func_005C11A8(void);

static inline void str_release(Str *s) {
    Rep *q = (Rep *)(s->p - 0x10);
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

static inline s32 vcall58(VObj *o) {
    VEntryI *e = (VEntryI *)(o->vtbl + 0x58);
    return e->fn((char *)o + e->delta);
}

static inline void vcall18(Str *ret, VObj *o) {
    VEntryV *e = (VEntryV *)(o->vtbl + 0x18);
    e->fn(ret, (char *)o + e->delta);
}

extern "C" void MNetwork__fileList(void **arg0, void *arg1, s32 arg2, VObj **arg3) {
    Str h;
    Str ctx;
    const char *name;
    s32 a, b, c, d, e;
    name = 0;
    if (arg2 > 0) {
        vcall18(&h, arg3[0]);
        name = c_str(&h);
        str_release(&h);
    }
    a = 0;
    if (arg2 >= 2) a = vcall58(arg3[1]);
    b = 100000000;
    if (arg2 >= 3) b = vcall58(arg3[2]);
    c = -1;
    if (arg2 >= 4) c = vcall58(arg3[3]);
    d = 0;
    if (arg2 >= 5) d = vcall58(arg3[4]);
    e = 0x40;
    if (arg2 >= 6) e = vcall58(arg3[5]);
    Str *pc = &ctx;
    func_001DC650(pc, arg1);
    func_001F7CB8(&h, pc->p, name, a, b, c, d, e);
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
    func_002ED5C0(&h, 2);
    func_001DC5F8(pc, 2);
}
