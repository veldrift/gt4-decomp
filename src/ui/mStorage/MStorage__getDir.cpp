/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Rep { int len,cap,ref,sel; };
struct Str { char *p; int pad[3]; };
struct Obj { int refs; char *vtbl; };
struct Handle { Obj *p; int pad[3]; };
struct E1 { short delta,index; int (*fn)(void *,const char *); };
struct E3 { short delta,index; void (*fn)(void *,void *,const char *,const char *); };
union Tmp { Str s; Handle h; };
struct Type { const char *name; };
extern Rep D_00659FA8;
extern char D_00698F10[];
extern char D_00698F18[];
extern "C" void func_00309378(void *,int);
extern "C" void func_002403C8(void *,int) throw();
extern "C" void func_00240420(void *,void *) throw();
extern "C" void func_00312318(void *,int);
extern "C" void *func_00312370(void *,void *);
extern "C" Str *func_00314920(void *);
extern "C" void func_00314B20(void *,void *);
extern "C" void func_003285A8(void *);
extern "C" void func_003285F8(void *);
extern "C" char *malloc(int) throw();
extern "C" void free(void *) throw();
extern "C" int func_0057F260(const char *) throw();
extern "C" char *func_005C2560(Rep *);
extern "C" void *func_005C2630(Str *,int,int,const char *,int);
extern "C" Type *func_005C11A8();
extern "C" void func_00326798(void *,int,int,const char *);
static inline const char *c_str(Str *t) {
 int len = ((Rep *)t->p)[-1].len;
 if (len == 0) return D_00698F10;
 t->p[len] = 0;
 return t->p;
}
static inline void release(Str *s) {
 Rep *q = (Rep *)(s->p - 0x10);
 if (--q->ref == 0) {
  int cap = q->cap + 0x10;
  func_00326798(q,cap,4,func_005C11A8()->name);
 }
}
extern "C" void MStorage__getDir(Obj **dst,void *ctx,int n,char *args) {
 if (n > 0) {
  Handle h,src,out;
  Tmp u;
  Handle *psrc;
  Handle *pout;
  Tmp *ptmp;
  Obj *p;
  func_00240420(&h,ctx);
  psrc = &src;
  func_00312370(psrc,args);
  {
   const char *text = D_00698F18;
   Rep *r = &D_00659FA8;
   char *d;
   ptmp = &u;
   if (r->sel) d = func_005C2560(r);
   else { d = (char *)(r + 1); r->ref++; }
   ptmp->s.p = d;
   func_005C2630(&ptmp->s,0,-1,text,func_0057F260(text));
   pout = &out;
   func_00314B20(pout,&ptmp->s);
   release(&ptmp->s);
  }
  if (n >= 2) {
   func_00312370(&ptmp->h,args + 4);
   if ((void *)pout != (void *)ptmp) {
    p = ptmp->h.p;
    if (p) func_003285A8(p);
    if (pout->p) func_003285F8(pout->p);
    pout->p = p;
   }
   func_00312318(&ptmp->h,2);
  }
  {
   Obj *o = h.p;
   E3 *e = (E3 *)(o->vtbl + 0x1D0);
   void *self = (char *)o + e->delta;
   const char *a = c_str(func_00314920(psrc->p));
   const char *b = c_str(func_00314920(pout->p));
   e->fn(&ptmp->h,self,a,b);
  }
  if ((void *)dst != (void *)ptmp) {
   p = ptmp->h.p;
   if (p) func_003285A8(p);
   if (*dst) func_003285F8(*dst);
   *dst = p;
  }
  func_00309378(&ptmp->h,2);
  func_00312318(pout,2);
  func_00312318(psrc,2);
  func_002403C8(&h,2);
 }
}
