/* compiler: ee-gcc2.96-no-strict-aliasing */
struct H { void *p; int pad[3]; };
struct Item { long x; long id; long rest[2]; };
struct G { char pad[16]; Item *items; };
struct It { Item *p; int i; int pad[2]; };
struct Desc { long data[3]; };
extern "C" void func_0013BD68(H *, int);
extern "C" int func_00145B20(void *, const void *, int);
extern "C" void *func_00147D80(void *);
extern "C" void func_00148030(H *);
extern "C" void func_002ED5A8(H *, H *);
extern "C" void func_002ED5C0(H *, int);
extern "C" H *func_002EEEB0(H *, void *, H *);
extern "C" H *func_002EFBF0(H *);
extern "C" void func_00309378(H *, int);
extern "C" int func_00435630(Item *);
extern "C" int func_00435958(Item *, int);
extern "C" void *func_00441248(void *);
extern "C" int SPEC_DATABASE__CarEquipments__getDriveTrainType(void *);
extern "C" int func_00445EB0(void *);
extern "C" int func_00448820(long, Desc *);
extern "C" unsigned char func_004488A8(Desc *);
extern "C" unsigned char func_004488B8(Desc *);
static inline void init(It *i, Item *p, int n) { i->p=p; i->i=n; }
static inline int eq(const It *a, const It *b) { int r=0; if (a->p == b->p) r=a->i == b->i; return r; }
static inline int neq(const It *a,const It *b) { return eq(a,b)^1; }
static inline long *value(It *a) { Item *e=a->p+a->i; return &e->id; }
static inline void advance(It *a) { a->i=func_00435958(a->p,a->i); }

struct Node { int color; Node *parent; Node *left; Node *right; int value; };
struct Tree { int alloc; Node *header; int count; unsigned char cmp; char pad[19]; };
struct Pair { Node *p; int success; int pad[2]; };
struct NI { Node *p; NI() {} NI(Node *x):p(x) {} };
struct Rep { int len, cap, ref, sel; };
struct Str { char *p; int pad[3]; };
struct Name { const char *name; };
extern Rep D_00659FA8;
extern "C" void *func_00326750(int,int,const char *);
extern "C" void func_00326798(void *,int,int,const char *);
extern "C" Name *func_005CB0E0();
extern "C" Name *func_005C11A8();
extern "C" char *func_005C2560(Rep *);
extern "C" Str *func_005C2630(Str *,unsigned int,unsigned int,const char *,unsigned int);
extern "C" int func_0057F260(const char *) throw();
extern "C" char *func_00448E50(int);
extern "C" void func_00314B20(H *, Str *);
extern "C" void func_00312318(H *,int);
extern "C" void func_005CAB18(Tree *,Node *);
extern "C" void func_005CAB88(Pair *,Tree *,const int *);
static inline void treeinit(Tree *t) {
 t->header=0;
 t->header=(Node *)func_00326750(20,4,func_005CB0E0()->name);
 t->count=0; t->cmp=0;
 t->header->color=0; t->header->parent=0;
 t->header->left=t->header; t->header->right=t->header;
}
static inline NI *increment(NI *it) {
 if(it->p->right) {
  it->p=it->p->right;
  while(it->p->left) it->p=it->p->left;
 } else {
  Node *y=it->p->parent;
  while(it->p==y->right) { it->p=y; y=y->parent; }
  if(it->p->right!=y) it->p=y;
 }
 return it;
}
static inline void nodeinit(NI *i,Node *p) { i->p=p; }
static inline bool nodeneq(const NI *i,const Tree *t) { return i->p!=t->header; }
static inline int nodevalue(const NI *i) { return i->p->value; }
static inline void release(Str *s) {
 Rep *q=(Rep *)(s->p-16);
 if(--q->ref==0) { int cap=q->cap+16; func_00326798(q,cap,4,func_005C11A8()->name); }
}
extern "C" H *func_00170278(H *ret,G *g) {
 Tree t;
 H list;
 It end;
 union { It cur; H temp; } u;
 union { Desc desc; struct { H car; Str s; } val; } v;
 Pair out;
 Pair tmp;
 NI it;
 int key;
 Item *p=g->items;
 treeinit(&t);
 H *pl=&list;
 func_002EFBF0(pl);
 init(&end,p,1000);
 init(&u.cur,p,func_00435958(p,-1));
 for(;neq(&u.cur,&end);advance(&u.cur)) {
  Desc *d=&v.desc;
  func_00448820(*value(&u.cur),d);
  {
   key=func_004488A8(d);
   Pair *pt=&tmp;
   func_005CAB88(pt,&t,&key);
   int ok=pt->success; Node *node=pt->p;
   out.success=ok; out.p=node;
  }
 }
 it=NI(t.header->left);
 for(;nodeneq(&it,&t);increment(&it)) {
  void *obj=pl->p;
  char *text=func_00448E50(nodevalue(&it));
  Str *ps=&v.val.s;
  Rep *r=&D_00659FA8;
  char *q;
  if(r->sel) q=func_005C2560(r);
  else { q=(char *)(r+1); r->ref++; }
  ps->p=q;
  func_005C2630(ps,0,-1,text,func_0057F260(text));
  H *h=&v.val.car;
  func_00314B20(h,&v.val.s);
  func_002EEEB0(&u.temp,obj,h);
  func_00309378(&u.temp,2);
  func_00312318(h,2);
  release(&v.val.s);
 }
 func_002ED5A8(ret,pl);
 func_002ED5C0(pl,2);
 if(t.count) {
  func_005CAB18(&t,t.header->parent);
  t.header->left=t.header; t.header->parent=0; t.header->right=t.header; t.count=0;
 }
 Node *h=t.header;
 func_00326798(h,20,4,func_005CB0E0()->name);
 return ret;
}
