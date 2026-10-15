/* compiler: ee-gcc2.96-stl */
/* SGI STL (include/stl/stl_vector.h) instantiated by tools/stl_vector.py: vector<T_005DBC00, GameAlloc> copy_ctor */
#include <stl_algobase.h>
#include <stl_alloc.h>
#include <stl_construct.h>
#include <stl_uninitialized.h>
#include <stl_vector.h>

extern "C" void *func_00326750(int size, int align, const char *name);
extern "C" void func_00326798(void *p, int size, int align, const char *name);
extern "C" void *func_00575E60(int heap, int size);
extern "C" void func_00575DA0(void *p, int size);

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

struct Sym { int id; Sym():id(0){} Sym(const Sym&o):id(o.id){} ~Sym(){} Sym&operator=(const Sym&o){if(this!=&o)id=o.id;return *this;} };
extern "C" void *HSymID__tf(void);
template <> struct TypeTag<Sym> { static void *tf() { return HSymID__tf(); } };
typedef vector<Sym,GameAlloc<Sym> > Vec;
template<> Sym* __uninitialized_fill_n_aux(Sym*,unsigned,const Sym&,__false_type) __asm__("func_005EE170");
struct Holder { Vec v; Holder(const Sym*x) __asm__("func_0030F6B0"); };
Holder::Holder(const Sym*x):v((Vec::size_type)1){v[0]=*x;}
