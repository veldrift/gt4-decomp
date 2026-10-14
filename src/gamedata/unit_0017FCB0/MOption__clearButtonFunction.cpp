/* compiler: ee-gcc2.96-stl */
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
};

struct VEntryI {
    s16 delta;
    s16 index;
    s32 (*fn)(void *);
};

struct VEntryG {
    s16 delta;
    s16 index;
    s32 (*fn)(void *, s32);
};

struct VEntryS {
    s16 delta;
    s16 index;
    void (*fn)(void *, s32, s32);
};

struct List {
    char pad[0xC];
    char *vtbl;
};

extern char D_00692090[];

extern "C" List *func_001908C0(s32 a, void *b);
extern "C" void func_00326798(void *p, s32 size, s32 align, const char *name);
extern "C" s32 func_004382F8(const char *);
extern "C" struct S00659988 *func_005C11A8(void);

static inline Rep *str_rep(Str *s) { return (Rep *)s->p - 1; }
static inline char *rep_data(Rep *r) { return (char *)(r + 1); }
static inline s32 str_length(Str *s) { return str_rep(s)->len; }
static inline void str_terminate(Str *s) { rep_data(str_rep(s))[str_length(s)] = 0; }
static inline const char *str_c_str(Str *s) {
    if (str_length(s) == 0) return D_00692090;
    str_terminate(s);
    return rep_data(str_rep(s));
}

static inline void str_release(Str *s) {
    Rep *q = (Rep *)(s->p - 0x10);
    if (--q->ref == 0) {
        s32 size = q->cap + 0x10;
        func_00326798(q, size, 4, func_005C11A8()->name);
    }
}

static inline void vcall18(Str *ret, VObj *o) {
    VEntryV *e = (VEntryV *)(o->vtbl + 0x18);
    e->fn(ret, (char *)o + e->delta);
}

extern "C" void MOption__clearButtonFunction(s32 arg0, s32 arg1, s32 arg2, Arg *arg3) {
    if (arg2 < 3) return;
    {
        Str sp0;
        List *l = func_001908C0(arg1, arg3);
        const char *c;
        s32 key;
        s32 n;
        s32 i;
        vcall18(&sp0, arg3->name);
        c = str_c_str(&sp0);
        str_release(&sp0);
        i = 0;
        key = func_004382F8(c);
        {
            VEntryI *e = (VEntryI *)(l->vtbl + 0x38);
            n = e->fn((char *)l + e->delta);
        }
        for (; i < n; i++) {
            VEntryG *g = (VEntryG *)(l->vtbl + 0x40);
            if (g->fn((char *)l + g->delta, i) == key) {
                VEntryS *s = (VEntryS *)(l->vtbl + 0x48);
                s->fn((char *)l + s->delta, i, -1);
            }
        }
    }
}
