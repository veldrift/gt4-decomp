typedef int s32;
typedef unsigned int u32;

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
    s32 pad[3];
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

extern "C" struct S00659988 *func_005C11A8(void);
extern "C" void func_00326798(void *p, s32 size, s32 align, const char *name);
extern "C" s32 func_005C2A50(Str *self, Str *other, u32 pos, u32 n);

extern "C" u32 func_005ED940(void *arg0, Obj **arg1, Obj **arg2) {
    Str s;
    Str t;
    Str *pt;
    u32 r;
    {
        Obj *o = *arg1;
        VEntry *e = (VEntry *)(o->vtbl + 0x18);
        e->fn(&s, (char *)o + e->delta);
    }
    pt = &t;
    {
        Obj *o2 = *arg2;
        VEntry *e2 = (VEntry *)(o2->vtbl + 0x18);
        e2->fn(pt, (char *)o2 + e2->delta);
    }
    r = (u32)func_005C2A50(&s, pt, 0, -1) >> 31;
    {
        Rep *q = (Rep *)(pt->p - 0x10);
        if (--q->ref == 0) {
            s32 cap = q->cap + 0x10;
            func_00326798(q, cap, 4, func_005C11A8()->name);
        }
    }
    {
        Rep *q = (Rep *)(s.p - 0x10);
        if (--q->ref == 0) {
            s32 cap = q->cap + 0x10;
            func_00326798(q, cap, 4, func_005C11A8()->name);
        }
    }
    return r;
}
