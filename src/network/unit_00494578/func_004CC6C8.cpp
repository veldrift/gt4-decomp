/* compiler: ee-gcc2.96-stl */
#include "stl/stl_tree.h"
#include "stl/stl_map.h"
extern "C" void *func_00575E60(int,int);

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

typedef pair<const unsigned,void *> Pair;
typedef _Rb_tree<unsigned,Pair,_Select1st<Pair>,less<unsigned>,GameAlloc<Pair> > Tree;
typedef map<unsigned,void *,less<unsigned>,GameAlloc<Pair> > Map;
typedef Tree::iterator It;
struct Obj { char pad[8]; Map t; unsigned counter; int lock; };
extern "C" void func_00576788(void *);
extern "C" void func_005767C0(void *);
extern "C" void *func_00578CB0(int);
extern "C" void free(void *) throw();
extern "C" int func_004CC0A0(Obj *,int *,int,int) throw();
extern "C" It func_0060C188(Tree *,const unsigned &);
extern "C" It func_0060C1D0(Tree *,const It &,const Pair &);
template <> inline It Tree::lower_bound(const unsigned &k) { return func_0060C188(this,k); }
template <> inline It Tree::insert_unique(It i,const Pair &v) { return func_0060C1D0(this,i,v); }
struct Guard { void *p; Guard(void *v):p(v) {func_00576788(p);} ~Guard(){func_005767C0(p);} };
extern "C" int func_004CC6C8(Obj *o,int a,int b) {
 Guard g(&o->lock);
 if(a==0) return -2;
 int *p=(int *)func_00578CB0(0x24);
 if(p==0) return -12;
 *p=0;
 int r=func_004CC0A0(o,p,a,b);
 if(r<0) free(p);
 else { r=o->counter; o->t[o->counter++]=p; }
 return r;
}
