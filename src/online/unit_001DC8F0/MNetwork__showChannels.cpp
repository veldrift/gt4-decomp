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

extern char D_006959D8[];
extern char D_006959E0[];
extern char D_00695A38[];

extern "C" struct S00659988 *func_005C11A8(void);
extern "C" void func_00326798(void *, s32, s32, const char *);
extern "C" void MNetwork__getChannels(s32 *, void *, s32, char **);
extern "C" void func_0023B1D8(void *, s32);
extern "C" void func_0023B478(void *);
extern "C" void func_0023CA78(s32, const char *, const char *);
extern "C" void func_002ED5C0(void *, s32);
extern "C" void func_002ED618(void *, void *);
extern "C" s32 hArray__size(s32);
extern "C" Obj **HArray__operator_index(void *, s32);
extern "C" void func_002FE278(s32 *, s32);
extern "C" void func_002FC870(s32 *, s32);
extern "C" void func_003285A8(s32);
extern "C" void func_003285F8(s32);
extern "C" s32 func_0057DA20(char *, const char *, ...);

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

static inline void assign(s32 *ret, s32 *h) {
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

#define SET_BOOL(ret, H, b) do { \
    func_002FE278(H, b); \
    if ((ret) != (H)) { \
        s32 newVal = (H)[0]; \
        s32 oldVal; \
        if (newVal != 0) \
            func_003285A8(newVal); \
        oldVal = *(ret); \
        if (oldVal != 0) \
            func_003285F8(oldVal); \
        *(ret) = newVal; \
    } \
    func_002FC870(H, 2); \
} while (0)

extern "C" void MNetwork__showChannels(s32 *ret, void *ctx, s32 argc, char **args) {
    s32 arr[4];
    union { char buf[0x80]; s32 h[4]; } b;
    s32 row[4];
    union { Str s; s32 h[4]; } u;
    Str *ps;
    s32 n;
    s32 i;

    MNetwork__getChannels(ret, ctx, argc, args);
    if (*ret == 0) {
        func_002FE278(arr, 0);
        assign(ret, arr);
        func_002FC870(arr, 2);
        return;
    }
    func_002ED618(arr, ret);
    i = 0;
    n = hArray__size(arr[0]);
    for (; i < n; i++) {
        s32 v0, v1, v2, v3, v4, v5, v6, v7, v8;
        func_002ED618(row, HArray__operator_index(arr, i));
        v0 = vcall_58(*HArray__operator_index(row, 0));
        v1 = vcall_58(*HArray__operator_index(row, 1));
        v2 = vcall_58(*HArray__operator_index(row, 2));
        v3 = vcall_58(*HArray__operator_index(row, 3));
        v4 = vcall_58(*HArray__operator_index(row, 4));
        v5 = vcall_58(*HArray__operator_index(row, 5));
        v6 = vcall_58(*HArray__operator_index(row, 6));
        v7 = vcall_58(*HArray__operator_index(row, 7));
        v8 = vcall_58(*HArray__operator_index(row, 8));
        vcall_18(&u.s, *HArray__operator_index(row, 9));
        ps = &u.s;
        {
            const char *cs;
            s32 len = *(s32 *)(u.s.p - 0x10);
            if (len == 0) {
                cs = D_006959D8;
            } else {
                u.s.p[len] = 0;
                cs = ps->p;
            }
            func_0057DA20(b.buf, D_00695A38, v0, v1, v2, v3, v4, v5, v6, v7, v8, cs);
        }
        str_release(ps);
        func_0023B478(ps);
        func_0023CA78(*(s32 *)ps, b.buf, D_006959E0);
        func_0023B1D8(ps, 2);
        func_002ED5C0(row, 2);
    }
    func_002FE278(b.h, 1);
    assign(ret, b.h);
    func_002FC870(b.h, 2);
    func_002ED5C0(arr, 2);
}
