/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef short s16;
struct Rep { s32 len, cap, ref, sel; };
struct Str { char *p; char pad[12]; };
struct Handle { void *p; char pad[12]; };
struct Name { const char *name; };
struct VE { s16 delta, index; void (*fn)(void *,void *); };
struct VO { char pad[4]; VE *vt; };
extern char D_0068EE68[];
extern "C" {
void func_0013BD68(void *,int) throw();
void func_0013BDC0(void *,void *) throw();
int func_00147D80(void *);
void func_002FC870(void *,int);
void func_002FE278(void *,int);
void func_00326798(void *,int,int,const char *);
void func_003285A8(void *);
void func_003285F8(void *);
int func_00441248(int);
int func_004454C0(int);
int func_004478F8(int,int *,int);
int func_00448788(int,int *,int *);
int func_00448DC8(const char *);
Name *func_005C11A8();
}
static inline const char *c_str(Str *s) {
 int len=((Rep *)s->p)[-1].len;
 if(len==0) return D_0068EE68;
 s->p[len]=0;
 return s->p;
}
static inline void release(Str *s) {
 Rep *r=(Rep *)(s->p-16);
 if(--r->ref==0) { int cap=r->cap+16; func_00326798(r,cap,4,func_005C11A8()->name); }
}
static inline void publish(void **out,Handle *h,int value) {
 func_002FE278(h,value);
 if((void *)out!=(void *)h) {
  void *p=h->p;
  if(p) func_003285A8(p);
  if(*out) func_003285F8(*out);
  *out=p;
 }
 func_002FC870(h,2);
}
extern "C" void MCarGarage__canTune(void **out,void *ctx,int count,VO **args) {
 union { Str s; Handle h; } tmp;
 int a,b;
 int ids[10];
 int i=0;
 if(count>0) {
 VO **cursor=args;
 for(;i<count;i++,cursor++) {
  VO *o=*cursor;
  VE *e=(VE *)((char *)o->vt+0x18);
  e->fn(&tmp.s,(char *)o+e->delta);
  int id=func_00448DC8(c_str(&tmp.s));
  release(&tmp.s);
  func_0013BDC0(&tmp.h,ctx);
  int obj=func_004454C0(func_00441248(func_00147D80(tmp.h.p)));
  func_0013BD68(&tmp.h,2);
  func_00448788(obj,&a,&b);
  if(id==b) { publish(out,&tmp.h,1); return; }
  int n=func_004478F8(obj,ids,10);
  for(int j=0;j<n;j++) {
   if(id==ids[j]) { publish(out,&tmp.h,1); return; }
  }
 }
 }
 publish(out,&tmp.h,0);
}
