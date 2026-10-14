/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef short s16;

struct Rep { s32 len; s32 cap; s32 ref; s32 sel; };
struct S00659988 { const char *name; };
struct Str { char *p; };
union U { Str s; s32 h[4]; };
struct VEntry { s16 delta; s16 index; void (*fn)(void *, void *); };
struct VObj { char pad0[4]; VEntry *vtbl; };

extern char D_00698E18[];
extern char D_00698E20[];

extern "C" struct S00659988 *func_005C11A8(void);
extern "C" void func_00326798(void *p, s32 size, s32 align, const char *name);
extern "C" void func_0023DDF0(void *, int) throw();
extern "C" void func_0023DE48(void *, void *) throw();
extern "C" void func_0023F848(void *, const char *);

static inline void vcall(void *ret, VObj *o) {
    VEntry *e = (VEntry *)((char *)o->vtbl + 0x18);
    e->fn(ret, (char *)o + e->delta);
}

static inline Rep *str_rep(Str *s) { return (Rep *)s->p - 1; }
static inline char *rep_data(Rep *r) { return (char *)(r + 1); }
static inline s32 str_length(Str *s) { return str_rep(s)->len; }
static inline void str_terminate(Str *s) { rep_data(str_rep(s))[str_length(s)] = 0; }
static inline const char *c_str(Str *s) {
    if (str_length(s) == 0) return D_00698E18;
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

extern "C" void MSound__load(void *arg0, void *arg1, s32 arg2, VObj **arg3) {
    U h0;
    func_0023DE48(&h0, arg1);
    if (arg2 > 0) {
        U h1;
        U *ph = &h1;
        func_0023DE48(ph, arg1);
        void *obj = (void *)ph->h[0];
        U t;
        vcall(&t, arg3[0]);
        const char *s = c_str(&t.s);
        release(&t.s);
        func_0023F848(obj, s);
        func_0023DDF0(ph, 2);
    } else {
        U h1;
        U *ph = &h1;        func_0023DE48(ph, arg1);
        func_0023F848((void *)ph->h[0], D_00698E20);
        func_0023DDF0(ph, 2);
    }
    func_0023DDF0(&h0, 2);
}
