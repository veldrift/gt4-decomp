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

union U {
    Str s;
    s32 h[4];
};

struct VEntry {
    short delta;
    short index;
    void (*fn)(void *, void *);
};

struct Obj {
    char pad0[4];
    char *vtbl;
};

extern char D_0068EE68[];

extern "C" void func_0013BD68(void *arg0, int arg1);
extern "C" void func_0013BDC0(void *arg0, void *arg1);
extern "C" s32 func_00145AD8(void *arg0, const char *name);
extern "C" void func_002FC870(void *arg0, int arg1);
extern "C" void func_002FE278(void *arg0, s32 arg1);
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
    if (len == 0) return D_0068EE68;
    t->p[len] = 0;
    return t->p;
}

extern "C" void func_0013C320(void **arg0, void *arg1, s32 arg2, void **arg3) {
    if (arg2 > 0) {
        Handle h;
        U u;
        U *pu;
        s32 res;
        void *hp;

        func_0013BDC0(&h, arg1);
        pu = &u;
        {
            Obj *o = *(Obj **)arg3;
            VEntry *e;
            hp = h.p;
            e = (VEntry *)(o->vtbl + 0x18);
            e->fn(pu, (char *)o + e->delta);
        }
        res = func_00145AD8(hp, c_str(&pu->s));
        str_release(&pu->s);
        func_002FE278(pu, res != 0);
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
        func_002FC870(pu, 2);
        func_0013BD68(&h, 2);
    }
}
