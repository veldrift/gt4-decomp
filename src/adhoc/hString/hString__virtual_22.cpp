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
typedef unsigned int u32;
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
extern "C" void func_00314B20(void *a, void *b);
extern "C" void *func_005CB368(void *str, u32 pos, u32 n1, u32 n2, char c);
extern "C" u32 func_005F00D0(const void *str, const char *s, u32 pos, u32 n);
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

extern "C" void hString__virtual_22(void *self, s32 *out, void **objA, void *a3, void **objB) {
    s32 newVal;
    s32 oldVal;
    Str sA;
    Str sB;
    VEntry *e1 = (VEntry *)(*(char **)((char *)*objA + 4) + 0x18);
    ((void (*)(Str *, void *))e1->fn)(&sA, (char *)*objA + e1->delta);
    VEntry *e2 = (VEntry *)(*(char **)((char *)*objB + 4) + 0x18);
    Str *pb = &sB;
    ((void (*)(Str *, void *))e2->fn)(pb, (char *)*objB + e2->delta);
    u32 idx = func_005F00D0(&sA, pb->p, 0, *(u32 *)(pb->p - 0x10));
    if (idx == (u32)-1) {
        if (out != (s32 *)objA) {
            newVal = *(s32 *)objA;
            if (newVal != 0) {
                func_003285A8(newVal);
            }
            oldVal = *out;
            if (oldVal != 0) {
                func_003285F8(oldVal);
            }
            *out = newVal;
        }
    } else {
        void *r = func_005CB368(&sA, idx, *(u32 *)(pb->p - 0x10), 0, 0);
        Val tmp;
        Val *pt = &tmp;
        func_00314B20(pt, r);
        if (out != &pt->p) {
            newVal = pt->p;
            if (newVal != 0) {
                func_003285A8(newVal);
            }
            oldVal = *out;
            if (oldVal != 0) {
                func_003285F8(oldVal);
            }
            *out = newVal;
        }
        func_00312318(pt, 2);
    }
    {
        Rep *q = (Rep *)(pb->p - 0x10);
        q->release();
    }
    {
        Rep *q = (Rep *)(sA.p - 0x10);
        q->release();
    }
}
