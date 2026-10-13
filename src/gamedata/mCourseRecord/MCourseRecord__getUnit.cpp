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

extern char D_0068FFA0[];

extern "C" void func_0015AA68(void *arg0, int arg1) throw();
extern "C" void func_0015AD00(void *arg0, void *arg1) throw();
extern "C" void func_0015C6B8(void *arg0, int arg1) throw();
extern "C" void func_0015C710(void *arg0, void *arg1) throw();
extern "C" s32 func_00433C10(Obj *o, const char *name) throw();
extern "C" void func_00326798(void *p, s32 size, s32 align, const char *name) throw();
extern "C" void func_003285A8(void *p) throw();
extern "C" void func_003285F8(void *p) throw();
extern "C" struct S00659988 *func_005C11A8(void) throw();

static inline void str_release(Str *s) {
    Rep *q = (Rep *)(s->p - 0x10);
    if (--q->ref == 0) {
        s32 size = q->cap + 0x10;
        func_00326798(q, size, 4, func_005C11A8()->name);
    }
}

static inline const char *c_str(Str *t) {
    s32 len = *(s32 *)(t->p - 0x10);
    if (len == 0) return D_0068FFA0;
    t->p[len] = 0;
    return t->p;
}

extern "C" void func_0015C898(void **arg0, void *arg1, s32 arg2, void **arg3) {
    if (arg2 > 0) {
        Handle h;
        Str s;
        Str *ps;
        int res;

        func_0015C710(&h, arg1);
        {
            Obj *o = *(Obj **)arg3;
            Obj *x = *(Obj **)((char *)h.p + 0x10);
            VEntry *e;
            ps = &s;
            e = (VEntry *)(o->vtbl + 0x18);
            e->fn(ps, (char *)o + e->delta);
            res = func_00433C10(x, c_str(ps));
        }
        str_release(ps);
        func_0015C6B8(&h, 2);
        if (res != 0) {
            func_0015AD00(&h, (void *)res);
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
            func_0015AA68(&h, 2);
        }
    }
}
