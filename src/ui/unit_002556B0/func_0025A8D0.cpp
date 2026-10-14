/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Rep { int len, cap, ref, sel; };
struct Str { char *p; char pad[12]; };
struct Info { const char *name; };
extern Rep D_00659FA8;
extern char D_00699BB8[];
extern "C" void *func_0025C298(void *);
extern "C" const char *hModule__getName(void *);
extern "C" void func_00326798(void *,int,int,const char *);
extern "C" int func_0057F260(const char *) throw();
extern "C" Info *func_005C11A8();
extern "C" char *func_005C2560(Rep *);
extern "C" Str *func_005C2630(Str *,unsigned,unsigned,const char *,unsigned);
static inline void init(Str *s) {
 char *p;
 if(D_00659FA8.sel) p=func_005C2560(&D_00659FA8);
 else {p=(char *)(&D_00659FA8+1);++D_00659FA8.ref;}
 s->p=p;
}
static inline void copy(Str *d,Str *s) {
 char *p=s->p; Rep *r=(Rep *)p-1;
 if(r->sel) p=func_005C2560(r); else ++r->ref;
 d->p=p;
}
static inline void release(Str *s) {
 Rep *r=(Rep *)s->p-1;
 if(--r->ref==0) {int n=r->cap+16;func_00326798(r,n,4,func_005C11A8()->name);}
}
static inline void append(Str *s,const char *p) {
 int n=func_0057F260(p);
 func_005C2630(s,((Rep *)s->p-1)->len,0,p,n);
}
static inline void assign(Str *d,Str *s) {if(s!=d) {release(d);copy(d,s);}}
extern "C" void recurse(Str *,void *) __asm__("func_0025A8D0");
extern "C" Str *func_0025A8D0(Str *out,void *obj) {
 Str str,tmp1,tmp2,parent,work;
 init(&str);
 if(func_0025C298(obj)==0) {
  const char *name=hModule__getName(obj);
  func_005C2630(&str,0,-1,name,func_0057F260(name));
 } else {
  Str *p=&parent;
  Str *s=&str;
  recurse(p,func_0025C298(obj));
  const char *sep=D_00699BB8;
  Str *w=&work;
  copy(w,p);
  append(w,sep);
  Str *b=&tmp2;
  copy(b,w);
  release(w);
  const char *name=hModule__getName(obj);
  copy(w,b);
  append(w,name);
  Str *a=&tmp1;
  copy(a,w);
  release(w);
  assign(s,a);
  release(a);
  release(b);
  release(p);
 }
 char *original=str.p;
 Rep *r=(Rep *)original-1;
 char *result;
 if(r->sel!=0) result=func_005C2560(r);
 else {result=original;++r->ref;}
 out->p=result;
 release(&str);
 return out;
}
