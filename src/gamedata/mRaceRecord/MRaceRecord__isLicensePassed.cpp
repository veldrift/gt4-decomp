/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef unsigned char u8;

struct Rep { s32 len; s32 cap; s32 ref; s32 sel; };
struct S00659988 { const char *name; };
struct Str { char *p; char pad[0xC]; };
struct VE { short d; short i; void (*fn)(Str *, void *); };
struct Obj { char pad[4]; char *vt; };
struct Item { char pad[0x10]; s32 i10; };
struct H { Item *p; char pad[0xC]; };

extern char D_00692A98[];

extern "C" void func_001A5CC8(void *, int) throw();
extern "C" void *func_001A5D20(void *, void *) throw();
extern "C" void func_002FC870(void *, int);
extern "C" void func_002FE278(void *, void *);
extern "C" void func_00326798(void *, s32, s32, const char *);
extern "C" void func_003285A8(void *);
extern "C" void func_003285F8(void *);
extern "C" s32 func_004312B0(s32, const char *);
extern "C" S00659988 *func_005C11A8(void);

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
        s32 size = q->cap + 0x10;
        func_00326798(q, size, 4, func_005C11A8()->name);
    }
}

extern "C" void MRaceRecord__isLicensePassed(void **arg0, void *arg1, s32 n, Obj **arg3) {
    Str s;
    H h;
    if (n > 0) {
        Obj *o = *arg3;
        VE *ve = (VE *)(o->vt + 0x18);
        ve->fn(&s, (char *)o + ve->d);
        const char *cs = c_str(&s);
        release(&s);
        H *ph = &h;
        func_001A5D20(ph, arg1);
        func_002FE278(&s, (void *)(func_004312B0(ph->p->i10, cs) != 0));
        if ((void *)arg0 != (void *)&s) {
            void *nv = s.p;
            if (nv != 0) func_003285A8(nv);
            if (*arg0 != 0) func_003285F8(*arg0);
            *arg0 = nv;
        }
        func_002FC870(&s, 2);
        func_001A5CC8(ph, 2);
    }
}
