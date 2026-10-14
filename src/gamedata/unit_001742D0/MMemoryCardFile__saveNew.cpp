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
extern "C" void func_00174148(void *,void *) throw();
extern "C" void func_001740F0(void *,int) throw();
extern "C" void func_0013BDC0(void *,void *);
extern "C" char *func_00147D80(void *);
extern "C" void func_0013BD68(void *,int);
extern "C" int func_00435568(void *,int,void *);
extern "C" void func_0017CA80(void *,int,void *);
extern "C" void *func_001792D8(void *,void *);
extern "C" void func_00179280(void *,int);
extern "C" void func_001CDA10(void *);
extern "C" int func_001CC528(void *,void *);
extern "C" int func_001CEEC0(void *,void *,void *,void *,int);
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

struct CallEntry {short delta,index; int (*fn)(void *,void *,const char *,void *,void *);};
struct Target {char pad[0x4c]; CallEntry *vt;};
struct File {char pad[0x1c];void *a; char gap[8];void *b;};
struct Callback {void *vt;void (*fn)(int *);void *p;int pad;};
extern char D_0065CDE0[],D_0065CE00[];
extern "C" void func_001742F0(int *);
extern "C" void func_002FE278(void *,int);
extern "C" void func_002FC870(void *,int);
static inline void assign(void **out,void **src) {
 if(out!=src) {void *v=src[0];if(v)func_003285A8(v);void *old=*out;if(old)func_003285F8(old);*out=v;}
}

extern "C" void *func_00312370(void *,void *);
extern "C" Str *func_00314920(void *);
extern char D_00690D10[],D_00690D20[];
static inline const char *cstr(Str *s) {
 char *p=s->p; int len=*(int *)(p-16);
 if(len==0)return D_00690D10;
 p[len]=0;
 return s->p;
}
extern "C" void MMemoryCardFile__saveNew(void **out,void *arg1,int argc,void **args) {
 struct Stack {void *h[4];void *file[4];void *val[4];Callback cb;void *ret[4];Str str;Str err;} sp;
 if(argc>=2) {
 func_00174148(sp.h,arg1);
 void **pf=sp.file;
 func_001792D8(pf,args);
 void **pv=sp.val;
 func_00312370(pv,args+1);
 void (*fp)(int *)=func_001742F0;
 char *data=(char *)*pf+0x10;
 Callback *pc=&sp.cb;
 pc->vt=D_0065CDE0;
 pc->fn=fp;
 pc->p=data;
 Target *t=*(Target **)((char *)sp.h[0]+0x10);
 File *f=(File *)*pf;
 CallEntry *e=t->vt+4;
 void *first=f->a;
 void *self=(char *)t+e->delta;
 const char *name=cstr(func_00314920(*pv));
 int result=e->fn(self,first,name,((File *)*pf)->b,pc);
 Str *s=&sp.str;
 const char *text=GT4MC__getFileResultString(result);
 Rep *r=&D_00659FA8;char *d;
 if(r->sel)d=func_005C2560(r);else{d=(char *)(r+1);r->ref++;}
 s->p=d;
 func_005C2630(s,0,-1,text,func_0057F260(text));
 void **pr=sp.ret;
 func_00314B20(pr,s);
 assign(out,pr);
 func_00312318(pr,2);
 release(s);
 pc->vt=D_0065CE00;
 func_00312318(pv,2);
 func_00179280(pf,2);
 func_001740F0(sp.h,2);
 return;
 }
 const char *text=D_00690D20;
 Str *s=&sp.err;
 Rep *r=&D_00659FA8;char *d;
 if(r->sel)d=func_005C2560(r);else{d=(char *)(r+1);r->ref++;}
 s->p=d;
 func_005C2630(s,0,-1,text,func_0057F260(text));
 func_00314B20(sp.h,s);
 assign(out,sp.h);
 func_00312318(sp.h,2);
 release(s);
}
