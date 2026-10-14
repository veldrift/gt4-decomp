/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef short s16;

struct Rep { s32 len; s32 cap; s32 ref; s32 sel; };
struct S00659988 { const char *name; };
struct Str { char *p; };
union U { Str s; s32 h[4]; };
struct VEntry { s16 delta; s16 index; void (*fn)(void *, void *); };
struct VObj { char pad0[4]; VEntry *vtbl; };

extern char D_0069B600[];

extern "C" struct S00659988 *func_005C11A8(void);
extern "C" void func_00326798(void *p, s32 size, s32 align, const char *name);
extern "C" void func_0029D498(void *, int) throw();
extern "C" void func_0029D4F0(void *) throw();
extern "C" void func_0029DF18(void *, s32, const char *);
extern "C" void func_003122E8(void *, void *);
extern "C" void func_00312318(void *, int);
extern "C" void func_00314B20(void *, void *);
extern "C" void func_003285A8(s32);
extern "C" void func_003285F8(s32);

static inline void vcall(void *ret, VObj *o) {
    VEntry *e = (VEntry *)((char *)o->vtbl + 0x18);
    e->fn(ret, (char *)o + e->delta);
}

static inline const char *c_str(Str *s) {
    s32 len = ((Rep *)s->p)[-1].len;
    if (len == 0) {
        return D_0069B600;
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

extern "C" void MGpb__get(s32 *arg0, s32 arg1, s32 arg2, VObj **arg3) {
    if (arg2 > 0) {
        Str sp0;
        U h;
        U *ph = &h;
        U t;
        s32 sp30;
        func_0029D4F0(ph);
        s32 first = ph->h[0];
        vcall(&t, *arg3);
        func_0029DF18(&sp0, first, c_str(&t.s));
        release(&t.s);
        func_0029D498(ph, 2);
        s32 newVal;
        s32 oldVal;
        if (((Rep *)sp0.p)[-1].len == 0) {
            sp30 = 0;
            func_003122E8(ph, &sp30);
            if (arg0 != ph->h) {
                newVal = ph->h[0];
                if (newVal != 0) func_003285A8(newVal);
                oldVal = *arg0;
                if (oldVal != 0) func_003285F8(oldVal);
                *arg0 = newVal;
            }
            func_00312318(ph, 2);
        } else {
            func_00314B20(ph, &sp0);
            if (arg0 != ph->h) {
                newVal = ph->h[0];
                if (newVal != 0) func_003285A8(newVal);
                oldVal = *arg0;
                if (oldVal != 0) func_003285F8(oldVal);
                *arg0 = newVal;
            }
            func_00312318(ph, 2);
        }
        release(&sp0);
    }
}
