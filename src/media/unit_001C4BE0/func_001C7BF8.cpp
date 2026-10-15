/* compiler: ee-gcc2.96-stl */
#include <stl_algobase.h>
#include <stl_alloc.h>
#include <stl_construct.h>
#include <stl_uninitialized.h>
#include <stl_vector.h>

typedef int s32;
extern "C" void free(void *p) throw();
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
        return n == 0 ? 0 : (T *)func_00575E60(0x10, n * sizeof(T));
    }
    void deallocate(T *p, size_type n) {
        free(p);
    }
    size_type max_size() const throw() { return size_t(-1) / sizeof(T); }
    void construct(T *p, const T &v) { new (p) T(v); }
    void destroy(T *p) { p->~T(); }
};

struct E16 { int w[4]; ~E16() {} };
struct Elem { vector<int, PlainAlloc<int> > v; char pad[0x18]; };
struct Sub {
    char pad0[0x1C];
    vector<int, PlainAlloc<int> > v1C;
    char pad2C[0x44 - 0x2C];
    vector<E16, PlainAlloc<E16> > v44;
    Elem arr[3];
};
struct LocalView {
    Sub sub;
    vector<int, PlainAlloc<int> > v0CC;
    char padDC[0xFC - 0xDC];
    void *f0FC;
    char pad100[0x10C - 0x100];
    void *f10C;
    char pad110[0x124 - 0x110];
    s32 f124;
    char pad128[0x170 - 0x128];
    void destroy() {
        if (f10C) free(f10C);
        if (f0FC) free(f0FC);
        v0CC.~vector();
        sub.~Sub();
    }
};

extern "C" void func_00333400(void *);
extern "C" s32 func_003351C0(void *);
extern "C" s32 func_00335248(void *, void *, void *, void *);
extern "C" void DevelopCamera__structor_0(void *);
extern "C" void func_003C8668(void *);
extern "C" void func_003C8AA8(void *, void *);
extern "C" void func_003C8B68(void *, void *);
extern "C" s32 RaceSinglePlayerInformation__structor_0(void *);
extern "C" void RaceSinglePlayerInformation__structor_1(void *, s32);
extern "C" void func_0044CA98(int, int, int, int);
extern "C" void func_0044CB10();
extern "C" void *exception__structor_0(int);
extern "C" void func_00387EF0(void *, int, int);
extern "C" void func_00109A78(void *);
extern "C" void func_00109AB8(void *, s32);
extern "C" int GranTurismo4__MenuGameObject__startProject(void *, const char *, void *);
extern "C" void *func_001D3A60(void);
extern "C" void func_001D3AD0(void *);

struct VEntry { short delta; short index; void (*fn)(void *, s32); };

struct Photo {
    char pad0[0x64];
    char *vtbl;
    char pad68[4];
    char *f6C;
    char pad70[0x2EF30 - 0x70];
    s32 f2EF30;
    s32 f2EF34;
};

struct Holder {
    Photo *p;
    Holder(Photo *q) { p = q; }
    ~Holder() {
        if (p) {
            VEntry *e = (VEntry *)(p->vtbl + 8);
            e->fn((char *)p + e->delta, 3);
        }
    }
};
struct Rspi {
    char pad[0x2C0];
    Rspi() { RaceSinglePlayerInformation__structor_0(this); }
    ~Rspi() { RaceSinglePlayerInformation__structor_1(this, 2); }
};
struct Local {
    char pad[0x170];
    Local() { func_00333400(this); }
    ~Local() { ((LocalView *)this)->destroy(); }
};
struct Menu {
    char pad[0xB0];
    Menu() { func_00109A78(this); }
    ~Menu() { func_00109AB8(this, 2); }
};

struct Src {
    void *a;
    char *b;
    void *c;
    s32 d;
};

static inline Photo *makePhoto() {
    Photo *o = (Photo *)exception__structor_0(0x2EF80);
    DevelopCamera__structor_0(o);
    return o;
}

extern "C" void func_001C7BF8(char *arg0) {
    Src src;
    src.c = arg0;
    src.a = arg0;
    src.b = arg0 + *(s32 *)(arg0 + 0x14000);
    if (func_003351C0(&src)) {
        func_0044CA98(0x30000, 2, 1, 0xBC8000);
    } else {
        func_0044CA98(0x30000, 2, 6, 0xBC8000);
    }
    {
    Photo *o;
    Holder h(o = makePhoto());
    Rspi rspi;
    Local loc;
    s32 n = func_00335248(&loc, &src, o, &rspi);
    LocalView *lv = (LocalView *)&loc;
    o->f2EF30 = lv->f124 ^ 1;
    o->f2EF34 = lv->f124;
    func_00387EF0(o, 2, 1);
    while (n-- != 0) func_003C8B68(o, &src);
    func_003C8668(o);
    func_003C8AA8(o, &loc);
    Menu menu;
    func_001D3AD0(func_001D3A60());
    *(void **)((char *)func_001D3A60() + 0x1C) = &loc;
    GranTurismo4__MenuGameObject__startProject(&menu, "photo_save", &loc);
    char *c = o->f6C;
    if (c) {
        VEntry *e = (VEntry *)(*(char **)(c + 0x974) + 8);
        e->fn(c + e->delta, 3);
    }
    }
    func_0044CB10();
}
