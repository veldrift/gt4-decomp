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
    char pad[0xC];
};

struct VEntryV {
    s16 delta;
    s16 index;
    void (*fn)(void *, void *);
};

struct VObj {
    char pad[4];
    char *vtbl;
};

struct Arg {
    char pad[8];
    VObj *name;
    char list[4];
};

extern char D_00692090[];

extern "C" s32 func_001908C0(s32 a, void *b);
extern "C" void func_002ED5C0(void *, int);
extern "C" void func_002ED618(void *, void *);
extern "C" s32 hArray__size(void *);
extern "C" VObj **HArray__operator_index(void *, s32);
extern "C" void func_00326798(void *p, s32 size, s32 align, const char *name);
extern "C" s32 func_004382B0(const char *);
extern "C" s32 func_00438458(s32, const char *);
extern "C" s32 func_004384A0(s32, const char *, s32);
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
    if (len == 0) return D_00692090;
    t->p[len] = 0;
    return t->p;
}

static inline void vcall18(Str *ret, VObj *o) {
    VEntryV *e = (VEntryV *)(o->vtbl + 0x18);
    e->fn(ret, (char *)o + e->delta);
}

extern "C" void MOption__unsetAnalogKey(s32 arg0, s32 arg1, s32 arg2, Arg *arg3) {
    if (arg2 < 4) return;
    {
        Str sp0;
        Str t;
        s32 h = func_001908C0(arg1, arg3);
        s32 key;
        s32 n;
        s32 i;
        vcall18(&sp0, arg3->name);
        key = func_004382B0(c_str(&sp0));
        str_release(&sp0);
        func_002ED618(&sp0, arg3->list);
        i = 0;
        n = hArray__size(sp0.p);
        for (; i < n; i++) {
            const char *s;
            Str *pt = &t;
            vcall18(pt, *HArray__operator_index(&sp0, i));
            if (*(s32 *)(pt->p - 0x10) == 0) {
                s = D_00692090;
            } else {
                pt->p[*(s32 *)(pt->p - 0x10)] = 0;
                s = pt->p;
            }
            str_release(&t);
            if (func_00438458(h, s) == key) {
                func_004384A0(h, s, -1);
            }
        }
        func_002ED5C0(&sp0, 2);
    }
}
