/* compiler: ee-gcc2.96-stl */
#include <stl_algobase.h>
#include <stl_alloc.h>
#include <stl_construct.h>
#include <stl_uninitialized.h>
#include <stl_vector.h>

typedef int s32;
typedef char u8;
extern "C" void func_00575DA0(int p) throw();
extern "C" void *func_00575E60(int heap, int size);

template <class T>
class PlainAlloc {
public:
    typedef size_t size_type;
    typedef ptrdiff_t difference_type;
    typedef T *pointer;
    typedef const T *const_pointer;
    typedef T &reference;
    typedef const T &const_reference;
    typedef T value_type;
    template <class U> struct rebind { typedef PlainAlloc<U> other; };
    PlainAlloc() throw() {}
    PlainAlloc(const PlainAlloc &) throw() {}
    template <class U> PlainAlloc(const PlainAlloc<U> &) throw() {}
    ~PlainAlloc() throw() {}
    T *allocate(size_type n, const void * = 0) {
        return n == 0 ? 0 : (T *)func_00575E60(0x40, n * sizeof(T));
    }
    void deallocate(T *p, size_type n) {
        func_00575DA0((int)p);
    }
    size_type max_size() const throw() { return size_t(-1) / sizeof(T); }
    void construct(T *p, const T &v) { new (p) T(v); }
    void destroy(T *p) { p->~T(); }
};

extern char D_00695120[];
struct Self { char pad0[0x78]; char name[0x20]; };
struct Src { int a; char *start; char *finish; };
extern "C" long long func_001CD840(void);
extern "C" void func_0057DA20(char *, const char *, ...);
extern "C" s32 func_001CF400(Self *, void *);
extern "C" Src *func_00335638(void *);
extern "C" void *func_005A4724(void *, const void *, unsigned int);
extern "C" void func_001D4D10(u8 *, s32, s32, s32, float, float);
extern "C" s32 func_001CCEC8(Self *, void *, u8 *, s32, s32);

extern "C" s32 func_001D0B28(Self *self, void *arg1, void *arg2, s32 arg3) {
    long long t = func_001CD840();
    volatile long long keep;
    keep = t;
    int hi = (int)(t >> 32) & 0x1FFFF;
    func_0057DA20(self->name, D_00695120, hi);
    if (!func_001CF400(self, arg1)) return 1;
    Src *src = func_00335638(arg2);
    s32 n = src->finish - src->start;
    vector<u8, PlainAlloc<u8> > v((size_t)((n + 0x47) & -0x40));
    u8 *p = v.begin();
    func_005A4724(p + 8, src->start, n);
    func_001D4D10(p, n, 0, 0, 0x1.5c9eecp-1f, 0x1.9db22cp-2f);
    return func_001CCEC8(self, arg1, v.begin(), v.end() - v.begin(), arg3) == 0;
}
