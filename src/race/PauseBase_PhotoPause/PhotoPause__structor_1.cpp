/* compiler: ee-gcc2.96-stl */
extern "C" void free(void *) throw();
#include <stl_algobase.h>
#include <stl_alloc.h>
#include <stl_construct.h>
#include <stl_uninitialized.h>
#include <stl_vector.h>
extern "C" void func_004768C0(void *);
extern "C" void func_00330890(void *,int);
extern "C" void PauseBase__structor_1(void *,int);
extern "C" void func_005C1628(void *) throw();
extern char PhotoPause__vtable[];
struct Elem { int a,b,c; ~Elem() {} };
struct Rep { int len,cap,ref,sel; };
struct VE { short delta,index; void (*fn)(void *,int); };
struct Owner { char pad[0x5c]; VE *vt; };
struct Node { Owner *owner; Node *prev,*next; char pad[0x168-12]; char *str; int x,y; int val[2]; char *str2; vector<Elem> vec; int val2[2]; };
template<class T> struct FreeAlloc {
 typedef T value_type; typedef T *pointer; typedef const T *const_pointer;
 typedef T &reference; typedef const T &const_reference;
 typedef unsigned size_type; typedef int difference_type;
 template<class U> struct rebind { typedef FreeAlloc<U> other; };
 void deallocate(T *const &p,unsigned) { free(p); }
};
template<class T> struct ValueAlloc : FreeAlloc<T> {
 void deallocate(T *p,unsigned) { free(p); }
 template<class U> struct rebind { typedef ValueAlloc<U> other; };
};
struct Elem16 { int a,b,c,d; ~Elem16() {} };
struct Buf { vector<char,FreeAlloc<char> > vec; char pad[24]; };
struct Sub {
 char pad0[0x1c]; vector<char,FreeAlloc<char> > vec;
 char pad30[0x18]; vector<Elem16,ValueAlloc<Elem16> > vec16;
 Buf buf[3]; Buf last; char gap[8]; char *p11c; char pad100[0xc]; char *p12c;
 ~Sub() {}
};
struct Obj { int x,y; void *vt; void *p; Node *node; char pad14[12]; Sub sub; char pad130[0x5c]; char handle[16]; };
static inline void release(char *s) { Rep *r=(Rep *)(s-16); if (--r->ref==0) free(r); }
static inline void unlink(Node *p) {
 if(p->prev==p->next) { if(p->owner) { Owner *o=p->owner; VE *e=o->vt+1; e->fn((char *)o+e->delta,3); } }
 else { p->next->prev=p->prev; p->prev->next=p->next; }
}
extern "C" void PhotoPause__structor_1(Obj *self,int flags) {
 self->vt=PhotoPause__vtable;
 Node *p=self->node;
 if(p) {
  func_004768C0(p->val2); p->vec.~vector(); release(p->str2);
  func_004768C0(p->val); release(p->str); unlink(p); func_005C1628(p);
 }
 Sub *sub = &self->sub;
 free(self->p);
 func_00330890(self->handle,2);
 if(self->sub.p12c) free(self->sub.p12c);
 if(self->sub.p11c) free(self->sub.p11c);
 sub->~Sub();
 PauseBase__structor_1(self,0);
 if(flags & 1) func_005C1628(self);
}
