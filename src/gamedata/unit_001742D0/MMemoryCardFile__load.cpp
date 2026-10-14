/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef unsigned int u32;
typedef unsigned short u16;
struct Rep { s32 len, cap, ref, sel; };
struct Str { char *p; char pad[12]; };
struct Handle { s32 v; char pad[12]; };
struct Obj { void *p; char pad[12]; };
struct Vt { short delta,index; void *fn; };
struct Inner { char pad[0x4c]; Vt *tab; };
struct Outer { char pad[0x10]; Inner *in; };
struct Type { const char *name; };
struct Tex { u32 magic; Tex *self; u32 a,b; u16 c,w,d,e; void *gs,*img; u32 f,g,h,i; };
struct Image { u16 *data; u16 a; unsigned char b,c; u16 w,h; };
extern Rep D_00659FA8;
extern char D_00690D18[];
extern "C" void func_00174148(void *,void *) throw();
extern "C" void func_001740F0(void *, int) throw();
extern "C" void func_00312318(void *, int);
extern "C" void func_00314B20(void *, void *);
extern "C" void func_00326798(void *, s32, s32, const char *);
extern "C" void func_003285A8(s32);
extern "C" void func_003285F8(s32);
extern "C" s32 func_0057F260(const char *) throw();
extern "C" Type *func_005C11A8();
extern "C" char *func_005C2560(Rep *);
extern "C" void *func_005C2630(Str *,u32,u32,const char *,u32);
extern "C" Str *func_005CB368(Str *,u32,u32,u32,char);
extern "C" void func_005CB5A0(Str *,u32,int);
static inline void init(Str *s) {
 Rep *r=&D_00659FA8; char *p;
 if(r->sel) p=func_005C2560(r); else { p=(char *)(r+1); r->ref=r->ref+1; }
 s->p=p;
}
static inline void release(Str *s) {
 Rep *q=(Rep *)(s->p-16);
 if(--q->ref==0) { s32 cap=q->cap+16; func_00326798(q,cap,4,func_005C11A8()->name); }
}
static inline void assign(s32 *dst,Handle *h) {
 if(dst!=&h->v) { s32 nv=h->v; if(nv) func_003285A8(nv); s32 ov=*dst; if(ov) func_003285F8(ov); *dst=nv; }
}

struct Cb { void *vtbl; void *fn; char *p; int pad; };
extern char D_0065CDE0[],D_0065CE00[],D_00690D20[];
extern "C" void func_001742F0(void *);
extern "C" void func_001792D8(void *,void *);
extern "C" void func_00179280(void *,int);
extern "C" const char *GT4MC__getFileResultString(int);

extern char D_00690D28[],D_00690D30[],D_00690D40[];
extern "C" void func_002FE278(void *,int);
extern "C" void func_002FC870(void *,int);
extern "C" void MMemoryCardFile__load(s32 *arg0,void *arg1,int count,void *arg3) {
 Obj a; Obj b; Cb c; Handle r; Str s;
 if(count>0) {
  func_00174148(&a,arg1);
  Obj *pb=&b;
  func_001792D8(pb,arg3);
  arg3=0;
  Cb *pc=&c;
  void *fnp=(void *)func_001742F0;
  char *t=(char *)pb->p+0x10;
  pc->vtbl=D_0065CDE0; c.fn=fnp; c.p=t;
  Inner *in=((Outer *)a.p)->in;
  Vt *e=(Vt *)((char *)in->tab+0x28);
  int result=((int (*)(void *,void *,void *,void *))e->fn)((char *)in+e->delta,*(void **)((char *)pb->p+0x1c),*(void **)((char *)pb->p+0x28),pc);
  switch(result) {
   case 0: arg3=D_00690D28; break;
   case 1: arg3=D_00690D30; break;
   case 2: arg3=D_00690D40; break;
  }
  Str *ps=&s;
  init(ps); func_005C2630(ps,0,-1,(const char *)arg3,func_0057F260((const char *)arg3));
  Handle *ph=&r;
  func_00314B20(ph,ps); assign(arg0,ph); func_00312318(ph,2); release(ps);
  pc->vtbl=D_0065CE00;
  func_00179280(pb,2); func_001740F0(&a,2);
 } else {
  Handle *ph=(Handle *)&a;
  func_002FE278(ph,0); assign(arg0,ph); func_002FC870(ph,2);
 }
}
