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

union StrOrHandle {
    Str s;
    Handle res;
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

extern char D_006901F0[];

extern "C" void func_0015F388(void *arg0, int arg1) throw();
extern "C" void *func_0015F3E0(void *arg0, void *arg1) throw();
extern "C" void func_002FC870(void *arg0, int arg1) throw();
extern "C" void func_002FE278(void *arg0, void *arg1) throw();
extern "C" void func_00326798(void *p, s32 size, s32 align, const char *name) throw();
extern "C" void func_003285A8(void *p) throw();
extern "C" void func_003285F8(void *p) throw();
extern "C" int func_0042EAC8(void *arg0, void *arg1) throw();
extern "C" s32 func_00447BB8(s32 arg0) throw();
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
    if (len == 0) return D_006901F0;
    t->p[len] = 0;
    return t->p;
}

extern "C" void MGame__isCarAvailable(void **arg0, void *arg1, s32 arg2, void **arg3) {
    if (arg2 > 0) {
        union StrOrHandle u;
        Handle h;
        Handle *pc;

        {
            Obj *o = *(Obj **)arg3;
            VEntry *e;
            e = (VEntry *)(o->vtbl + 0x18);
            e->fn(&u.s, (char *)o + e->delta);
        }
        s32 idx = func_00447BB8((s32)c_str(&u.s));
        str_release(&u.s);
        if (idx != -1) {
            pc = &h;
            func_0015F3E0(pc, arg1);
            Obj *x = *(Obj **)((char *)pc->p + 0x10);
            int res = func_0042EAC8((char *)x + 0x36550, (void *)idx);
            func_002FE278(&u.res, (void *)res);
            if ((void *)arg0 != (void *)&u.res) {
                void *p = u.res.p;
                if (p != 0) {
                    func_003285A8(p);
                }
                if (*arg0 != 0) {
                    func_003285F8(*arg0);
                }
                *arg0 = p;
            }
            func_002FC870(&u.res, 2);
            func_0015F388(pc, 2);
        }
    }
}
