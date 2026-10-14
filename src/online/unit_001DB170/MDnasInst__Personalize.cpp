/* compiler: ee-gcc2.96-stl */
extern "C" void free(void *) throw();
extern "C" void *malloc(unsigned int) throw();
#include <stl_tree.h>
#include <stl_map.h>
#include <stl_list.h>
extern "C" void *func_00575E60(int, int);
struct Rep { int len, cap, ref, sel; };
extern "C" char *strobe__toUpper(Rep *);
extern char D_00695940[];
struct Str {
 char *p;
 Str(const Str &o) {
  char *v = o.p; Rep *r = (Rep *)v-1;
  if(r->sel) v=strobe__toUpper(r); else ++r->ref;
  p=v;
 }
 Rep *rep() const {return (Rep *)p-1;}
 int length() const {return rep()->len;}
 char *data() const {return (char *)(rep()+1);}
 void terminate() const {data()[length()]=0;}
 const char *c_str() const {if(!length()) return D_00695940; terminate(); return data();}
};
template<class T> struct Alloc {
 typedef size_t size_type; typedef ptrdiff_t difference_type;
 typedef T *pointer; typedef const T *const_pointer;
 typedef T &reference; typedef const T &const_reference; typedef T value_type;
 template<class U> struct rebind {typedef Alloc<U> other;};
 Alloc() throw() {} Alloc(const Alloc &) throw() {} template<class U> Alloc(const Alloc<U> &) throw() {} ~Alloc() throw() {}
 T *allocate(size_type n,const void * = 0){return (T *)func_00575E60(16,n*sizeof(T));}
 void deallocate(T *p,size_type){free(p);}
 size_type max_size() const throw(){return size_t(-1)/sizeof(T);}
 void construct(T *p,const T &v){new(p) T(v);} void destroy(T *p){p->~T();}
};
typedef pair<const Str,Str> Value;
typedef _Rb_tree_node<Value> Node;
typedef _Rb_tree<Str,Value,_Select1st<Value>,less<Str>,Alloc<Value> > Tree;
typedef map<Str,Str,less<Str>,Alloc<Value> > Map;
extern "C" Node *func_005D2FE8(Tree *,Node *,Node *);
template<> inline Tree::_Link_type Tree::_M_copy(Tree::_Link_type x,Tree::_Link_type p){return func_005D2FE8(this,x,p);}
template<> inline Tree::_Rb_tree(const Tree &x)
 : _Base(x.get_allocator()), _M_node_count(0), _M_key_compare(x._M_key_compare) {
 if(x._M_root()==0) _M_empty_initialize();
 else {
  _S_color(_M_header)=_S_rb_tree_red;
  _Link_type root=_M_copy(x._M_root(),_M_header);
  _M_root()=root;
  _M_leftmost()=_S_minimum(_M_root());
  _M_rightmost()=_S_maximum(_M_root());
 }
 _M_node_count=x._M_node_count;
}
typedef pair<Str,Str> LV;
typedef list<LV,Alloc<LV> > List;
extern "C" void func_005D31D0(void *,void *,void *,void *,int);
template<> template<> inline void List::_M_insert_dispatch(List::iterator p,List::const_iterator first,List::const_iterator last,__false_type){func_005D31D0(this,&p,first._M_node,last._M_node,0);}
struct Block12 {int a,b,c;};
struct Url {int a;Str b,c,d;int e;Str f;};
struct Conn {
 int a,b,c;Str d;
 int e10,e14,e18,e1c,e20,e24,e28,e2c,e30,e34,e38;
 Block12 block;
 int e48,e4c,e50; Str s54;
 Map m58; List l68; Map m70,m80;
 Url u90,ua8;
 Str c0,c4;
 int c8,cc,d0,d4,d8,dc,e0,e4,e8;
 ~Conn() __asm__("func_004E70F0");
};
struct HConn {
 char *p;
 HConn(void *) __asm__("func_001D6ED8");
 HConn(const HConn &);
 ~HConn() __asm__("func_001D6E80");
 const Conn &get() const {return *(Conn *)(p+16);}
};
struct Worker {
 char *p;
 Worker(void *) throw() __asm__("func_001DAF28");
 Worker(const Worker &);
 ~Worker() throw() __asm__("func_001DAED0");
 char *get() const {return p+16;}
};
extern "C" void func_003285A8(void *);
extern "C" void func_003285F8(void *);
struct Handle {
 void *p;
 Handle(void *) __asm__("func_002FE278");
 Handle(const Handle &);
 ~Handle() __asm__("func_002FC870");
 Handle &operator=(const Handle &o){if(this!=&o){void *v=o.p;if(v)func_003285A8(v);if(p)func_003285F8(p);p=v;}return *this;}
};
struct Inflate {
 char data[0x3050];
 Inflate(void *,const char *,int) __asm__("func_00574B18");
 ~Inflate() __asm__("func_00574BA0");
};
extern "C" void func_004EA398(Conn *);
extern "C" void *func_0032EEA0(void *,const void *,int);
extern "C" void MDnasInst__Personalize(Handle *out,void *worker,int n,void *arg) {
 if(n>0){
  Conn conn(HConn(arg).get());
  int len=conn.s54.length();
  const char *p=conn.s54.c_str();
  int tag=p[0] | p[1]<<8 | p[2]<<16 | p[3]<<24;
  if(tag==(int)0xfff7eec5){
   const unsigned char *b=(const unsigned char *)p;
   int size=b[4]; size|=b[5]<<8; size|=b[6]<<16; size|=b[7]<<24; size=-size;
   void *buf=malloc(size);
   {Inflate stream(buf,p,1);}
   func_004EA398(&conn);
   *out=Handle(func_0032EEA0(Worker(worker).get(),buf,size));
   free(buf);
  } else {
   *out=Handle(func_0032EEA0(Worker(worker).get(),p,len));
   func_004EA398(&conn);
  }
 }
}
