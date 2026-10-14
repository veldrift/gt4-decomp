/* compiler: ee-gcc2.96-no-strict-aliasing */
struct W { int x; char *vt; };
struct H { W *p; char pad[12]; };
struct Temp { int x; char pad[12]; };
struct E70 { short d,i; W **(*fn)(void *,int); };
struct E58 { short d,i; int (*fn)(void *); };
extern "C" void func_002DD640(void *,int) throw();
extern "C" void func_002DD698(void *,void *) throw();
extern "C" int func_002DF940(void *);
extern "C" int func_002DF988(void *);
extern "C" void func_002DFA10(void *,int,int);
extern "C" void func_002ED5C0(void *,int);
extern "C" void func_002ED618(void *,void *);
extern "C" void *func_002EEEB0(void *,void *,void *);
extern "C" void func_002EFBF0(void *);
extern "C" void func_002FC870(void *,int);
extern "C" void func_002FE278(void *,int);
extern "C" void func_00309378(void *,int);
extern "C" void func_003285A8(void *);
extern "C" void func_003285F8(void *);
static inline int get(W *o,int i) {
 E70 *e=(E70 *)(o->vt+0x70);
 W *p=*e->fn((char *)o+e->d,i);
 E58 *f=(E58 *)(p->vt+0x58);
 return f->fn((char *)p+f->d);
}
extern "C" void MSliderBar__get_range(H *out,void *arg1,int count,void *arg3) {
 H h;
 H a;
 if(count>0) {
  func_002ED618(&h,arg3);
  H *pa=&a;
  func_002DD698(pa,arg1);
  W *p=pa->p;
  int lo=get(h.p,0);
  int hi=get(h.p,1);
  func_002DFA10(p,lo,hi);
  func_002DD640(pa,2);
  func_002ED5C0(&h,2);
  return;
 } else {
  H result;
  Temp t,v,w;
  func_002DD698(&h,arg1);
  H *pr=&result;
  func_002EFBF0(pr);
  W *p=pr->p;
  Temp *pt=&t;
  int value=func_002DF940(h.p);
  Temp *pv=&v;
  func_002FE278(pv,value);
  func_002EEEB0(pt,p,pv);
  func_00309378(pt,2);
  func_002FC870(pv,2);
  W * p_2 = pr->p;
  value=func_002DF988(h.p);
  Temp *pw=&w;
  func_002FE278(pw,value);
  func_002EEEB0(pt,p_2,pw);
  func_00309378(pt,2);
  func_002FC870(pw,2);
  if(out!=pr) {
   W *q=pr->p;
   if(q) func_003285A8(q);
   if(out->p) func_003285F8(out->p);
   out->p=q;
  }
  func_002ED5C0(pr,2);
  func_002DD640(&h,2);
 }
}
