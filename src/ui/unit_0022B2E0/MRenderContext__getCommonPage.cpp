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
    char pad[12];
};

struct VEntry {
    s16 delta;
    s16 index;
    void (*fn)(Str *, void *);
};

struct Obj {
    char pad0[4];
    char *vtbl;
};

extern char D_006984E0[];
extern "C" void func_0022ACC8(void *, s32) throw();
extern "C" void func_0022AD20(void *) throw();
extern "C" s32 func_00231FC8(void *, const char *);
extern "C" void func_00232BF0(void *, s32 *);
extern "C" void func_00232C20(void *, s32);
extern "C" void func_00326798(void *, s32, s32, const char *);
extern "C" void func_003285A8(s32);
extern "C" void func_003285F8(s32);
extern "C" struct S00659988 *func_005C11A8(void);

static inline const char *c_str(Str *s) {
    s32 len = ((Rep *)s->p)[-1].len;
    if (len == 0) return D_006984E0;
    s->p[len] = 0;
    return s->p;
}

extern "C" void MRenderContext__getCommonPage(s32 *arg0, s32 arg1, s32 count, Obj **arg3) {
    s32 buf[8];
    Str s;
    s32 sp30;
    if (count > 0) {
        void *owner;
        s32 found;
        func_0022AD20(buf);
        owner = (void *)buf[0];
        Str *ps = &s;
        {
            Obj *o = *arg3;
            VEntry *e = (VEntry *)(o->vtbl + 0x18);
            e->fn(ps, (char *)o + e->delta);
        }
        found = func_00231FC8(owner, c_str(ps));
        {
            Rep *q = (Rep *)(ps->p - 0x10);
            if (--q->ref == 0) {
                s32 cap = q->cap + 0x10;
                func_00326798(q, cap, 4, func_005C11A8()->name);
            }
        }
        func_0022ACC8(buf, 2);
        if (found != 0) {
            sp30 = found;
            func_00232BF0(buf, &sp30);
            if (arg0 != buf) {
                s32 v = buf[0];
                if (v != 0) {
                    func_003285A8(v);
                }
                if (*arg0 != 0) {
                    func_003285F8(*arg0);
                }
                *arg0 = v;
            }
            func_00232C20(buf, 2);
        }
    }
}
