/* Calls IfWidget__structor_0(a0); when bit 0x10 of a0->0xE8 is set, passes basic_string<char>(hModule__getName(a0)) to virtual entry 0x38 of a1; then releases a0->0xC8 (func_003286B8) and clears it (bastring.h: default ctor = nilRep.grab(), (const char *) ctor = grab + assign(s, strlen(s)), copy ctor = rep()->grab(), dtor = rep()->release() -> func_00326798(p, sizeof(Rep) + res, 4, heap name)) */
typedef unsigned int u32;
typedef int s32;

struct StringRep { u32 len; u32 res; u32 ref; u32 selfish; };
struct String { char *dat; int pad[3]; };
struct Heap { const char *name; };

extern StringRep D_00659FA8;

extern "C" char *func_005C2560(StringRep *r);
extern "C" String *func_005C2630(String *str, u32 pos, u32 n1, const char *s, u32 n2);
extern "C" u32 func_0057F260(const char *s);
extern "C" Heap *func_005C11A8(void);
extern "C" void func_00326798(void *p, u32 n, u32 align, const char *name);
struct VEntry { short delta; short index; void (*fn)(void *self, String *s, String *t); };
struct Obj { s32 x; VEntry *vtbl; };
struct Win { char pad[0x10]; Obj *o; };
extern "C" void IfWidget__structor_0(void *a);
extern "C" const char *hModule__getName(void *a);
extern "C" void func_0025A7E0(String *s, void *self);
extern "C" void func_0026A118(String *s, int n);
extern "C" void mTextFace__virtual_67(void *self, void *a);
extern "C" s32 func_0025C110(void *self);
extern "C" void func_00229D18(String *s, s32 r);
extern "C" void func_003286B8(void *a);

static inline char *grab(StringRep *r) {
    if (r->selfish)
        return func_005C2560(r);
    ++r->ref;
    return (char *)(r + 1);
}

static inline String &assign(String *str, const char *s, u32 n) {
    return *func_005C2630(str, 0, (u32)-1, s, n);
}

static inline String &assign(String *str, const char *s) {
    return assign(str, s, func_0057F260(s));
}

static inline void construct(String *str, const char *s, u32 n) {
    str->dat = grab(&D_00659FA8);
    assign(str, s, n);
}

static inline void construct(String *str, const char *s) {
    str->dat = grab(&D_00659FA8);
    assign(str, s);
}

static inline void construct(String *str) {
    str->dat = grab(&D_00659FA8);
}

static inline StringRep *rep(const String *str) { return (StringRep *)str->dat - 1; }
static inline void copy(String *str, const String *src) { str->dat = grab(rep(src)); }
static inline void deallocate(void *p, u32 n) { func_00326798(p, n, 4, func_005C11A8()->name); }
static inline void rep_delete(void *ptr) { deallocate(ptr, sizeof(StringRep) + ((StringRep *)ptr)->res); }
static inline void release(StringRep *r) { if (--r->ref == 0) rep_delete(r); }
static inline void destroy(String *str) { release(rep(str)); }

struct ReleasedString : String { ~ReleasedString() { release(rep(this)); } };

extern "C" void mRootWindow__virtual_67(char *self, Win *a1) {
    String h;
    func_0025A7E0(&h, self);
    *(Win **)(h.dat + 0x14) = a1;
    func_0026A118(&h, 2);
    mTextFace__virtual_67(self, a1);
    s32 r = func_0025C110(self);
    if (r && !(*(s32 *)(self + 0xE8) & 0x30)) {
        Obj *o = a1->o;
        String s;
        func_00229D18(&h, r);
        construct(&s, hModule__getName(self));
        VEntry *e = o->vtbl + 0x1B0 / 8;
        e->fn((char *)o + e->delta, &h, &s);
        destroy(&s);
        ((ReleasedString *)&h)->~ReleasedString();
    }
    *(s32 *)(self + 0xE8) &= ~8;
}
