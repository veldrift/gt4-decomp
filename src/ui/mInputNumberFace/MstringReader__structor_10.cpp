/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned int u32;
typedef int s32;
struct Rep { u32 len,res,ref,selfish; };
struct Str { char *dat; char pad[12]; };
struct Heap { const char *name; };
struct Cb { void **vtbl; void *p; char pad[8]; };
struct Vec { s32 unused; s32 *start,*finish,*end; };
extern Rep D_00659FA8;
extern char D_0069B930[],D_0069B938[];
extern void *D_0066CF80[],*MstringReader__vtable[];
extern "C" char *func_005C2560(Rep *);
extern "C" u32 func_0057F260(const char *) throw();
extern "C" Heap *func_005C11A8();
extern "C" Heap *func_005C1100();
extern "C" void func_00326798(void *,u32,u32,const char *);
extern "C" Str *func_005C2630(Str *,u32,u32,const char *,u32);
extern "C" s32 mSlideShowFace__virtual_61(char *,void *);
extern "C" s32 MboolReader__structor_7(char *,void *);
extern "C" s32 func_0020FD38(void *,Str *,Cb *);
extern "C" void MReaderBase__structor_0(Cb *,s32);
extern "C" void func_0057CD90(void *,s32,s32);
static inline char *grab(Rep *r) { if(r->selfish) return func_005C2560(r); ++r->ref; return (char *)(r+1); }
static inline Str &assign(Str *s,const char *p,u32 n) {return *func_005C2630(s,0,-1,p,n);}
static inline void construct(Str *s) {s->dat=grab(&D_00659FA8);}
static inline void construct(Str *s,const char *p) {construct(s);assign(s,p,func_0057F260(p));}
static inline Rep *rep(Str *s) {return (Rep *)s->dat-1;}
static inline void deallocate(void *p,u32 n) {func_00326798(p,n,4,func_005C11A8()->name);}
static inline void rep_delete(void *p) {deallocate(p,sizeof(Rep)+((Rep *)p)->res);}
static inline void release(Rep *r) {if(--r->ref==0)rep_delete(r);}
static inline void destroy(Str *s) {release(rep(s));}
static inline void copy(Str *s,Str *t) {if(t!=s){destroy(s);s->dat=grab(rep(t));}}
static inline void destroy(Vec *v,s32 **tmp) {s32 *p=v->start;*tmp=p;u32 n=v->end-p;if(p)func_00326798(p,n*4,4,func_005C1100()->name);}
extern "C" s32 MstringReader__structor_10(char *self,void *reader) {
 if(mSlideShowFace__virtual_61(self,reader))return 1;
 if(MboolReader__structor_7(self+0xA0,reader))return 1;
 struct Locals {Vec v;Str value,name0;Cb cb0;Str name1;Cb cb1;s32 *tmp;char pad[12];} u;
 u.v.start=0;u.v.finish=0;u.v.end=0;
 {
 construct(&u.name0,D_0069B930);
 Cb *cb=&u.cb0;cb->vtbl=D_0066CF80;cb->p=&u.v;
 s32 r=func_0020FD38(reader,&u.name0,cb);
 cb->vtbl=D_0066CF80;MReaderBase__structor_0(cb,0);destroy(&u.name0);
 if(r){func_0057CD90(self+0x108,u.v.start[0],u.v.start[1]);destroy(&u.v,&u.tmp);return 1;}
 }
 construct(&u.value);
 construct(&u.name1,D_0069B938);
 {
 Cb *cb=&u.cb1;cb->vtbl=MstringReader__vtable;cb->p=&u.value;
 s32 r=func_0020FD38(reader,&u.name1,cb);
 cb->vtbl=MstringReader__vtable;MReaderBase__structor_0(cb,0);destroy(&u.name1);
 if(r){copy((Str *)(self+0x104),&u.value);destroy(&u.value);destroy(&u.v,&u.tmp);return 1;}
 }
 destroy(&u.value);destroy(&u.v,&u.tmp);return 0;
}
