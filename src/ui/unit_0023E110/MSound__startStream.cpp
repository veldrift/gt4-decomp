typedef int s32;
typedef short s16;

struct Rep { s32 len; s32 cap; s32 ref; s32 sel; };
struct S00659988 { const char *name; };
struct Str { char *p; };
union U { Str s; s32 h[4]; };
struct VEntry { s16 delta; s16 index; void (*fn)(void *, void *); };
struct VObj { char pad0[4]; VEntry *vtbl; };

extern char D_00698E18[];

extern "C" struct S00659988 *func_005C11A8(void);
extern "C" void func_00326798(void *p, s32 size, s32 align, const char *name);
extern "C" void func_0023DDF0(void *, int) throw();
extern "C" void func_0023DE48(void *, void *) throw();
extern "C" void func_0023FA78(void *, const char *, const char *);

static inline void vcall(void *ret, VObj *o) {
    VEntry *e = (VEntry *)((char *)o->vtbl + 0x18);
    e->fn(ret, (char *)o + e->delta);
}

static inline const char *c_str(Str *s) {
    s32 len = ((Rep *)s->p)[-1].len;
    if (len == 0) {
        return D_00698E18;
    }
    s->p[len] = 0;
    return s->p;
}

static inline void release(Str *s) {
    Rep *q = (Rep *)(s->p - 0x10);
    if (--q->ref == 0) {
        s32 cap = q->cap + 0x10;
        func_00326798(q, cap, 4, func_005C11A8()->name);
    }
}

extern "C" void MSound__startStream(void *arg0, void *arg1, s32 arg2, VObj **arg3) {
    if (arg2 >= 2) {
        struct { s32 h[12]; } h;
        U a;
        U b;
        func_0023DE48(&h, arg1);
        void *obj = (void *)h.h[0];
        vcall(&a, arg3[0]);
        const char *s1 = c_str(&a.s);
        release(&a.s);
        vcall(&b, arg3[1]);
        const char *s2 = c_str(&b.s);
        release(&b.s);
        func_0023FA78(obj, s1, s2);
        func_0023DDF0(&h, 2);
    }
}
