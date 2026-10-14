/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned int u32;
struct StringRep { u32 len, res, ref, selfish; };
struct String { char *dat; };
extern StringRep D_00659FA8;
extern "C" char *func_005C2560(StringRep *);
extern "C" String *func_005CE388(String *, u32, u32, const String *, u32, u32);
extern "C" u32 func_005DACE0(const String *, char, u32);
static inline char *grab(StringRep *r) {
    if (r->selfish) return func_005C2560(r);
    ++r->ref;
    return (char *)(r + 1);
}
static inline StringRep *rep(const String *s) { return (StringRep *)s->dat - 1; }
static inline void copy(String *r, const String *s) { r->dat = grab(rep(s)); }
static inline void construct(String *r, const String *s, u32 pos, u32 n) {
    r->dat = grab(&D_00659FA8);
    func_005CE388(r, 0, (u32)-1, s, pos, n);
}
extern "C" String *func_0030D700(String *ret, const String *s) {
    if (rep(s)->len != 0) {
        u32 pos = func_005DACE0(s, '.', (u32)-1);
        if (pos != (u32)-1) {
            construct(ret, s, 0, pos);
            return ret;
        }
    }
    copy(ret, s);
    return ret;
}
