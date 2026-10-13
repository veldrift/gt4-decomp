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

struct Handle {
    void *p;
    char pad[0xC];
};

struct Obj {
    char pad0[4];
    char *vtbl;
};

struct VEntryI {
    short delta;
    short index;
    s32 (*fn)(void *);
};

struct VEntryV {
    short delta;
    short index;
    void (*fn)(void *, void *);
};

extern char D_006959D8[];

extern "C" void func_001DC5F8(void *arg0, int arg1);
extern "C" void func_001DC650(void *arg0, void *arg1);
extern "C" s32 func_001F4778(void *ctx, const char *kind_name, const char *type_name, int value);
extern "C" void func_002FC870(void *arg0, int arg1);
extern "C" void func_002FE278(void *arg0, void *arg1);
extern "C" void func_00326798(void *p, s32 size, s32 align, const char *name);
extern "C" void func_003285A8(void *p);
extern "C" void func_003285F8(void *p);
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

static inline s32 vcall58(void *obj) {
    Obj *o = (Obj *)obj;
    VEntryI *e = (VEntryI *)(o->vtbl + 0x58);
    return e->fn((char *)o + e->delta);
}

static inline void vcall18(Str *ret, void *obj) {
    Obj *o = (Obj *)obj;
    VEntryV *e = (VEntryV *)(o->vtbl + 0x18);
    e->fn(ret, (char *)o + e->delta);
}

extern "C" void func_001E1F40(void **arg0, void *arg1, s32 arg2, void **arg3) {
    if (arg2 >= 3) {
        Handle h;
        s32 spare[4];
        s32 spare2[4];
        Str s;
        Str t;
        s32 v;
        s32 res;
        void *hp;
        const char *kn;
        const char *tn;
        Str *ps;

        v = vcall58(arg3[2]);
        func_001DC650(&h, arg1);
        hp = h.p;
        ps = &s;
        vcall18(ps, arg3[0]);
        kn = c_str(ps);
        vcall18(&t, arg3[1]);
        tn = c_str(&t);
        res = func_001F4778(hp, kn, tn, v);
        str_release(&t);
        str_release(ps);
        func_001DC5F8(&h, 2);
        func_002FE278(&h, (void *)res);
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
    }
}
