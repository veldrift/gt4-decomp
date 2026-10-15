/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
struct Rep { s32 len,cap,ref,sel; };
struct Str { char *p; char pad[12]; };
struct Handle { void *p; char pad[12]; };
struct TI { const char *name; };
struct Obj { char pad0[4]; char *vt; char pad1[0xB8]; void *c0; };
struct VE { short d,pad; void (*fn)(void *,Str *); };
struct E3 { short d,pad; void (*fn)(void *,s32,void *); };
struct E4 { short d,pad; void (*fn)(void *,s32,void *,void *); };
extern Rep D_00659FA8;
extern char D_0069C760[];
extern "C" char *func_005C2560(Rep *);
extern "C" s32 func_0057F260(const char *) throw();
extern "C" void *func_005C2630(Str *,s32,s32,const char *,s32);
extern "C" TI *func_005C11A8();
extern "C" void func_00326798(void *,s32,s32,const char *);
extern "C" void *func_002C8180(void *) throw();
extern "C" void func_002556B0(void *);
extern "C" s32 HSymID__GetID(void *);
extern "C" void func_003069F8(void *,void *,void *);
extern "C" void *func_00263368(void *,void *);
extern "C" void mWidget__setWindowPosition(void *,float,float);
extern "C" void mWidget__setActive(void *,void *);
extern "C" void func_002550B8(void *,s32);
extern "C" void func_002C8410(void *,void *);
static inline void init(Str *s,const char *src) {
 Rep *r=&D_00659FA8; char *d;
 if (r->sel) d=func_005C2560(r);
 else { d=(char *)(r+1); s32 n=r->ref+1; r->ref=n; }
 s->p=d;
 func_005C2630(s,0,-1,src,func_0057F260(src));
}
static inline void destroy(Str *s) {
 Rep *q=(Rep *)(s->p-16);
 if (--q->ref==0) { s32 cap=q->cap+16; func_00326798(q,cap,4,func_005C11A8()->name); }
}
extern "C" void func_002C8198(Obj *self,s32 arg1) {
 void *item=func_002C8180(self);
 if (item) {
  Handle h0; Handle h1; Str s; Str t;
  func_002556B0(&h0);
  Handle *ph=&h1; Str *ps=&s;
  init(ps,D_0069C760);
  ph->p=(void *)HSymID__GetID(ps);
  func_003069F8(self,&h0,ph);
  destroy(ps);
  func_00263368(ph,item);
  Obj *o=(Obj *)ph->p;
  VE *e=(VE *)(o->vt+0x190);
  void *adjusted=(char *)o+e->d;
  Str *pt=&t;
  init(pt,D_0069C760);
  e->fn(adjusted,pt);
  destroy(pt);
  mWidget__setWindowPosition(ph->p,0.0f,0.0f);
  mWidget__setActive(ph->p,0);
  if (__builtin_expect((s32)h0.p, 0)) { E3 *e=(E3 *)(self->vt+0x338); e->fn((char *)self+e->d,arg1,h0.p); }
  E4 *e4=(E4 *)(self->vt+0x328); e4->fn((char *)self+e4->d,arg1,ph->p,self->c0);
  func_002550B8(ph,2); func_002550B8(&h0,2); func_002C8410(self,item);
 }
}
