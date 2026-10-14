/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned int u32;
typedef int s32;
struct Rep { u32 len, res, ref, selfish; };
struct Str { char *dat; char pad[12]; };
struct Heap { const char *name; };
struct Cb { void **vtbl; void *p; char pad[8]; };
extern Rep D_00659FA8;
extern char D_0069B3C0[];
extern char D_0069B3D0[];
extern char D_0069B3E0[];
extern char D_0069B3F0[];
extern char D_0069B400[];
extern char D_0069B410[];
extern char D_0069B420[];
extern char D_0069B430[];
extern char D_0069B440[];
extern char D_0069B450[];
extern void *MstringReader__vtable[], *MfloatReader__vtable[];
extern "C" char *func_005C2560(Rep *r);
extern "C" u32 func_0057F260(const char *s) throw();
extern "C" Heap *func_005C11A8(void);
extern "C" void func_00326798(void *p, u32 n, u32 align, const char *name);
extern "C" Str *func_005C2630(Str *, u32, u32, const char *, u32);
extern "C" s32 MboolReader__structor_11(char *, void *);
extern "C" s32 func_0020FD38(void *, Str *, Cb *);
extern "C" void MReaderBase__structor_0(Cb *, s32);
extern "C" Str *func_0020FE28(Str *, void *, Str *);
static inline char *grab(Rep *r) {
 if (r->selfish) return func_005C2560(r);
 ++r->ref; return (char *)(r+1);
}
static inline Str &assign(Str *s, const char *p, u32 n) {return *func_005C2630(s,0,(u32)-1,p,n);}
static inline void construct(Str *s) {s->dat=grab(&D_00659FA8);}
static inline void construct(Str *s,const char *p) {s->dat=grab(&D_00659FA8); assign(s,p,func_0057F260(p));}
static inline Rep *rep(Str *s) {return (Rep *)s->dat-1;}
static inline void deallocate(void *p,u32 n) {func_00326798(p,n,4,func_005C11A8()->name);}
static inline void rep_delete(void *p) {deallocate(p,sizeof(Rep)+((Rep *)p)->res);}
static inline void release(Rep *r) {if (--r->ref==0) rep_delete(r);}
static inline void destroy(Str *s) {release(rep(s));}

extern "C" void func_00295C68(char *,Str *) throw();
extern "C" void func_00295E20(char *,Str *) throw();
extern "C" void func_00295FD8(char *,Str *) throw();
extern "C" void func_00296190(char *,Str *) throw();
extern "C" void func_00296348(char *,Str *) throw();
extern "C" void func_00296500(char *,Str *) throw();
extern "C" void func_002966B8(char *,Str *) throw();
extern "C" void func_00296870(char *,Str *) throw();
extern "C" s32 MfloatReader__structor_7(char *self,void *reader) {
 if(MboolReader__structor_11(self,reader)) return 1;
 struct Locals { Str value,name; Cb cb0; Str r0; Cb cb1; Str r1; Cb cb2; Str r2,r3,r4; } u;
 construct(&u.value);
 {
 construct(&u.name,D_0069B3C0);
 Cb *cb=&u.cb0;
 cb->vtbl=MstringReader__vtable; cb->p=&u.value;
 s32 r=func_0020FD38(reader,&u.name,cb);
 cb->vtbl=MstringReader__vtable; MReaderBase__structor_0(cb,0); destroy(&u.name);
 if(r) {func_0020FE28(&u.r0,reader,&u.value);func_00295C68(self,&u.r0);destroy(&u.r0);destroy(&u.value);return 1;}
 }
 {
 construct(&u.name,D_0069B3D0);
 Cb *cb=&u.cb1;
 cb->vtbl=MstringReader__vtable; cb->p=&u.value;
 s32 r=func_0020FD38(reader,&u.name,cb);
 cb->vtbl=MstringReader__vtable; MReaderBase__structor_0(cb,0); destroy(&u.name);
 if(r) {func_0020FE28(&u.r1,reader,&u.value);func_00295E20(self,&u.r1);destroy(&u.r1);destroy(&u.value);return 1;}
 }
 {
 construct(&u.name,D_0069B3E0);
 Cb *cb=&u.cb2;
 cb->vtbl=MstringReader__vtable; cb->p=&u.value;
 s32 r=func_0020FD38(reader,&u.name,cb);
 cb->vtbl=MstringReader__vtable; MReaderBase__structor_0(cb,0); destroy(&u.name);
 if(r) {func_0020FE28(&u.r2,reader,&u.value);func_00295FD8(self,&u.r2);destroy(&u.r2);destroy(&u.value);return 1;}
 }
 {
 construct(&u.name,D_0069B3F0);
 Cb *cb=&u.cb0;
 cb->vtbl=MstringReader__vtable; cb->p=&u.value;
 s32 r=func_0020FD38(reader,&u.name,cb);
 cb->vtbl=MstringReader__vtable; MReaderBase__structor_0(cb,0); destroy(&u.name);
 if(r) {func_0020FE28(&u.r3,reader,&u.value);func_00296190(self,&u.r3);destroy(&u.r3);destroy(&u.value);return 1;}
 }
 {
 construct(&u.name,D_0069B400);
 Cb *cb=&u.cb0;
 cb->vtbl=MstringReader__vtable; cb->p=&u.value;
 s32 r=func_0020FD38(reader,&u.name,cb);
 cb->vtbl=MstringReader__vtable; MReaderBase__structor_0(cb,0); destroy(&u.name);
 if(r) {func_0020FE28(&u.r4,reader,&u.value);func_00296348(self,&u.r4);destroy(&u.r4);destroy(&u.value);return 1;}
 }
 {
 construct(&u.name,D_0069B410);
 Cb *cb=&u.cb0;
 cb->vtbl=MstringReader__vtable; cb->p=&u.value;
 s32 r=func_0020FD38(reader,&u.name,cb);
 cb->vtbl=MstringReader__vtable; MReaderBase__structor_0(cb,0); destroy(&u.name);
 if(r) {func_0020FE28(&u.r0,reader,&u.value);func_00296500(self,&u.r0);destroy(&u.r0);destroy(&u.value);return 1;}
 }
 {
 construct(&u.name,D_0069B420);
 Cb *cb=&u.cb0;
 cb->vtbl=MstringReader__vtable; cb->p=&u.value;
 s32 r=func_0020FD38(reader,&u.name,cb);
 cb->vtbl=MstringReader__vtable; MReaderBase__structor_0(cb,0); destroy(&u.name);
 if(r) {func_0020FE28(&u.r0,reader,&u.value);func_002966B8(self,&u.r0);destroy(&u.r0);destroy(&u.value);return 1;}
 }
 {
 construct(&u.name,D_0069B430);
 Cb *cb=&u.cb0;
 cb->vtbl=MstringReader__vtable; cb->p=&u.value;
 s32 r=func_0020FD38(reader,&u.name,cb);
 cb->vtbl=MstringReader__vtable; MReaderBase__structor_0(cb,0); destroy(&u.name);
 if(r) {func_0020FE28(&u.r0,reader,&u.value);func_00296870(self,&u.r0);destroy(&u.r0);destroy(&u.value);return 1;}
 }
 {
 construct(&u.name,D_0069B440);
 Cb *cb=&u.cb0;
 cb->vtbl=MfloatReader__vtable; cb->p=self+0x130;
 s32 r=func_0020FD38(reader,&u.name,cb);
 cb->vtbl=MfloatReader__vtable; MReaderBase__structor_0(cb,0); destroy(&u.name);
 if(r) {destroy(&u.value);return 1;}
 }
 {
 construct(&u.name,D_0069B450);
 Cb *cb=&u.cb0;
 char *p=self+0x134; cb->vtbl=MfloatReader__vtable; cb->p=p;
 s32 r=func_0020FD38(reader,&u.name,cb);
 cb->vtbl=MfloatReader__vtable; MReaderBase__structor_0(cb,0); destroy(&u.name);
 if(r) {destroy(&u.value);return 1;}
 }
 destroy(&u.value);return 0;
}
