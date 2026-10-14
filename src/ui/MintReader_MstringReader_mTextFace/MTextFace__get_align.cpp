/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Data { char pad[0x20]; int valid, value; };
struct Obj { char pad[0xC0]; int valid,value; };
struct Handle { Obj *p; char pad[12]; };
struct Tmp { void *p; char pad[12]; };
struct VEntry { short delta,index; int (*fn)(void *); };
struct VObj { int data; VEntry *vtbl; };
extern "C" int func_002434C8(Handle *,void *) throw();
extern "C" void func_00243470(Handle *,int) throw();
extern "C" void func_002FC870(Tmp *,int);
extern "C" void func_002FE278(Tmp *,int);
extern "C" void func_003285A8(void *);
extern "C" void func_003285F8(void *);
static inline void assign(Tmp *dst,Tmp *src) {
 if (dst != src) {
  void *p = src->p;
  if (p) func_003285A8(p);
  if (dst->p) func_003285F8(dst->p);
  dst->p = p;
 }
}
static inline int vcall(VObj *o) {
 VEntry *e = (VEntry *)((char *)o->vtbl+0x58);
 return e->fn((char *)o+e->delta);
}
extern "C" void MTextFace__get_align(Tmp *dst,void *arg1,int n,VObj **reader) {
 Handle h;
 Tmp t;
 if (n == 0) {
  func_002434C8(&h,arg1);
  Data *d = (Data *)((char *)h.p+0xA0);
  if (d->valid != 0) {
   func_002FE278(&t,d->value);
   assign(dst,&t);
   func_002FC870(&t,2);
  } else {
   func_002FE278(&t,-1);
   assign(dst,&t);
   func_002FC870(&t,2);
  }
  func_00243470(&h,2);
 } else if (n == 1) {
  func_002434C8(&h,arg1);
  int value = vcall(*reader);
  if (value >= 0) {
   h.p->valid = n;
   h.p->value = value;
  } else {
   h.p->valid = 0;
  }
  func_00243470(&h,2);
 }
}
