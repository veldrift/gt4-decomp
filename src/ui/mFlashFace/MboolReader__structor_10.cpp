/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned int u32;
typedef int s32;
struct Rep { u32 len, res, ref, selfish; };
struct Str { char *dat; char pad[12]; };
struct Heap { const char *name; };
struct Cb { void **vtbl; void *p; char pad[8]; };
extern Rep D_00659FA8;
extern char D_0069B1E8[], D_0069B218[], D_0069B220[], D_0069B230[], D_0069B250[], D_0069B258[], D_0069B240[];
extern char D_0069B3D0[];
extern char D_0069B3E0[];
extern char D_0069B3F0[];
extern char D_0069B400[];
extern char D_0069B410[];
extern char D_0069B420[];
extern char D_0069B430[];
extern char D_0069B440[];
extern char D_0069B450[];
extern void *MstringReader__vtable[], *MboolReader__vtable[];
extern "C" char *func_005C2560(Rep *r);
extern "C" u32 func_0057F260(const char *s) throw();
extern "C" Heap *func_005C11A8(void);
extern "C" void func_00326798(void *p, u32 n, u32 align, const char *name);
extern "C" Str *func_005C2630(Str *, u32, u32, const char *, u32);
extern "C" s32 mSlideShowFace__virtual_61(char *, void *);
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

extern "C" void func_002939D8(char *,Str *);
extern "C" void func_00293AE0(char *,s32);
extern "C" void func_00293B10(char *,s32);
extern "C" void func_00293B40(char *,s32);
extern "C" void func_00293B70(char *,s32);
extern "C" void func_00293BA0(char *,s32);
struct Flags { u32 low:6; u32 repeat:1; u32 high:25; };
extern "C" s32 MboolReader__structor_10(char *self,void *reader) {
 if(mSlideShowFace__virtual_61(self,reader)) return 1;
 struct Locals { Str value; union { Str name; Cb cb; } a; Cb cb0; Str result; s32 flag; char pad[12]; union { Str name; Cb cb; } b; } u;
 construct(&u.value);
 {
 construct(&u.a.name,D_0069B1E8);
 Cb *cb=&u.cb0;
 cb->vtbl=MstringReader__vtable; cb->p=&u.value;
 s32 r=func_0020FD38(reader,&u.a.name,cb);
 cb->vtbl=MstringReader__vtable; MReaderBase__structor_0(cb,0); destroy(&u.a.name);
 if(r) {func_0020FE28(&u.result,reader,&u.value);func_002939D8(self,&u.result);destroy(&u.result);destroy(&u.value);return 1;}
 }
 {
 construct(&u.a.name,D_0069B218);
 Cb *cb=&u.b.cb;
 cb->vtbl=MboolReader__vtable; cb->p=&u.flag;
 s32 r=func_0020FD38(reader,&u.a.name,cb);
 cb->vtbl=MboolReader__vtable; MReaderBase__structor_0(cb,0); destroy(&u.a.name);
 if(r) {func_00293AE0(self,u.flag);destroy(&u.value);return 1;}
 }
 {
 construct(&u.b.name,D_0069B220);
 Cb *cb=&u.a.cb;
 cb->vtbl=MboolReader__vtable; cb->p=&u.flag;
 s32 r=func_0020FD38(reader,&u.b.name,cb);
 cb->vtbl=MboolReader__vtable; MReaderBase__structor_0(cb,0); destroy(&u.b.name);
 if(r) {func_00293B10(self,u.flag);destroy(&u.value);return 1;}
 }
 {
 construct(&u.b.name,D_0069B230);
 Cb *cb=&u.a.cb;
 cb->vtbl=MboolReader__vtable; cb->p=&u.flag;
 s32 r=func_0020FD38(reader,&u.b.name,cb);
 cb->vtbl=MboolReader__vtable; MReaderBase__structor_0(cb,0); destroy(&u.b.name);
 if(r) {func_00293B40(self,u.flag);destroy(&u.value);return 1;}
 }
 {
 construct(&u.b.name,D_0069B250);
 Cb *cb=&u.a.cb;
 cb->vtbl=MboolReader__vtable; cb->p=&u.flag;
 s32 r=func_0020FD38(reader,&u.b.name,cb);
 cb->vtbl=MboolReader__vtable; MReaderBase__structor_0(cb,0); destroy(&u.b.name);
 if(r) {func_00293B70(self,u.flag);destroy(&u.value);return 1;}
 }
 {
 construct(&u.b.name,D_0069B258);
 Cb *cb=&u.a.cb;
 cb->vtbl=MboolReader__vtable; cb->p=&u.flag;
 s32 r=func_0020FD38(reader,&u.b.name,cb);
 cb->vtbl=MboolReader__vtable; MReaderBase__structor_0(cb,0); destroy(&u.b.name);
 if(r) {func_00293BA0(self,u.flag);destroy(&u.value);return 1;}
 }
 {
 construct(&u.b.name,D_0069B240);
 Cb *cb=&u.a.cb;
 cb->vtbl=MboolReader__vtable; cb->p=&u.flag;
 s32 r=func_0020FD38(reader,&u.b.name,cb);
 cb->vtbl=MboolReader__vtable; MReaderBase__structor_0(cb,0); destroy(&u.b.name);
 if(r) {((Flags *)(self+0xB4))->repeat = u.flag != 0;destroy(&u.value);return 1;}
 }
 destroy(&u.value);return 0;
}
