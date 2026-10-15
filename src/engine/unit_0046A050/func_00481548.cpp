/* compiler: ee-gcc2.96-stl */
/* map<Str2, Val>::operator[] (SGI STL stl_map.h) inlined; lower_bound and insert_unique stay out of line. */
#include <stl_tree.h>

extern "C" void *func_00575E60(int heap, int size);
extern "C" void free(void *p);


struct Rep {
    int len;
    int cap;
    int ref;
    int sel;
    char *data() { return (char *)(this + 1); }
    char &operator[](unsigned i) { return data()[i]; }
};

struct HeapName {
    const char *name;
};

extern "C" int func_00608D98(const void *self, const void *other, unsigned int pos, unsigned int n);
extern "C" char *strobe__toUpper(Rep *rep);
extern "C" void stl_unknown_release(void *p, int size);

/* the game's string: libstdc++ v2 basic_string (knowledge/runtime-types.md) */
extern char D_006ADE20[];
struct Traits { static char eos() { return 0; } static void assign(char &x, const char &c) { x=c; } };
struct Str2 {
    char *p;
    Rep *rep() const { return (Rep *)p - 1; }
    unsigned length() const { return rep()->len; }
    void terminate() const { Traits::assign((*rep())[length()], Traits::eos()); }
    const char *c_str() const { if (length() == 0) return D_006ADE20; terminate(); return rep()->data(); }
    static char *grab(Rep *r) {
        if (r->sel)
            return strobe__toUpper(r);
        ++r->ref;
        return (char *)(r + 1);
    }
    Str2(const Str2 &o) : p(grab(o.rep())) {}
    ~Str2() {
        Rep *r = rep();
        if (--r->ref == 0)
            free(r);
    }
    bool operator<(const Str2 &o) const { return func_00608D98(this, &o, 0, (unsigned int)-1) < 0; }
};

extern "C" void func_00476768(void *self, const void *other);
extern "C" void stl_unknown_dtor(void *self, int in_charge);

extern "C" void func_004768C0(void *self) throw();
extern "C" void func_00476A98(void *, const char *) throw();
extern "C" void func_00480F20(void *, const void *) throw();

/* the script value (named after its copy constructor, as in the map's other members) */
struct Val_00476768 {
    int type;
    int v;
    Val_00476768() : type(1) {}
    Val_00476768(const char *s) : type(1) { func_00476A98(this,s); }
    Val_00476768(const Val_00476768 &o) { func_00476768(this, &o); }
    ~Val_00476768() { func_004768C0(this); }
};

/* gcc 2.96's type_info: the name first, the vtable pointer after it */
struct TypeInfo {
    const char *name;
};

/* typeid(T).name() of the types this source allocates, without typeid: the game's own __tf getter */
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
        return (T *)func_00575E60(0x10, n * sizeof(T));
    }
    void deallocate(T *p, size_type n) {
        free(p);
    }
    size_type max_size() const throw() { return size_t(-1) / sizeof(T); }
    void construct(T *p, const T &v) { new (p) T(v); }
    void destroy(T *p) { p->~T(); }
};

typedef Str2 Key;
typedef Val_00476768 Val;
typedef pair<const Str2, Val> Value;
typedef _Rb_tree<Key, Value, _Select1st<Value>, less<Key>, GameAlloc<Value> > Tree;

extern "C" void func_00481548(const Tree *t, void *out) {
    for (Tree::const_iterator it = t->begin(); it != t->end(); ++it) {
        Val v;
        func_00476A98(&v, it->first.c_str());
        func_00480F20(out, &v);
    }
}
