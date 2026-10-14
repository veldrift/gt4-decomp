/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Rep { int len,cap,ref,sel; };
struct Str { char *p; };
extern Rep D_00659FA8;
extern char mFrameImageFace__vtable[];
extern "C" int mImageFace__structor_0(void *);
extern "C" void func_00210810(void *);
extern "C" char *func_005C2560(Rep *);
static inline void init(Str *s) {
 char *v;
 if(D_00659FA8.sel) v=func_005C2560(&D_00659FA8);
 else { v=(char *)(&D_00659FA8+1); D_00659FA8.ref=D_00659FA8.ref+1; }
 s->p=v;
}
extern "C" void mFrameImageFace__structor_0(char *self) {
 Str *s=(Str *)(self+0xf0);
 mImageFace__structor_0(self);
 *(void **)(self+4)=mFrameImageFace__vtable;
 init(s);
 init((Str *)(self+0xf4));
 init((Str *)(self+0xf8));
 init((Str *)(self+0xfc));
 init((Str *)(self+0x100));
 init((Str *)(self+0x104));
 init((Str *)(self+0x108));
 init((Str *)(self+0x10c));
 func_00210810(self+0x110);
 func_00210810(self+0x114);
 func_00210810(self+0x118);
 func_00210810(self+0x11c);
 func_00210810(self+0x120);
 func_00210810(self+0x124);
 func_00210810(self+0x128);
 func_00210810(self+0x12c);
 *(float *)(self+0x130)=16.0f;
 *(float *)(self+0x134)=16.0f;
}
