/* compiler: ee-gcc2.96-stl */
/* SGI STL (include/stl/stl_vector.h) instantiated by tools/stl_vector.py: vector<T_005DBC00, GameAlloc> copy_ctor */
#include <stl_algobase.h>
#include <stl_alloc.h>
#include <stl_construct.h>
#include <stl_uninitialized.h>
#include <stl_vector.h>

extern "C" void *func_00326750(int size, int align, const char *name);
extern "C" void func_00326798(void *p, int size, int align, const char *name);
extern "C" void *func_00575E60(int heap, int size);
extern "C" void func_00575DA0(void *p, int size);

/* gcc 2.96's type_info: the name first, the vtable pointer after it */
struct TypeInfo {
    const char *name;
};

/* typeid(T).name() without typeid: the game's own __tf getter */
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

struct Sym { int id; Sym():id(0){} Sym(const Sym&o):id(o.id){} ~Sym(){} Sym&operator=(const Sym&o){if(this!=&o)id=o.id;return *this;} };
extern "C" void *HSymID__tf(void);
template <> struct TypeTag<Sym> { static void *tf() { return HSymID__tf(); } };
typedef vector<Sym,GameAlloc<Sym> > Vec;
template<> void Vec::insert(Vec::iterator,Vec::size_type,const Sym&) __asm__("func_005EDE90");
extern Sym D_0083FC00;
extern "C" void func_0030F190(Vec*) throw();
extern "C" void func_0030F308(Vec*self,Vec*src){
 int n=src->size();
 if(n>=2){
  int i;
  if((*src)[0].id==D_0083FC00.id){
   self->resize(n);
   for(i=0;i<n-1;i++)(*self)[i]=(*src)[i+1];
  }else{
   self->resize(n+1);
   for(i=0;i<n;i++)(*self)[i]=(*src)[i];
  }
  (*self)[i]=D_0083FC00;
 }else{
  self->resize(1);
  (*self)[0]=(*src)[0];
 }
 func_0030F190(self);
}
