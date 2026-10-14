/* compiler: ee-gcc2.96-stl */
#include <stl_algobase.h>
#include <stl_alloc.h>
#include <stl_construct.h>
#include <stl_uninitialized.h>
#include <stl_vector.h>

typedef int s32;
extern "C" void *func_00326750(unsigned int size, int align, const char *name);
extern "C" void func_00326798(void *p, int size, int align, const char *name);
extern "C" void free(void *p, int size);

struct TypeInfo {
    const char *name;
};
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

struct Elem { int v; Elem() {} Elem(const Elem &o) : v(o.v) {} ~Elem() {} };
extern "C" void *HSymID__tf(void);
template <> struct TypeTag<Elem> { static void *tf() { return HSymID__tf(); } };
typedef vector<Elem, GameAlloc<Elem> > Vec;

struct S_0025C298;
extern "C" S_0025C298 *func_0025C298(S_0025C298 *);
extern "C" Elem *func_00305548(S_0025C298 *);

extern "C" void func_002350C8(Vec *v, unsigned n, S_0025C298 *p, S_0025C298 *q) {
    if (p != 0 && p != q) {
        S_0025C298 *r = func_0025C298(p);
        func_002350C8(v, n + 1, r, q);
        v->push_back(*func_00305548(p));
        return;
    }
    v->reserve(n);
}
