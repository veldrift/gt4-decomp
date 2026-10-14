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

struct Self;
struct S002BEB40;

struct Obj {
    char pad0[4];
    char *vtbl;
};

struct VEntry {
    short delta;
    short index;
    void (*fn)(Str *, void *);
};

struct VEntryB {
    short delta;
    short index;
    s32 (*fn)(void *);
};

extern "C" void func_002BAAE0(void *arg0, int arg1);
extern "C" void func_002BAB38(void *arg0, void *arg1);
extern "C" void func_002BE9E8(Self *self, Str *src);
extern "C" void func_002BEAE0(struct Obj *arg0, s32 arg1);
extern "C" void func_002BEB10(struct Obj *arg0, s32 arg1);
extern "C" void func_002BEB40(struct S002BEB40 *arg0, s32 arg1);
extern "C" struct S00659988 *func_005C11A8(void);
extern "C" void func_00326798(void *p, s32 size, s32 align, const char *name);

extern "C" void MModelFace__setEnvImagePath(void *arg0, void *arg1, s32 n, Obj **args) {
    s32 tmp[4];
    Str s;
    Str *ps;
    if (n == 4) {
        func_002BAB38(tmp, arg1);
        {
            Obj *o = args[0];
            VEntry *e;
            ps = &s;
            s32 h = tmp[0];
            e = (VEntry *)(o->vtbl + 0x18);
            e->fn(ps, (char *)o + e->delta);
            func_002BE9E8((Self *)h, ps);
        }
        {
            Rep *q = (Rep *)(ps->p - 0x10);
            if (--q->ref == 0) {
                s32 cap = q->cap + 0x10;
                func_00326798(q, cap, 4, func_005C11A8()->name);
            }
        }
        {
            Obj *o2 = args[1];
            s32 hv = tmp[0];
            VEntryB *e2 = (VEntryB *)(o2->vtbl + 0x58);
            func_002BEAE0((Obj *)hv, e2->fn((char *)o2 + e2->delta) != 0);
        }
        {
            Obj *o3 = args[2];
            s32 hv = tmp[0];
            VEntryB *e3 = (VEntryB *)(o3->vtbl + 0x58);
            func_002BEB10((Obj *)hv, e3->fn((char *)o3 + e3->delta) != 0);
        }
        {
            Obj *o4 = args[3];
            s32 hv = tmp[0];
            VEntryB *e4 = (VEntryB *)(o4->vtbl + 0x58);
            func_002BEB40((struct S002BEB40 *)hv, e4->fn((char *)o4 + e4->delta) != 0);
        }
        func_002BAAE0(tmp, 2);
    }
}
