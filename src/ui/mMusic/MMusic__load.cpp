/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef short s16;

struct Rep { s32 len; s32 cap; s32 ref; s32 sel; };
struct S00659988 { const char *name; };
struct Str { char *p; char pad[0xC]; };
struct VEntry { s16 delta; s16 index; void (*fn)(void *, void *); };
struct VObj { char pad0[4]; VEntry *vtbl; };
struct H { void *o; char pad[0xC]; };

extern char D_0069C550[];
extern char D_0069C558[];

extern "C" void func_002C2878(void *, int) throw();
extern "C" void func_002C28D0(void *, void *) throw();
extern "C" void func_002C3B60(void *, const char *);
extern "C" void func_00326798(void *, s32, s32, const char *);
extern "C" S00659988 *func_005C11A8(void);

static inline Rep *str_rep(Str *s) { return (Rep *)s->p - 1; }
static inline char *rep_data(Rep *r) { return (char *)(r + 1); }
static inline s32 str_length(Str *s) { return str_rep(s)->len; }
static inline void str_terminate(Str *s) { rep_data(str_rep(s))[str_length(s)] = 0; }
static inline const char *c_str(Str *s) {
    if (str_length(s) == 0) return D_0069C550;
    str_terminate(s);
    return rep_data(str_rep(s));
}
static inline void release(Str *s) {
    Rep *q = str_rep(s);
    if (--q->ref == 0) { s32 size = q->cap + 0x10; func_00326798(q, size, 4, func_005C11A8()->name); }
}

extern "C" void MMusic__load(void *self, void *arg1, s32 n, VObj **args) {
    H h;
    Str s;
    func_002C28D0(&h, arg1);
    if (n > 0) {
        void *o = h.o;
        VObj *obj = args[0];
        VEntry *e = (VEntry *)((char *)obj->vtbl + 0x18);
        e->fn(&s, (char *)obj + e->delta);
        const char *cs = c_str(&s);
        release(&s);
        func_002C3B60(o, cs);
    } else {
        func_002C3B60(h.o, D_0069C558);
    }
    func_002C2878(&h, 2);
}
