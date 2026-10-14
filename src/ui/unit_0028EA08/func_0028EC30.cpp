/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef short s16;
typedef unsigned int u32;

struct S00659988 { const char *name; };
extern char D_0069B0D8[], D_0069B0D0[];
extern "C" void HOutput__printf(void *, const char *, ...);
extern "C" void func_00326798(void *, s32, s32, const char *);
extern "C" struct S00659988 *func_005C11A8(void);

struct Traits {
    static void assign(char &c1, const char &c2) { c1 = c2; }
};
struct Str {
    struct Rep {
        u32 len, res, ref;
        s32 selfish;
        char *data() { return (char *)(this + 1); }
        char &operator[](u32 s) { return data()[s]; }
        static void deallocate(void *p, u32 n) { func_00326798(p, n, 4, func_005C11A8()->name); }
        static void operator delete(void *p) { deallocate(p, ((Rep *)p)->res + sizeof(Rep)); }
        void release() { if (--ref == 0) delete this; }
    };
    char *dat;
    Rep *rep() const { return ((Rep *)dat) - 1; }
    char *data() const { return rep()->data(); }
    u32 length() const { return rep()->len; }
    static char eos() { return char(); }
    void terminate() const { Traits::assign((*rep())[length()], eos()); }
    const char *c_str() const {
        if (length() == 0) return D_0069B0D0;
        terminate();
        return data();
    }
    Str() {}
    Str(const Str &o) { dat = o.dat; }
    ~Str() { rep()->release(); }
};
struct Item;
struct NodeBase { NodeBase *next; NodeBase *prev; };
struct Node : public NodeBase { Item *data; };
struct IterBase {
    NodeBase *node;
    IterBase(NodeBase *x) : node(x) {}
    IterBase() {}
    void incr() { node = node->next; }
    bool operator!=(const IterBase &x) const { return node != x.node; }
};
struct Iter : public IterBase {
    Iter(Node *x) : IterBase(x) {}
    Iter() {}
    Iter(const Iter &x) : IterBase(x.node) {}
    Item *&operator*() const { return ((Node *)node)->data; }
    Iter &operator++() { incr(); return *this; }
    Iter operator++(int) { Iter tmp = *this; incr(); return tmp; }
};
struct List {
    Node *node;
    Iter begin() { return (Node *)(node->next); }
    Iter end() { return node; }
};
struct E { s16 delta; s16 index; Str (*fn)(void *); };
struct Item {
    char pad[4]; char *vtbl;
    Str name() { E *e = (E *)(vtbl + 0x18); return e->fn((char *)this + e->delta); }
};
struct Self { s32 pad; List list; };

extern "C" void func_0028EC30(Self *self, void *arg1) {
    Iter it = self->list.begin();
    Iter end = self->list.end();
    for (; it != end; it++) {
        Str s = (*it)->name();
        HOutput__printf(arg1, D_0069B0D8, s.c_str());
    }
}
