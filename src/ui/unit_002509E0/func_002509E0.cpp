/* compiler: ee-gcc2.96-no-strict-aliasing */
extern "C" void func_003285A8(void*);
extern "C" void func_003285F8(void*);
struct Handle {
 void *p;
 ~Handle() __asm__("func_0028E378");
 Handle &operator=(const Handle &o) {
  if(this!=&o) {
   void *v=o.p;
   if(v) func_003285A8(v);
   if(p) func_003285F8(p);
   p=v;
  }
  return *this;
 }
};
struct Node { Node *next,*prev; Handle value; };
struct Iter {
 Node *n;
 Iter() {}
 Iter(Node *x):n(x) {}
 Iter(const Iter &o):n(o.n) {}
 Handle &operator*() const { return n->value; }
 Iter &operator--() { n=n->prev;return *this; }
};
struct Heap { const char *name; };
extern "C" Heap *func_005DD7F0();
extern "C" void func_00326798(void*,int,int,const char*);
extern "C" void func_00576788(void*);
extern "C" void func_005767C0(void*);
struct List {
 int word;Node *head;
 bool empty() const { return head->next==head; }
 Iter end() { return head; }
 Handle &back() { Iter it=end();--it;return *it; }
 Iter erase(Iter pos) {
  Node *p=pos.n;
  Node *next=p->next;
  Node *prev=p->prev;
  prev->next=next;
  next->prev=prev;
  pos.n->value.~Handle();
  Node *q=pos.n;
  func_00326798(q,0xC,4,func_005DD7F0()->name);
  return Iter(next);
 }
 void pop_back() { Iter it=end();erase(--it); }
};
struct Obj { char pad[0x10]; List list; char pad18[0xD0]; char lock[4]; };
extern "C" int func_002509E0(Obj *p, Handle *out) {
 void *lock=p->lock;
 int result=0;
 func_00576788(lock);
 if(!p->list.empty()) {
  *out=p->list.back();
  p->list.pop_back();
  result=1;
 }
 func_005767C0(lock);
 return result;
}
