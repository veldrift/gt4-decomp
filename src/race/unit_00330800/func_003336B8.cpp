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
};

struct Src {
    char pad0[4];
    s32 u4, u8, uC, u10;
    f32 f14;
    char pad18[4];
    Img img;
};

extern "C" s32 func_00575D00(void);
extern "C" void func_005CD968(void *);

static inline void body(Src *arg0, s32 k) {
    Img *s1 = &arg0->img;
    s32 pa = s1->u10 * s1->u20;
    s32 t3 = arg0->u4;
    s32 t1 = arg0->u8;
    s32 t0 = arg0->uC;
    s32 t2 = arg0->u10;
    s32 a1 = t3 * k * t1;
    s32 a3 = t0 * t2;
    pa = pa * s1->u14;
    s32 pb = s1->u18 * s1->u1C;
    s32 old = pa * pb;
    s1->f24 = arg0->f14;
    u32 s3 = a1 * a3;
    s1->u10 = t3;
    s1->u14 = t1;
    s1->u18 = t0;
    s1->u1C = t2;
    s1->u20 = k;
    u32 s2 = func_00575D00();
    if (s3 != (u32)old) {
        func_005CD968(s1);
        if (s2 >= s3) {
            s1->v.resize(s3);
        }
    }
}

extern "C" void func_003336B8(Src *arg0) {
    body(arg0, 3);
}
