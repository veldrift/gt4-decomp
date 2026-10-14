/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef short s16;
struct RefCounter;
struct Str { char *p; s32 pad[3]; };
struct VE { s16 delta; s16 pad; void (*fn)(Str *, void *); };
struct Obj { char pad0[4]; char *vtbl; };
struct Rep { s32 len; s32 cap; s32 ref; s32 sel; };
struct S00659988 { const char *name; };

extern char D_006959D8[];

extern "C" void func_001DC5F8(void *, s32) throw();
extern "C" void func_001DC650(void *, s32) throw();
extern "C" s32 func_001F7648(s32, const char *);
extern "C" void func_002FC870(void *, s32);
extern "C" void func_002FE278(void *, s32);
extern "C" void func_00326798(void *, s32, s32, const char *);
extern "C" void func_003285A8(RefCounter *);
extern "C" void func_003285F8(RefCounter *);
extern "C" S00659988 *func_005C11A8(void);

static inline Rep *str_rep(Str *s) { return (Rep *)s->p - 1; }
static inline char *rep_data(Rep *r) { return (char *)(r + 1); }
static inline s32 str_length(Str *s) { return str_rep(s)->len; }
static inline void str_terminate(Str *s) { rep_data(str_rep(s))[str_length(s)] = 0; }
static inline const char *c_str(Str *s) {
    if (str_length(s) == 0) return D_006959D8;
    str_terminate(s);
    return rep_data(str_rep(s));
}
static inline void release(Str *s) {
    Rep *q = str_rep(s);
    if (--q->ref == 0) { s32 size = q->cap + 0x10; func_00326798(q, size, 4, func_005C11A8()->name); }
}

extern "C" void MNetwork__sayGame(s32 *dst, s32 a1, s32 n, Obj **pobj) {
    struct F { s32 h[4]; Str s; } fr;
    if (n > 0) {
        func_001DC650(fr.h, a1);
        Obj *o = *pobj;
        VE *e = (VE *)(o->vtbl + 0x18);
        e->fn(&fr.s, (char *)o + e->delta);
        const char *c = c_str(&fr.s);
        release(&fr.s);
        Str *ps = &fr.s;
        s32 v = func_001F7648(fr.h[0], c);
        func_002FE278(ps, v != 0);
        if (dst != (s32 *)ps) {
            s32 x = *(s32 *)ps;
            if (x != 0)
                func_003285A8((RefCounter *)x);
            s32 old = *dst;
            if (old != 0)
                func_003285F8((RefCounter *)old);
            *dst = x;
        }
        func_002FC870(ps, 2);
        func_001DC5F8(fr.h, 2);
    }
}
