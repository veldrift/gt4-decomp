/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Rep { int len, cap, ref, sel; };
struct Str { char *p; char pad[12]; };
struct Scale { char pad[0x2C]; float x,y,sx,sy; };
struct Obj { char pad[0xA0]; Scale scale; };
struct Handle { Obj *p; char pad[12]; };
struct Info { const char *name; };
struct VEntry { short delta,index; void (*fn)(Str *,void *); };
struct VObj { int data; VEntry *vtbl; };
extern Rep D_00659FA8;
extern char D_00699070[];
extern "C" void func_002434C8(Handle *,void *) throw();
extern "C" void func_00243470(Handle *,int) throw();
extern "C" void func_00245270(Obj *,Str *);
extern "C" char *func_005C2560(Rep *);
extern "C" int func_0057F260(const char *) throw();
extern "C" Str *func_005C2630(Str *,unsigned int,unsigned int,const char *,unsigned int);
extern "C" Info *func_005C11A8();
extern "C" void func_00326798(void *,int,int,const char *);
static inline void release(Str *s) {
 Rep *r = (Rep *)(s->p-16);
 if (--r->ref == 0) {
  int size = r->cap+16;
  func_00326798(r,size,4,func_005C11A8()->name);
 }
}
static inline bool isNull(VObj **r) { return *r == 0; }
extern "C" void MTextFace__set_text(void *arg0,void *arg1,int n,VObj **reader) {
 if (n > 0) {
  Handle h;
  Str s;
  func_002434C8(&h,arg1);
  if (!isNull(reader)) {
   VEntry *e = (VEntry *)((char *)(*reader)->vtbl+0x18);
   Str *ps = &s;
   Obj *p = h.p;
   e->fn(ps,(char *)(*reader)+e->delta);
   func_00245270(p,ps);
   release(ps);
   Scale *sc = (Scale *)((char *)h.p+0xA0);
   float x = sc->sx, y = sc->sy;
   sc->x = x;
   sc->y = y;
  } else {
   Rep *r = &D_00659FA8;
   const char *src = D_00699070;
   Str *ps = &s;
   Obj *p = h.p;
   char *d;
   if (r->sel != 0) d = func_005C2560(r);
   else { d = (char *)(r+1); r->ref++; }
   ps->p = d;
   func_005C2630(ps,0,-1,src,func_0057F260(src));
   func_00245270(p,ps);
   release(ps);
  }
  func_00243470(&h,2);
 }
}
