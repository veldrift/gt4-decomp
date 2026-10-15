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

struct Dim { s32 w, h, a; };
struct Range { s32 size; char *start; };

extern "C" void func_00332740(s32, char *, s32);
extern "C" void func_0046C050(void *);
extern "C" void func_0046C098(void *, s32);
extern "C" void func_0046C118(void *, void *, void *);
extern "C" s32 func_0046C258(void *);
extern "C" s32 func_0046F490(void *);
extern "C" s32 func_005B2DF0(const char *, s32);
extern "C" void func_005B3080(s32);

struct Obj {
    char d0[0x85C];
    char d85C[0x8DC - 0x85C];
    s32 u8DC;
    char rest[0x8F0 - 0x8DC - 4];
    Obj() { func_0046C050(this); }
    ~Obj() { func_0046C098(this, 2); }
};

extern "C" s32 func_00332EE0(const char *arg0, s32 arg1, s32 w, s32 h, s32 arg4) {
    Dim d;
    d.a = arg1;
    d.w = w;
    d.h = h;
    Vec v((Vec::size_type)(w * h * 3 / 2));
    Range r;
    r.start = &v[0];
    r.size = v.end() - v.begin();
    Obj o;
    func_0046C118(&o, &d, &r);
    o.u8DC = arg4;
    if (func_0046C258(&o) == 0) {
        return 0;
    }
    s32 fd = func_005B2DF0(arg0, 0x602);
    if (fd < 0) {
        return 0;
    }
    func_00332740(fd, v.begin(), func_0046F490(o.d85C));
    func_005B3080(fd);
    return 1;
}
