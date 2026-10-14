/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef short s16;

struct Rep { s32 len; s32 cap; s32 ref; s32 sel; };
struct S00659988 { const char *name; };
struct Str { char *p; };
struct VEntry { s16 delta; s16 index; void (*fn)(void *, void *); };
struct VObj { char pad0[4]; VEntry *vtbl; };
struct HO { char pad[0x10]; s32 f10; };

extern char D_00692A98[];

extern "C" struct S00659988 *func_005C11A8(void);
extern "C" void func_00326798(void *p, s32 size, s32 align, const char *name);
extern "C" void func_001A4808(void *, int) throw();
extern "C" void func_001A4860(void *, void *) throw();
extern "C" s32 func_00430990(const char *);
extern "C" s32 func_00431C60(const char *);
extern "C" void func_00430A58(s32, s32, s32);

static inline void vcall(void *ret, VObj *o) {
    VEntry *e = (VEntry *)((char *)o->vtbl + 0x18);
    e->fn(ret, (char *)o + e->delta);
}
static inline Rep *str_rep(Str *s) { return (Rep *)s->p - 1; }
static inline char *rep_data(Rep *r) { return (char *)(r + 1); }
static inline s32 str_length(Str *s) { return str_rep(s)->len; }
static inline void str_terminate(Str *s) { rep_data(str_rep(s))[str_length(s)] = 0; }
static inline const char *c_str(Str *s) {
    if (str_length(s) == 0) return D_00692A98;
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

extern "C" void MRaceRecordUnit__update(void *arg0, void *arg1, s32 arg2, VObj **arg3) {
    if (arg2 >= 2) {
        Str a;
        vcall(&a, arg3[0]);
        const char *s1 = c_str(&a);
        release(&a);
        vcall(&a, arg3[1]);
        const char *s2 = c_str(&a);
        release(&a);
        s32 r1 = func_00430990(s1);
        s32 r2 = func_00431C60(s2);
        func_001A4860(&a, arg1);
        func_00430A58(((HO *)a.p)->f10, r1, r2);
        func_001A4808(&a, 2);
    }
}
