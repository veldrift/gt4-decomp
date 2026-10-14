/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Obj;
struct H { Obj *p; int pad[3]; };
struct T { int pad[4]; };
struct V { short d, i; void (*fn)(void *, void *, void *); };
struct Obj { int n; V *vt; };
extern "C" {
void func_003041A0(void *,void *);
void func_003041B8(void *,int);
int func_00304258(void *,void *);
Obj *func_00305620(Obj *);
void hModule__findModuleValue(Obj *,void *,const void *);
void *func_00306638(void *,Obj *,void *);
void HModule__dynamicAssign(void *,void *);
int func_00306E80(void *);
void func_00309378(void *,int);
T *func_0030BB18(void *);
void func_0030F628(void *,void *,int);
int func_0030F648(void *);
Obj *func_00322060(void *);
void func_00323B60(void *,int);
void func_00323D08(void *);
void func_003285A8(void *);
void func_003285F8(void *);
}
static inline Obj *get(H *h) { return h->p; }
static inline void invoke(Obj *p, void *out, T *tmp) {
 V *e=&p->vt[9]; p=(Obj *)((char *)p+e->d);
 func_0030BB18(tmp); e->fn(p,out,tmp); func_00309378(tmp,2);
}
static inline void assign(H *a, H *b) {
 if(a != b) { Obj *p = b->p; if(p) func_003285A8(p); if(a->p) func_003285F8(a->p); a->p=p; }
}
extern "C" void *func_00321AE8(void *ret, void *arg1, void *arg2) {
 H h, h1, h2; T t3,t4,t5,t6,t7;
 func_00323D08(&h);
 int n=func_0030F648(arg2);
 Obj *o=func_00322060(arg1);
 while(o) {
  func_0030F628(&h1,arg2,0);
  V *e=&o->vt[51];
  e->fn((char *)o+e->d,&h,&h1);
  if(h.p) break;
  o=func_00305620(o);
 }
 if(!o) {
  o=func_00322060(arg1);
  func_0030F628(&t3,arg2,0);
  HModule__dynamicAssign(&h2,&t3);
  func_00306638(&h1,o,&h2);
  assign(&h,&h1);
  func_00323B60(&h1,2);
  func_003041B8(&h2,2);
 }
 func_00306E80(&h1);
 if(n>=2) {
  int i=1;
  func_0030BB18(&t4);
  for(;i<n;i++) {
   invoke(get(&h),&t4,&t5);
   Obj *p;
   if(func_00304258(&h1,&t4)) {
    p=get(&h1); func_0030F628(&t5,arg2,i); hModule__findModuleValue(p,&h,&t5);
    if(!h.p) {
     p=get(&h1); func_0030F628(&t7,arg2,i); HModule__dynamicAssign(&t6,&t7);
     func_00306638(&t5,p,&t6); assign(&h,(H *)&t5);
     func_00323B60(&t5,2); func_003041B8(&t6,2);
    }
   }
  }
  func_00309378(&t4,2);
 }
 invoke(get(&h),&h1,&t4);
 func_003041A0(ret,&h1); func_003041B8(&h1,2); func_00323B60(&h,2);
 return ret;
}
