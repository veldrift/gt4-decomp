typedef int s32;
typedef short s16;
typedef unsigned int u32;

struct StringRep { u32 len; u32 res; u32 ref; u32 selfish; };
struct Str {
    char *p;
    char pad[0xC];
};
struct S00659988 { const char *name; };

struct VEntry18 { s16 delta; s16 index; void (*fn)(Str *, void *); };
struct VEntry58 { s16 delta; s16 index; s32 (*fn)(void *); };
struct Obj { char pad0[4]; char *vtbl; };

extern StringRep D_00659FA8;
extern char D_006959B0[];
extern char D_006959D8[];
extern char D_006959E0[];
extern char D_006959F0[];

extern "C" char *func_005C2560(StringRep *r);
extern "C" Str *func_005C2630(Str *str, u32 pos, u32 n1, const char *s, u32 n2);
extern "C" u32 func_0057F260(const char *s);
extern "C" struct S00659988 *func_005C11A8(void);
extern "C" void func_00326798(void *, s32, s32, const char *);
extern "C" void *func_001DC650(s32 *, void *);
extern "C" void func_001DC5F8(s32 *, s32);
extern "C" s32 func_001F16A8(s32);
extern "C" s32 func_001F16D0(s32);
extern "C" const char *func_001F1330(s32, const char *);
extern "C" bool func_001F1600(s32, Str *, s32, s32);
extern "C" void func_001F1738(void *, s32);
extern "C" void func_002ED5C0(void *, s32);
extern "C" void func_002ED618(s32 *, s32 *);
extern "C" s32 hArray__size(s32);
extern "C" s32 *HArray__operator_index(s32 *, s32);
extern "C" s32 func_0057DA20(char *, const char *, ...);
extern "C" void func_0023B478(void *);
extern "C" void func_0023CA78(s32, const char *, const char *);
extern "C" void func_0023B1D8(void *, s32);
extern "C" void func_002FE278(s32 *, s32);
extern "C" void func_002FC870(s32 *, s32);
extern "C" void func_003285A8(s32);
extern "C" void func_003285F8(s32);

static inline char *grab(StringRep *r) {
    if (r->selfish)
        return func_005C2560(r);
    ++r->ref;
    return (char *)(r + 1);
}

static inline void construct(Str *str, const char *s) {
    str->p = grab(&D_00659FA8);
    func_005C2630(str, 0, (u32)-1, s, func_0057F260(s));
}

static inline void str_release(Str *s) {
    StringRep *q = (StringRep *)(s->p - 0x10);
    if (--q->ref == 0) {
        s32 size = q->res + 0x10;
        func_00326798(q, size, 4, func_005C11A8()->name);
    }
}

static inline const char *c_str(Str *t) {
    s32 len = *(s32 *)(t->p - 0x10);
    if (len == 0) return D_006959D8;
    t->p[len] = 0;
    return t->p;
}

static inline void vcall_18(Str *ret, Obj *o) {
    VEntry18 *e = (VEntry18 *)(o->vtbl + 0x18);
    e->fn(ret, (char *)o + e->delta);
}

static inline s32 vcall_58(Obj *o) {
    VEntry58 *e = (VEntry58 *)(o->vtbl + 0x58);
    return e->fn((char *)o + e->delta);
}

extern "C" void MNetwork__getUniverseInformation(s32 *ret, void *ctx, s32 argc, Obj **args) {
    s32 h0[4];
    union { Str s; s32 tmp[4]; } u;
    s32 h1[4];
    const char *name;
    s32 kind;

    func_001DC650(h0, ctx);
    name = D_006959B0;
    if (argc > 0) {
        vcall_18(&u.s, args[0]);
        name = c_str(&u.s);
        str_release(&u.s);
    }
    kind = 0x275F;
    if (argc >= 2)
        kind = vcall_58(args[1]);
    if (!__builtin_expect(func_001F16A8(h0[0]), 0)) {
        func_001DC5F8(h0, 2);
        return;
    }
    {
        const char *p = func_001F1330(h0[0], name);
        s32 hv = h0[0];
        Str *ps = &u.s;
        s32 *ph1;
        s32 newVal;
        s32 oldVal;
        construct(ps, p);
        bool miss = !func_001F1600(hv, ps, kind, 1);
        str_release(ps);
        if (miss || !func_001F16D0(h0[0]) || !func_001F16A8(h0[0])) {
            func_001DC5F8(h0, 2);
            return;
        }
        ph1 = h1;
        func_001DC650(ph1, ctx);
        func_001F1738(ps, ph1[0]);
        if (ret != (s32 *)ps) {
            newVal = *(s32 *)ps;
            if (newVal != 0)
                func_003285A8(newVal);
            oldVal = *ret;
            if (oldVal != 0)
                func_003285F8(oldVal);
            *ret = newVal;
        }
        func_002ED5C0(ps, 2);
        func_001DC5F8(ph1, 2);
        func_001DC5F8(h0, 2);
    }
}

extern "C" void MNetwork__showUniverseInformation(s32 *ret, void *ctx, s32 argc, Obj **args) {
    s32 arr[4];
    s32 h[4];
    char buf[0x80];
    union { Str t1; s32 dlg[4]; } ub;
    Str t2;
    Str t3;
    s32 i;
    s32 n;

    MNetwork__getUniverseInformation(ret, ctx, argc, args);
    if (*ret == 0)
        return;
    func_002ED618(arr, ret);
    n = hArray__size(arr[0]);
    for (i = 0; i < n; i++) {
        s32 a, b, c, d, e;
        const char *name1, *name2, *name3;
        func_002ED618(h, HArray__operator_index(arr, i));
        a = vcall_58(*(Obj **)HArray__operator_index(h, 0));
        vcall_18(&ub.t1, *(Obj **)HArray__operator_index(h, 1));
        name1 = c_str(&ub.t1);
        vcall_18(&t2, *(Obj **)HArray__operator_index(h, 2));
        name2 = c_str(&t2);
        b = vcall_58(*(Obj **)HArray__operator_index(h, 3));
        vcall_18(&t3, *(Obj **)HArray__operator_index(h, 4));
        name3 = c_str(&t3);
        c = vcall_58(*(Obj **)HArray__operator_index(h, 5));
        d = vcall_58(*(Obj **)HArray__operator_index(h, 6));
        e = vcall_58(*(Obj **)HArray__operator_index(h, 7));
        func_0057DA20(buf, D_006959F0, a, name1, name2, b, name3, c, d, e);
        str_release(&t3);
        str_release(&t2);
        str_release(&ub.t1);
        {
            s32 *pd = ub.dlg;
            func_0023B478(pd);
            func_0023CA78(pd[0], buf, D_006959E0);
            func_0023B1D8(pd, 2);
        }
        func_002ED5C0(h, 2);
    }
    func_002FE278(h, 1);
    if (ret != h) {
        s32 newVal = h[0];
        s32 oldVal;
        if (newVal != 0)
            func_003285A8(newVal);
        oldVal = *ret;
        if (oldVal != 0)
            func_003285F8(oldVal);
        *ret = newVal;
    }
    func_002FC870(h, 2);
    func_002ED5C0(arr, 2);
}
