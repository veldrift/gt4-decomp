/* compiler: ee-gcc2.96-no-strict-aliasing */
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

extern "C" void func_00304210(void *arg0) throw();
extern "C" void func_003041B8(void *arg0, int arg1) throw();
extern "C" const char *hModule__getName(void *node);
extern "C" void func_00312318(void *arg0, int arg1);
extern "C" void func_00323D08(void *arg0);
extern "C" void func_00323B60(void *arg0, int arg1);
extern "C" void func_002FC870(void *arg0, int arg1);
extern "C" void func_002FE278(void *arg0, int arg1);
extern "C" s32 HSymID__GetID(void *arg0);
extern "C" u8 *func_00314920(s32 arg0);
extern "C" void func_00314B20(void *arg0, void *arg1);
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

extern "C" void Module__defined(s32 *arg0, s32 arg1, s32 mode, void **arg3) {
    s32 newVal;
    s32 oldVal;
    H h;
    if (mode == 1) {
        Val o10;
        Val v20;
        Str s30;
        func_00304210(&h);
        Val *po = &o10;
        func_00323D08(po);
        void *o = *arg3;
        VEntry *e1 = (VEntry *)(*(char **)((char *)o + 4) + 0x18);
        VEntry *e2 = (VEntry *)(*(char **)((char *)h.p + 4) + 0x198);
        char *rcv2 = (char *)h.p + e2->delta;
        Val *pv = &v20;
        Str *ps = &s30;
        ((void (*)(Str *, void *))e1->fn)(ps, (char *)o + e1->delta);
        pv->p = HSymID__GetID(ps);
        ((void (*)(void *, void *, void *))e2->fn)(rcv2, po, pv);
        {
            Rep *q = (Rep *)(ps->p - 0x10);
            q->release();
        }
        func_002FE278(pv, po->p != 0);
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
        func_002FC870(pv, 2);
        func_00323B60(po, 2);
        func_003041B8(&h, 2);
    }
}
