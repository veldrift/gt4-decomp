/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned int u32;
typedef int s32;

struct Rep { u32 len; u32 res; u32 ref; u32 selfish; };
struct Str { char *dat; };
struct Heap { const char *name; };
extern Rep D_00659FA8;
extern "C" char *func_005C2560(Rep *r);
extern "C" u32 func_0057F260(const char *s) throw();
extern "C" Heap *func_005C11A8(void);
extern "C" void func_00326798(void *p, u32 n, u32 align, const char *name);
extern "C" Str *func_005C2630(Str *self, u32 pos, u32 n1, const char *s, u32 n2);

static inline char *grab(Rep *r) {
    if (r->selfish)
        return func_005C2560(r);
    ++r->ref;
    return (char *)(r + 1);
}
static inline Str &assign(Str *str, const char *s, u32 n) { return *func_005C2630(str, 0, (u32)-1, s, n); }
static inline Str &assign(Str *str, const char *s) { return assign(str, s, func_0057F260(s)); }
static inline void construct(Str *str, const char *s) { str->dat = grab(&D_00659FA8); assign(str, s); }
static inline void construct(Str *str) { str->dat = grab(&D_00659FA8); }
static inline Rep *rep(const Str *str) { return (Rep *)str->dat - 1; }
static inline void deallocate(void *p, u32 n) { func_00326798(p, n, 4, func_005C11A8()->name); }
static inline void rep_delete(void *ptr) { deallocate(ptr, sizeof(Rep) + ((Rep *)ptr)->res); }
static inline void release(Rep *r) { if (--r->ref == 0) rep_delete(r); }
static inline void destroy(Str *str) { release(rep(str)); }

struct Cb { void **vtbl; void *p; };
struct Color { char data[16]; };
extern "C" s32 MColorReader__structor_0(Color *, void *);
extern "C" void MColorReader__structor_1(void *, int);
extern "C" s32 func_0020FD38(void *, Str *, void *);
extern "C" void MReaderBase__structor_0(Cb *, int);
extern "C" int mSlideShowFace__virtual_61(void *, void *);
extern char D_0068E708[], D_0068E718[], D_0068E728[], D_0068E738[];
extern void *MboolReader__vtable[];
struct B0 { Str t; char pad[28]; Color cb; };
struct B1 { Str t; char pad[60]; Color cb; };
struct B2 { Str t; char pad[12]; Cb cb; };
extern "C" int MboolReader__structor_0(char *self, void *ev) {
    if (mSlideShowFace__virtual_61(self, ev)) return 1;
    union { B0 b0; B1 b1; B2 b2; } u;
    {
        construct(&u.b0.t, D_0068E708);
        Color *cb = &u.b0.cb;
        MColorReader__structor_0(cb, self + 0xA0);
        int r = func_0020FD38(ev, &u.b0.t, cb);
        MColorReader__structor_1(cb, 2);
        destroy(&u.b0.t);
        if (r) return 1;
    }
    {
        construct(&u.b1.t, D_0068E718);
        Color *cb = &u.b1.cb;
        MColorReader__structor_0(cb, self + 0xB0);
        int r = func_0020FD38(ev, &u.b1.t, cb);
        MColorReader__structor_1(cb, 2);
        destroy(&u.b1.t);
        if (r) return 1;
    }
    {
        construct(&u.b2.t, D_0068E728);
        void *p = self + 0xC0;
        Cb *cb = &u.b2.cb;
        cb->vtbl = MboolReader__vtable;
        cb->p = p;
        int r = func_0020FD38(ev, &u.b2.t, cb);
        cb->vtbl = MboolReader__vtable;
        MReaderBase__structor_0(cb, 0);
        destroy(&u.b2.t);
        if (r) return 1;
    }
    {
        construct(&u.b2.t, D_0068E738);
        void *p = self + 0xC4;
        Cb *cb = &u.b2.cb;
        cb->vtbl = MboolReader__vtable;
        cb->p = p;
        int r = func_0020FD38(ev, &u.b2.t, cb);
        cb->vtbl = MboolReader__vtable;
        MReaderBase__structor_0(cb, 0);
        destroy(&u.b2.t);
        return r != 0;
    }
}
