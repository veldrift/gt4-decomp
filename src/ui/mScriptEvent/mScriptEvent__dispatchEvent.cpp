/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
struct Rep {int len,cap,ref,sel;};
struct Str { char *p; char pad[12]; };
struct Info {const char *name;};
struct EntI {short d,i; void *(*fn)(void *);};
struct EntV {short d,i; void (*fn)(void *,void *,int,void *);};
struct Obj {int zero; char *vt; int x8,xc,x10,x14,x18,x1c; Str name;};
extern char D_00698C28[],D_00698C30[],D_00698C48[],D_00698C50[],D_00698C70[];
extern Rep D_00659FA8;
extern "C" void func_005D4AD8(const char *,...);
extern "C" void func_005DB110(const char *,...);
extern "C" void *func_0028EA18(void *);
extern "C" void *func_0028EA08(void *);
extern "C" const char *hModule__getName(void *);
extern "C" void func_002FA120(void *);
extern "C" void func_002F9B38(void *,int);
extern "C" int func_0057F260(const char *) throw();
extern "C" char *func_005C2560(Rep *);
extern "C" void *func_005C2630(Str *,unsigned,unsigned,const char *,unsigned);
extern "C" int HSymID__GetID(Str *);
extern "C" void func_003069F8(void *,void *,void *);
extern "C" Info *func_005C11A8();
extern "C" void func_00326798(void *,int,int,const char *);
extern "C" void func_003285A8(void *);
extern "C" void func_003285F8(void *);
extern "C" void func_0030BB18(void *);
extern "C" void func_00309378(void *,int);
extern "C" void func_0022AC98(void *,void *);
extern "C" void func_0022ACC8(void *,int);
extern "C" int hArray__size(void *);
extern "C" void *HArray__operator_index(void *,int);
extern "C" void func_00309360(void *,void *);
struct H { void *p; H() { func_0030BB18(this); } ~H() { func_00309378(this,2); } };
static inline const char *cstr(Str *s) {
 int n=((Rep *)s->p-1)->len;
 if (!n) return D_00698C48;
 s->p[n]=0;
 return (char *)(((Rep *)s->p-1)+1);
}
static inline void release(Str *s) {Rep *r=((Rep **)s)[0]-1;if (--r->ref==0) {int n=r->cap+16;func_00326798(r,n,4,func_005C11A8()->name);}}
static inline void assign(void **a,void **b) {if(a!=b) {void *p=*b;if(p)func_003285A8(p);if(*a)func_003285F8(*a);*a=p;}}
extern "C" int mScriptEvent__dispatchEvent(Obj *self) {
 void *fun[4];
 void *tmp[4];
 Str str;
 func_005D4AD8(D_00698C28);
 EntI *e=(EntI *)(self->vt+0x50);
 func_005D4AD8(D_00698C30,hModule__getName(e->fn((char *)self+e->d)),self->x14,self->x10);
 if(func_0028EA18(self)) {
  func_002FA120(fun);
  Str *name=&self->name;
  void *module=func_0028EA18(self);
  {
   void **ptmp=tmp;
   Str *ps=&str;
   const char *text=cstr(name);
   char *p;
   if(D_00659FA8.sel) p=func_005C2560(&D_00659FA8); else {p=(char *)(&D_00659FA8+1);++D_00659FA8.ref;}
   ps->p=p;
   func_005C2630(ps,0,-1,text,func_0057F260(text));
   ptmp[0]=(void *)HSymID__GetID(ps);
   func_003069F8(module,fun,ptmp);
   release(ps);
  }
  if(!fun[0]) {func_005DB110(D_00698C50,cstr(name));func_002F9B38(fun,2);return 2;}
  {
   H args[9];
   void *v[4];
   void **pv=v;
   v[0]=func_0028EA08(self);
   func_0022AC98(tmp,pv);
   void **array=(void **)args;
   assign(array,tmp);
   void **params=(void **)((char *)self+0x24);
   int i=0;
   func_0022ACC8(tmp,2);
   int n=hArray__size(*params);
   if(n>0) {
    do {
     func_00309360(tmp,HArray__operator_index(params,i));
     assign(array+i+1,tmp);
     func_00309378(tmp,2);
     ++i;
    } while(i<n);
   }
   func_0030BB18(tmp);
   Obj *o=(Obj *)fun[0];
   EntV *ev=(EntV *)(o->vt+0xA8);
   ev->fn((char *)o+ev->d,tmp,n+1,args);
   func_00309378(tmp,2);
  }
  func_002F9B38(fun,2);
 }
 func_005D4AD8(D_00698C70);
 return 1;
}
