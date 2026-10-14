/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned int u32;
typedef int s32;
struct Rep { u32 len,res,ref,selfish; };
struct Str { char *dat; };
struct Heap { const char *name; };
struct Cb { void **vtbl; void *p; char pad[8]; };
struct Vec { s32 unused; float *start,*finish,*end; };
extern Rep D_00659FA8;
extern char D_00697218[],D_00697228[],D_00697230[],D_00697238[],D_00697248[];
extern void *MfloatReader__vtable[],*D_00662D00[];
extern "C" char *func_005C2560(Rep *);
extern "C" u32 func_0057F260(const char *) throw();
extern "C" Heap *func_005C11A8();
extern "C" Heap *func_005C1288();
extern "C" void func_00326798(void *,u32,u32,const char *);
extern "C" Str *func_005C2630(Str *,u32,u32,const char *,u32);
extern "C" s32 func_0020FD38(void *,Str *,Cb *);
extern "C" void MReaderBase__structor_0(Cb *,s32);
static inline char *grab(Rep *r) { if(r->selfish) return func_005C2560(r); ++r->ref; return (char *)(r+1); }
static inline Str &assign(Str *s,const char *p,u32 n) {return *func_005C2630(s,0,-1,p,n);}
static inline void construct(Str *s,const char *p) {s->dat=grab(&D_00659FA8);assign(s,p,func_0057F260(p));}
static inline Rep *rep(Str *s) {return (Rep *)s->dat-1;}
static inline void deallocate(void *p,u32 n) {func_00326798(p,n,4,func_005C11A8()->name);}
static inline void rep_delete(void *p) {deallocate(p,sizeof(Rep)+((Rep *)p)->res);}
static inline void release(Rep *r) {if(--r->ref==0)rep_delete(r);}
static inline void destroy(Str *s) {release(rep(s));}
static inline void destroy(Vec *v,float **tmp) {float *p=v->start;*tmp=p;u32 n=v->end-p;if(p)func_00326798(p,n*4,4,func_005C1288()->name);}
extern "C" s32 MfloatReader__structor_1(char *self,void *reader) {
 struct Locals {union { Str name; Vec vec; } a; union {Cb cb; Str name;} b; Cb cb0; s32 spare[4]; Cb cb1,cb3,cb4; float *tmp; char pad[12];} u;
 {
 construct(&u.a.name,D_00697218);
 char *p=self+4; Cb *cb=&u.cb0;cb->vtbl=MfloatReader__vtable;cb->p=p;
 s32 r=func_0020FD38(reader,&u.a.name,cb);
 cb->vtbl=MfloatReader__vtable;MReaderBase__structor_0(cb,0);destroy(&u.a.name);
 if(r)return 1;
 }
 {
 construct(&u.a.name,D_00697228);
 char *p=self+8; Cb *cb=&u.cb1;cb->vtbl=MfloatReader__vtable;cb->p=p;
 s32 r=func_0020FD38(reader,&u.a.name,cb);
 cb->vtbl=MfloatReader__vtable;MReaderBase__structor_0(cb,0);destroy(&u.a.name);
 if(r)return 1;
 }
 {
 construct(&u.a.name,D_00697230);
 char *p=self+12; Cb *cb=&u.b.cb;cb->vtbl=MfloatReader__vtable;cb->p=p;
 s32 r=func_0020FD38(reader,&u.a.name,cb);
 cb->vtbl=MfloatReader__vtable;MReaderBase__structor_0(cb,0);destroy(&u.a.name);
 if(r)return 1;
 }
 u.a.vec.start=0;u.a.vec.finish=0;u.a.vec.end=0;
 {
 construct(&u.b.name,D_00697238);
 Cb *cb=&u.cb3;cb->vtbl=D_00662D00;cb->p=&u.a.vec;
 s32 r=func_0020FD38(reader,&u.b.name,cb);
 cb->vtbl=D_00662D00;MReaderBase__structor_0(cb,0);destroy(&u.b.name);
 if(r){*(float *)(self+16)=u.a.vec.start[0];*(float *)(self+20)=u.a.vec.start[1];*(float *)(self+24)=u.a.vec.start[2];destroy(&u.a.vec,&u.tmp);return 1;}
 }
 {
 construct(&u.b.name,D_00697248);
 Cb *cb=&u.cb4;cb->vtbl=D_00662D00;cb->p=&u.a.vec;
 s32 r=func_0020FD38(reader,&u.b.name,cb);
 cb->vtbl=D_00662D00;MReaderBase__structor_0(cb,0);destroy(&u.b.name);
 if(r){*(float *)(self+28)=u.a.vec.start[0];*(float *)(self+32)=u.a.vec.start[1];*(float *)(self+36)=u.a.vec.start[2];destroy(&u.a.vec,&u.tmp);return 1;}
 }
 destroy(&u.a.vec,&u.tmp);return 0;
}
