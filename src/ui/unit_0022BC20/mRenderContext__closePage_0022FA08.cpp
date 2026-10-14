/* compiler: ee-gcc2.96-stl */
/* SGI STL (include/stl/stl_vector.h) instantiated by tools/stl_vector.py: vector<int, GameAlloc> insert_fill */
#include <stl_algobase.h>
#include <stl_alloc.h>
#include <stl_construct.h>
#include <stl_uninitialized.h>
#include <stl_vector.h>

extern "C" void *func_00326750(int size, int align, const char *name);
extern "C" void func_00326798(void *p, int size, int align, const char *name);
extern "C" void *func_00575E60(int heap, int size);
extern "C" void free(void *p, int size);

/* gcc 2.96's type_info: the name first, the vtable pointer after it */
struct TypeInfo {
    const char *name;
};

/* typeid(T).name() without typeid: the game's own __tf getter */
template <class T> struct TypeTag;

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

typedef void *Elem;
extern "C" void *func_005DB330(void);
template <> struct TypeTag<Elem> { static void *tf() { return func_005DB330(); } };
typedef vector<Elem, GameAlloc<Elem> > Vec;

struct VE { short delta; short idx; void (*fn)(void *, void *); };
extern "C" void mUpdateContext__Sync(int);
extern "C" void func_0022F080(void *, void *) throw();
extern "C" void func_0022F178(void *, void *) throw();
extern "C" void func_0022F248(char *, int) throw();
extern "C" void func_0022F2F8(char *, int) throw();
extern "C" void func_0022F3A8(char *, int) throw();
extern "C" void IfRootEvent__structor_0(void *, void *) throw();
extern "C" void func_00233D18(void *);
extern "C" void func_00327970(void);

extern "C" void mRenderContext__closePage(char *self, char *obj) {
    *(int *)(self + 0x6DC) = 0;
    Vec v(1);
    v[0] = obj;
    IfRootEvent__structor_0(self, &v);
    func_00233D18(obj);
    mUpdateContext__Sync(2);
    VE *e = (VE *)(*(char **)(obj + 4) + 0x2D8);
    e->fn(obj + e->delta, self);
    func_0022F080(self, 0);
    func_0022F178(self, 0);
    func_0022F248(self, 0);
    func_0022F3A8(self, 0);
    func_0022F2F8(self, 0);
    func_00327970();
    *(int *)(self + 0x6DC) = 1;
}
