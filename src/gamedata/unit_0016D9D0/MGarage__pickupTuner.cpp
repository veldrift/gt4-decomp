/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef short s16;
struct VE { s16 delta; s16 idx; void *fn; };
struct Rep { s32 len, cap, ref, sel; };
struct S00659988 { const char *name; };
struct H { char *p; s32 pad[3]; };
struct Ob { s32 pad0; char *vt; };
extern char D_00690A30[];
extern char D_00690A38[];
extern "C" s32 func_0016D848(void *, s32) throw();
extern "C" void func_0016D7F0(void *, s32) throw();
extern "C" void func_001705E0(void *, s32, s32);
extern "C" void func_002ED5C0(void *, s32);
extern "C" void func_003285A8(s32);
extern "C" void func_003285F8(s32);
extern "C" s32 func_00448E28(const char *);
extern "C" s32 func_0057F238(const char *, const char *) throw();
extern "C" S00659988 *func_005C11A8(void);
extern "C" void func_00326798(void *, s32, s32, const char *);
static inline Rep *str_rep(H *s) { return (Rep *)s->p - 1; }
static inline char *rep_data(Rep *r) { return (char *)(r + 1); }
static inline s32 str_length(H *s) { return str_rep(s)->len; }
static inline void str_terminate(H *s) { rep_data(str_rep(s))[str_length(s)] = 0; }
static inline const char *c_str(H *s) {
    if (str_length(s) == 0) return D_00690A30;
    str_terminate(s);
    return rep_data(str_rep(s));
}
static inline void release(H *s) {
    Rep *q = str_rep(s);
    if (--q->ref == 0) { s32 size = q->cap + 0x10; func_00326798(q, size, 4, func_005C11A8()->name); }
}
extern "C" void MGarage__pickupTuner(s32 *out, s32 arg1, s32 n, Ob **arg3) {
    H s;
    H h;
    s32 s5 = -1;
    if (n > 0) {
        Ob *o = *arg3;
        VE *e3 = (VE *)(o->vt + 0x18);
        ((void (*)(H *, void *))e3->fn)(&s, (char *)o + e3->delta);
        const char *cs = c_str(&s);
        release(&s);
        if (func_0057F238(cs, D_00690A38) != 0) s5 = func_00448E28(cs);
    }
    H *hp = &h;
    func_0016D848(hp, arg1);
    func_001705E0(&s, (s32)hp->p, s5);
    if (out != (s32 *)&s) {
        s32 nv = (s32)s.p;
        if (nv) func_003285A8(nv);
        if (*out) func_003285F8(*out);
        *out = nv;
    }
    func_002ED5C0(&s, 2);
    func_0016D7F0(hp, 2);
}
