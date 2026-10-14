/* compiler: ee-gcc2.96-nogcse */
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

struct String;
extern "C" String *func_005C2630(String *str, u32 pos, u32 n1, const char *s, u32 n2);
extern "C" String *func_005CE388(String *str, u32 pos1, u32 n1, const String *s, u32 pos2, u32 n2);
extern char D_006957A8[]; /* "" */

struct String {
    char *dat;
    char pad[0xC];
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
    String &replace(u32 pos, u32 n1, const char *s, u32 n2) { return *func_005C2630(this, pos, n1, s, n2); }
    String &replace(u32 pos1, u32 n1, const String &str, u32 pos2, u32 n2) {
        return *func_005CE388(this, pos1, n1, &str, pos2, n2);
    }
    String &append(const String &str, u32 pos = 0, u32 n = (u32)-1) { return replace(length(), 0, str, pos, n); }
    String &append(const char *s, u32 n) { return replace(length(), 0, s, n); }
    String &append(const char *s) { return append(s, func_0057F260(s)); }
    String &assign(const String &str, u32 pos = 0, u32 n = (u32)-1) { return replace(0, (u32)-1, str, pos, n); }
    String &assign(const char *s, u32 n) { return replace(0, (u32)-1, s, n); }
    String &assign(const char *s) { return assign(s, func_0057F260(s)); }
};

extern "C" void func_004EA398(void *);
extern "C" int func_001D94F0(void *, int, void *) throw();
extern "C" int func_001D9A80(void *) throw();
extern "C" void func_001D9AE0(String *, void *) throw();
extern "C" void func_00208EE8(void *, const int &);
extern "C" void func_00208F00(void *, const void *);
extern "C" void func_0026C458(void *, int);
extern "C" void func_0026CB90(void *);
extern "C" int func_0026D320(void *, const char *, int, int);

static inline void parse(void *obj, const String &s) {
    const char *cs = s.c_str();
    func_0026D320(obj, cs, s.length(), 1);
}

static inline void close_conn(void *p) { func_004EA398(p); }

struct Self { char pad0[0x10]; char sub[0x54]; String name; };

extern "C" void *func_001DA628(void *arg0, Self *arg1, int arg2, void *arg3) {
    String h;
    if (func_001D94F0((void *)arg1, arg2, arg3) == 0) {
        func_00208EE8(arg0, 0);
        return arg0;
    }
    if (func_001D9A80((void *)arg1) == 0) {
        {
            func_001D9AE0(&h, (void *)arg1);
            h.rep()->release();
        }
        func_00208EE8(arg0, 0);
        return arg0;
    }
    {
        func_0026CB90(&h);
        void *obj = h.dat;
        String *name = &arg1->name;
        const char *cs = name->c_str();
        int len = name->length();
        arg1 = (Self *)arg1->sub;
        func_0026D320(obj, cs, len, 1);
        close_conn(arg1);
        func_00208F00(arg0, h.dat + 0x10);
        func_0026C458(&h, 2);
    }
    return arg0;
}
