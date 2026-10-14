/* compiler: ee-gcc2.96-stl */
/* mUpdateContextPS2: release every entry of a map<String, Buffers> (SGI STL, include/stl), then clear it. */
#include <stl_tree.h>
#include <stl_map.h>

typedef int s32;

struct Rep {
    s32 len;
    s32 cap;
    s32 ref;
    s32 sel;
};
struct HeapName {
    const char *name;
};

extern "C" void *func_00326750(unsigned int size, int align, const char *name);
extern "C" void func_00326798(void *p, s32 size, s32 align, const char *name);
extern "C" HeapName *func_005C11A8(void);
extern "C" int func_005C2A50(const void *self, const void *other, unsigned int pos, unsigned int n);
extern char D_0069E910[];
extern "C" char *func_005C2560(Rep *);

/* the game's string: libstdc++ v2 basic_string */
struct Str {
    char *p;
    Rep *rep() const { return (Rep *)p - 1; }
    static char *data(Rep *r) { return (char *)(r + 1); }
    s32 length() const { return rep()->len; }
    void terminate() const { data(rep())[length()] = 0; }
    const char *c_str() const {
        if (length() == 0) return D_0069E910;
        terminate();
        return data(rep());
    }
    Str(const Str &o) {
        int src = *(int *)&o.p;
        Rep *r = (Rep *)(src - 16);
        int d;
        if (r->sel != 0) d = (int)func_005C2560(r);
        else { d = src; r->ref = r->ref + 1; }
        *(int *)&p = d;
    }
    ~Str() {
        Rep *q = rep();
        if (--q->ref == 0) {
            s32 size = q->cap + 0x10;
            func_00326798(q, size, 4, func_005C11A8()->name);
        }
    }
    bool operator<(const Str &o) const { return func_005C2A50(this, &o, 0, (unsigned int)-1) < 0; }
};

struct TypeInfo {
    const char *name;
};
template <class T> struct TypeTag;

/* the game's allocator: every block is tagged with the name of its type */
template <class T>
class GameAlloc {
public:
    typedef size_t size_type;
    typedef ptrdiff_t difference_type;
    typedef T *pointer;
    typedef const T *const_pointer;
    typedef T &reference;
    typedef const T &const_reference;
    typedef T value_type;
    template <class U> struct rebind { typedef GameAlloc<U> other; };
    GameAlloc() throw() {}
    GameAlloc(const GameAlloc &) throw() {}
    template <class U> GameAlloc(const GameAlloc<U> &) throw() {}
    ~GameAlloc() throw() {}
    T *allocate(size_type n, const void * = 0) {
        return (T *)func_00326750(n * sizeof(T), 4, ((TypeInfo *)TypeTag<T>::tf())->name);
    }
    void deallocate(T *p, size_type n) {
        func_00326798(p, n * sizeof(T), 4, ((TypeInfo *)TypeTag<T>::tf())->name);
    }
    size_type max_size() const throw() { return size_t(-1) / sizeof(T); }
    void construct(T *p, const T &v) { new (p) T(v); }
    void destroy(T *p) { p->~T(); }
};

extern "C" void func_0048F2B0(void *self, int in_charge);
extern "C" void func_0048F448(void *self);
extern "C" void func_0048F270(void *);
extern "C" void func_0048F280(void *, const void *);
extern "C" void *func_0048F298(void *, const void *);

/* two owned blocks */
struct Buffers {
    void *a;
    void *b;
    Buffers() { func_0048F270(this); }
    Buffers(const Buffers &o) { func_0048F280(this, &o); }
    Buffers &operator=(const Buffers &o) { return *(Buffers *)func_0048F298(this, &o); }
    ~Buffers() { func_0048F2B0(this, 2); }
    void release() { func_0048F448(this); }
};

typedef pair<const Str, Buffers> Value;
typedef _Rb_tree_node<Value> Node;
typedef _Rb_tree<Str, Value, _Select1st<Value>, less<Str>, GameAlloc<Value> > Tree;
typedef map<Str, Buffers, less<Str>, GameAlloc<Value> > Map;

/* the tree's out-of-line _M_erase */
extern "C" void func_005D90F8(Tree *self, Node *x);
template <> inline void Tree::_M_erase(Node *x) { func_005D90F8(this, x); }

struct mUpdateContextPS2 {
    char pad[0x424];
    Map buffers;
};

extern "C" void *func_005DA140(void);
template <> struct TypeTag<Node> { static void *tf() { return func_005DA140(); } };
extern "C" Tree::iterator func_005D91C8(Tree *, const Str &);
template <> inline Tree::iterator Tree::find(const Str &key) { return func_005D91C8(this, key); }

extern "C" Tree::iterator func_005D9290(Tree *, const Str &);
template <> inline Tree::iterator Tree::lower_bound(const Str &key) { return func_005D9290(this, key); }
extern "C" Tree::iterator func_005D9310(Tree *, const Tree::iterator &, const Value &);
template <> inline Tree::iterator Tree::insert_unique(Tree::iterator pos, const Value &v) { return func_005D9310(this, pos, v); }
extern "C" void func_00213C88(mUpdateContextPS2 *self, const Str &name, const Buffers &value) {
    Map *m = &self->buffers;
    if (m->find(name) == m->end()) {
        Map::iterator it = m->lower_bound(name);
        Map::iterator end = m->end();
        char reserved[0x50];
        int need = 0;
        if (it == end || m->key_comp()(name, (*it).first)) need = 1;
        if (need)
            it = m->insert(it, Value(name, Buffers()));
        (*it).second = value;
    }
}
