/* compiler: ee-gcc2.96-nosib */
typedef unsigned int u32;
typedef int s32;
struct StringRep { u32 len, res, ref, selfish; };
struct String { char *dat; };
struct Heap { const char *name; };
struct Cb { void **vtbl; char *p; char pad[8]; };
struct Node { char pad[12]; String name; };
struct Handle { void *p; char pad[12]; };
extern StringRep D_00659FA8;
extern char D_00697468[],D_00697470[],D_00697480[];
extern void *D_00666D50[],*D_00667528[];
extern "C" char *func_005C2560(StringRep *r);
extern "C" String *func_005C2630(String *,u32,u32,const char *,u32);
extern "C" u32 func_0057F260(const char *);
extern "C" Heap *func_005C11A8();
extern "C" void func_00326798(void *,u32,u32,const char *);
extern "C" s32 func_00261BC8(void *,void *);
extern "C" s32 func_0020FD38(void *,String *,Cb *);
extern "C" void func_0020FCE0(Cb *,s32);
extern "C" s32 func_005CD320(String *,const char *,u32,u32);
extern "C" void func_00206D18(void *) throw();
extern "C" s32 func_0020EEA0(void *,String *);
extern "C" s32 func_005A2F88(const char *);
extern "C" void func_002556B0(Handle *);
extern "C" void func_00269940(Cb *,Handle *);
extern "C" s32 func_0024DB78(Cb *,void *);
extern "C" void func_00206B60(void *,void *) throw();
extern "C" void func_002550B8(Handle *,s32);
static inline char *grab(StringRep *r) {
 if(r->selfish) return func_005C2560(r);
 ++r->ref; return (char *)(r+1);
}
static inline String &assign(String *s,const char *p,u32 n) { return *func_005C2630(s,0,(u32)-1,p,n); }
static inline String &assign(String *s,const char *p) { return assign(s,p,func_0057F260(p)); }
static inline void construct(String *s,const char *p) { s->dat=grab(&D_00659FA8); assign(s,p); }
static inline void construct(String *s) { s->dat=grab(&D_00659FA8); }
static inline StringRep *rep(const String *s) { return (StringRep *)s->dat-1; }
static inline void copy(String *s,const String *src) { s->dat=grab(rep(src)); }
static inline void deallocate(void *p,u32 n) { func_00326798(p,n,4,func_005C11A8()->name); }
static inline void rep_delete(void *p) { deallocate(p,sizeof(StringRep)+((StringRep *)p)->res); }
static inline void release(StringRep *r) { if(--r->ref==0) rep_delete(r); }
static inline void destroy(String *s) { release(rep(s)); }
static inline void destroy_reader(Cb *p) { p->vtbl=D_00667528; func_0020FCE0(p,0); }
static inline char *c_str(String *s) { if(rep(s)->len==0) return D_00697480; s->dat[rep(s)->len]=0; return s->dat; }
extern "C" bool func_00207590(char *self,Node *node) {
 if(func_00261BC8(self,node)) return 1;
 String name[8]; Cb cb; String token[4]; Handle item; Cb reader;

 construct(name,D_00697468);
 Cb *pcb=&cb;
 char *p=self+0xac;
 pcb->vtbl=D_00666D50; pcb->p=p;
 s32 r=func_0020FD38(node,name,pcb);
 pcb->vtbl=D_00666D50; func_0020FCE0(pcb,0);
 destroy(name);
 if(r) return 1;
 copy(name,&node->name);
 bool different=func_005CD320(name,D_00697470,0,func_0057F260(D_00697470))==0;
 destroy(name);
 if(!different) return 0;
 func_00206D18(self);
 construct(token);
 if(func_0020EEA0(node,token)==0x5b) {
  func_0020EEA0(node,token);
  func_005A2F88(c_str(token));
  func_0020EEA0(node,token); func_0020EEA0(node,token);
  Cb *preader=&reader; Handle *pitem=&item;
  while(true) {
   func_002556B0(pitem); func_00269940(preader,pitem);
   if(func_0024DB78(preader,node)==0x7d) break;
   func_00206B60(self,pitem->p);
   destroy_reader(preader); func_002550B8(pitem,2);
  }
  destroy_reader(preader); func_002550B8(pitem,2);
 }
 destroy(token);
 return 1;
}
