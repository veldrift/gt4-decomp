/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef unsigned int u32;
struct Rep { int len,cap,ref,sel; };
struct Str { char *p; char pad[12]; };
struct Type { const char *name; };
struct Entry { short delta,index; int (*fn)(void *); };
struct Obj { int x; Entry *vt; };
struct Block { long data[152]; };
extern Rep D_00659FA8;
extern char D_006614F8[];
extern "C" void func_0016D848(void *,void *) throw();
extern "C" void func_0016D7F0(void *,int) throw();
extern "C" void func_0013BDC0(void *,void *);
extern "C" char *func_00147D80(void *);
extern "C" void func_0013BD68(void *,int);
extern "C" int func_00435568(void *,int,void *);
extern "C" void func_0017CA80(void *,int,void *);
extern "C" void func_001792D8(void *,void *);
extern "C" void func_00179280(void *,int);
extern "C" void func_001CDA10(void *);
extern "C" int func_001CC528(void *,void *);
extern "C" int func_001CEAA8(void *,void *,void *,int);
extern "C" void func_001CC060(void *,int);
extern "C" const char *GT4MC__getFileResultString(int);
extern "C" char *func_005C2560(Rep *);
extern "C" int func_0057F260(const char *) throw();
extern "C" void *func_005C2630(void *,u32,u32,const char *,u32);
extern "C" void func_00314B20(void *,void *);
extern "C" void func_003285A8(void *);
extern "C" void func_003285F8(void *);
extern "C" void func_00312318(void *,int);
extern "C" Type *func_005C11A8();
extern "C" void func_00326798(void *,int,int,const char *);
static inline void release(Str *s) {
 Rep *q=(Rep *)(s->p-16);
 if (--q->ref==0) { int size=q->cap+16; func_00326798(q,size,4,func_005C11A8()->name); }
}
extern "C" void MGarage__pushRidingCar(void **out,void *arg1,int argc,void **args) {
 struct Stack { void *h[4]; char pad[16]; Str str; char ctx[0x4c]; void *vt; } sp;
 func_0016D848(sp.h,arg1);
 char *garage=*(char **)((char *)sp.h[0]+16);
 func_0016D7F0(sp.h,2);
 int result;
 if(*(int *)(garage+0x81c8)<0) result=0;
 else {
 int made=0; void *a;
 if(argc<=0) {func_0017CA80(&sp.str,0x11,0); a=&sp.str; made=1;}
 else a=args;
 func_001792D8(sp.h,a);
 if(made) func_00179280(&sp.str,2);
 result=3;
 func_001CDA10(sp.ctx);
 if(func_001CC528(sp.ctx,*(void **)((char *)sp.h[0]+0x1c)))
 result=func_001CEAA8(sp.ctx,*(void **)((char *)sp.h[0]+0x1c),garage,0);
 sp.vt=D_006614F8;
 func_001CC060(sp.ctx,0);
 func_00179280(sp.h,2);
 }
 const char *text=GT4MC__getFileResultString(result);
 Str *s=&sp.str;
 Rep *r=&D_00659FA8; char *d;
 if(r->sel) d=func_005C2560(r);
 else {d=(char *)(r+1); r->ref++;}
 s->p=d;
 func_005C2630(s,0,-1,text,func_0057F260(text));
 func_00314B20(sp.h,s);
 if(out!=sp.h) { void *v=sp.h[0]; if(v) func_003285A8(v); void *old=*out; if(old) func_003285F8(old); *out=v; }
 func_00312318(sp.h,2);
 release(s);
}
