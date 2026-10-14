/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned int u32;
typedef int s32;
struct Rep { u32 len, res, ref, selfish; };
struct Str { char *dat; char pad[12]; };
struct Heap { const char *name; };
struct Cb { void **vtbl; void *p; char pad[8]; };
extern Rep D_00659FA8;
extern char D_00699088[], D_00699098[], D_00699160[];
extern void *MstringReader__vtable[];
extern void *MintReader__vtable[];
extern "C" char *func_005C2560(Rep *r);
extern "C" u32 func_0057F260(const char *s) throw();
extern "C" Heap *func_005C11A8(void);
extern "C" void func_00326798(void *p, u32 n, u32 align, const char *name);
extern "C" Str *func_005C2630(Str *, u32, u32, const char *, u32);
extern "C" s32 mSlideShowFace__virtual_61(char *, void *);
extern "C" s32 func_0020FD38(void *, Str *, Cb *);
extern "C" void MReaderBase__structor_0(Cb *, s32);
extern "C" void func_0020FE28(Str *, void *, Str *);
extern "C" int MboolReader__structor_7(char *,void *);
extern "C" void func_002B7118(void *,Str *);
extern "C" void func_002B7310(void *,Str *);
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
extern "C" s32 MintReader__structor_4(char *self,void *reader) {
 if(mSlideShowFace__virtual_61(self,reader)) return 1;
 if(MboolReader__structor_7(self+0xA0,reader)) return 1;
 struct Locals { Str value; Str name; Cb cb0; Cb cb1; int blend[4]; Cb cb2; } u;
 construct(&u.value);
 {
  construct(&u.name,D_00699088);
  Cb *cb=&u.cb0;
  cb->vtbl=MstringReader__vtable; cb->p=&u.value;
  s32 r=func_0020FD38(reader,&u.name,cb);
  cb->vtbl=MstringReader__vtable; MReaderBase__structor_0(cb,0); destroy(&u.name);
  if(r) {func_002B7118(*(void **)(self+0x104),&u.value);destroy(&u.value);return 1;}
 }
 {
  construct(&u.name,D_00699098);
  Cb *cb=&u.cb1;
  cb->vtbl=MstringReader__vtable; cb->p=&u.value;
  s32 r=func_0020FD38(reader,&u.name,cb);
  cb->vtbl=MstringReader__vtable; MReaderBase__structor_0(cb,0); destroy(&u.name);
  if(r) {func_002B7310(*(void **)(self+0x104),&u.value);destroy(&u.value);return 1;}
 }
 {
  construct(&u.name,D_00699160);
  Cb *cb=&u.cb2;
  cb->vtbl=MintReader__vtable; cb->p=u.blend;
  s32 r=func_0020FD38(reader,&u.name,cb);
  cb->vtbl=MintReader__vtable; MReaderBase__structor_0(cb,0); destroy(&u.name);
  if(r) {*(s32 *)(self+0x108)=u.blend[0];destroy(&u.value);return 1;}
 }
 destroy(&u.value);return 0;
}
