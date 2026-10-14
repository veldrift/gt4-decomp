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
extern "C" void func_001F8FC0(void *, s32, const char *);
extern "C" void func_002ED5C0(void *, s32);
extern "C" void func_00326798(void *, s32, s32, const char *);
extern "C" void func_003285A8(RefCounter *);
extern "C" void func_003285F8(RefCounter *);
extern "C" S00659988 *func_005C11A8(void);

static inline const char *cstr(Str *s) {
    char *d = s->p;
    s32 len = ((s32 *)d)[-4];
    if (len == 0)
        return D_006959D8;
    d[len] = 0;
    return s->p;
}

extern "C" void MNetwork__billingGetProductDetail(s32 *dst, s32 a1, s32 n, Obj **pobj) {
    struct F { s32 h[4]; s32 k[4]; Str s; } fr;
    if (n > 0) {
        s32 *pk = fr.k;
        func_001DC650(pk, a1);
        s32 k0 = pk[0];
        Obj *o = *pobj;
        Str *ps = &fr.s;
        VE *e = (VE *)(o->vtbl + 0x18);
        e->fn(ps, (char *)o + e->delta);
        func_001F8FC0(fr.h, k0, cstr(ps));
        if (dst != fr.h) {
            s32 x = fr.h[0];
            if (x != 0)
                func_003285A8((RefCounter *)x);
            s32 old = *dst;
            if (old != 0)
                func_003285F8((RefCounter *)old);
            *dst = x;
        }
        func_002ED5C0(fr.h, 2);
        Rep *q = (Rep *)(ps->p - 0x10);
        if (--q->ref == 0) {
            s32 cap = q->cap + 0x10;
            func_00326798(q, cap, 4, func_005C11A8()->name);
        }
        func_001DC5F8(pk, 2);
    }
}
