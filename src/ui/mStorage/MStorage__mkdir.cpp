/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef short s16;

struct Rep { s32 len; s32 cap; s32 ref; s32 sel; };
struct Str { char *p; };
struct VEntry { s16 delta; s16 index; s32 (*fn)(void *, const char *); };
struct Obj { char pad0[4]; char *vtbl; };
struct Hold { Obj *p; char pad[12]; };
struct Hold2 { s32 *p; char pad[12]; };

extern char D_00698F10[];

extern "C" void func_002403C8(void *, int) throw();
extern "C" void func_00240420(void *, void *) throw();
extern "C" void func_002FC870(void *, int);
extern "C" void func_002FE278(void *, s32);
extern "C" void func_00312318(void *, int);
extern "C" void func_00312370(void *, void *);
extern "C" Str *func_00314920(void *);
extern "C" void func_003285A8(s32);
extern "C" void func_003285F8(s32);

static inline const char *c_str(Str *s) {
    s32 len = ((Rep *)s->p)[-1].len;
    if (len == 0) {
        return D_00698F10;
    }
    s->p[len] = 0;
    return s->p;
}

extern "C" void MStorage__mkdir(s32 *arg0, void *arg1, s32 arg2, void *arg3) {
    if (arg2 > 0) {
        Hold sp0;
        Hold2 a;
        Hold2 b;
        func_00240420(&sp0, arg1);
        Hold2 *pa = &a;
        func_00312370(pa, arg3);
        Obj *o = sp0.p;
        VEntry *e = (VEntry *)(o->vtbl + 0x1D8);
        s16 d = e->delta;
        void *adj = (char *)o + d;
        Str *str = func_00314920(pa->p);
        const char *cs = c_str(str);
        int result = e->fn(adj, cs) != 0;
        Hold2 *pb = &b;
        func_002FE278(pb, result);
        if ((void *)arg0 != (void *)pb) {
            s32 nv = (s32)pb->p;
            if (nv != 0) func_003285A8(nv);
            if (*arg0 != 0) func_003285F8(*arg0);
            *arg0 = nv;
        }
        func_002FC870(pb, 2);
        func_00312318(pa, 2);
        func_002403C8(&sp0, 2);
    }
}
