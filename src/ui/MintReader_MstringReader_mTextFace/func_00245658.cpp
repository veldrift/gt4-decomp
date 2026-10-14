/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Rep { int len, cap, ref, sel; };
struct Str { char *p; char pad[12]; };
struct Obj { char pad[0x104]; void *p104; };
struct Info { const char *name; };
extern Rep D_00659FA8;
extern char D_00699158[];
extern "C" void *func_00247448(void *, Obj *);
extern "C" float mWidget__getWindowW(Obj *);
extern "C" Str *func_002B74B0(Str *, void *);
extern "C" void func_002B7310(void *, Str *);
extern "C" int func_0048F790(void *, char *, int, const char *, float);
extern "C" int func_0057F260(const char *) throw();
extern "C" char *func_005C2560(Rep *);
extern "C" Str *func_005C2630(Str *, unsigned int, unsigned int, const char *, unsigned int);
extern "C" Info *func_005C11A8();
extern "C" void func_00326798(void *, int, int, const char *);
static inline const char *c_str(Str *s) {
 int n = *(int *)(s->p-16);
 if (n == 0) return D_00699158;
 s->p[n] = 0;
 return s->p;
}
static inline void release(Str *s) {
 Rep *r = (Rep *)(s->p-16);
 if (--r->ref == 0) {
  int size = r->cap+16;
  func_00326798(r,size,4,func_005C11A8()->name);
 }
}
extern "C" int func_00245658(Obj *o) {
 Str s;
 char buf[0x104];
 void **handle = &o->p104;
 float width = mWidget__getWindowW(o);
 func_002B74B0(&s,*handle);
 int result = func_0048F790(func_00247448((char *)o+0xA0,o),buf,0x104,c_str(&s),width);
 if (result != 0) {
  Str tmp;
  void *h = *handle;
  Str *ps = &tmp;
  Rep *r = &D_00659FA8;
  char *d;
  if (r->sel != 0) d = func_005C2560(r);
  else { d = (char *)(r+1); r->ref++; }
  ps->p = d;
  func_005C2630(ps,0,-1,buf,func_0057F260(buf));
  func_002B7310(h,ps);
  release(ps);
 }
 release(&s);
 return result;
}
