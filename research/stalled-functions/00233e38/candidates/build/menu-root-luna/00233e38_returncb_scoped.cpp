/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef unsigned int u32;
struct Rep { u32 len, cap, ref, sel; };
struct Str { char *p; };
struct Heap { const char *name; };
struct Cb;
struct Obj { char pad0[0xE4]; float valueE4; int bitsE8; };
extern Rep D_00659FA8;
extern char MboolReader__vtable[], MfloatReader__vtable[], MstringReader__vtable[];
extern char D_00698980[], D_00698988[], D_00698990[], D_006989A8[], D_006989C0[], D_006989D8[], D_006989F0[], D_00698A00[];
extern "C" int func_00201168(Obj *,void *);
extern "C" char *func_005C2560(Rep *);
extern "C" u32 func_0057F260(const char *) throw();
extern "C" Str *func_005C2630(Str *,u32,u32,const char *,u32);
extern "C" Heap *func_005C11A8();
extern "C" void func_00326798(void *,u32,u32,const char *);
extern "C" int func_0020FD38(void *,Str *,Cb *);
extern "C" void func_0020FCE0(Cb *,int);
struct Cb { void *vt; void *dst; Cb(void *v,void *d):vt(v),dst(d){} ~Cb(){ func_0020FCE0(this,0); } };
static inline Cb makeCb(void *v,void *d) { return Cb(v,d); }
extern "C" void func_00233D48(void *,int);
extern "C" void func_00233D78(void *,int);
extern "C" void func_00233DB8(void *,int);
extern "C" void func_00233DE8(void *,int);
extern "C" void func_00233E18(void *,int);
static inline char *grab(Rep *r) { if (r->sel) return func_005C2560(r); ++r->ref; return (char *)(r+1); }
static inline Str &assign(Str *s,const char *p,u32 n) { return *func_005C2630(s,0,0xffffffff,p,n); }
static inline Str &assign(Str *s,const char *p) { return assign(s,p,func_0057F260(p)); }
static inline void construct(Str *s,const char *p) { s->p=grab(&D_00659FA8); assign(s,p); }
static inline Rep *rep(const Str *s) { return (Rep *)(s->p-16); }
static inline void deallocate(void *p,u32 n) { func_00326798(p,n,4,func_005C11A8()->name); }
static inline void rep_delete(void *p) { deallocate(p,sizeof(Rep)+((Rep *)p)->cap); }
static inline void release(Rep *r) { if (--r->ref==0) rep_delete(r); }
static inline void destroy(Str *s) { release(rep(s)); }
extern "C" bool func_00233E38(Obj *self,void *node) {
 int value[4];
 Str name;
 if(func_00201168(self,node)!=0) return true;
 {
  int ok;
  construct(&name,D_00698980);
  { Cb cb=makeCb(MboolReader__vtable,&value[0]); ok=func_0020FD38(node,&name,&cb); cb.vt=MboolReader__vtable; }
  destroy(&name);
  if(ok!=0) { func_00233D48(self,value[0]); return true; }
 }
 {
  int ok;
  construct(&name,D_00698988);
  { Cb cb=makeCb(MboolReader__vtable,&value[0]); ok=func_0020FD38(node,&name,&cb); cb.vt=MboolReader__vtable; }
  destroy(&name);
  if(ok!=0) { func_00233D78(self,value[0]); return true; }
 }
 {
  int ok;
  construct(&name,D_00698990);
  { Cb cb=makeCb(MfloatReader__vtable,&self->valueE4); ok=func_0020FD38(node,&name,&cb); cb.vt=MfloatReader__vtable; }
  destroy(&name);
  if(ok!=0) return true;
 }
 {
  int ok;
  construct(&name,D_006989A8);
  { Cb cb=makeCb(MboolReader__vtable,&value[0]); ok=func_0020FD38(node,&name,&cb); cb.vt=MboolReader__vtable; }
  destroy(&name);
  if(ok!=0) { func_00233DB8(self,value[0]); return true; }
 }
 {
  int ok;
  construct(&name,D_006989C0);
  { Cb cb=makeCb(MboolReader__vtable,&value[0]); ok=func_0020FD38(node,&name,&cb); cb.vt=MboolReader__vtable; }
  destroy(&name);
  if(ok!=0) { func_00233DE8(self,value[0]); return true; }
 }
 {
  int ok;
  construct(&name,D_006989D8);
  { Cb cb=makeCb(MboolReader__vtable,&value[0]); ok=func_0020FD38(node,&name,&cb); cb.vt=MboolReader__vtable; }
  destroy(&name);
  if(ok!=0) { func_00233E18(self,value[0]); return true; }
 }
 {
  int ok;
  construct(&name,D_006989F0);
  { Cb cb=makeCb(MstringReader__vtable,(char *)self+0xDC); ok=func_0020FD38(node,&name,&cb); cb.vt=MstringReader__vtable; }
  destroy(&name);
  if(ok!=0) return true;
 }
 {
  int ok;
  construct(&name,D_00698A00);
  { Cb cb=makeCb(MstringReader__vtable,(char *)self+0xE0); ok=func_0020FD38(node,&name,&cb); cb.vt=MstringReader__vtable; }
  destroy(&name);
  return ok!=0;
 }
}
