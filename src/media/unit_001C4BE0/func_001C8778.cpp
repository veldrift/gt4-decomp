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
struct VEntry { short delta; short index; void (*fn)(void *); };
struct VEntry2 { short delta; short index; void (*fn)(void *, s32); };
struct Obj {
    char pad0[0x64];
    char *vtbl;
    char pad68[0xA4 - 0x68];
    char *fA4;
    char *fA8;
    Sub sub;
    vector<int, PlainAlloc<int> > v178;
    char pad188[0x1A8 - 0x188];
    void *f1A8;
    char pad1AC[0x1B8 - 0x1AC];
    void *f1B8;
    ~Obj();
};
struct G { char pad[0x38CB0]; char name[1]; };
struct Item { char pad0[0x64]; char *vtbl; char pad68[4]; char *f6C; };
extern G *D_00622F4C;
extern char D_00660DE8[];
extern "C" void *func_001D3A60(void);
extern "C" void func_001D3AD0(void *);
extern "C" int func_00436740(char *);
extern "C" void func_00107AB8(s32);
extern "C" void func_00109AB8(void *, s32);
extern "C" void func_004AB040(s32);
extern "C" void func_005C1628(void *) throw();

extern "C" void func_001C8778(Obj *o, s32 flags) {
    o->vtbl = D_00660DE8;
    func_001D3AD0(func_001D3A60());
    func_00436740((char *)D_00622F4C + 0x38CB0);
    func_00107AB8(1);
    func_004AB040(0x16);
    {
        Item *it = (Item *)o->fA8;
        VEntry *e = (VEntry *)(it->vtbl + 0x2C0);
        e->fn((char *)it + e->delta);
    }
    {
        Item *it = (Item *)o->fA8;
        char *c = it->f6C;
        if (c) {
            VEntry2 *e = (VEntry2 *)(*(char **)(c + 0x974) + 8);
            e->fn(c + e->delta, 3);
        }
    }
    Sub *sp = &o->sub;
    if (o->f1B8) free(o->f1B8);
    if (o->f1A8) free(o->f1A8);
    o->v178.~vector();
    sp->~Sub();
    {
        char *c = o->fA4;
        if (c) {
            VEntry2 *e = (VEntry2 *)(*(char **)(c + 0x64) + 8);
            e->fn(c + e->delta, 3);
        }
    }
    func_00109AB8(o, 0);
    if (flags & 1) func_005C1628(o);
}
