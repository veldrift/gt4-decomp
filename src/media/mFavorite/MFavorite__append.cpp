/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef unsigned int u32;
typedef long s64;

struct Rep { s32 len; s32 cap; s32 ref; s32 sel; };
struct S00659988 { const char *name; };
struct VE { short d; short i; void (*fn)(void *, void *); };
struct Obj { char pad[4]; void *vt; };
struct Str { char *p; char pad[0xC]; };

extern "C" void func_001BFE50(void *, int) throw();
extern "C" void func_001BFEA8(void *, void *) throw();
extern "C" void func_002FC870(void *, int);
extern "C" void func_002FE278(void *, u32);
extern "C" void func_00326798(void *, s32, s32, const char *);
extern "C" void func_003285A8(s32);
extern "C" void func_003285F8(s32);
extern "C" s32 func_004303F8(void *, s64);
extern "C" s32 func_00447BB8(const char *);
extern "C" s32 func_00447C78(const char *);
extern "C" S00659988 *func_005C11A8(void);
extern char D_00693BE8[];

static inline Rep *str_rep(Str *s) { return (Rep *)s->p - 1; }
static inline char *rep_data(Rep *r) { return (char *)(r + 1); }
static inline s32 str_length(Str *s) { return str_rep(s)->len; }
static inline void str_terminate(Str *s) { rep_data(str_rep(s))[str_length(s)] = 0; }
static inline const char *c_str(Str *s) {
    if (str_length(s) == 0) return D_00693BE8;
    str_terminate(s);
    return rep_data(str_rep(s));
}
static inline void release(Str *s) {
    Rep *q = str_rep(s);
    if (--q->ref == 0) { s32 size = q->cap + 0x10; func_00326798(q, size, 4, func_005C11A8()->name); }
}
extern "C" void MFavorite__append(s32 *arg0, void *arg1, s32 arg2, Obj **arg3) {
    if (arg2 > 0) {
        Str s;
        Obj *o = *arg3;
        VE *ve = (VE *)((char *)o->vt + 0x18);
        const char *name;
        s32 id;
        s32 r;
        ve->fn(&s, (char *)o + ve->d);
        name = c_str(&s);
        release(&s);
        id = func_00447BB8(name);
        if (id == -1) id = func_00447C78(name);
        func_001BFEA8(&s, arg1);
        r = func_004303F8(*(void **)(s.p + 0x10), id);
        func_001BFE50(&s, 2);
        func_002FE278(&s, (u32)~r >> 31);
        if (arg0 != (s32 *)&s) {
            s32 nv = *(s32 *)&s;
            if (nv != 0) func_003285A8(nv);
            if (*arg0 != 0) func_003285F8(*arg0);
            *arg0 = nv;
        }
        func_002FC870(&s, 2);
    }
}
