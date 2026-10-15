/* compiler: ee-gcc2.96-stl */
/* SGI STL (include/stl/stl_vector.h) instantiated by tools/stl_vector.py: vector<signed char, PlainAlloc40> insert_fill */
#include <stl_algobase.h>
#include <stl_alloc.h>
#include <stl_construct.h>
#include <stl_uninitialized.h>
#include <stl_vector.h>

extern "C" void *func_00326750(int size, int align, const char *name);
extern "C" void func_00326798(void *p, int size, int align, const char *name);
extern "C" void *func_00575E60(int heap, int size);
extern "C" void free(void *) throw();

/* gcc 2.96's type_info: the name first, the vtable pointer after it */
struct TypeInfo {
    const char *name;
};

/* typeid(T).name() without typeid: the game's own __tf getter */
template <class T> struct TypeTag;

template <class T>
class PlainAlloc40 {
public:
    typedef size_t size_type;
    typedef ptrdiff_t difference_type;
    typedef T *pointer;
    typedef const T *const_pointer;
    typedef T &reference;
    typedef const T &const_reference;
    typedef T value_type;
    template <class U> struct rebind { typedef PlainAlloc40<U> other; };
    PlainAlloc40() throw() {}
    PlainAlloc40(const PlainAlloc40 &) throw() {}
    template <class U> PlainAlloc40(const PlainAlloc40<U> &) throw() {}
    ~PlainAlloc40() throw() {}
    T *allocate(size_type n, const void * = 0) {
        return n == 0 ? 0 : (T *)func_00575E60(0x40, n * sizeof(T));
    }
    void deallocate(T *p, size_type n) {
        free(p);
    }
    size_type max_size() const throw() { return size_t(-1) / sizeof(T); }
    void construct(T *p, const T &v) { new (p) T(v); }
    void destroy(T *p) { p->~T(); }
};

typedef signed char Elem;
typedef vector<Elem, PlainAlloc40<Elem> > Vec;

typedef int s32;
typedef float f32;
typedef unsigned int u32;

struct Img {
    Vec v;
    s32 u10, u14, u18, u1C, u20;
    f32 f24;
    s32 u28;
};

extern "C" s32 func_00575D00(void);
extern "C" void func_005CD968(void *);

struct Raw { s32 p0, st, fin, eos; };

static inline void body(Img *s1, u32 n) {
    s1->f24 = 0x1.555554p0f;
    s1->u10 = 0x40;
    s1->u18 = 1;
    s1->u14 = 0x40;
    s1->u1C = 1;
    s1->u20 = 2;
    ((Raw *)&s1->v)->st = 0;
    ((Raw *)&s1->v)->fin = 0;
    ((Raw *)&s1->v)->eos = 0;
    s1->u28 = 0;
    u32 s0 = func_00575D00();
    func_005CD968(s1);
    if (s0 >= n) {
        s1->v.resize(n);
    }
}

extern "C" void func_003309F0(Img *s1) {
    s32 spare[4];
    body(s1, 0x2000);
    spare[0] = 0;
}
