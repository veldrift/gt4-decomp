typedef int s32;
typedef short s16;
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
    char pad[0xC];
};

struct Obj16 {
    char pad[0x10];
};

struct VEntryV {
    s16 delta;
    s16 index;
    void (*fn)(void *, void *);
};

struct VEntryI {
    s16 delta;
    s16 index;
    s32 (*fn)(void *);
};

struct VEntryII {
    s16 delta;
    s16 index;
    s32 (*fn)(void *, s32);
};

struct VObj {
    char pad[4];
    char *vtbl;
};

struct VObjC {
    char pad[0xC];
    char *vtbl;
};

struct Arg {
    char pad[8];
    VObj *name;
};

extern Rep D_00659FA8;
extern char D_00692090[];

extern "C" VObjC *func_001908C0(s32 a, void *b);
extern "C" void func_002ED5C0(void *, int);
extern "C" void *func_002EEEB0(void *, void *, void *);
extern "C" void func_002EFBF0(void *);
extern "C" void func_00309378(void *, s32);
extern "C" void func_00312318(void *, int);
extern "C" void func_00314B20(void *, void *);
extern "C" void func_00326798(void *, s32, s32, const char *);
extern "C" void func_003285A8(void *p);
extern "C" void func_003285F8(void *p);
extern "C" s32 func_004382F8(const char *);
extern "C" const char *func_004385E0(void *, s32);
extern "C" s32 func_0057F260(const char *);
extern "C" struct S00659988 *func_005C11A8(void);
extern "C" char *func_005C2560(void *);
extern "C" void *func_005C2630(void *, u32, u32, const char *, u32);

static inline void str_release(Str *s) {
    Rep *q = (Rep *)(s->p - 0x10);
    if (--q->ref == 0) {
        s32 size = q->cap + 0x10;
        func_00326798(q, size, 4, func_005C11A8()->name);
    }
}

static inline Rep *str_rep(Str *s) { return (Rep *)s->p - 1; }
static inline char *rep_data(Rep *r) { return (char *)(r + 1); }
static inline s32 str_length(Str *s) { return str_rep(s)->len; }
static inline void str_terminate(Str *s) { rep_data(str_rep(s))[str_length(s)] = 0; }
static inline const char *c_str(Str *s) {
    if (str_length(s) == 0) return D_00692090;
    str_terminate(s);
    return rep_data(str_rep(s));
}

static inline void vcall18(Str *ret, VObj *o) {
    VEntryV *e = (VEntryV *)(o->vtbl + 0x18);
    e->fn(ret, (char *)o + e->delta);
}

static inline s32 vcall20(VObjC *o) {
    VEntryI *e = (VEntryI *)(o->vtbl + 0x38);
    return e->fn((char *)o + e->delta);
}

static inline s32 vcall28(VObjC *o, s32 i) {
    VEntryII *e = (VEntryII *)(o->vtbl + 0x40);
    return e->fn((char *)o + e->delta, i);
}

extern "C" void MOption__searchButtonConfig(void **arg0, s32 arg1, s32 arg2, Arg *arg3) {
    if (arg2 >= 3) {
        VObjC *obj = func_001908C0(arg1, arg3);
        if (obj != 0) {
            Str sp0;
            s32 key;
            s32 n;
            s32 i;
            Obj16 res;
            Obj16 a;
            Str t;
            vcall18(&sp0, arg3->name);
            const char *nm = c_str(&sp0);
            str_release(&sp0);
            key = func_004382F8(nm);
            i = 0;
            func_002EFBF0(&sp0);
            n = vcall20(obj);
            if (n > 0) do {
                s32 v = vcall28(obj, i);
                if (v == key) {
                    Obj16 *pr = &res;
                    char *pt = (char *)&t;
                    void *hp = sp0.p;
                    const char *s = func_004385E0(obj, i);
                    Rep *r = &D_00659FA8;
                    char *d = (char *)(r + 1);
                    if (r->sel != 0) {
                        d = func_005C2560(r);
                    } else {
                        r->ref++;
                    }
                    ((Str *)pt)->p = d;
                    func_005C2630(pt, 0, -1, s, func_0057F260(s));
                    func_00314B20(&a, pt);
                    func_002EEEB0(pr, hp, &a);
                    func_00309378(pr, 2);
                    func_00312318(&a, 2);
                    pt = ((Str *)pt)->p - 0x10;
                    Rep *q = (Rep *)pt;
                    if (--q->ref == 0) {
                        s32 size = q->cap + 0x10;
                        func_00326798(q, size, 4, func_005C11A8()->name);
                    }
                }
                i++;
            } while (i < n);
            if ((void *)arg0 != (void *)&sp0) {
                void *p = sp0.p;
                if (p != 0) {
                    func_003285A8(p);
                }
                if (*arg0 != 0) {
                    func_003285F8(*arg0);
                }
                *arg0 = p;
            }
            func_002ED5C0(&sp0, 2);
        }
    }
}
