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

struct SS {
    char *p;
    s32 pad[3];
};

struct Str {
    char *p;
};

struct Val {
    char pad0[4];
    char *vtbl;
};

struct SV {
    char pad0[0xC];
    Val *val;
};

struct VEntry {
    short delta;
    short index;
    void (*fn)(void *, void *);
};

extern char D_0069E110[];
extern char D_0069E118[];
extern char D_0069E120[];
extern char D_0069E100[];

extern "C" void func_0032B5C0(SS *arg0);
extern "C" SS *func_0032B808(SS *arg0, const char *arg1);
extern "C" SS *func_0032B658(SS *self, SS *str);
extern "C" Str *func_0032B8C0(SS *arg0);
extern "C" const char *func_00323CD8(SV *arg0);
extern "C" struct S00659988 *func_005C11A8(void);
extern "C" char *func_005C2560(Rep *r);
extern "C" void func_00326798(void *p, s32 size, s32 align, const char *name);

extern "C" Str *func_003118B8(Str *arg0, SV *arg1) {
    SS ss;
    SS tmp;
    func_0032B5C0(&ss);
    SS *t = func_0032B808(&ss, D_0069E100);
    const char *nm = func_00323CD8(arg1);
    func_0032B808(func_0032B808(t, nm), D_0069E110);
    {
        Val *v = arg1->val;
        if (v == 0) {
            func_0032B808(&ss, D_0069E118);
        } else {
            VEntry *e = (VEntry *)(v->vtbl + 0x18);
            e->fn(&tmp, (char *)v + e->delta);
            func_0032B808(func_0032B658(&ss, &tmp), D_0069E120);
            {
                SS *pt = &tmp;
                Rep *q = (Rep *)(*(s32 *)&pt->p - 0x10);
                if (--q->ref == 0) {
                    s32 cap = q->cap + 0x10;
                    func_00326798(q, cap, 4, func_005C11A8()->name);
                }
            }
        }
    }
    {
        s32 p = *(s32 *)&func_0032B8C0(&ss)->p;
        Rep *r = (Rep *)(p - 0x10);
        s32 d = p;
        if (r->sel != 0) {
            d = (s32)func_005C2560(r);
        } else {
            r->ref++;
        }
        *(s32 *)&arg0->p = d;
    }
    {
        Rep *q = (Rep *)(*(s32 *)&ss.p - 0x10);
        if (--q->ref == 0) {
            s32 cap = q->cap + 0x10;
            func_00326798(q, cap, 4, func_005C11A8()->name);
        }
    }
    return arg0;
}
