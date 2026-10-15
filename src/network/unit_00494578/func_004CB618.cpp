/* compiler: ee-gcc2.96-stl */
/* Constructor of a network object that owns a map<int, int> (SGI STL, memalign allocator): the
   map's default constructor is inlined, with its _Compare() and allocator_type() temporaries. */
#include <stl_tree.h>
#include <stl_map.h>

typedef unsigned char u8;

extern "C" void *func_00575E60(int heap, int size);
extern "C" void free(void *p);
extern "C" void *exception__structor_0(int);

template <class T>
class GameAlloc {
public:
    typedef size_t size_type;
    typedef ptrdiff_t difference_type;
    typedef T *pointer;
    typedef const T *const_pointer;
    typedef T &reference;
    typedef const T &const_reference;
    typedef T value_type;
    template <class U> struct rebind { typedef GameAlloc<U> other; };
    GameAlloc() throw() {}
    GameAlloc(const GameAlloc &) throw() {}
    template <class U> GameAlloc(const GameAlloc<U> &) throw() {}
    ~GameAlloc() throw() {}
    T *allocate(size_type n, const void * = 0) {
        return n != 0 ? (T *)func_00575E60(0x10, n * sizeof(T)) : 0;
    }
    void deallocate(T *p, size_type n) {
        free(p);
    }
    size_type max_size() const throw() { return size_t(-1) / sizeof(T); }
    void construct(T *p, const T &v) { new (p) T(v); }
    void destroy(T *p) { p->~T(); }
};

typedef pair<const int, int> Value;
typedef map<int, int, less<int>, GameAlloc<Value> > Map;

struct Sub {
    char d[0x30];
    Sub() __asm__("func_00574D78");
};
struct A1 {
    virtual void v0();
    virtual int get();
};
struct Src {
    char pad0[0xD];
    u8 bD;
    u8 bE;
    u8 bF;
    u8 b10;
};
struct Arg3 {
    Src *s;
    int w4;
    int w8;
    char padC[8];
    int w14;
    int w18;
};
extern "C" void func_004CA2C0(void *, A1 *, int, int, int) throw();

struct D_00689568 {
    A1 *p0;
    void *f4;
    Map m;
    int f18;
    Sub sub;
    int f4C;
    int f50;
    int f54;
    int f58;
    int f5C;
    int f60;
    int f64;
    int f68;
    int f6C;
    int f70;
    char pad74[4];
    D_00689568(A1 *a1, int a2, Arg3 *a3) __asm__("func_004CB618");
    virtual ~D_00689568();
};

D_00689568::D_00689568(A1 *a1, int a2, Arg3 *a3) : p0(a1), f18(0) {
    f4C = a2;
    int v = a1->get();
    int k = 0;
    f50 = v;
    u8 *p = (u8 *)a3->s + 0xE;
    f54 = (p[1] << 8) | p[0];
    f58 = a3->s->b10;
    f5C = a3->w8;
    f60 = a3->w14;
    f64 = a3->w18;
    int a0 = a3->s->bD;
    f68 = a0;
    f6C = v * a0;
    if (a0 & 1) {
        f70 = 0;
    } else {
        int x;
        do {
            k++;
            x = 1;
            x <<= k;
            x &= f68;
        } while (!x);
        f70 = k;
    }
    void *obj = exception__structor_0(0x28);
    func_004CA2C0(obj, a1, a2, 0x100, f50);
    f4 = obj;
}
