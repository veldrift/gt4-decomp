/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
struct Rep { s32 len; s32 cap; s32 ref; s32 sel; };
struct Str { char *p; char pad[0xC]; };
struct O { char pad[0x268]; s32 f268; };
extern char D_0069A578[];
extern "C" {
s32 func_004ED980(s32, int, const char *, const char *);
void func_00275830(void *) throw();
static inline Rep *str_rep(Str *s) { return (Rep *)s->p - 1; }
static inline char *rep_data(Rep *r) { return (char *)(r + 1); }
static inline s32 str_length(Str *s) { return str_rep(s)->len; }
static inline void str_terminate(Str *s) { rep_data(str_rep(s))[str_length(s)] = 0; }
static inline const char *c_str(Str *s) {
    if (str_length(s) == 0) return D_0069A578;
    str_terminate(s);
    return rep_data(str_rep(s));
}
s32 mNetConfPS2__virtual_100(O *self, Str *a, Str *b) {
    const char *p1 = c_str(a);
    const char *p2 = c_str(b);
    s32 r = func_004ED980(self->f268, 0, p1, p2);
    if (r >= 0) func_00275830(self);
    return r;
}
}
