/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
struct Rep { s32 len; s32 cap; s32 ref; s32 sel; };
struct Str { char *p; char pad[0xC]; };
struct O { char pad[0x268]; s32 f268; };
extern char D_0069A578[];
extern "C" {
void func_004EDD60(s32, const char *, const char *, const char *, const char *);
static inline Rep *str_rep(Str *s) { return (Rep *)s->p - 1; }
static inline char *rep_data(Rep *r) { return (char *)(r + 1); }
static inline s32 str_length(Str *s) { return str_rep(s)->len; }
static inline void str_terminate(Str *s) { rep_data(str_rep(s))[str_length(s)] = 0; }
static inline const char *c_str(Str *s) {
    if (str_length(s) == 0) return D_0069A578;
    str_terminate(s);
    return rep_data(str_rep(s));
}
void mNetConfPS2__virtual_94(O *self, Str *a, Str *b, Str *c, Str *d) {
    const char *p1 = c_str(a);
    const char *p2 = c_str(b);
    const char *p3 = c_str(c);
    const char *p4 = c_str(d);
    func_004EDD60(self->f268, p1, p2, p3, p4);
}
}
