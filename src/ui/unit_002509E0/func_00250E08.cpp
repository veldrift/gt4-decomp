/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Target { int word; char *vt; char pad[8]; int flag; };
struct Val { Target *p; ~Val() __asm__("func_002540B8"); };
struct Node { Node *next, *prev; Val value; };
struct Iter {
 Node *n;
 Iter() {}
 Iter(Node *x):n(x) {}
 Iter(const Iter &o):n(o.n) {}
 Val &operator*() const { return n->value; }
 bool operator!=(const Iter &o) const { return n!=o.n; }
 Iter &operator++() { n=n->next; return *this; }
 Iter operator++(int) { Iter old=*this; ++*this; return old; }
};
struct Heap { const char *name; };
extern "C" Heap *func_005DD870();
extern "C" void func_00326798(void*,int,int,const char*);
extern "C" int func_00254850(Target*);
struct Entry { short delta,index; void (*fn)(void*); };
static inline void invoke(Target *p) {
 Entry *e=(Entry*)(p->vt+0x190);
 e->fn((char*)p+e->delta);
}
struct List {
 int word; Node *head;
 Iter begin() { return head->next; }
 Iter end() { return head; }
 Iter erase(Iter pos) {
  Node *p=pos.n;
  Node *next=p->next;
  Node *prev=p->prev;
  prev->next=next;
  next->prev=prev;
  pos.n->value.~Val();
  Node *q=pos.n;
  func_00326798(q,0xC,4,func_005DD870()->name);
  return Iter(next);
 }
};
struct Obj { char pad[0xCC]; List list; };
extern "C" void func_00250E08(Obj *p) {
 List *l=&p->list;
 Iter it=l->begin();
 while(it!=l->end()) {
  if((*it).p->flag) it=l->erase(it);
  else {
   if(func_00254850((*it).p)) invoke((*it).p);
   it++;
  }
 }
}
