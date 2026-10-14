struct Rep { int len, cap, ref, sel; };
struct Str { char *p; };
struct Info { const char *name; };
struct Obj {
 char pad0[0x6f4]; float x; char pad1[8]; float y;
 char pad2[0x1d2c-0x704]; float a,b;
 char pad3[0x14]; int active;
};
extern "C" void *func_0022F0F8(Obj *) throw();
extern "C" Str *func_00230788(Str *, Obj *);
extern "C" void func_002308E8(Obj *, Str *);
extern "C" void func_00230B68(Obj *, void *);
extern "C" Info *func_005C11A8();
extern "C" void func_00326798(void *, int, int, const char *);
extern "C" void func_002306D0(Obj *o, int active) {
 if (active && o->active == 0) {
  func_00230B68(o, func_0022F0F8(o));
  o->x = o->a;
  o->y = o->b;
 }
 o->active = active;
 Str s;
 func_00230788(&s,o);
 func_002308E8(o,&s);
 Rep *r = (Rep *)(s.p - 16);
 if (--r->ref == 0) {
  int n = r->cap + 16;
  func_00326798(r,n,4,func_005C11A8()->name);
 }
}
