/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
struct Rep { s32 len,cap,ref,sel; };
struct Str { char *p; char pad[12]; };
struct Handle { void *p; char pad[12]; };
struct TI { const char *name; };
struct Obj { char pad0[4]; char *vt; char pad1[0xB8]; void *c0; void *c4; void *c8; s32 cc; s32 d0; s32 d4; char pad2[0x24]; s32 fc; s32 f100; s32 f104; };
struct VE { short d,pad; void (*fn)(void *,Str *); };
struct E3 { short d,pad; void (*fn)(void *,s32,void *); };
struct E4 { short d,pad; void (*fn)(void *,s32,void *,void *); };
extern Rep D_00659FA8;
extern char D_0069C760[];
extern "C" char *func_005C2560(Rep *);
extern "C" s32 func_0057F260(const char *) throw();
extern "C" void *func_005C2630(Str *,s32,s32,const char *,s32);
extern "C" TI *func_005C11A8();
extern "C" void func_00326798(void *,s32,s32,const char *);
extern "C" void *func_002C8180(void *) throw();
extern "C" void *func_002556B0(void *);
extern "C" s32 HSymID__GetID(void *);
extern "C" void func_003069F8(void *,void *,void *);
extern "C" void *func_00263368(void *,void *);
extern "C" void mWidget__setWindowPosition(void *,float,float);
extern "C" void mWidget__setActive(void *,void *);
extern "C" void func_002550B8(void *,s32);
extern "C" void func_002C8410(void *,void *);
static inline void init(Str *s,const char *src) {
 Rep *r=&D_00659FA8; char *d;
 if (r->sel) d=func_005C2560(r);
 else { d=(char *)(r+1); s32 n=r->ref+1; r->ref=n; }
 s->p=d;
 func_005C2630(s,0,-1,src,func_0057F260(src));
}
static inline void destroy(Str *s) {
 Rep *q=(Rep *)(s->p-16);
 if (--q->ref==0) { s32 cap=q->cap+16; func_00326798(q,cap,4,func_005C11A8()->name); }
}
extern "C" void func_002F9B08(void *,s32 *);
extern "C" void func_002F9B38(void *,s32);
extern "C" s32 func_00231F60(s32,s32);
extern "C" void mTextFace__virtual_68(void *,s32);
extern "C" void func_003285A8(s32);
extern "C" void func_003285F8(s32);
static inline void assign(s32 *dst,s32 *src) {
 if (dst!=src) {
  s32 nv=*src;
  if (nv) func_003285A8(nv);
  if (*dst) func_003285F8(*dst);
  *dst=nv;
 }
}
static inline bool valid(const Handle *h) { return h->p != 0; }
extern "C" void mOptionMenu__virtual_68(Obj *self,s32 arg1) {
 union { Handle h; s32 v[4]; } u;
 s32 id[4]; Str s;
 s32 zero0,zero1,zero2;
 { s32 *dst=&self->cc;
 zero0=0; func_002F9B08(&u,&zero0); assign(dst,u.v); func_002F9B38(&u,2); }
 { s32 *dst=&self->d0;
 zero1=0; func_002F9B08(&u,&zero1); assign(dst,u.v); func_002F9B38(&u,2); }
 { s32 *dst=&self->d4;
 zero2=0; func_002F9B08(&u,&zero2); assign(dst,u.v); func_002F9B38(&u,2); }
 func_00231F60(arg1,0);
 self->f104=0; self->fc=0; self->c0=0; self->c4=0; self->c8=0;
 func_002556B0(&u);
 s32 *pid=id; Str *ps=&s;
 init(ps,D_0069C760);
 pid[0]=HSymID__GetID(ps);
 func_003069F8(self,&u,pid);
 destroy(ps);
 if (valid(&u.h)) { E3 *e=(E3 *)(self->vt+0x338); e->fn((char *)self+e->d,arg1,u.h.p); }
 mTextFace__virtual_68(self,arg1);
 func_002550B8(&u,2);
}
