/* compiler: ee-gcc2.96-stl */
#include <stl_algobase.h>
#include <stl_alloc.h>
#include <stl_construct.h>
#include <stl_uninitialized.h>
#include <stl_vector.h>

typedef int s32;
typedef signed char u8;
typedef unsigned int u32;

struct Arg {
    char pad0[4];
    u8 *u4;
    char pad8[8];
    s32 u10;
    s32 u14;
    s32 u18;
    s32 u1C;
    s32 u20;
};

extern "C" void free(void *) throw();
extern "C" void *func_00575E60(s32, s32);
extern "C" void *func_005A4724(void *, const void *, u32);
extern "C" void *func_005A47D4(void *, const void *, u32);

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
    void deallocate(T *p, size_type n) {
        free(p);
    }
    size_type max_size() const throw() { return size_t(-1) / sizeof(T); }
    void construct(T *p, const T &v) { new (p) T(v); }
    void destroy(T *p) { p->~T(); }
};

typedef vector<u8, Alloc<u8> > Vec;

extern "C" void func_003311B8(Arg *arg0) {
    s32 n = arg0->u10 * arg0->u18 * arg0->u20;
    Vec v((Vec::size_type)n);
    s32 size = arg0->u20;
    s32 stride = arg0->u10 * size;
    s32 cnt = arg0->u14 * arg0->u1C;
    for (s32 fp = 0; fp < cnt; fp++) {
        u8 *dst = v.begin();
        u8 *row = arg0->u4 + fp * n;
        for (s32 i = 0; i < arg0->u10; i++, row += arg0->u20) {
            u8 *src = row;
            for (s32 j = 0; j < arg0->u18; j++) {
                dst = copy(src, src + arg0->u20, dst);
                src += stride;
            }
        }
        func_005A4724(arg0->u4 + fp * n, v.begin(), n);
    }
}
