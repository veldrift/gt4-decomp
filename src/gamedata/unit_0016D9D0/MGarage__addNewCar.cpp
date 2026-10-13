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

extern char D_00690A30[];
extern void *D_00622F4C;

extern "C" void func_0016D7F0(void *arg0, int arg1);
extern "C" void func_0016D848(void *arg0, void *arg1);
extern "C" void func_002FC870(void *arg0, int arg1);
extern "C" void func_002FE278(void *arg0, void *arg1);
extern "C" void func_00326798(void *p, s32 size, s32 align, const char *name);
extern "C" void func_003285A8(void *p);
extern "C" void func_003285F8(void *p);
extern "C" s32 func_00435800(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
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
    if (len == 0) return D_00690A30;
    t->p[len] = 0;
    return t->p;
}

static inline s32 vcall58(void *obj) {
    Obj *o = (Obj *)obj;
    VEntryI *e = (VEntryI *)(o->vtbl + 0x58);
    return e->fn((char *)o + e->delta);
}

extern "C" void func_0016DBB0(void **arg0, void *arg1, s32 arg2, void **arg3) {
    if (arg2 >= 2) {
        Str s;
        s32 s5 = 0;
        s32 s4;
        s32 s2;
        s32 s1;

        func_0016D848(&s, arg1);
        s4 = *(s32 *)((char *)s.p + 0x10);
        func_0016D7F0(&s, 2);
        s2 = *(s32 *)((char *)D_00622F4C + 0xBC28);
        if (arg2 >= 3) {
            s5 = vcall58(arg3[2]);
        }
        s1 = vcall58(arg3[1]);
        {
            Obj *o = *(Obj **)arg3;
            VEntryV *e = (VEntryV *)(o->vtbl + 0x18);
            e->fn(&s, (char *)o + e->delta);
        }
        s2 = func_00435800(s4, (s32)c_str(&s), s1, s2, s5);
        str_release(&s);
        func_002FE278(&s, (void *)s2);
        if ((void *)arg0 != (void *)&s) {
            void *p = s.p;
            if (p != 0) {
                func_003285A8(p);
            }
            if (*arg0 != 0) {
                func_003285F8(*arg0);
            }
            *arg0 = p;
        }
        func_002FC870(&s, 2);
    }
}
