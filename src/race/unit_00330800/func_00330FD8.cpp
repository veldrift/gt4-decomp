/* compiler: ee-gcc2.96-stl */
#include <stl_algobase.h>
#include <stl_alloc.h>
#include <stl_construct.h>
#include <stl_uninitialized.h>
#include <stl_vector.h>

typedef int s32;

extern "C" void *func_00575E60(int heap, int size);
extern "C" void free(void *) throw();

template <class T>
class Alloc {
public:
    typedef size_t size_type;
    typedef ptrdiff_t difference_type;
    typedef T *pointer;
    typedef const T *const_pointer;
    typedef T &reference;
    typedef const T &const_reference;
    typedef T value_type;
    template <class U> struct rebind { typedef Alloc<U> other; };
    Alloc() throw() {}
    Alloc(const Alloc &) throw() {}
    template <class U> Alloc(const Alloc<U> &) throw() {}
    ~Alloc() throw() {}
    T *allocate(size_type n, const void * = 0) {
        return n == 0 ? 0 : (T *)func_00575E60(0x10, n * sizeof(T));
    }
    void deallocate(T *p, size_type n) { free(p); }
    size_type max_size() const throw() { return size_t(-1) / sizeof(T); }
    void construct(T *p, const T &v) { new (p) T(v); }
    void destroy(T *p) { p->~T(); }
};

typedef vector<char, Alloc<char> > Vec;

extern "C" void *func_005A4724(void *, const void *, unsigned int);
extern "C" void func_003331C8(s32, s32, s32, s32, s32, void *, void *);

extern "C" void func_00330FD8(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    Vec v((Vec::size_type)(arg4 * arg3 * arg2));
    func_003331C8(arg0, arg1, arg2, arg3, arg4, &v, (void *)func_005A4724);
}
