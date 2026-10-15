/* compiler: ee-gcc2.96-stl */
#include <stl_algobase.h>
#include <stl_alloc.h>
#include <stl_construct.h>
#include <stl_uninitialized.h>
#include <stl_vector.h>

typedef int s32;
extern "C" void free(void *) throw();
extern "C" void func_001CC060(void *, s32);
extern "C" void func_001D11D0(void *, s32);
extern "C" void *func_001D16E0(void *, s32);
extern "C" s32 func_001C6A10(void *, s32, s32);
extern "C" s32 func_001CC528(void *, void *);
extern "C" s32 func_001D0CC0(void *, void *, s32, s32);
extern "C" s32 func_001D1038(void *, void *, s32, s32);
extern "C" void *func_001D1340(void *, s32, void *);
extern "C" void *func_005A4724(void *, const void *, unsigned int);
extern char D_00660CD8[];

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
    T *allocate(size_type n, const void * = 0);
    void deallocate(T *p, size_type n) { free(p); }
    size_type max_size() const throw() { return size_t(-1) / sizeof(T); }
};

struct func_001CBFE0 {
    char data[0x4C];
    func_001CBFE0();
    ~func_001CBFE0() __asm__("func_001CC060");
    virtual void update();
};
struct D_006614F8 : func_001CBFE0 {
    virtual void update();
};
struct D_00661B70 : D_006614F8 {
    char *p50;
    D_00661B70() : p50(0) { func_001D11D0(this, 0); }
    virtual void update();
};
struct D_006611F0 : D_006614F8 {
    vector<char, PlainAlloc<char> > list;
    int x60;
    D_006611F0() : x60(0) {}
    virtual void update();
};
struct D_00661758 : D_006611F0 {
    char pad[0x150 - 0x64];
    vector<char, PlainAlloc<char> > list2;
    virtual void update();
};

struct Body {
    char *vt;
    char pad[0xC90 - 4];
    s32 count;
    Body(s32 v) { func_001D16E0(this, v); count = 0; }
    ~Body() { vt = D_00660CD8; }
};
struct G { char pad[0x39E28]; s32 f39E28; };
extern G *D_00622F4C;
struct Ctx { char pad[0xBD0]; char *fBD0; char pad2[0x1DD8 - 0xBD4]; s32 f1DD8; };

extern "C" s32 func_001C65B8(Ctx *self, s32 idx, s32 max) {
    if (self->f1DD8) return func_001C6A10(self, idx, max);
    Body body(D_00622F4C->f39E28);
    char *table = (char *)&body + 0x10;
    D_00661B70 a;
    a.p50 = table;
    if (__builtin_expect(func_001D1038(&a, &body, 0, 0), 0)) return -1;
    s32 ret = -1;
    if (idx < body.count) {
        D_00661758 d;
        if (func_001D1340(table, idx, d.data + 0x24)) {
            if (!func_001CC528(&d, &body)) return -1;
            unsigned flags = *(unsigned short *)(d.data + 0x48);
            if ((flags >> 2) & 1) return -1;
            if (__builtin_expect(func_001D0CC0(&d, &body, 0, 0), 0)) return -1;
            ret = d.list2.end() - d.list2.begin();
            if (ret < max) func_005A4724(self->fBD0, d.list2.begin(), ret);
            else ret = -1;
        }
    }
    return ret;
}
