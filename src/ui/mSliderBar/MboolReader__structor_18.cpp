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
extern "C" s32 MfloatReader__structor_0(char *,void *);
extern "C" void func_002DFA10(char *,s32,s32) throw();
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

extern char D_0069CF20[],D_0069CF28[],D_0069CF90[],D_0069CFA0[],D_0069CFA8[],D_0069CF60[];
extern void *MintReader__vtable[], *MboolReader__vtable[];
extern "C" s32 MboolReader__structor_18(char *self,void *reader) {
 if(MfloatReader__structor_0(self,reader))return 1;
 struct Locals { Vec v; union {Str name; Cb cb;} x10; Str name0; Cb cb0; Cb cb1; s32 value50; char pad50[12]; union {Cb cb; Str name;} x60; s32 value70; s32 *tmp; char pad78[8]; } u;
 u.v.start=0;u.v.finish=0;u.v.end=0;
 { construct(&u.name0,D_0069CF20);
 Cb *cb=&u.cb0; cb->vtbl=D_0066CF80; cb->p=&u.v;
 s32 r=func_0020FD38(reader,&u.name0,cb);
 cb->vtbl=D_0066CF80;MReaderBase__structor_0(cb,0);destroy(&u.name0);
 if(r){func_002DFA10(self,u.v.start[0],u.v.start[1]);destroy(&u.v,&u.tmp);return 1;}
 }
 { construct(&u.x10.name,D_0069CF28);
 Cb *cb=&u.cb1; cb->vtbl=MintReader__vtable; cb->p=self+0xE8;
 s32 r=func_0020FD38(reader,&u.x10.name,cb);
 cb->vtbl=MintReader__vtable;MReaderBase__structor_0(cb,0);destroy(&u.x10.name);
 if(r){destroy(&u.v,&u.tmp);return 1;}
 }
 { construct(&u.x10.name,D_0069CF90);
 Cb *cb=&u.x60.cb; cb->vtbl=MintReader__vtable; cb->p=&u.value50;
 s32 r=func_0020FD38(reader,&u.x10.name,cb);
 cb->vtbl=MintReader__vtable;MReaderBase__structor_0(cb,0);destroy(&u.x10.name);
 if(r){*(s32 *)(self+0x104)=u.value50;destroy(&u.v,&u.tmp);return 1;}
 }
 { construct(&u.x60.name,D_0069CFA0);
 Cb *cb=&u.x10.cb; cb->vtbl=MboolReader__vtable; cb->p=&u.value70;
 s32 r=func_0020FD38(reader,&u.x60.name,cb);
 cb->vtbl=MboolReader__vtable;MReaderBase__structor_0(cb,0);destroy(&u.x60.name);
 if(r){*(s32 *)(self+0xD8)=u.value70;destroy(&u.v,&u.tmp);return 1;}
 }
 { construct(&u.x60.name,D_0069CFA8);
 void *field=self+0x108;
 Cb *cb=&u.x10.cb; cb->vtbl=MboolReader__vtable; cb->p=field;
 s32 r=func_0020FD38(reader,&u.x60.name,cb);
 cb->vtbl=MboolReader__vtable;MReaderBase__structor_0(cb,0);destroy(&u.x60.name);
 if(r){destroy(&u.v,&u.tmp);return 1;}
 }
 { construct(&u.x60.name,D_0069CF60);
 void *field=self+0xC0;
 Cb *cb=&u.x10.cb; cb->vtbl=MboolReader__vtable; cb->p=field;
 s32 r=func_0020FD38(reader,&u.x60.name,cb);
 cb->vtbl=MboolReader__vtable;MReaderBase__structor_0(cb,0);destroy(&u.x60.name);
 if(r){destroy(&u.v,&u.tmp);return 1;}
 }
destroy(&u.v,&u.tmp);return 0;
}
