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
extern "C" void func_002A0D20(void *arg0, int arg1);
extern "C" void func_002A0D78(void *arg0, void *arg1);
extern "C" void func_002A35F8(Obj *self, Str *src);

extern "C" void func_002A1288(void *arg0, void *arg1, s32 n, Obj **args) {
    s32 tmp[4];
    Str s;
    Str *ps;
    s32 h;
    if (n == 1) {
        func_002A0D78(tmp, arg1);
        {
            Obj *o = *args;
            VEntry *e;
            h = tmp[0];
            ps = &s;
            e = (VEntry *)(o->vtbl + 0x18);
            e->fn(ps, (char *)o + e->delta);
        }
        func_002A35F8((Obj *)h, ps);
        {
            Rep *q = (Rep *)(ps->p - 0x10);
            if (--q->ref == 0) {
                s32 cap = q->cap + 0x10;
                func_00326798(q, cap, 4, func_005C11A8()->name);
            }
        }
        func_002A0D20(tmp, 2);
    }
}
