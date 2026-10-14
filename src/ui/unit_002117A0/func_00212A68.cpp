/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned int u32;
typedef int s32;
typedef unsigned int size_t;
struct Heap { const char *name; };
extern "C" Heap *func_005C11A8(void) throw();
extern "C" void func_00326798(void *ptr, size_t size, size_t align, const char *name) throw();
extern "C" size_t func_0057F260(const char *s) throw();
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


struct Obj { int a; char *vt; };
extern "C" const char *hModule__getName(Obj *);
extern "C" Obj *func_00206868(Obj *);
extern "C" Obj *func_0025C300(Obj *);
extern "C" void func_003285A8(Obj *);
extern "C" void func_003285F8(Obj *);
struct H;
extern "C" void func_002556B0(H *);
extern "C" H *func_002550A0(H *, const H *);
extern "C" void func_00255088(H *, Obj *const *);
extern "C" void func_002550B8(H *, s32);
struct H {
    Obj *p;
    H() { func_002556B0(this); }
    H(const H &o) { func_002550A0(this,&o); }
    H(Obj *const &o) { func_00255088(this,&o); }
    ~H() { func_002550B8(this,2); }
    H &operator=(const H &o) {
        if (this != &o) {
            Obj *p = o.p;
            if (p) func_003285A8(p);
            if (this->p) func_003285F8(this->p);
            this->p = p;
        }
        return *this;
    }
};
struct Pair { String key; H val; Pair(const String &s,const H &h):key(s),val(h) {} };
struct Node { int a; Node *parent,*left,*right; Pair v; };
struct Iter {
    Node *p;
    Iter(Node *n):p(n) {}
    Iter(const Iter &o):p(o.p) {}
    Iter &operator=(const Iter &o) {p=o.p;return *this;}
};
struct Map;
extern "C" Iter func_005D8D98(Map *, const String &) asm("func_005D8D98");
extern "C" Iter func_005D8E18(Map *, Iter, const Pair &) asm("func_005D8E18");
extern "C" s32 func_005C2A50(const String *,const String *,u32,u32);
struct Map {
    int count; Node *header;
    Iter lower_bound(const String &s) {return func_005D8D98(this,s);}
    Iter end() {return Iter(header);}
    Iter insert(Iter pos,const Pair &v) { return func_005D8E18(this,pos,v); }
    H &operator[](const String &k) {
        Iter i = lower_bound(k);
        if (i.p == end().p || func_005C2A50(&k,&i.p->v.key,0,-1) < 0)
            i = insert(i,Pair(k,H()));
        return i.p->v.val;
    }
};
static inline String &append_n(String &s,const char *p,size_t n) {s.replace(s.length(),0,p,n);return s;}
static inline String &append(String &s,const char *p) {return append_n(s,p,traits::length(p));}
static inline String operator+(const String &a,const char *p) {String t(a);return append(t,p);}
struct Self { char pad[0x10]; Map map; };
struct VEnt { short delta; short index; int (*fn)(void *); };
extern char D_00697A58[];

inline void *operator new(size_t, void *p) { return p; }
extern "C" void func_005D8D98_raw(Iter *,Map *,const String *) asm("func_005D8D98");
extern "C" void func_005D8E18_raw(Iter *,Map *,Iter *,const Pair *) asm("func_005D8E18");
extern "C" void func_00212A68(Self *arg0, Obj *arg1, const String *arg2) {
    struct Scratch { char key[16],tmp[16],end[16],ins[16],pos[16],pair[16],h[16],param[16],ptr[16]; } st;
    const char *n = hModule__getName(arg1);
    String *ps = (String*)st.tmp;
    new (ps) String(*arg2);
    append(*ps,n);
    new (st.key) String(*ps);
    ps->~String();
    Map *map = &arg0->map;
    Iter *pi = (Iter*)ps;
    func_005D8D98_raw(pi,map,(String*)st.key);
    H *ph = (H*)st.end;
    *(Node**)ph = map->header;
    int add = 0;
    if (pi->p == *(Node**)ph || func_005C2A50((String*)st.key,&pi->p->v.key,0,-1)<0) add=1;
    if (add) {
        Iter *pos = (Iter*)st.pos;
        pos->p = pi->p;
        Pair *p = (Pair*)st.pair;
        H *empty = new (st.h) H;
        new (p) Pair(*(String*)st.key,*empty);
        Iter *param = (Iter*)st.param;
        param->p = pos->p;
        func_005D8E18_raw((Iter*)st.ins,map,param,p);
        ((Iter*)st.tmp)->p = ((Iter*)st.ins)->p;
        func_002550B8((H*)(st.pair+4),2);
        p->key.~String();
        empty->~H();
    }
    H *dest = &pi->p->v.val;
    *(Obj**)st.ptr = arg1;
    func_00255088(ph,(Obj**)st.ptr);
    *dest = *ph;
    ph->~H();
    VEnt *e = (VEnt *)(arg1->vt+0x1B0);
    if (e->fn((char*)arg1+e->delta)) {
        append(*(String*)st.key,D_00697A58);
        Obj *child = func_00206868(arg1);
        while (child) {
            func_00212A68(arg0,child,(String*)st.key);
            child = func_0025C300(child);
        }
    }
    ((String*)st.key)->~String();
}
