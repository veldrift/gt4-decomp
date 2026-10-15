/* compiler: ee-gcc2.96-stl */
void func_00575DA0(void *) throw();
#include <stl_algobase.h>
#include <stl_alloc.h>
#include <stl_construct.h>
#include <stl_uninitialized.h>
#include <stl_vector.h>

typedef int s32;

extern "C" void *func_00575E60(int heap, int size);

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
    void deallocate(T *p, size_type n) { func_00575DA0(p); }
    size_type max_size() const throw() { return size_t(-1) / sizeof(T); }
    void construct(T *p, const T &v) { new (p) T(v); }
    void destroy(T *p) { p->~T(); }
};

typedef vector<unsigned char, Alloc<unsigned char> > Vec;

template <> unsigned char *fill_n<unsigned char *, unsigned int, unsigned char>(unsigned char *, unsigned int, const unsigned char &) __asm__("func_005CDDB8");

extern "C" s32 func_0041B268(void *);
extern "C" void func_0041B2E0(void *, void *);
extern "C" void GT4Model__BinStreamWriter__write8u(void *, s32);

extern "C" void func_00339970(void *arg0, void *arg1) {
    s32 n = func_0041B268(arg1);
    Vec v((Vec::size_type)n);
    func_0041B2E0(arg1, &v[0]);
    for (s32 i = 0; i < n; i++) {
        GT4Model__BinStreamWriter__write8u(arg0, v[i]);
    }
}
