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
extern "C" void *func_00174148(void *) throw();
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
static inline char *data(Str *s) {
 Rep *r=(Rep *)(s->p-16);
 if((u32)r->ref>=2) func_005CB5A0(s,r->len,1);
 ((Rep *)(s->p-16))->sel=1;
 return s->p;
}
extern "C" void MMemoryCardFile__getIconTexture(s32 *arg0) {
 Obj h0; Str s1; Handle tmp; Str s2;
 func_00174148(&h0);
 Inner *in=((Outer *)h0.p)->in;
 Vt *e=(Vt *)((char *)in->tab+0x58);
 u16 *src=((u16 *(*)(void *))e->fn)((char *)in+e->delta);
 if(src) {
  Str *ps=&s1;
  init(ps);
  func_005CB368(ps,0,-1,0x2080,0);
  Tex *t=(Tex *)data(ps);
  long *gs=(long *)(data(ps)+0x30);
  Image *img=(Image *)(data(ps)+0x58);
  u16 *out=(u16 *)(data(ps)+0x80);
  t->magic=0x31786554;
  t->self=t; t->a=0; t->b=0; t->c=0; t->w=32; t->d=1; t->e=1;
  t->gs=gs; t->img=img; t->f=0; t->g=0; t->h=0; t->i=0;
  img->data=out; img->a=0; img->b=1; img->c=2; img->w=64; img->h=64;
  gs[0]=0x598204000L; gs[1]=0x60; gs[2]=0; gs[3]=0; gs[4]=0xfc000fc005L;
  u16 *cur=src;
  u32 i=0;
  do { u16 val=*cur++; i++; *out++=val|0x8000; } while(i<0x1000);
  Handle *ph=&tmp;
  func_00314B20(ph,ps); assign(arg0,ph); func_00312318(ph,2); release(ps);
 } else {
  const char *lit=D_00690D18; Str *ps=&s2;
  init(ps); func_005C2630(ps,0,-1,lit,func_0057F260(lit));
  Handle *ph=(Handle *)&s1;
  func_00314B20(ph,ps); assign(arg0,ph); func_00312318(ph,2); release(ps);
 }
 func_001740F0(&h0,2);
}
