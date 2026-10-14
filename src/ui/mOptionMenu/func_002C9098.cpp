/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
struct E { short d; short pad; void (*fn)(void *, void *, s32, void *); };
struct VObj { char pad[4]; char *vt; };
struct S {
 char pad0[0xC0]; void *c0; void *c4; void *c8; VObj *cc;
 char pad1[8]; s32 d8; char pad2[0x1C]; float f8; s32 fc; s32 f100; s32 f104;
 float f108; float f10c; float f110[3]; float f11c;
};
struct Cur { void *p; char pad[12]; };
extern char D_0069C7B8[];
extern "C" void func_0023FB80(void *);
extern "C" void func_0023F8C8(void *,char *);
extern "C" void func_0023DDF0(void *,int);
extern "C" s32 func_00265D00(void *);
extern "C" void func_0030BB18(void *);
extern "C" void func_00309348(void *,void *);
extern "C" void func_00309378(void *,s32);
extern "C" void func_003285A8(s32);
extern "C" void func_003285F8(s32);
extern "C" float func_002C8FA8(void *) throw();
extern "C" void *func_002C8180(void *) throw();
extern "C" void mWidget__setWindowH(void *,float);
extern "C" void *mWidget__getRootWindow(void *);
extern "C" void func_0025BAA0(void *,float *,float *,float *,float *);
extern "C" float mWidget__getWindowY(void *);
extern "C" void mWidget__setWindowY(void *,float);
extern "C" void func_0025BA68(void *,float,float);
extern "C" void func_0025B500(void *,float *,float *,float *,float *);
extern "C" void func_0025B538(void *,float,float,float,float);
extern "C" void mWidget__setOpacity(void *,float);
extern "C" void func_00231F60(s32,void *);
extern "C" void mUpdateContext__Sync(s32);
extern "C" void func_002C8D68(void *,s32) throw();
extern "C" void func_002C9098(S *self,s32 arg1) {
 union { Cur c; char h0[16]; } u; s32 rbuf[4]; s32 tbuf[4]; float a[4]; float b[4]; s32 v;
 func_0023FB80(&u.c); func_0023F8C8(u.c.p,D_0069C7B8); func_0023DDF0(&u.c,2);
 if (func_00265D00(self) != 0) {
  VObj **hp = &self->cc;
  if (*hp != 0) {
   func_0030BB18(u.h0);
   s32 *r = rbuf; func_0030BB18(r);
   s32 *t = tbuf; v = arg1; func_00309348(t,&v);
   if (r != t) { s32 nv = t[0]; if (nv) func_003285A8(nv); if (r[0]) func_003285F8(r[0]); r[0] = nv; }
   func_00309378(t,2);
   VObj *o = *hp; E *e = (E *)(o->vt+0xA8); e->fn((char *)o+e->d,u.h0,1,r);
   s32 *p = rbuf+1; while (r != p) { --p; func_00309378(p,2); }
   func_00309378(u.h0,2);
  }
 }

 float height=func_002C8FA8(self); self->f8=height; mWidget__setWindowH(self->c4,height);
 void *item=func_002C8180(self);
 if (item) {
  func_0025BAA0(mWidget__getRootWindow(self),b,b+1,b+2,b+3);
  float margin=b[3]/20.0f; self->f108=b[1]+margin; self->f10c=b[1]+b[3]-margin;
  mWidget__setWindowY(self->c4,-mWidget__getWindowY(item));
  func_0025BAA0(self->c4,a,a+1,a+2,a+3);
  float h=self->f8;
  if (b[3]-2.0f*(b[3]/20.0f)<h) {
   float *p=self->f110; p[2]=a[1]; p[1]=p[0]=0.0f; self->f11c=a[1]; self->f104=1;
  } else {
   float y=a[1];
   if (y<self->f108) { y=self->f108; a[1]=y; }
   else if (self->f10c<y+h) { y-=y+h-self->f10c; a[1]=y; }
   func_0025BA68(self->c4,a[0],y);
  }
  if (self->c8) { func_0025B500(self->c4,a,a+1,a+2,a+3); func_0025B538(self->c8,a[0]+4.0f,a[1]+4.0f,a[2],a[3]); }
 }
 s32 old=self->d8; self->fc=1; self->f100=old;
 mWidget__setOpacity(self->c0,0.0f); func_00231F60(arg1,self->c0); mUpdateContext__Sync(1); func_002C8D68(self,arg1);
}
