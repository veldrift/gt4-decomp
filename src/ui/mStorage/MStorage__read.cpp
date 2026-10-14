/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Rep { int len,cap,ref,sel; };
struct Str { char *p; int pad[3]; };
struct Obj { int refs; char *vtbl; };
struct Handle { Obj *p; int pad[3]; };
struct E1 { short delta,index; int (*fn)(void *,const char *); };
struct E2 { short delta,index; int (*fn)(void *,const char *,char *,int); };
struct Type { const char *name; };
extern Rep D_00659FA8;
extern char D_00698F10[];
extern "C" void func_002403C8(void *,int) throw();
extern "C" void func_00240420(void *,void *) throw();
extern "C" void func_00312318(void *,int);
extern "C" void func_00312370(void *,void *);
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
extern "C" void MStorage__read(Obj **dst,void *ctx,int n,void *args) {
 if (n > 0) {
  Handle h,src,out;
  Str s;
  Handle *psrc;
  int size;
  char *buf;
  func_00240420(&h,ctx);
  psrc = &src;
  func_00312370(psrc,args);
  {
   Obj *o = h.p;
   E1 *e = (E1 *)(o->vtbl + 0x1B0);
   void *self = (char *)o + e->delta;
   size = e->fn(self,c_str(func_00314920(psrc->p)));
  }
  buf = malloc(size);
  {
   Obj *o = h.p;
   E2 *e = (E2 *)(o->vtbl + 0x1C0);
   void *self = (char *)o + e->delta;
   if (e->fn(self,c_str(func_00314920(psrc->p)),buf,size) >= 0) {
    Str *ps;
    Rep *r = &D_00659FA8;
    char *d;
    ps = &s;
    if (r->sel) d = func_005C2560(r);
    else { d = (char *)(r + 1); r->ref++; }
    ps->p = d;
    func_005C2630(ps,0,-1,buf,func_0057F260(buf));
    Handle *ph = &out;
    func_00314B20(ph,ps);
    if ((void *)dst != (void *)ph) {
     Obj *p = ph->p;
     if (p) func_003285A8(p);
     if (*dst) func_003285F8(*dst);
     *dst = p;
    }
    func_00312318(ph,2);
    release(ps);
   }
  }
  free(buf);
  func_00312318(psrc,2);
  func_002403C8(&h,2);
 }
}
