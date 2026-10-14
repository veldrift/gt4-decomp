/* compiler: ee-gcc2.96-stl */
#include <stl_algobase.h>
#include <stl_alloc.h>
#include <stl_construct.h>
#include <stl_uninitialized.h>
#include <stl_list.h>

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

extern "C" void *func_005DD830();
template <class T> struct TypeTag { static void *tf() { return func_005DD830(); } };
typedef list<bool, GameAlloc<bool> > List;
struct Obj { char pad[24]; List events; };
struct Entry { short delta,index; void (*fn)(void*); };
extern "C" void *func_002A95A8();
extern "C" void func_00250B98(Obj*,void*) throw();
extern "C" void func_00250AF0(Obj*) throw();
extern "C" void func_00250E08(Obj*) throw();
extern "C" void func_00251EC8(Obj*);
extern "C" int func_00250F30(Obj*) throw();
extern "C" void func_00250FA0(Obj*) throw();
extern "C" void func_005D4AD8(const char*,...);
extern char D_006997E8[];
extern "C" void func_00251CE8(Obj *p) {

 func_00250B98(p,func_002A95A8());
 p->events.push_back(true);
 for(;p->events.back();) {
  func_00250AF0(p); func_00250E08(p); func_00251EC8(p);
  Entry *e=(Entry*)(*(char**)((char*)p+4)+0x1a0);
  e->fn((char*)p+e->delta);
 }
 p->events.pop_back();
 func_00250B98(p,func_002A95A8());
 if (p->events.empty() && func_00250F30(p)>0) {
  func_005D4AD8(D_006997E8,func_00250F30(p)); func_00250FA0(p);
 }
}
