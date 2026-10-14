/* compiler: ee-gcc2.96-no-strict-aliasing */
/* Unless *(a1 + 0x188) is set: formats *(a1 + 0x1CC) into a buffer (func_0057DA20), builds
 * D_00695900 + String(a1 + 0x18C) + D_00695908 + String(buf) + D_00695910 and passes it, as a
 * string of the second basic_string instantiation (nilRep D_00659E20, clone strobe__toUpper,
 * replace strobe__Any__setMember, operator delete free), to func_004EC078(a0 + 0x10 + 0xA8).
 * gcc 2.96 bastring.h members inline: constructors, destructor, append, operator+, c_str(). */
typedef unsigned int u32;

struct Heap { const char *name; };

extern "C" Heap *func_005C11A8(void);
extern "C" void func_00326798(void *ptr, int size, int align, const char *name);
extern "C" u32 func_0057F260(const char *s);

struct Rep {
    u32 len;
    u32 res;
    u32 ref;
    u32 selfish;
    char *data() { return (char *)(this + 1); }
    char &operator[](u32 s) { return data()[s]; }
    inline char *grab();
    static void operator delete(void *p, u32 n) { func_00326798(p, n, 4, func_005C11A8()->name); }
    void release() {
        if (--ref == 0)
            operator delete(this, sizeof(Rep) + res);
    }
};

extern "C" char *func_005C2560(Rep *r);
extern Rep D_00659FA8;

inline char *Rep::grab() {
    if (selfish)
        return func_005C2560(this);
    ++ref;
    return data();
}

extern char D_006957A8[];
struct String { char *dat; char pad[0xC];
    Rep *rep() const { return (Rep *)dat - 1; }
    u32 length() const { return rep()->len; }
    char *data() const { return rep()->data(); }
    void terminate() const { (*rep())[length()] = 0; }
    const char *c_str() const {
        if (length() == 0)
            return D_006957A8;
        terminate();
        return data();
    }
};
struct Rep2 {
    u32 len;
    u32 res;
    u32 ref;
    u32 selfish;
    char *data() { return (char *)(this + 1); }
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

struct String2;
extern "C" String2 *strobe__Any__setMember(String2 *str, u32 pos, u32 n1, const char *s, u32 n2);

struct String2 {
    char *dat;
    char pad[0xC];
    Rep2 *rep() const { return (Rep2 *)dat - 1; }
    String2(const char *s) : dat(D_00659E20.grab()) { assign(s); }
    ~String2() { rep()->release(); }
    String2 &replace(u32 pos, u32 n1, const char *s, u32 n2) { return *strobe__Any__setMember(this, pos, n1, s, n2); }
    String2 &assign(const char *s, u32 n) { return replace(0, (u32)-1, s, n); }
    String2 &assign(const char *s) { return assign(s, func_0057F260(s)); }
};

extern "C" int func_004EC078(void *obj, String2 *s);
extern "C" int func_004EA1B0(void *);
extern "C" int func_004EA2B8(void *);
extern "C" void func_001D93A8(int, void *);



extern "C" int func_001D93C0(char *a0, String *a1) {
    char *p = a0 + 0x10;
    *(void **)(p + 0x18) = (void *)func_001D93A8;
    *(int *)(p + 0x10) = 0;
    *(char **)(p + 0x14) = a0;
    *(char **)(p + 0x1C) = a0;
    *(int *)(p + 0) = 0;
    int r;
    char padv[16];
    const char *c = a1->c_str();
    {
        String2 t(c);
        r = func_004EC078(p + 0x90, &t);
    }
    if (r == 0)
        return 0;
    int v = func_004EA1B0(p);
    if (v == 0)
        return v;
    *(int *)(a0 + 0x108) = 0;
    *(int *)(a0 + 0x10C) = 0;
    return func_004EA2B8(p) != 0;
}
