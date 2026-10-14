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
    char pad[0xC];
};

struct Handle {
    char pad0[0x10];
    s32 p10;
};

struct B32 { char x[0x20]; };
struct In { s32 f0, f4, f8, fC, f10, f14, f18, f1C, f20, f24; const char *f28; };

struct VEntry58 {
    s16 delta;
    s16 index;
    s32 (*fn)(void *);
};

struct VEntry18 {
    s16 delta;
    s16 index;
    Str (*fn)(void *);
};

struct VObj {
    char pad[4];
    char *vtbl;
};

struct Hold {
    Handle *p;
    char pad[0xC];
};

extern char D_0068FFA0[];

extern "C" void func_0015AA68(void *arg0, int arg1) throw();
extern "C" void func_0015AAC0(void *arg0, void *arg1) throw();
extern "C" void func_00326798(void *p, s32 size, s32 align, const char *name);
extern "C" s32 func_00433260(s32 list, s32 key, const char *arg2, B32 *src);
extern "C" s32 func_00447BB8(const char *arg0);
extern "C" s32 func_004482C0(s32 a);
extern "C" void func_0044B258(In *src, B32 *dst, s32 n);
extern "C" void func_005A48D8(void *p, s32 c, s32 n);
extern "C" struct S00659988 *func_005C11A8(void);

static inline s32 vcall58(VObj *o) {
    VEntry58 *e = (VEntry58 *)(o->vtbl + 0x58);
    return e->fn((char *)o + e->delta);
}

static inline Rep *str_rep(Str *s) { return (Rep *)s->p - 1; }
static inline char *rep_data(Rep *r) { return (char *)(r + 1); }
static inline s32 str_length(Str *s) { return str_rep(s)->len; }
static inline void str_terminate(Str *s) { rep_data(str_rep(s))[str_length(s)] = 0; }
static inline const char *c_str(Str *s) {
    if (str_length(s) == 0) return D_0068FFA0;
    str_terminate(s);
    return rep_data(str_rep(s));
}
static inline void release(Str *s) {
    Rep *q = str_rep(s);
    if (--q->ref == 0) {
        s32 size = q->cap + 0x10;
        func_00326798(q, size, 4, func_005C11A8()->name);
    }
}

extern "C" void MCourseRecordUnit__insertEntry(void *arg0, void *arg1, s32 arg2, VObj **arg3) {
    Hold list;
    if (arg2 >= 4) {
        s32 key;
        const char *name;
        func_0015AAC0(&list, arg1);
        key = vcall58(arg3[0]);
        VObj *o = arg3[1];
        VEntry18 *e = (VEntry18 *)(o->vtbl + 0x18);
        Str t = e->fn((char *)o + e->delta);
        Str *pt = &t;
        In in;
        B32 out;
        name = c_str(&t);
        release(&t);
        vcall58(arg3[2]);
        vcall58(arg3[3]);
        in.f4 = func_004482C0(func_00447BB8(name));
        in.f0 = 0;
        in.f8 = 1;
        in.f10 = 1;
        in.f14 = 1;
        in.f18 = 1;
        in.f1C = key;
        in.f20 = 1;
        in.f24 = 1;
        in.f28 = name;
        func_005A48D8(&out, 0, 0x20);
        func_0044B258(&in, &out, 0x20);
        func_00433260(list.p->p10, key, name, &out);
        func_0015AA68(&list, 2);
    }
}
