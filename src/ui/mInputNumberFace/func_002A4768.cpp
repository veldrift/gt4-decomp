/* compiler: ee-gcc2.96-no-strict-aliasing */

typedef int s32;

struct Rep {
    s32 len;
    s32 cap;
    s32 ref;
    s32 sel;
};

struct Str {
    char *p;
    char pad[0xC];
};

struct S00659988 {
    const char *name;
};

struct Obj;

struct VObj {
    char pad0[4];
    char *vtbl;
};

struct VEntryCall {
    short delta;
    short index;
    void (*fn)(void *, s32 *, s32, void *);
};

extern Rep D_00659FA8;

extern "C" void *func_002FA120(void *arg0);
extern "C" void func_002F9B38(void *arg0, int arg1);
extern "C" char *func_005C2560(Rep *r);
extern "C" s32 func_0057F260(const char *s) throw();
extern "C" void func_005C2630(Str *s, s32 pos, s32 n, const char *src, s32 len);
extern "C" struct S00659988 *func_005C11A8(void);
extern "C" void func_00326798(void *p, s32 size, s32 align, const char *name);
extern "C" s32 HSymID__GetID(Str *s);
extern "C" void func_003069F8(Obj *obj, void *h, s32 *val);
extern "C" void func_0030BB18(void *h);
extern "C" void func_0024E348(void *h, s32 *val);
extern "C" void func_0024E378(void *h, int flags);
extern "C" void func_00309378(void *h, int flags);
extern "C" void func_003285A8(s32 p);
extern "C" void func_003285F8(s32 p);

struct Value {
    s32 p;
    Value() { func_0030BB18(this); }
};

struct MethodHandle {
    s32 p;
    s32 pad[3];
    MethodHandle() { func_002FA120(this); }
    ~MethodHandle() { func_002F9B38(this, 2); }
};

static inline void vcall20(VObj *o, s32 *ret, s32 n, void *args) {
    VEntryCall *e = (VEntryCall *)(o->vtbl + 0xA8);
    e->fn((char *)o + e->delta, ret, n, args);
}


extern "C" void mWidget__setActive(Obj *,s32);
extern "C" void func_002117A0(s32 *);
extern "C" s32 func_00213158(s32);
extern "C" s32 func_00251BD8(s32,s32);
extern "C" void func_00211408(s32 *,s32);
extern "C" s32 func_0022AC98(s32 *,s32 *);
extern "C" void func_0022ACC8(s32 *,s32) throw();
extern "C" void func_002FE278(s32 *,s32);
extern "C" void func_002FC870(s32 *,s32);
static inline void copy(Value *dst,s32 *p0) {
 if(dst!=(Value *)p0){s32 n=*p0;if(n)func_003285A8(n);s32 o=dst->p;if(o)func_003285F8(o);dst->p=n;}
}
extern "C" void func_002A4768(Obj *self,s32 active) {
 mWidget__setActive(self,active);
 MethodHandle h;
 s32 ret[4];
 Str s;
 s32 *pv=ret;
 {
  Str *ps=&s;const char *src="onModeToggled";Rep *r=&D_00659FA8;char *d;
  if(r->sel)d=func_005C2560(r);else {d=(char *)(r+1);r->ref++;}
  ps->p=d;
  func_005C2630(ps,0,-1,src,func_0057F260(src));
  *pv=HSymID__GetID(ps);
  func_003069F8(self,&h,pv);
  Rep *q=(Rep *)(ps->p-16);
  if(--q->ref==0){s32 cap=q->cap+16;func_00326798(q,cap,4,func_005C11A8()->name);}
 }
 if(h.p){
  func_0030BB18(pv);
  Value args[2];
  s32 tmp[4];
  s32 val;
  s32 *p0=tmp;
  func_002117A0(p0);
  s32 v=func_00251BD8(func_00213158(*p0),0);
  func_00211408(p0,2);
  val=v;func_0022AC98(p0,&val);
  copy(args,p0);func_0022ACC8(p0,2);
  Value *dst=args+1;
  func_002FE278(p0,active!=0);
  copy(dst,p0);func_002FC870(p0,2);
  vcall20((VObj *)h.p,pv,2,args);
  Value *q=args+2;
  while(args!=q){--q;func_00309378(q,2);}
  func_00309378(pv,2);
 }
}
