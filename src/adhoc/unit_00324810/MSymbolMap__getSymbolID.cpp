/* compiler: ee-gcc2.96-stl */
/* MSymbolMap::getSymbolName(id): a linear search of map<String, int> by value (SGI STL, include/stl),
   with the symbol dump when the id is unknown. */
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

extern "C" void *func_00326750(unsigned int size, int align, const char *name) throw();
extern "C" void func_00326798(void *p, s32 size, s32 align, const char *name) throw();
extern "C" HeapName *func_005C11A8(void);
extern "C" int func_005C2A50(const void *self, const void *other, unsigned int pos, unsigned int n);
extern char D_0069E910[];

/* the game's string: libstdc++ v2 basic_string */
extern "C" char *func_005C2560(Rep *);
struct Str {
    char *p;
    static char *grab(Rep *r, char *p) { if (r->sel) return func_005C2560(r); ++r->ref; return p; }
    Str(const Str &o) { p = grab(o.rep(), o.p); }
    Rep *rep() const { return (Rep *)p - 1; }
    static char *data(Rep *r) { return (char *)(r + 1); }
    s32 length() const { return rep()->len; }
    void terminate() const { data(rep())[length()] = 0; }
    const char *c_str() const {
        if (length() == 0) return D_0069E910;
        terminate();
        return data(rep());
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

typedef pair<const Str, s32> Value;
typedef _Rb_tree<Str, Value, _Select1st<Value>, less<Str>, GameAlloc<Value> > Tree;
typedef map<Str, s32, less<Str>, GameAlloc<Value> > Map;
extern "C" Tree::iterator func_005F1CA0(Tree *, const Str &);
extern "C" Tree::iterator func_005F1D68(Tree *, const Str &);
extern "C" Tree::iterator func_005F1DE8(Tree *, const Tree::iterator &, const Value &);
template <> inline Tree::iterator Tree::find(const Str &k) { return func_005F1CA0(this, k); }
template <> inline Tree::iterator Tree::lower_bound(const Str &k) { return func_005F1D68(this, k); }
template <> inline Tree::iterator Tree::insert_unique(Tree::iterator i, const Value &v) { return func_005F1DE8(this, i, v); }
struct MSymbolMap { char pad[0x30]; Map symbols; s32 counter; };
extern "C" void func_00576788(MSymbolMap *);
extern "C" void func_005767C0(MSymbolMap *);
extern "C" s32 MSymbolMap__getSymbolID(MSymbolMap *self, const Str &k) {
    func_00576788(self);
    Map::iterator it = self->symbols.find(k);
    s32 r;
    if (it == self->symbols.end()) {
        r = self->counter++;
        self->symbols[k] = r;
    } else {
        r = it->second;
    }
    func_005767C0(self);
    return r;
}
