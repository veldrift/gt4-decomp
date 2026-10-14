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
extern char D_00695AA0[];
extern char D_006959E0[];

extern "C" void MNetwork__getGameInfo(void *, void *, void *, void *);
extern "C" void func_0023B1D8(void *, int);
extern "C" void func_0023B478(void *);
extern "C" void func_0023CA78(void *, const char *, const char *);
extern "C" void func_002ED5C0(void *, int);
extern "C" void func_002EFBF0(void *);
extern "C" VObj **HArray__operator_index(void *, s32);
extern "C" void func_002FC870(void *, int);
extern "C" void func_002FE278(void *, s32);
extern "C" void func_00326798(void *p, s32 size, s32 align, const char *name);
extern "C" void func_003285A8(void *p);
extern "C" void func_003285F8(void *p);
extern "C" void func_0057DA20(char *, const char *, ...);
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

static inline s32 vcall58(VObj *o) {
    VEntryI *e = (VEntryI *)(o->vtbl + 0x58);
    return e->fn((char *)o + e->delta);
}

static inline void vcall18(Str *ret, VObj *o) {
    VEntryV *e = (VEntryV *)(o->vtbl + 0x18);
    e->fn(ret, (char *)o + e->delta);
}

extern "C" void MNetwork__showGameInfo(void **arg0, void *arg1, void *arg2, void *arg3) {
    Str h10;
    Str h20;
    char buf[0x80];
    Str hB0;
    s32 v4;
    Str *p10;
    func_002EFBF0(&h10);
    MNetwork__getGameInfo(&h10, arg1, arg2, arg3);
    p10 = &h10;
    if (p10->p == 0) {
        Str *ph = &h20;
        func_002FE278(ph, 0);
        if ((void *)arg0 != (void *)ph) {
            void *p = ph->p;
            if (p != 0) {
                func_003285A8(p);
            }
            if (*arg0 != 0) {
                func_003285F8(*arg0);
            }
            *arg0 = p;
        }
        func_002FC870(ph, 2);
    } else {
        s32 v0, v1, v2, v3;
        Str *p20;
        Str *pB0;
        const char *c1;
        const char *c2;
        v4 = vcall58(*HArray__operator_index(p10, 4));
        v0 = vcall58(*HArray__operator_index(p10, 0));
        v1 = vcall58(*HArray__operator_index(p10, 1));
        v2 = vcall58(*HArray__operator_index(p10, 2));
        v3 = vcall58(*HArray__operator_index(p10, 3));
        p20 = &h20;
        vcall18(p20, *HArray__operator_index(p10, 6));
        c1 = c_str(p20);
        pB0 = &hB0;
        vcall18(pB0, *HArray__operator_index(&h10, 5));
        c2 = c_str(pB0);
        func_0057DA20(buf, D_00695AA0, v4, v0, v1, v2, v3, c1, c2);
        str_release(pB0);
        str_release(p20);
        func_0023B478(pB0);
        func_0023CA78(pB0->p, buf, D_006959E0);
        func_0023B1D8(pB0, 2);
        func_002FE278(pB0, 1);
        if ((void *)arg0 != (void *)pB0) {
            void *p = pB0->p;
            if (p != 0) {
                func_003285A8(p);
            }
            if (*arg0 != 0) {
                func_003285F8(*arg0);
            }
            *arg0 = p;
        }
        func_002FC870(pB0, 2);
    }
    func_002ED5C0(&h10, 2);
}
