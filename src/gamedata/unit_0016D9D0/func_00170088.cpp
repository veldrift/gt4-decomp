/* compiler: ee-gcc2.96-no-strict-aliasing */
struct H { void *p; int pad[3]; };
struct Item { long x; long id; long rest[2]; };
struct G { char pad[16]; Item *items; };
struct It { Item *p; int i; int pad[2]; };
struct Desc { char data[32]; };
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
extern "C" H *func_00170088(H *ret, G *g, int a, int b, int c) {
 H list;
 It end;
 It cur;
 Desc desc;
 H car;
 H tmp;
 Item *p=g->items;
 func_00435630(p);
 func_002EFBF0(&list);
 init(&end,p,1000);
 init(&cur,p,func_00435958(p,-1));
 for (; neq(&cur,&end); advance(&cur)) {
  Desc *d=&desc;
  func_00448820(*value(&cur),d);
  if (a>=0 && a!=func_004488A8(d)) continue;
  if (b>=0 && b!=func_004488B8(d)) continue;
  H *h=&car;
  func_00148030(h);
  func_00145B20(h->p,value(&cur),cur.i);
  if (c>=0 && (!func_00445EB0(func_00441248(func_00147D80(h->p))) || SPEC_DATABASE__CarEquipments__getDriveTrainType(func_00441248(func_00147D80(h->p)))!=c)) {
   func_0013BD68(h,2);
   continue;
  }
  func_002EEEB0(&tmp,list.p,h);
  func_00309378(&tmp,2);
  func_0013BD68(h,2);
 }
 func_002ED5A8(ret,&list);
 func_002ED5C0(&list,2);
 return ret;
}
