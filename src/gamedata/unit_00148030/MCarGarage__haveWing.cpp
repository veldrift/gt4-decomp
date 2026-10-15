/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef unsigned int u32;

struct Rep { s32 len; s32 cap; s32 ref; s32 sel; };
struct S00659988 { const char *name; };
struct Str { char *p; Str(const Str &); ~Str(); const char *c_str(); };
struct Handle { void *p; char pad[0xC]; };
union U { Handle h; s32 w[4]; };
struct VEntry { short delta; short index; Str (*fn)(void *); };
struct VObj { char pad[4]; VEntry *vtbl; };

extern char D_0068F788[];
extern char D_0068F798[];

extern "C" void func_0013BD68(void *arg0, int arg1);
extern "C" void func_0013BDC0(void *arg0, void *arg1);
extern "C" int func_00147D80(void *arg0);
extern "C" void func_002FC870(void *, int);
extern "C" void func_002FE278(void *, s32);
extern "C" void func_00326798(void *p, s32 size, s32 align, const char *name);
extern "C" void func_003285A8(void *p);
extern "C" void func_003285F8(void *p);
extern "C" int func_00440A10(int arg0, const char *arg1);
extern "C" int func_0057F238(const char *, const char *) throw();
extern "C" struct S00659988 *func_005C11A8(void);

inline const char *Str::c_str() {
    Str *s=this;
    s32 len = ((Rep *)s->p)[-1].len;
    if (len == 0) {
        return D_0068F788;
    }
    s->p[len] = 0;
    return s->p;
}
inline Str::~Str() {
    Str *s=this;
    Rep *q = (Rep *)(s->p - 0x10);
    if (--q->ref == 0) {
        s32 cap = q->cap + 0x10;
        func_00326798(q, cap, 4, func_005C11A8()->name);
    }
}

struct Val {
 void *p;
 Val(const Val &);
 Val(int) __asm__("func_002FE278");
 ~Val() __asm__("func_002FC870");
};
static inline void assign(void **dst, const Val &v) {
 if((void *)dst != (void *)&v) {
  void *p=v.p;
  if(p) func_003285A8(p);
  if(*dst) func_003285F8(*dst);
  *dst=p;
 }
}
extern "C" void MCarGarage__haveWing(void **arg0, void *arg1, s32 arg2, VObj **arg3) {
 if(arg2>0) {
  Handle h;
  const char *sel=0;
  func_0013BDC0(&h,arg1);
  VObj *o=*arg3;
  if(o) {
   VEntry *e=(VEntry *)((char *)o->vtbl+0x18);
   sel=e->fn((char *)o+e->delta).c_str();
   if(func_0057F238(sel,D_0068F798)==0) sel=0;
  }
  assign(arg0,Val(func_00440A10(func_00147D80(h.p),sel)!=0));
  func_0013BD68(&h,2);
 }
}
