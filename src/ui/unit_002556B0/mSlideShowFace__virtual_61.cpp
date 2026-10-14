/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Rep { int len, cap, ref, sel; };
struct Str { char *p; char pad[12]; };
struct Event { char pad[12]; char *key; };
struct Obj {};
typedef void (Obj::*PM)(Event *);
struct Node { char pad[20]; PM pm; };
struct Iter { Node *node; char pad[12]; };
struct Tree { int x; Node *end; };
struct Info { const char *name; };
extern Tree D_00830A08;
extern "C" char *func_005C2560(Rep *);
extern "C" Info *func_005C11A8(char *);
extern "C" void func_00326798(void *, int, int, const char *);
extern "C" void func_005DDF68(Iter *, Tree *, Str *);
static inline void grab(Str *dst, char *p) {
 Rep *r=(Rep *)(p-16);
 if(r->sel) p=func_005C2560(r); else ++r->ref;
 dst->p=p;
}
static inline void release(Str *s) {
 char *p=s->p;
 Rep *r=(Rep *)(p-16);
 if(--r->ref==0) {
 int cap=r->cap+16;
 func_00326798(r,cap,4,func_005C11A8(p)->name);
 }
}
extern "C" int mSlideShowFace__virtual_61(Obj *self, Event *ev) {
 Iter it;
 Iter tmp;
 Str s;
 PM pm;
 Str *ps=&s;
 grab(ps,ev->key);
 Iter *pt=&tmp;
 Tree *tree=&D_00830A08;
 func_005DDF68(pt,tree,ps);
 it.node=pt->node;
 release(ps);
 pt->node=tree->end;
 if(it.node!=pt->node) {
 pm=it.node->pm;
 (self->*pm)(ev);
 return 1;
 }
 return 0;
}
