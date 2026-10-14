/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef unsigned int u32;

struct Rep2 {
    u32 len;
    u32 res;
    u32 ref;
    u32 selfish;
    char *data() { return (char *)(this + 1); }
    char &operator[](u32 s) { return data()[s]; }
    inline char *grab();
    static void operator delete(void *p, u32 n);
    void release() {
        if (--ref == 0)
            operator delete(this, sizeof(Rep2) + res);
    }
};

extern "C" char *strobe__toUpper(Rep2 *r);
extern "C" void free(void *p);
extern Rep2 D_00659E20;

inline void Rep2::operator delete(void *p, u32 n) { free(p); }

inline char *Rep2::grab() {
    if (selfish)
        return strobe__toUpper(this);
    ++ref;
    return data();
}

extern "C" u32 func_0057F260(const char *s);


struct String2;
extern "C" String2 *strobe__Any__setMember(String2 *str, u32 pos, u32 n1, const char *s, u32 n2);

struct String2 {
    char *dat;
    Rep2 *rep() const { return (Rep2 *)dat - 1; }
    String2(const char *s) : dat(D_00659E20.grab()) { assign(s); }
    String2(const String2 &str) : dat(str.rep()->grab()) {}
    u32 length() const { return rep()->len; }
    char *data() const { return rep()->data(); }
    void terminate() const { (*rep())[length()] = 0; }
    ~String2() { rep()->release(); }
    String2 &replace(u32 pos, u32 n1, const char *s, u32 n2) { return *strobe__Any__setMember(this, pos, n1, s, n2); }
    String2 &assign(const char *s, u32 n) { return replace(0, (u32)-1, s, n); }
    String2 &assign(const char *s) { return assign(s, func_0057F260(s)); }
    String2 &operator=(const String2 &str) {
        if (&str != this) {
            rep()->release();
            dat = str.rep()->grab();
        }
        return *this;
    }
};


struct Any;
extern "C" const char *strobe__Any__toString(Any *, int base);
extern "C" s32 func_00478968(Any *);
extern "C" void func_004787B8(Any *, int base);
extern "C" float func_00477460(Any *);
extern "C" void func_00480638(void *, s32);
extern "C" void func_00480648(void *, const char *);
extern "C" void func_00480FA0(void *, s32);
extern "C" void func_00480FE8(String2 *);
extern char D_006AD838[];

struct Holder { char pad[8]; char *item; };

static inline const char *c_str(const String2 &s) {
    if (s.length() == 0)
        return D_006AD838;
    s.terminate();
    return s.dat;
}

extern "C" s32 *func_0047B068(s32 *out, void *obj, s32 flag, Holder *h)
{
    if (flag != 0) {
        Any *a = (Any *)(h->item - 8);
        if (func_00478968(a) != 0) {
            String2 str(strobe__Any__toString(a, 10));
            func_00480FE8(&str);
            func_00480648(obj, c_str(str));
        } else {
            func_004787B8(a, 10);
            func_00480638(obj, (s32)func_00477460(a) - 1);
        }
        func_00480FA0(h, flag);
    }
    *out = 1;
    return out;
}
