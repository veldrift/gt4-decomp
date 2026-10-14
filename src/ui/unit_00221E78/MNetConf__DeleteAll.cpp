/* compiler: ee-gcc2.96-no-strict-aliasing */
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
    void *fn;
};

struct Obj {
    char pad0[4];
    char *vtbl;
};

struct Owner {
    char pad0[4];
    char *vtbl;
};

typedef void (*FnS)(Str *, void *);
typedef s32 (*FnR)(void *, Str *);

extern "C" void func_00221AD0(void *, s32) throw();
extern "C" void func_00221B28(void *, s32) throw();
extern "C" void func_002FC870(void *, s32);
extern "C" void func_002FE278(void *, s32);
extern "C" void func_00326798(void *, s32, s32, const char *);
extern "C" void func_003285A8(s32);
extern "C" void func_003285F8(s32);
extern "C" struct S00659988 *func_005C11A8(void);

extern "C" void MNetConf__DeleteAll(s32 *arg0, s32 arg1, s32 count, Obj **arg3) {
    s32 hv[4];
    s32 own[4];
    Str s;
    if (count > 0) {
        s32 *po = own;
        Str *ps;
        func_00221B28(po, arg1);
        {
            Owner *ow = (Owner *)po[0];
            Obj *o = *arg3;
            VEntry *e = (VEntry *)(o->vtbl + 0x18);
            VEntry *e2 = (VEntry *)(ow->vtbl + 0x310);
            void *this2 = (char *)ow + e2->delta;
            ps = &s;
            ((FnS)e->fn)(ps, (char *)o + e->delta);
            func_002FE278(hv, ((FnR)e2->fn)(this2, ps));
        }
        if (arg0 != hv) {
            s32 v = hv[0];
            if (v != 0) {
                func_003285A8(v);
            }
            if (*arg0 != 0) {
                func_003285F8(*arg0);
            }
            *arg0 = v;
        }
        func_002FC870(hv, 2);
        {
            Rep *q = (Rep *)(ps->p - 0x10);
            if (--q->ref == 0) {
                s32 cap = q->cap + 0x10;
                func_00326798(q, cap, 4, func_005C11A8()->name);
            }
        }
        func_00221AD0(po, 2);
    }
}
