/* compiler: ee-gcc2.96-stl */
#include <stl_algobase.h>
#include <stl_alloc.h>
#include <stl_construct.h>
#include <stl_uninitialized.h>
#include <stl_vector.h>

typedef int s32;
extern "C" void *func_00326750(unsigned int size, int align, const char *name);
extern "C" void func_00326798(void *p, int size, int align, const char *name);
extern "C" void free(void *p, int size);

struct TypeInfo {
    const char *name;
};
template <class T> struct TypeTag;

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
        return (T *)func_00326750(n * sizeof(T), 4, ((TypeInfo *)TypeTag<T>::tf())->name);
    }
    void deallocate(T *p, size_type n) {
        func_00326798(p, n * sizeof(T), 4, ((TypeInfo *)TypeTag<T>::tf())->name);
    }
    size_type max_size() const throw() { return size_t(-1) / sizeof(T); }
    void construct(T *p, const T &v) { new (p) T(v); }
    void destroy(T *p) { p->~T(); }
};

struct Elem44 {char x[44]; ~Elem44() {}};
struct Elem16 {char x[16]; ~Elem16() {}};
extern "C" TypeInfo *func_005DBC80() throw();
extern "C" TypeInfo *MRegion__tf();
template <> struct TypeTag<Elem44> {static void *tf(){return func_005DBC80();}};
template <> struct TypeTag<Elem16> {static void *tf(){return MRegion__tf();}};
typedef vector<Elem44,GameAlloc<Elem44> > Vec44;
typedef vector<Elem16,GameAlloc<Elem16> > Vec16;
extern "C" void func_0026EE28(void*);
extern "C" int func_00270118(void*,void*,void*);
extern "C" int func_00234810(void *arg0) {
 char ctx[0x60];
 func_0026EE28(ctx);
 int result;
 {Vec44 v; result=func_00270118(ctx,&v,arg0);}
 ((Vec16*)(ctx+0x40))->~Vec16();
 return result;
}
