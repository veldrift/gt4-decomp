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

typedef map<Str, s32, less<Str>, GameAlloc<pair<const Str, s32> > > Map;

struct MSymbolMap {
    char pad[0x30];
    Map symbols;
};

/* the output object of the symbol dump: two words and a string */
struct Out {
    s32 m0;
    s32 m4;
    Str str;
    Out() __asm__("func_0030C2C8");
};

extern "C" void func_00327338(MSymbolMap *self, Out *out);
extern "C" void func_00576788(MSymbolMap *self);
extern "C" void func_005767C0(MSymbolMap *self);

extern "C" const char *MSymbolMap__getSymbolName(MSymbolMap *self, s32 id) {
    func_00576788(self);
    Map::iterator it = self->symbols.begin();
    Map::iterator end = self->symbols.end();
    for (; it != end && (*it).second != id; it++)
        ;
    if (it == end) {
        Out out;
        func_00327338(self, &out);
    }
    const char *name = (*it).first.c_str();
    func_005767C0(self);
    return name;
}
