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
struct Obj { char pad0[4]; char *vtbl; };

extern StringRep D_00659FA8;

extern "C" char *func_005C2560(StringRep *r);
extern "C" Str *func_005C2630(Str *str, u32 pos, u32 n1, const char *s, u32 n2);
extern "C" u32 func_0057F260(const char *s);
extern "C" struct S00659988 *func_005C11A8(void);
extern "C" void func_00326798(void *, s32, s32, const char *);
extern "C" void func_001DC650(s32 *, void *);
extern "C" void func_001DC5F8(s32 *, s32);
extern "C" u32 func_001F1578(s32);
extern "C" const char *func_001DC9C8(s32);
extern "C" s32 func_001F1600(s32, Str *, s32, s32);
extern "C" s32 func_001F16A8(s32);
extern "C" void *func_001F20C8(s32);
extern "C" s32 func_001F21D8(s32);
extern "C" s32 func_001F2118(s32, Str *, Str *);
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

static inline void vcall_18(Str *ret, Obj *o) {
    VEntry18 *e = (VEntry18 *)(o->vtbl + 0x18);
    e->fn(ret, (char *)o + e->delta);
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

extern "C" void MNetwork__adduser(s32 *ret, void *ctx, s32 argc, Obj **args) {
    s32 h0[4];
    union { Str s; s32 h[4]; } u;
    Str b;
    s32 h3[4];

    func_001DC650(h0, ctx);
    if (func_001F1578(h0[0])) {
        set_bool(ret, u.h, 0);
        func_001DC5F8(h0, 2);
        return;
    }
    {
        const char *name = func_001DC9C8(h0[0]);
        s32 obj = h0[0];
        s32 x = *(s32 *)(obj + 0x30);
        s32 ok;
        construct(&u.s, name);
        ok = func_001F1600(obj, &u.s, x, 1);
        str_release(&u.s);
        if (!ok) {
            set_bool(ret, u.h, 0);
            func_001DC5F8(h0, 2);
            return;
        }
    }
    if (!func_001F20C8(h0[0]) || !func_001F21D8(h0[0])) {
        func_001F16A8(h0[0]);
        set_bool(ret, u.h, 0);
        func_001DC5F8(h0, 2);
        return;
    }
    vcall_18(&u.s, args[0]);
    vcall_18(&b, args[1]);
    if (func_001F2118(h0[0], &u.s, &b) == 0) {
        func_001F16A8(h0[0]);
        set_bool(ret, h3, 0);
        str_release(&b);
        str_release(&u.s);
        func_001DC5F8(h0, 2);
        return;
    }
    if (func_001F16A8(h0[0]) == 0) {
        set_bool(ret, h3, 0);
        str_release(&b);
        str_release(&u.s);
        func_001DC5F8(h0, 2);
        return;
    }
    set_bool(ret, h3, 1);
    str_release(&b);
    str_release(&u.s);
    func_001DC5F8(h0, 2);
}
