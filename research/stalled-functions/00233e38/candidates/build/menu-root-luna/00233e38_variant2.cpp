/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef unsigned int u32;
typedef unsigned char u8;
struct Rep { u32 len, cap, ref, sel; };
struct Str { char *p; char pad[12]; };
struct Heap { const char *name; };
struct Cb { void *vt; void *dst; int pad[2]; };
extern Rep D_00659FA8;
extern char MboolReader__vtable[], MfloatReader__vtable[], MstringReader__vtable[];
extern "C" int func_00201168();
extern char MboolReader__vtable[], MfloatReader__vtable[], MstringReader__vtable[];
extern char D_00698980[], D_00698988[], D_00698990[], D_006989a8[], D_006989c0[], D_006989d8[], D_006989f0[], DAT_00698a00[];
extern "C" char *func_005C2560(Rep *);
extern "C" u32 func_0057F260(const char *) throw();
extern "C" Str *func_005C2630(Str *,u32,u32,const char *,u32);
extern "C" Heap *func_005C11A8();
extern "C" void func_00326798(void *,u32,u32,const char *);
extern "C" int func_0020FD38(void *,Str *,Cb *);
extern "C" void func_0020FCE0(Cb *,int);
extern "C" void func_00233D48(void *,int);
extern "C" void func_00233D78(void *,int);
extern "C" void func_00233DB8(void *,int);
extern "C" void func_00233DE8(void *,int);
extern "C" void func_00233E18(void *,int);
static inline char *grab(Rep *r) { if (r->sel) return func_005C2560(r); ++r->ref; return (char *)(r+1); }
static inline void make(Str *s,const char *p) { s->p=grab(&D_00659FA8); func_005C2630(s,0,0xffffffff,p,func_0057F260(p)); }
static inline void drop(Str *s) { Rep *r=(Rep *)(s->p-16); if (--r->ref==0) func_00326798(r,r->cap+16,4,func_005C11A8()->name); }
static inline int read(void *node,Str *name,Cb *cb,const char *key,void *vt,void *dst) { make(name,key); cb->vt=vt; cb->dst=dst; int r=func_0020FD38(node,name,cb); cb->vt=vt; func_0020FCE0(cb,0); drop(name); return r; }
struct Obj { char pad[0xe4]; u8 v_e4; u8 pad2[3]; u32 bits; };
extern "C" bool func_00233E38(Obj *self,void *node) {
 if(func_00201168()) return true;
 Str name; Cb cb; int val;
 if(read(node,&name,&cb,D_00698980,MboolReader__vtable,&val)) { func_00233D48(self,val); return true; }
 if(read(node,&name,&cb,D_00698988,MboolReader__vtable,&val)) { func_00233D78(self,val); return true; }
 if(read(node,&name,&cb,D_00698990,MfloatReader__vtable,&self->v_e4)) return true;
 if(read(node,&name,&cb,D_006989a8,MboolReader__vtable,&val)) { func_00233DB8(self,val); return true; }
 if(read(node,&name,&cb,D_006989c0,MboolReader__vtable,&val)) { func_00233DE8(self,val); return true; }
 if(read(node,&name,&cb,D_006989d8,MboolReader__vtable,&val)) { func_00233E18(self,val); return true; }
 if(read(node,&name,&cb,D_006989f0,MstringReader__vtable,(char *)self+0xdc)) return true;
 return read(node,&name,&cb,DAT_00698a00,MstringReader__vtable,(char *)self+0xe0);
}
