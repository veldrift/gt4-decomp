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
extern "C" s32 func_005CD320(Str *, const char *, u32, u32);
extern "C" Str *func_001F23A8(Str *, s32, s32);
extern "C" void func_00314B20(void *, Str *);
extern "C" void func_00312318(void *, s32);
extern "C" s32 func_005A5AD8(const char *, const char *, ...);
extern "C" s32 func_001F2A28(s32, s32, s32, s32, s32, s32, s32);
extern char D_00695A10[];
extern char D_00695A18[];
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


extern "C" void MNetwork__getPolicy(s32 *ret, void *ctx, s32 argc, Obj **args) {
    s32 h0[4];
    Str s;
    s32 v[4];
    s32 mode;

    func_001DC650(h0, ctx);
    mode = 1;
    if (argc > 0) {
        s32 eq;
        vcall_18(&s, args[0]);
        eq = func_005CD320(&s, D_00695A10, 0, func_0057F260(D_00695A10)) == 0;
        str_release(&s);
        mode = !eq;
    }
    func_001F23A8(&s, h0[0], mode);
    s32 *pv = v;
    func_00314B20(pv, &s);
    if (ret != pv) {
        s32 newVal = *pv;
        s32 oldVal;
        if (newVal != 0)
            func_003285A8(newVal);
        oldVal = *ret;
        if (oldVal != 0)
            func_003285F8(oldVal);
        *ret = newVal;
    }
    func_00312318(pv, 2);
    str_release(&s);
    func_001DC5F8(h0, 2);
}

struct Handle {
    s32 p;
    char pad[0x1C];
};

#define ASSIGN(ret, src) do { if ((void *)(ret) != (void *)(src)) { \
        s32 newVal = *(s32 *)(src); \
        s32 oldVal; \
        if (newVal != 0) \
            func_003285A8(newVal); \
        oldVal = *(ret); \
        if (oldVal != 0) \
            func_003285F8(oldVal); \
        *(ret) = newVal; } } while (0)

extern "C" void MNetwork__showPolicy(s32 *ret, void *ctx, s32 argc, Obj **args) {
    Handle h;
    Str t;
    MNetwork__getPolicy(ret, ctx, argc, args);
    if (*ret != 0) {
        Str *pt;
        s32 hp;
        func_0023B478(&h);
        pt = &t;
        hp = h.p;
        vcall_18(pt, *(Obj **)ret);
        func_0023CA78(hp, c_str(pt), D_006959E0);
        str_release(pt);
        func_0023B1D8(&h, 2);
        func_002FE278((s32 *)&h, 1);
        if ((void *)ret != (void *)&h) {
            s32 newVal = h.p;
            s32 oldVal;
            if (newVal != 0)
                func_003285A8(newVal);
            oldVal = *ret;
            if (oldVal != 0)
                func_003285F8(oldVal);
            *ret = newVal;
        }
        func_002FC870((s32 *)&h, 2);
    } else {
        func_002FE278((s32 *)&h, 0);
        if ((void *)ret != (void *)&h) {
            s32 newVal = h.p;
            s32 oldVal;
            if (newVal != 0)
                func_003285A8(newVal);
            oldVal = *ret;
            if (oldVal != 0)
                func_003285F8(oldVal);
            *ret = newVal;
        }
        func_002FC870((s32 *)&h, 2);
    }
}

static inline void set_bool(s32 *ret, s32 *h, s32 b) {
    func_002FE278(h, b);
    if (ret != h) {
        s32 newVal = *h;
        s32 oldVal;
        if (newVal != 0)
            func_003285A8(newVal);
        oldVal = *ret;
        if (oldVal != 0)
            func_003285F8(oldVal);
        *ret = newVal;
    }
    func_002FC870(h, 2);
}

extern "C" void MNetwork__setLobbyWorldFilter(s32 *ret, void *ctx, s32 argc, Obj **args) {
    s32 x0;
    union { Str s; s32 h[4]; } u;
    s32 x1;
    s32 x2;
    s32 x3;
    s32 r;

    if (argc >= 6) {
        s32 a, b;
        Str *ps = &u.s;
        vcall_18(&u.s, args[0]);
        func_005A5AD8(c_str(&u.s), D_00695A18, &x0);
        str_release(ps);
        vcall_18(ps, args[1]);
        func_005A5AD8(c_str(ps), D_00695A18, &x1);
        str_release(ps);
        vcall_18(ps, args[2]);
        func_005A5AD8(c_str(ps), D_00695A18, &x2);
        str_release(ps);
        vcall_18(ps, args[3]);
        func_005A5AD8(c_str(ps), D_00695A18, &x3);
        str_release(ps);
        a = vcall_58(args[4]);
        b = vcall_58(args[5]);
        func_001DC650((s32 *)ps, ctx);
        r = func_001F2A28(*(s32 *)ps, x0, x1, x2, x3, a, b);
        func_001DC5F8((s32 *)ps, 2);
    } else {
        s32 *h = u.h;
        func_001DC650(h, ctx);
        r = func_001F2A28(*h, 0, 0, 0, 0, 1, 0x40);
        func_001DC5F8(h, 2);
    }
    set_bool(ret, u.h, r != 0);
}
