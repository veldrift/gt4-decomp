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
    char pad[12];
};

struct VEntry {
    short delta;
    short index;
    void (*fn)(Str *, void *);
};

struct VEntryInt {
    short delta;
    short index;
    s32 (*fn)(void *);
};

struct Obj {
    char pad0[4];
    char *vtbl;
};

extern char D_006959D8[];

extern "C" void func_001DC5F8(void *arg0, int arg1);
extern "C" void func_001DC650(void *arg0, void *arg1);
extern "C" void func_001DCA28(void *arg0, s32 arg1, s32 arg2);
extern "C" struct S00659988 *func_005C11A8(void);
extern "C" void func_00326798(void *p, s32 size, s32 align, const char *name);

static inline const char *c_str(Str *s) {
    s32 len = ((Rep *)s->p)[-1].len;
    if (len == 0) return D_006959D8;
    s->p[len] = 0;
    return s->p;
}

extern "C" void func_001DEA60(void *arg0, void *arg1, s32 arg2, Obj **arg3) {
    if (arg2 >= 2) {
        s32 buf[8];
        Str s;
        s32 n;
        {
            Obj *o1 = arg3[1];
            VEntryInt *e1 = (VEntryInt *)(o1->vtbl + 0x58);
            n = e1->fn((char *)o1 + e1->delta);
        }
        func_001DC650(buf, arg1);
        Str *ps = &s;
        s32 h = buf[0];
        {
            Obj *o = *arg3;
            VEntry *e = (VEntry *)(o->vtbl + 0x18);
            e->fn(ps, (char *)o + e->delta);
        }
        func_001DCA28((void *)h, (s32)c_str(ps), n);
        {
            Rep *q = (Rep *)(ps->p - 0x10);
            if (--q->ref == 0) {
                s32 cap = q->cap + 0x10;
                func_00326798(q, cap, 4, func_005C11A8()->name);
            }
        }
        func_001DC5F8(buf, 2);
    }
}
