/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Obj { char p[0x14]; void *face; void *a,*b,*c; int count; float x,y,w,h; };
struct Rep { int len,cap,ref,sel; };
struct Str { char *p; char pad[12]; };
struct Info { const char *name; };
extern Rep D_00659FA8;
extern char D_0069D0F0[],D_0069D0F8[],D_0069D100[];
extern "C" void func_0025B500(void *,float *,float *,float *,float *);
extern "C" void *func_0030BB18(void *);
extern "C" char *func_005C2560(Rep *);
extern "C" int func_0057F260(const char *) throw();
extern "C" void *func_005C2630(Str *,int,int,const char *,int);
extern "C" int HSymID__GetID(Str *);
extern "C" void func_003069F8(void *,void *,void *);
extern "C" Info *func_005C11A8();
extern "C" void func_00326798(void *,int,int,const char *);
extern "C" void *func_00255110(void *,void *) throw();
extern "C" void func_002550B8(void *,int);
extern "C" void func_00309378(void *,int);
static inline bool valid(int *h) { return h[0] != 0; }
extern "C" void func_002E2908(Obj *o,void *face) {
 int handle[4];
 int name[4];
 Str a,b,c;
 o->face=face;
 func_0025B500(face,&o->x,&o->y,&o->w,&o->h);
 func_0030BB18(handle);
 {
  const char *src=D_0069D0F0;
  Rep *r=&D_00659FA8;
  int *pn=name;
  Str *ps=&a;
  char *d;
  if(r->sel) d=func_005C2560(r);
  else { d=(char *)(r+1); r->ref++; }
  ps->p=d;
  func_005C2630(ps,0,-1,src,func_0057F260(src));
  pn[0]=HSymID__GetID(ps);
  func_003069F8(o->face,handle,pn);
  Rep *q=(Rep *)(ps->p-0x10);
  if(--q->ref==0) {
   int size=q->cap+0x10;
   func_00326798(q,size,4,func_005C11A8()->name);
  }
  if(valid(handle)) {
   func_00255110(pn,handle);
   o->a=(void *)pn[0];
   func_002550B8(pn,2);
  }
 }
 {
  const char *src=D_0069D0F8;
  Rep *r=&D_00659FA8;
  int *pn=name;
  Str *ps=&b;
  char *d;
  if(r->sel) d=func_005C2560(r);
  else { d=(char *)(r+1); r->ref++; }
  ps->p=d;
  func_005C2630(ps,0,-1,src,func_0057F260(src));
  pn[0]=HSymID__GetID(ps);
  func_003069F8(o->face,handle,pn);
  Rep *q=(Rep *)(ps->p-0x10);
  if(--q->ref==0) {
   int size=q->cap+0x10;
   func_00326798(q,size,4,func_005C11A8()->name);
  }
  if(valid(handle)) {
   func_00255110(pn,handle);
   o->b=(void *)pn[0];
   func_002550B8(pn,2);
  }
 }
 {
  const char *src=D_0069D100;
  Rep *r=&D_00659FA8;
  int *pn=name;
  Str *ps=&c;
  char *d;
  if(r->sel) d=func_005C2560(r);
  else { d=(char *)(r+1); r->ref++; }
  ps->p=d;
  func_005C2630(ps,0,-1,src,func_0057F260(src));
  pn[0]=HSymID__GetID(ps);
  func_003069F8(o->face,handle,pn);
  Rep *q=(Rep *)(ps->p-0x10);
  if(--q->ref==0) {
   int size=q->cap+0x10;
   func_00326798(q,size,4,func_005C11A8()->name);
  }
  if(valid(handle)) {
   func_00255110(pn,handle);
   o->c=(void *)pn[0];
   func_002550B8(pn,2);
  }
 }
 func_00309378(handle,2);
}
