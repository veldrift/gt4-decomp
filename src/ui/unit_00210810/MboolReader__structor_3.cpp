/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned int u32; typedef int s32;
struct Rep { u32 len,res,ref,selfish; };
struct Str { char *dat; char pad[12]; };
struct Heap { const char *name; };
struct Cb { void **vtbl; void *p; char pad[8]; };
struct Vec { int unused; float *start,*finish,*end; };
struct Color { float x,y,z,w; };
struct Elem { int flag; float f[4]; Color v[4]; };
struct Obj { int m; Color v; Elem e[4]; };
extern Rep D_00659FA8;
extern char D_006978A8[],D_006978B8[],D_006978C8[],D_006978D0[],D_006978D8[],D_006978E0[],D_006978E8[];
extern void *MboolReader__vtable[],*D_00662D00[];
extern "C" char *func_005C2560(Rep *);
extern "C" u32 func_0057F260(const char *) throw();
extern "C" Heap *func_005C11A8();
extern "C" Heap *func_005C1288();
extern "C" void func_00326798(void *,u32,u32,const char *);
extern "C" Str *func_005C2630(Str *,u32,u32,const char *,u32);
extern "C" int func_0020FD38(void *,Str *,Cb *);
extern "C" void MReaderBase__structor_0(Cb *,int);
extern "C" Color *func_002030A0(Color *);
extern "C" Color *func_002030E8(Color *,Color *);
extern "C" void func_00203118(Color *,int);
extern "C" int MColorReader__structor_0(Cb *,Color *);
extern "C" void MColorReader__structor_1(Cb *,int);
extern "C" int func_0057DA20(char *,const char *,...);
static inline char *grab(Rep *r) {if(r->selfish)return func_005C2560(r);++r->ref;return (char *)(r+1);}
static inline Str &assign(Str *s,const char *p,u32 n) {return *func_005C2630(s,0,-1,p,n);}
static inline void construct(Str *s,const char *p) {s->dat=grab(&D_00659FA8);assign(s,p,func_0057F260(p));}
static inline void deallocate(void *p,u32 n) {func_00326798(p,n,4,func_005C11A8()->name);}
static inline void rep_delete(void *p) {deallocate(p,sizeof(Rep)+((Rep *)p)->res);}
static inline void destroy(Str *s) {Rep *r=(Rep *)s->dat-1;if(--r->ref==0)rep_delete(r);}
static inline void destroy(Vec *v,float **tmp) {float *p=v->start;*tmp=p;u32 n=v->end-p;if(p)func_00326798(p,n*4,4,func_005C1288()->name);}
extern "C" int MboolReader__structor_3(Obj *self,void *reader) {
 struct Locals {Color col;union {Str name;Cb cb;} x10;Cb cb20;char buf[32];union {Str name;Cb cb;} x50;Vec vec;} u;
 float *tmp;
 func_002030A0(&u.col);
 construct(&u.x10.name,D_006978A8);
 Cb *cb=&u.cb20;MColorReader__structor_0(cb,&u.col);
 int r=func_0020FD38(reader,&u.x10.name,cb);
 MColorReader__structor_1(cb,2);destroy(&u.x10.name);
 if(r) {func_002030E8(&self->v,&u.col);func_00203118(&u.col,2);return 1;}
 for(int i=0;i<4;i++) {
   func_0057DA20(u.buf,D_006978B8,i);
   construct(&u.x10.name,u.buf);
   Cb *cb=&u.x50.cb;cb->vtbl=MboolReader__vtable;cb->p=&self->e[i].flag;
   int r=func_0020FD38(reader,&u.x10.name,cb);
   cb->vtbl=MboolReader__vtable;MReaderBase__structor_0(cb,0);destroy(&u.x10.name);
   if(r) {func_00203118(&u.col,2);return 1;}
   u.vec.start=0;u.vec.finish=0;u.vec.end=0;
   func_0057DA20(u.buf,D_006978C8,i);
   construct(&u.x50.name,u.buf);
   Cb *cb2=&u.x10.cb;cb2->vtbl=D_00662D00;cb2->p=&u.vec;
   int rp=func_0020FD38(reader,&u.x50.name,cb2);
   cb2->vtbl=D_00662D00;MReaderBase__structor_0(cb2,0);destroy(&u.x50.name);
   if(rp) {for(int j=0;j<4;j++)self->e[i].f[j]=u.vec.start[j];destroy(&u.vec,&tmp);func_00203118(&u.col,2);return 1;}
   {
   func_0057DA20(u.buf,D_006978D0,i);
   construct(&u.x50.name,u.buf);
   Cb *cb=&u.x10.cb;MColorReader__structor_0(cb,&u.col);
   int r=func_0020FD38(reader,&u.x50.name,cb);
   MColorReader__structor_1(cb,2);destroy(&u.x50.name);
   if(r) {func_002030E8(&self->e[i].v[0],&u.col);destroy(&u.vec,&tmp);func_00203118(&u.col,2);return 1;}
   }
   {
   func_0057DA20(u.buf,D_006978D8,i);
   construct(&u.x50.name,u.buf);
   Cb *cb=&u.x10.cb;MColorReader__structor_0(cb,&u.col);
   int r=func_0020FD38(reader,&u.x50.name,cb);
   MColorReader__structor_1(cb,2);destroy(&u.x50.name);
   if(r) {func_002030E8(&self->e[i].v[1],&u.col);destroy(&u.vec,&tmp);func_00203118(&u.col,2);return 1;}
   }
   {
   func_0057DA20(u.buf,D_006978E0,i);
   construct(&u.x50.name,u.buf);
   Cb *cb=&u.x10.cb;MColorReader__structor_0(cb,&u.col);
   int r=func_0020FD38(reader,&u.x50.name,cb);
   MColorReader__structor_1(cb,2);destroy(&u.x50.name);
   if(r) {func_002030E8(&self->e[i].v[2],&u.col);destroy(&u.vec,&tmp);func_00203118(&u.col,2);return 1;}
   }
   {
   func_0057DA20(u.buf,D_006978E8,i);
   construct(&u.x50.name,u.buf);
   Cb *cb=&u.x10.cb;MColorReader__structor_0(cb,&u.col);
   int r=func_0020FD38(reader,&u.x50.name,cb);
   MColorReader__structor_1(cb,2);destroy(&u.x50.name);
   if(r) {func_002030E8(&self->e[i].v[3],&u.col);destroy(&u.vec,&tmp);func_00203118(&u.col,2);return 1;}
   }
destroy(&u.vec,&tmp);
 }
 func_00203118(&u.col,2);return 0;
}
