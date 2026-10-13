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
    char pad[0x1C];
};

struct VEntry {
    short delta;
    short index;
    void (*fn)(Str *, void *);
};

struct Obj {
    char pad0[4];
    char *vtbl;
};

extern char D_006959D8[];

extern "C" void func_001DC5F8(void *arg0, int arg1);
extern "C" void func_001DC650(void *arg0, void *arg1);
extern "C" int func_001F48E0(void *ctx, const char *name);
extern "C" void func_002FC870(void *arg0, int arg1);
extern "C" void func_002FE278(void *arg0, int arg1);
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

extern "C" void func_001E2138(void **arg0, void *arg1, s32 arg2, void **arg3) {
    if (arg2 > 0) {
        Handle h;
        Str s;
        Str *ps;
        int res;

        func_001DC650(&h, arg1);
        {
            Obj *o = *(Obj **)arg3;
            void *hp;
            VEntry *e;
            ps = &s;
            hp = h.p;
            e = (VEntry *)(o->vtbl + 0x18);
            e->fn(ps, (char *)o + e->delta);
            res = func_001F48E0(hp, c_str(ps));
        }
        str_release(ps);
        func_001DC5F8(&h, 2);
        func_002FE278(&h, res);
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
