/* compiler: ee-gcc2.96-stl */
#include <stl_algobase.h>
#include <stl_alloc.h>
#include <stl_construct.h>
#include <stl_uninitialized.h>
#include <stl_vector.h>

typedef int s32;
extern "C" void free(int p) throw();
typedef unsigned char u8;
typedef unsigned int u32;
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
        free((int)p);
    }
    size_type max_size() const throw() { return size_t(-1) / sizeof(T); }
    void construct(T *p, const T &v) { new (p) T(v); }
    void destroy(T *p) { p->~T(); }
};

struct Vector { s32 a; u8 *begin; u8 *end; u8 *cap; };
extern "C" void *func_005A47D4(void *, const void *, u32);
extern "C" void func_005CD6E8(void *, u8 *, u32, const u8 *);
extern "C" void func_001C74B8(void *);
extern "C" void func_001C74F8(void *, s32);
extern "C" void func_001C7648(void *, void *, void *, void *);
extern "C" void func_001C7688(void *, void *, s32);
extern "C" s32 func_0046C258(void *);
extern "C" u32 func_0046F490(void *);
extern "C" s32 func_00579F38(void *, void *, s32);

inline void resize(Vector *vec, u32 n, const u8 &fill) {
    u8 *finish = vec->end;
    u32 size = finish - vec->begin;
    if (size > n) {
        u8 *resized = vec->begin + n;
        func_005A47D4(resized, finish, 0);
        vec->end -= finish - resized;
    } else
        func_005CD6E8(vec, finish, n - size, &fill);
}

struct Info {
    char pad0[4];
    s32 f4;
    char pad8[8];
    s32 f10;
    s32 f14;
    s32 f18;
    s32 f1C;
};
struct Dims { s32 a, b, c; };
struct Span { s32 n; u8 *p; };
struct Sub { char pad[4]; u8 *start; u8 *finish; };
struct Obj { char pad[0xF8]; Sub sub; };
struct Big {
    char pad[0x85C];
    char f85C[0x80];
    char pad8DC[0x8DC - 0x85C - 0x80];
    s32 f8DC;
    char pad8E0[0x900 - 0x8E0];
    Big() { func_001C74B8(this); }
    ~Big() { func_001C74F8(this, 2); }
};
extern "C" void func_001CAF30(Vector *vec, Info *info, Obj *p, s32 val) {
    s32 s6 = info->f10 * info->f18;
    s32 s5 = info->f14 * info->f1C;
    resize(vec, (s6 * s5 * 3) / 2, 0);
    Dims d;
    Span sp;
    d.a = s6;
    d.b = s5;
    d.c = info->f4;
    sp.n = vec->end - vec->begin;
    sp.p = vec->begin;
    Big big;
    func_001C7648(&big, &d, &sp, p ? (void *)((char *)p + 0x144) : 0);
    big.f8DC = val;
    vector<char, PlainAlloc<char> > vv2;
#define v2 (*(Vector *)&vv2)
    if (p) {
        Sub *sb = &p->sub;
        resize(&v2, sb->finish - sb->start + 4, 0);
        *(s32 *)v2.begin = func_00579F38(v2.begin + 4, sb->start, sb->finish - sb->start);
        func_001C7688(&big, v2.begin, v2.end - v2.begin);
    }
    if (func_0046C258(&big) != 0) {
        resize(vec, func_0046F490(big.f85C), 0);
    } else {
        resize(vec, 0, 0);
    }
}
