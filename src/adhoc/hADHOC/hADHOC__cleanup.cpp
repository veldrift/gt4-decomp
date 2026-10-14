/* compiler: ee-gcc2.96-stl */
#define private public
#define protected public
#include <stl_tree.h>
#include <stl_map.h>
#include <stl_list.h>
#undef private
#undef protected
extern "C" void RefCounter__cleanup();
extern "C" void func_003285A8(void*);
extern "C" void func_003285F8(void*);
extern "C" void func_002ED590(void*,const int&);
extern "C" void func_002ED5C0(void*,int);
extern "C" void func_00304188(void*,const int&);
extern "C" void func_003041B8(void*,int);
extern "C" void func_002EB798(void*,void*) throw();
extern "C" void func_005EB300(void*,void*);
extern "C" void func_005EB460(void*,void*);
extern "C" void func_005EB3D0(void*);
extern int D_00620178[2];
template<class T> class GameAlloc {
public:
 typedef size_t size_type; typedef ptrdiff_t difference_type;
 typedef T* pointer; typedef const T* const_pointer; typedef T& reference; typedef const T& const_reference; typedef T value_type;
 template<class U> struct rebind {typedef GameAlloc<U> other;};
 GameAlloc() throw() {} GameAlloc(const GameAlloc&) throw() {}
 template<class U> GameAlloc(const GameAlloc<U>&) throw() {}
 ~GameAlloc() throw() {}
 T* allocate(size_type n,const void * = 0);
 void deallocate(T*,size_type);
 size_type max_size() const throw(){return size_t(-1)/sizeof(T);}
 void construct(T*p,const T&v){new(p) T(v);} void destroy(T*p){p->~T();}
};
struct Key { unsigned int v; bool operator<(const Key&o) const {return v<o.v;} };
typedef pair<const Key,void*> Value;
typedef _Rb_tree<Key,Value,_Select1st<Value>,less<Key>,GameAlloc<Value> > Tree;
typedef _Rb_tree_node<Value> Node;
typedef map<Key,void*,less<Key>,GameAlloc<Value> > Map;
template<> inline void Tree::_M_erase(Node *n) {func_005EB460(this,n);}
struct Key2 { unsigned int v; bool operator<(const Key2&o) const {return v<o.v;} };
typedef pair<const Key2,int> Value2;
typedef _Rb_tree<Key2,Value2,_Select1st<Value2>,less<Key2>,GameAlloc<Value2> > Tree2;
typedef _Rb_tree_node<Value2> Node2;
typedef map<Key2,int,less<Key2>,GameAlloc<Value2> > Map2;
template<> inline void Tree2::_M_erase(Node2*n) {func_005EB300(this,n);}
typedef void (*Fn)(int);
typedef list<Fn,GameAlloc<Fn> > List;
struct Obj { char pad[8]; Map m; List l; List l2; Map2 m2; void *h38,*h3c; char gap[0x34]; void *h74; };
struct H { void *p; char pad[12]; };
static inline void assign(void **d,H *s) {
 if((void*)d!=(void*)s) { void *n=s->p; if(n)func_003285A8(n); if(*d)func_003285F8(*d); *d=n; }
}
extern "C" void hADHOC__cleanup(Obj *o) {
 RefCounter__cleanup();
 if(D_00620178[1]) {
  D_00620178[1]=0;
  { H h;func_002ED590(&h,0);assign(&o->h74,&h);func_002ED5C0(&h,2); }
  { H h;func_00304188(&h,0);assign(&o->h3c,&h);func_003041B8(&h,2); }
  { H h;func_00304188(&h,0);assign(&o->h38,&h);func_003041B8(&h,2); }
  o->m2.clear();
  func_005EB3D0(&o->l2);
  { List::reverse_iterator it=o->l.rbegin();
  List::reverse_iterator end=o->l.rend();
  for(;it!=end;it++) (*it)(1); }
  Map::iterator it;
  for(it=o->m.begin();it!=o->m.end();it++) func_002EB798(o,it->second);
  o->m.clear();
 }
}
