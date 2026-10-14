/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Rep { unsigned int len, cap, ref, sel; };
struct String { char *p; char pad[12]; ~String(); };
struct Vec;
struct Info { const char *name; };
extern char D_0069E020[];
extern "C" String func_0030ECE0(Vec *) throw();
extern "C" Info *func_005C11A8();
extern "C" void func_00326798(void *, unsigned int, int, const char *);
static inline Rep *rep(const String *s) { return (Rep *)s->p - 1; }
static inline char *data(const String *s) { return (char *)(rep(s) + 1); }
static inline unsigned int length(const String *s) { return rep(s)->len; }
static inline void terminate(const String *s) { data(s)[length(s)] = 0; }
static inline const char *c_str(const String *s) {
    if (length(s) == 0) return D_0069E020;
    terminate(s);
    return data(s);
}
static inline void release(String *s) {
    Rep *r = (Rep *)s->p - 1;
    if (--r->ref == 0) {
        unsigned int size = r->cap + 16;
        func_00326798(r, size, 4, func_005C11A8()->name);
    }
}
inline String::~String() { release(this); }
extern "C" const char *func_0030F590(Vec *v) {
    String tmp = func_0030ECE0(v);
    return c_str(&tmp);
}
