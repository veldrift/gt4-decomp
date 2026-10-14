/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Obj { int base; char *vt; };
struct Face { char pad[0xB4]; int b4; void *b8; Obj *image; char p[12]; float cc,d0,d4,d8,dc,e0,e4,e8; };
extern "C" void func_002030A0(void *);
extern "C" void func_002030C0(void *,void *);
extern "C" void func_002030E8(void *,void *);
extern "C" void func_00203118(void *,int);
extern "C" float func_00231420(void *);
extern "C" float func_00231440(void *);
extern "C" void mColorFace__virtual_70(void *,void *,int);
extern "C" int func_00286060(void *);
extern "C" void *func_002861D8(void *,int);
extern "C" float func_002A3820(void *,int);
extern "C" float func_002A3860(void *,int);
extern "C" void func_005769F0(void *);
extern "C" void func_00576A28(void *);
extern "C" char D_00836D58[];
struct Vec { float v[4]; Vec() { func_002030A0(this); } Vec(void *p) { func_002030C0(this,p); } ~Vec() {func_00203118(this,2);} };
static inline void *copy_colors(Vec *c, Face *self) {
   void *value=func_002861D8(self,0);
   func_002030E8(c,value);
   func_002030E8(c+1,func_002861D8(self,1));
   func_002030E8(c+2,func_002861D8(self,3));
   func_002030E8(c+3,func_002861D8(self,2));
 return c;
}
struct EI {short d,i; int (*fn)(void *);};
struct EF {short d,i; float (*fn)(void *);};
struct EV {short d,i; void (*fn)(void *);};
struct EV1 {short d,i; void (*fn)(void *,void *);};
struct EI1 {short d,i; int (*fn)(void *,void *);};
static inline int vi1(Obj *o,int n,void *p) { EI1 *e=(EI1 *)(o->vt+n); return e->fn((char *)o+e->d,p); }
struct EDraw {short d,i; void (*fn)(void *,int,void *,void *,void *);};
static inline int vi(Obj *o,int n) { EI *e=(EI *)(o->vt+n); return e->fn((char *)o+e->d); }
static inline float vf(Obj *o,int n) { EF *e=(EF *)(o->vt+n); return e->fn((char *)o+e->d); }
static inline void vv(Obj *o,int n) { EV *e=(EV *)(o->vt+n); e->fn((char *)o+e->d); }
static inline void vv1(Obj *o,int n,void *p) { EV1 *e=(EV1 *)(o->vt+n); e->fn((char *)o+e->d,p); }
extern "C" void mImageFace__virtual_70(Face *self,Obj *ctx,int active) {
 mColorFace__virtual_70(self,ctx,0);
 if(active && self->image && vi(self->image,0x58)) {
  void *colors=0;
  float w=func_00231420(ctx); float h=func_00231440(ctx);
  struct P {float x,y;} pos[4];
  pos[0].x=0; pos[0].y=0; pos[1].x=w; pos[1].y=0; pos[2].x=0; pos[2].y=h; pos[3].x=w; pos[3].y=h;
  Vec c[4];
  if(func_00286060(self)==1) {
   void *value=func_002861D8(self,0);
   colors=0;
   Vec tmp(value); vi1(ctx,0x198,&tmp);
  } else if(func_00286060(self)==4) {
   colors=copy_colors(c,self);
  }
  float iw=vf(self->image,0x70),ih=vf(self->image,0x78);
  float sx=func_002A3820(self,vi(self->image,0x48));
  float sy=func_002A3860(self,vi(self->image,0x50));
  func_005769F0(D_00836D58);
  P uv[4]; P *puv=uv;
  puv[0].x=self->cc*iw; puv[0].y=self->d0*ih;
  puv[1].x=self->d4*iw*sx; puv[1].y=self->d8*ih;
  puv[2].x=self->e4*iw; puv[2].y=self->e8*ih*sy;
  puv[3].x=self->dc*iw*sx; puv[3].y=self->e0*ih*sy;
  func_00576A28(D_00836D58);
  vv(ctx,0x1D0); vv1(ctx,0x1C0,(void *)self->b4); vv(self->image,0x68);
  EDraw *e=(EDraw *)(ctx->vt+0x1B0); e->fn((char *)ctx+e->d,4,pos,puv,colors);
  vv(ctx,0x1C8); vv(ctx,0x1D8);
 }
}
