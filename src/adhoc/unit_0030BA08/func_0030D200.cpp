/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned int u32;

struct StringRep { u32 len; u32 res; u32 ref; u32 selfish; };
struct String { char *dat; };

extern StringRep D_00659FA8;

extern "C" char *func_005C2560(StringRep *r);
extern "C" String *func_005C2630(String *str, u32 pos, u32 n1, const char *s, u32 n2);
extern "C" u32 func_0057F260(const char *s) throw();

static inline char *grab(StringRep *r) {
    if (r->selfish)
        return func_005C2560(r);
    ++r->ref;
    return (char *)(r + 1);
}

static inline String &assign(String *str, const char *s, u32 n) {
    return *func_005C2630(str, 0, (u32)-1, s, n);
}

static inline String &assign(String *str, const char *s) {
    return assign(str, s, func_0057F260(s));
}

static inline void construct(String *str, const char *s) {
    str->dat = grab(&D_00659FA8);
    assign(str, s);
}

extern char D_0069DED8[]; /* "" */
extern "C" void func_0030C5D8(char *buf, const char *s) throw();
extern "C" void func_0030CCF0(char *buf, char *a, char *b) throw();
extern "C" int func_0030D8E0(String *s);

static inline StringRep *rep(const String *str) { return (StringRep *)str->dat - 1; }
static inline u32 length(const String *str) { return rep(str)->len; }
static inline bool empty(const String *str) { return length(str) == 0; }
static inline char *rep_data(StringRep *r) { return (char *)(r + 1); }
static inline char &rep_at(StringRep *r, u32 i) { return rep_data(r)[i]; }
static inline void terminate(const String *str) { rep_at(rep(str), length(str)) = 0; }
static inline const char *c_str(const String *str) {
    if (length(str) == 0)
        return D_0069DED8;
    terminate(str);
    return rep_data(rep(str));
}
static inline void copy(String *str, const String *src) {
    str->dat = grab(rep(src));
}

extern "C" String *func_0030D200(String *ret, const String *a, String *b) {
    if (!empty(b)) {
        if (!func_0030D8E0(b)) {
            copy(ret, b);
        } else {
            char buf1[0x400];
            char buf2[0x400];
            char buf3[0x400];
            func_0030C5D8(buf1, c_str(a));
            func_0030C5D8(buf2, c_str(b));
            func_0030CCF0(buf3, buf1, buf2);
            construct(ret, buf3);
        }
    } else {
        copy(ret, b);
    }
    return ret;
}
