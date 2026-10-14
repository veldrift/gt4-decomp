/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef unsigned int u32;

struct Rep { s32 len; s32 cap; s32 ref; s32 sel; };
struct S00659988 { const char *name; };
struct Str { char *p; char pad[0xC]; };
struct Handle { void *p; char pad[0xC]; };
union U { Str s; Handle h; s32 w[4]; };
struct VEntry { short delta; short index; void (*fn)(void *, void *); };
struct VObj { char pad[4]; VEntry *vtbl; };

extern char D_0068F788[];
extern char D_0068F790[];

extern "C" void func_0013BD68(void *arg0, int arg1);
extern "C" void func_0013BDC0(void *arg0, void *arg1);
extern "C" int func_00147D80(void *arg0);
extern "C" int func_0014D968(const char *arg0) throw();
extern "C" void func_002FC870(void *, int);
extern "C" void func_002FE278(void *, s32);
extern "C" void func_00326798(void *p, s32 size, s32 align, const char *name);
extern "C" void func_003285A8(void *p);
extern "C" void func_003285F8(void *p);
extern "C" int func_00440938(int arg0, int arg1, const char *arg2);
extern "C" int func_0057F238(const char *, const char *) throw();
extern "C" struct S00659988 *func_005C11A8(void);

static inline void vcall(void *ret, VObj *o) {
    VEntry *e = (VEntry *)((char *)o->vtbl + 0x18);
    e->fn(ret, (char *)o + e->delta);
}
static inline Rep *str_rep(Str *s) { return (Rep *)s->p - 1; }
static inline char *rep_data(Rep *r) { return (char *)(r + 1); }
static inline s32 str_length(Str *s) { return str_rep(s)->len; }
static inline void str_terminate(Str *s) { rep_data(str_rep(s))[str_length(s)] = 0; }
static inline const char *c_str(Str *s) {
    if (str_length(s) == 0) return D_0068F788;
    str_terminate(s);
    return rep_data(str_rep(s));
}
static inline void release(Str *s) {
    Rep *q = str_rep(s);
    if (--q->ref == 0) {
        s32 cap = q->cap + 0x10;
        func_00326798(q, cap, 4, func_005C11A8()->name);
    }
}

extern "C" void MCarGarage__haveTireCategoryWheel(void **arg0, void *arg1, s32 arg2, VObj **arg3) {
    if (arg2 > 1) {
        U u;
        vcall(&u.s, arg3[0]);
        int k = func_0014D968(c_str(&u.s));
        release(&u.s);
        vcall(&u.s, arg3[1]);
        const char *nm = c_str(&u.s);
        release(&u.s);
        const char *sel = 0;
        if (func_0057F238(nm, D_0068F790) != 0)
            sel = nm;
        func_0013BDC0(&u, arg1);
        int r = func_00440938(func_00147D80(u.s.p), k, sel);
        func_0013BD68(&u, 2);
        func_002FE278(&u, r != 0);
        if ((void *)arg0 != (void *)&u) {
            void *p = u.s.p;
            if (p != 0) func_003285A8(p);
            if (*arg0 != 0) func_003285F8(*arg0);
            *arg0 = p;
        }
        func_002FC870(&u, 2);
    }
}
