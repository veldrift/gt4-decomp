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

extern "C" void MNetwork__fileList(void *);
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
extern "C" int func_0057DA20(void *, const char *, ...);
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

extern "C" void MNetwork__showFileList(void **arg0) {
    Str sp0;
    Str h;
    char buf[0x80];
    Str s;
    MNetwork__fileList(arg0);
    if (*arg0 == 0) {
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
        return;
    }
    func_002ED618(&sp0, arg0);
    s32 i = 0;
    s32 n = hArray__size(sp0.p);
    if (i < n) {
        do {
            Str *ps = &s;
            func_002ED618(&h, HArray__operator_index(&sp0, i));
            vcall18(ps, *HArray__operator_index(&h, 0));
            const char *name = c_str(ps);
            s32 a = vcall58(*HArray__operator_index(&h, 1));
            s32 b = vcall58(*HArray__operator_index(&h, 2));
            s32 c = vcall58(*HArray__operator_index(&h, 3));
            s32 d = vcall58(*HArray__operator_index(&h, 4));
            func_0057DA20(buf, D_00695AD0, name, a, b, c, d);
            str_release(ps);
            func_0023B478(ps);
            i++;
            func_0023CA78(ps->p, buf, D_006959E0);
            func_0023B1D8(ps, 2);
            func_002ED5C0(&h, 2);
        } while (i < n);
    }
    func_002FE278(&h, 1);
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
    func_002FC870(&h, 2);
    func_002ED5C0(&sp0, 2);
}
