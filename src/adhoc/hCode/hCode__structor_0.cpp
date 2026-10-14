/* compiler: ee-gcc2.96-stl */
#include <stl_algobase.h>
#include <stl_alloc.h>
#include <stl_construct.h>
#include <stl_uninitialized.h>
#include <stl_vector.h>
struct TypeInfo { const char *name; };
extern "C" void *func_00326750(unsigned,int,const char*);
extern "C" void func_00326798(void*,int,int,const char*);
extern "C" void *func_005A47D4(void*,const void*,unsigned) throw();
extern "C" TypeInfo *func_005EE2B0();
extern "C" TypeInfo *func_005C11A8();
struct Sym { int p; Sym(int n=0):p(n){} Sym(const Sym&o):p(o.p){} ~Sym(){} Sym&operator=(const Sym&o){if(this!=&o)p=o.p;return *this;} };
extern "C" TypeInfo*HSymID__tf();
template<class T>struct Alloc {typedef size_t size_type;typedef ptrdiff_t difference_type;typedef T*pointer;typedef const T*const_pointer;typedef T&reference;typedef const T&const_reference;typedef T value_type;template<class U>struct rebind{typedef Alloc<U>other;};Alloc()throw(){} Alloc(const Alloc&)throw(){}template<class U>Alloc(const Alloc<U>&)throw(){}~Alloc()throw(){} inline T*allocate(size_type n,const void * =0);void deallocate(T*p,size_type n){func_00326798(p,n*4,4,HSymID__tf()->name);}size_type max_size()const throw(){return size_t(-1)/4;}void construct(T*p,const T&x){new(p)T(x);}void destroy(T*p){p->~T();}};
template<class T>inline T*Alloc<T>::allocate(size_type n,const void*){return(T*)func_00326750(n*4,4,HSymID__tf()->name);}

typedef vector<Sym,Alloc<Sym> > SV;
typedef vector<void*,Alloc<void*> > IV;
template<> Sym*__uninitialized_copy_aux(const Sym*,const Sym*,Sym*,__false_type) __asm__("func_005EDCF0");
extern char hCode__vtable[];
extern "C" void *hObject__structor_0(void*);
struct Base{int x;void*vt;int x8,xc;Base(){hObject__structor_0(this);vt=hCode__vtable;}};
struct Obj:Base{SV syms;int x20,x24,x28;IV insts;Obj(SV*src) __asm__("func_002F45F8");};
Obj::Obj(SV*src):syms(*src),x20(0),x24(0),x28(0),insts(){}
