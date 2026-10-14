typedef int s32;
typedef short s16;
typedef unsigned int u32;

struct StringRep { u32 len; u32 res; u32 ref; u32 selfish; };
struct S00659988 { const char *name; };
extern char D_006959D8[];
extern char D_00695AC8[];

extern "C" struct S00659988 *func_005C11A8(void);
extern "C" void func_00326798(void *, s32, s32, const char *);
extern "C" void func_001DC5F8(void *, int);
extern "C" void func_001DC650(void *, s32);
extern "C" s32 func_001F4DA8(char *);
extern "C" s32 func_001F6548(char *, const char *, const char *, const char *, int, int, int, int, int);
extern "C" void func_002FE278(s32 *, s32);
extern "C" void func_002FC870(s32 *, s32);
extern "C" void func_003285A8(s32);
extern "C" void func_003285F8(s32);

struct Str {
    char *p;
    char pad[0xC];
    ~Str() {
        StringRep *q = (StringRep *)(p - 0x10);
        if (--q->ref == 0) {
            s32 size = q->res + 0x10;
            func_00326798(q, size, 4, func_005C11A8()->name);
        }
    }
    const char *c_str() {
        s32 len = *(s32 *)(p - 0x10);
        if (len == 0) return D_006959D8;
        p[len] = 0;
        return p;
    }
};

struct VEntry18 { s16 delta; s16 index; Str (*fn)(void *); };
struct VEntry58 { s16 delta; s16 index; s32 (*fn)(void *); };
struct Obj {
    char pad0[4]; char *vtbl;
    Str str() {
        VEntry18 *e = (VEntry18 *)(vtbl + 0x18);
        return e->fn((char *)this + e->delta);
    }
    s32 num() {
        VEntry58 *e = (VEntry58 *)(vtbl + 0x58);
        return e->fn((char *)this + e->delta);
    }
};
struct Obj2 { char *p; char pad[0xC]; char *get() { return p; } };

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


struct VE18 { s16 delta; s16 index; void (*fn)(void *, void *); };
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
static inline const char *c_str(Str *t) {
    s32 len = *(s32 *)(t->p - 0x10);
    if (len == 0) return D_006959D8;
    t->p[len] = 0;
    return t->p;
}
static inline void str_release(Str *s) {
    StringRep *q = (StringRep *)(s->p - 0x10);
    if (--q->ref == 0) {
        s32 size = q->res + 0x10;
        func_00326798(q, size, 4, func_005C11A8()->name);
    }
}
#define VC18(ret, o) do { Obj *o_ = (o); VE18 *e_ = (VE18 *)(o_->vtbl + 0x18); e_->fn(ret, (char *)o_ + e_->delta); } while (0)
struct SS { char *p; char pad[0xC];
    const char *c_str() {
        s32 len = *(s32 *)(p - 0x10);
        if (len == 0) return D_006959D8;
        p[len] = 0;
        return p;
    }
    void release() {
        StringRep *q = (StringRep *)(p - 0x10);
        if (--q->ref == 0) {
            s32 size = q->res + 0x10;
            func_00326798(q, size, 4, func_005C11A8()->name);
        }
    }
};
extern "C" void MNetwork__createGameMGCL(s32 *ret, s32 ctx, s32 argc, Obj **args) {
    union { SS s; Obj2 o; } u;
    s32 h[4];
    const char *name;
    const char *password;
    const char *desc;
    s32 a, b, c, d, e;

    name = D_00695AC8;
    if (argc > 0) {
        VC18(&u.s, args[0]);
        name = u.s.c_str();
        u.s.release();
    }
    password = 0;
    if (argc > 1) {
        VC18(&u.s, args[1]);
        password = u.s.c_str();
        u.s.release();
    }
    desc = 0;
    if (argc > 2) {
        VC18(&u.s, args[2]);
        desc = u.s.c_str();
        u.s.release();
    }
    a = 6;
    if (argc > 3) a = args[3]->num();
    b = 2;
    if (argc > 4) b = args[4]->num();
    c = 1;
    if (argc > 5) c = args[5]->num();
    d = 1;
    if (argc > 6) d = args[6]->num();
    e = 1;
    if (argc > 7) e = args[7]->num();
    func_001DC650(&u.o, ctx);
    if (func_001F6548(u.o.get(), name, password, desc, a, b, c, d, e) == 0 || func_001F4DA8(u.o.get()) == 0) {
        set_bool(ret, h, 0);
        func_001DC5F8(&u.o, 2);
        return;
    }
    set_bool(ret, h, 1);
    func_001DC5F8(&u.o, 2);
}
