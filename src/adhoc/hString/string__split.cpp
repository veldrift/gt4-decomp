typedef unsigned int u32;

struct Heap { const char *name; };

extern "C" Heap *func_005C11A8(void);
extern "C" void func_00326798(void *ptr, int size, int align, const char *name);
extern "C" u32 func_0057F260(const char *s) throw();

struct Rep {
    u32 len;
    u32 res;
    u32 ref;
    u32 selfish;
    char *data() { return (char *)(this + 1); }
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

struct String {
    char *dat;
    char pad[0xC];
    Rep *rep() const { return (Rep *)dat - 1; }
    String() : dat(D_00659FA8.grab()) {}
    String(const String &str) : dat(str.rep()->grab()) {}
    ~String() { rep()->release(); }
    u32 length() const { return rep()->len; }
    String &replace(u32 pos, u32 n1, const char *s, u32 n2) { return *func_005C2630(this, pos, n1, s, n2); }
    String &append(const char *s, u32 n) { return replace(length(), 0, s, n); }
    String &append(const char *s) { return append(s, func_0057F260(s)); }
    String &assign(const char *s, u32 n) { return replace(0, (u32)-1, s, n); }
    String &assign(const char *s) { return assign(s, func_0057F260(s)); }
    String &operator=(const char *s) { return assign(s); }
    String &operator=(const String &str) {
        if (&str != this) {
            rep()->release();
            dat = str.rep()->grab();
        }
        return *this;
    }
};

inline String operator+(const String &lhs, const char *rhs) {
    String str(lhs);
    str.append(rhs);
    return str;
}


typedef int s32;
typedef unsigned char u8;
struct VEntry {
    short delta;
    short index;
    void *fn;
};
#define VCALL1(R, o, off, a) ({ VEntry *e_ = (VEntry *)(*(char **)((char *)(o) + 4) + (off)); ((R(*)(void *, ...))e_->fn)((char *)(o) + e_->delta, a); })

extern "C" void func_002ED5C0(void *arg0, int arg1);
extern "C" void *func_002EEEB0(void *ret, void *self, s32 x);
extern "C" void func_002EFBF0(void *arg0);
extern "C" void func_00309378(void *arg0, s32 arg1);
extern "C" void func_00312318(void *arg0, int arg1) throw();
extern "C" void func_00312370(void *arg0) throw();
extern "C" void func_00314B88(void *a, void *b, void *c);
extern "C" void func_003285A8(s32 p);
extern "C" void func_003285F8(s32 p);

struct H {
    void *p;
    char pad[12];
};
struct Val {
    s32 p;
    char pad[12];
};
struct Str {
    char *p;
    char pad[0xC];
};

extern "C" void string__split(s32 *arg0, s32 arg1, s32 mode, void **arg3) {
    s32 newVal;
    s32 oldVal;
    Val w;
    if (mode == 1) {
        H &h = *(H *)&w;
        Val v;
        Str s;
        func_00312370(&h);
        void *o = *arg3;
        Str *ps = &s;
        void *hp = h.p;
        VEntry *e1 = (VEntry *)(*(char **)((char *)o + 4) + 0x18);
        Val *pv = &v;
        ((void (*)(Str *, void *))e1->fn)(ps, (char *)o + e1->delta);
        func_00314B88(pv, hp, ps);
        if (arg0 != &pv->p) {
            newVal = pv->p;
            if (newVal != 0) {
                func_003285A8(newVal);
            }
            oldVal = *arg0;
            if (oldVal != 0) {
                func_003285F8(oldVal);
            }
            *arg0 = newVal;
        }
        func_002ED5C0(pv, 2);
        {
            Rep *q = (Rep *)(ps->p - 0x10);
            q->release();
        }
        func_00312318(&h, 2);
        return;
    }
    func_002EFBF0(&w);
    {
        Val t;
        func_002EEEB0(&t, (void *)w.p, arg1);
        func_00309378(&t, 2);
    }
    if (arg0 != &w.p) {
        newVal = w.p;
        if (newVal != 0) {
            func_003285A8(newVal);
        }
        oldVal = *arg0;
        if (oldVal != 0) {
            func_003285F8(oldVal);
        }
        *arg0 = newVal;
    }
    func_002ED5C0(&w, 2);
}
