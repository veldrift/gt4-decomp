/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Obj { char p[0xc0]; int popup; void *child; char q[0x34]; void *a,*b; int x,y,flag; };
struct Rep { int len,cap,ref,sel; };
struct Str { char *p; char pad[12]; };
struct Info { const char *name; };
extern Rep D_00659FA8;
extern char D_0069CF60[],D_0069CF68[],D_0069CF70[];
extern "C" void func_0025B500(void *,float *,float *,float *,float *);
extern "C" void *func_0030BB18(void *);
extern "C" char *func_005C2560(Rep *);
extern "C" int func_0057F260(const char *) throw();
extern "C" void *func_005C2630(Str *,int,int,const char *,int);
extern "C" int HSymID__GetID(Str *);
extern "C" void func_003069F8(void *,void *,void *);
extern "C" Info *func_005C11A8();
extern "C" void func_00326798(void *,int,int,const char *);
extern "C" void *func_00255110(void *,void *);
extern "C" void func_002550B8(void *,int);
extern "C" void func_00309378(void *,int);
extern "C" void mTextFace__virtual_67(Obj *);
extern "C" void func_00265E50(void *,int);
extern "C" void mSliderBar__virtual_67(Obj *o) {
 int handle[4];
 int name[4];
 Str a,b,c;
 void *parent=o;
 mTextFace__virtual_67(o);
 func_0030BB18(handle);
 if(o->popup) {
  int *pn2=name;
  Rep *r=&D_00659FA8;
  const char *src=D_0069CF60;
  Str *ps=&a;
  char *d;
  if(r->sel) d=func_005C2560(r);
  else { d=(char *)(r+1); r->ref++; }
  ps->p=d;
  func_005C2630(ps,0,-1,src,func_0057F260(src));
  pn2[0]=HSymID__GetID(ps);
  func_003069F8(o,handle,pn2);
  Rep *q=(Rep *)(ps->p-0x10);
  if(--q->ref==0) {
   int size=q->cap+0x10;
   func_00326798(q,size,4,func_005C11A8()->name);
  }
  if(__builtin_expect(handle[0],0)) {
   func_00255110(pn2,handle);
   parent=(void *)pn2[0];
   o->child=parent;
   func_00265E50(parent,0);
   func_002550B8(pn2,2);
  }
 }
 o->flag=0;
 int *pn=name;
 {
  const char *src=D_0069CF68;
  Rep *r=&D_00659FA8;
  Str *ps=&b;
  char *d;
  if(r->sel) d=func_005C2560(r);
  else { d=(char *)(r+1); r->ref++; }
  ps->p=d;
  func_005C2630(ps,0,-1,src,func_0057F260(src));
  pn[0]=HSymID__GetID(ps);
  func_003069F8(parent,handle,pn);
  Rep *q=(Rep *)(ps->p-0x10);
  if(--q->ref==0) {
   int size=q->cap+0x10;
   func_00326798(q,size,4,func_005C11A8()->name);
  }
  if(__builtin_expect(handle[0],0)) {
   func_00255110(pn,handle);
   o->a=(void *)pn[0];
   func_002550B8(pn,2);
  }
 }
 {
  const char *src=D_0069CF70;
  Rep *r=&D_00659FA8;
  Str *ps=&c;
  char *d;
  if(r->sel) d=func_005C2560(r);
  else { d=(char *)(r+1); r->ref++; }
  ps->p=d;
  func_005C2630(ps,0,-1,src,func_0057F260(src));
  pn[0]=HSymID__GetID(ps);
  func_003069F8(parent,handle,pn);
  Rep *q=(Rep *)(ps->p-0x10);
  if(--q->ref==0) {
   int size=q->cap+0x10;
   func_00326798(q,size,4,func_005C11A8()->name);
  }
  if(__builtin_expect(handle[0],0)) {
   func_00255110(pn,handle);
   o->b=(void *)pn[0];
   func_002550B8(pn,2);
  }
 }
 func_00309378(handle,2);
}
