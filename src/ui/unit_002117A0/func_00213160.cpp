/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned int u32;
typedef int s32;
typedef unsigned int size_t;
struct Heap { const char *name; };
extern "C" Heap *func_005C11A8(void);
extern "C" void func_00326798(void *ptr, size_t size, size_t align, const char *name);
extern "C" size_t func_0057F260(const char *s);
struct Rep;
extern "C" char *func_005C2560(Rep *r);
struct traits {
    static size_t length(const char *s) { return func_0057F260(s); }
};
struct Rep {
    size_t len, res, ref;
    bool selfish;
    char *data() { return reinterpret_cast<char *>(this + 1); }
    char *grab() { if (selfish) return clone(); ++ref; return data(); }
    void release() { if (--ref == 0) delete this; }
    inline static void operator delete(void *);
    char *clone() { return func_005C2560(this); }
};
extern Rep D_00659FA8;
struct String;
extern "C" String *func_005C2630(String *str, size_t pos, size_t n1, const char *s, size_t n2);
struct String {
    char *dat;
    Rep *rep() const { return reinterpret_cast<Rep *>(dat) - 1; }
    String &replace(size_t pos, size_t n1, const char *s, size_t n2) { return *func_005C2630(this, pos, n1, s, n2); }
    String &assign(const char *s, size_t n) { return replace(0, (size_t)-1, s, n); }
    String &assign(const char *s) { return assign(s, traits::length(s)); }
    String(): dat(D_00659FA8.grab()) {}
    String(const String &str): dat(str.rep()->grab()) {}
    String(const char *s, size_t n): dat(D_00659FA8.grab()) { assign(s, n); }
    String(const char *s): dat(D_00659FA8.grab()) { assign(s); }
    ~String() { rep()->release(); }
    String &operator=(const String &str) {
        if (&str != this) { rep()->release(); dat = str.rep()->grab(); }
        return *this;
    }
    String &operator=(const char *s) { return assign(s); }
    s32 length() const { return rep()->len; }
};
struct GameAlloc {
    static void deallocate(void *p, size_t n) { func_00326798(p, n, 4, func_005C11A8()->name); }
};
inline void Rep::operator delete(void *ptr) {
    GameAlloc::deallocate(ptr, sizeof(Rep) + reinterpret_cast<Rep *>(ptr)->res);
}

extern "C" void func_005CE388(String *, s32, s32, const String *, s32, s32);
extern "C" s32 func_005C2A50(const String *, const String *, u32, u32);
extern "C" s32 func_0030D8E0(String *);
struct H;
extern "C" H *func_002ECDE0(H *);
extern "C" void func_002EA590(H *, s32);
struct H { s32 v; H() { func_002ECDE0(this); } ~H() { func_002EA590(this,2); } };
extern "C" String *func_002EC3D0(String *, s32);

static inline String &append(String &a,const String &b) { func_005CE388(&a,a.length(),0,&b,0,-1); return a; }
static inline String operator+(const String &a,const String &b) { String t(a); append(t,b); return t; }
extern "C" String func_002EC3D0_value(s32) asm("func_002EC3D0");

inline void *operator new(size_t, void *p) { return p; }
static inline s32 compare_suffix(String *p,const String &a,const String &b,s32 pos,s32 n) {
    new (p) String();
    func_005CE388(p,0,-1,&a,pos,n);
    s32 result = func_005C2A50(p,&b,0,-1) != 0;
    p->~String();
    return result;
}
extern "C" String *func_00213160(String *out, const String *a, const String *b) {
    s32 n = b->length();
    s32 m = a->length();
    String s(*a);
    union { char partial[sizeof(String)]; char h[sizeof(H)]; } u;
    if (m < n || compare_suffix((String*)u.partial,*a,*b,m-n,n)) append(s,*b);
    if (!func_0030D8E0(&s)) {
        H *h = new (u.h) H;
        s = func_002EC3D0_value(h->v) + s;
        h->~H();
    }
    new (out) String(s);
    return out;
}
