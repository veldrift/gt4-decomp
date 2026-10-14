/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef unsigned int u32;

struct StringRep { u32 len; u32 res; u32 ref; u32 selfish; };
struct String { char *dat; };
struct S00659988 { const char *name; };
struct Vec { s32 pad0; s32 *begin; s32 *end; };

extern StringRep D_00659FA8;
extern char D_0069E018[];

extern "C" char *func_005C2560(StringRep *r);
extern "C" String *func_005C2630(String *str, u32 pos, u32 n1, const char *s, u32 n2);
extern "C" u32 func_0057F260(const char *s) throw();
extern "C" const char *HSymID__GetName(s32 id);
extern "C" struct S00659988 *func_005C11A8(void);
extern "C" void func_00326798(void *, s32, s32, const char *);

static inline StringRep *rep(const String *str) { return (StringRep *)str->dat - 1; }

static inline char *grab(StringRep *r) {
    if (r->selfish)
        return func_005C2560(r);
    ++r->ref;
    return (char *)(r + 1);
}

static inline void str_release(String *s) {
    StringRep *q = rep(s);
    if (--q->ref == 0) {
        s32 size = q->res + 0x10;
        func_00326798(q, size, 4, func_005C11A8()->name);
    }
}

static inline void assign(String *str, const char *s, u32 n) {
    func_005C2630(str, 0, (u32)-1, s, n);
}

static inline void append(String *str, const char *s, u32 n) {
    func_005C2630(str, rep(str)->len, 0, s, n);
}

extern "C" String *func_0030ECE0(String *ret, Vec *v) {
    String s;
    s32 n = v->end - v->begin;
    s32 i;
    s32 m;
    s.dat = grab(&D_00659FA8);
    if (n == 1) {
        const char *nm = HSymID__GetName(v->begin[0]);
        assign(&s, nm, func_0057F260(nm));
    } else {
        m = n - 1;
        for (i = 0; i < m; i++) {
            const char *nm;
            append(&s, D_0069E018, func_0057F260(D_0069E018));
            s32 *b = v->begin;
            s32 *e = b + i;
            nm = HSymID__GetName(*e);
            append(&s, nm, func_0057F260(nm));
        }
    }
    ret->dat = grab(rep(&s));
    str_release(&s);
    return ret;
}
