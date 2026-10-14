/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Type { const char *name; };
extern "C" {
void func_001FEF38(void *, const void *);
void func_001FEF50(void *,int);
void *func_001FF1A0(void *);
void *func_00326750(unsigned,int,const char *);
void func_00326798(void *,int,int,const char *);
void func_003285A8(void *);
void func_003285F8(void *);
void func_005769F0(void *);
void func_00576A28(void *);
Type *func_005DEA88();
extern char D_008309D8[];
}
inline void *operator new(unsigned int,void *p) throw() {return p;}
struct Handle {
 void *p;
 int isNull() const { return p==0; }
 Handle() { func_001FF1A0(this); }
 Handle(const Handle &v) { func_001FEF38(this,&v); }
 ~Handle() {func_001FEF50(this,2);}
 Handle &operator=(const Handle &v) {
  void *n=v.p;
  if(this!=&v) {
   if(n) func_003285A8(n);
   void *o=p;
   if(o) func_003285F8(o);
   p=n;
  }
  return *this;
 }
};
struct Node { void *next,*prev; Handle data; };
struct It {
 Node *node;
 It(Node *n):node(n) {}
 It() {}
 It(const It &i):node(i.node) {}
 bool operator==(const It &i) const { return node==i.node; }
 bool operator!=(const It &i) const { return node!=i.node; }
 Handle &operator*() const {return node->data;}
 It &operator++(){node=(Node *)node->next;return *this;}
 It operator++(int){It t=*this;++*this;return t;}
};
struct CIt {
 Node *node;
 CIt(Node *n):node(n) {}
 CIt(const It &i):node(i.node) {}
 bool operator==(const CIt &i) const { return node==i.node; }
 bool operator!=(const CIt &i) const { return node!=i.node; }
 CIt &operator++(){node=(Node *)node->next;return *this;}
};
template<class I,class D> inline void distance2(I first,I last,D &n) {
 while(first!=last) {++first;++n;}
}
template<class I,class D> inline void distance1(I first,I last,D &n) {
 distance2(first,last,n);
}
struct List {
 int alloc; Node *node;
 It begin() {return (Node *)node->next;}
 It end() {return node;}
 CIt begin() const {return (Node *)node->next;}
 CIt end() const {return node;}
 unsigned size() const {unsigned n=0;distance1(begin(),end(),n);return n;}
 Node *create(const Handle &v) {
  Node *p=(Node *)func_00326750(12,4,func_005DEA88()->name);
  new(&p->data) Handle(v);
  return p;
 }
 It insert(It pos,const Handle &v) {
  Node *n=create(v);
  n->next=pos.node;
  n->prev=pos.node->prev;
  ((Node *)pos.node->prev)->next=n;
  pos.node->prev=n;
  return n;
 }
 void push_back(const Handle &v) {insert(end(),v);}
 It erase(It pos) {
  Node *next=(Node *)pos.node->next;
  Node *prev=(Node *)pos.node->prev;
  prev->next=next;
  next->prev=prev;
  pos.node->data.~Handle();
  Node *n=pos.node;
  func_00326798(n,12,4,func_005DEA88()->name);
  return It(next);
 }
};
extern "C" void func_00266D20(char *self,Handle *value,int index) {
 if(index>=0) {
  List *list=(List *)(self+0x60);
  func_005769F0(D_008309D8);
  if((unsigned)index<list->size()) {
   It iter=list->begin();
   for(int i=0;i<index;++i) iter++;
   if(value->isNull()) list->erase(iter);
   else *iter=*value;
  } else if(!value->isNull()) {
   int n=index-list->size();
   for(int i=0;i<n;++i) list->push_back(Handle());
   list->push_back(*value);
  }
  func_00576A28(D_008309D8);
 }
}
