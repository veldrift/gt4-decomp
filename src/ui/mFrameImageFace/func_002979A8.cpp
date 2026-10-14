/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Obj { int base; char *vt; };
extern "C" void func_002030A0(void *);
extern "C" void *func_002030E8(void *,const void *);
extern "C" void func_00203118(void *,int);
extern "C" void func_00203148(void *,float,float,float,float);
extern "C" float func_00231420(void *);
extern "C" float func_00231440(void *);
extern "C" int func_00286060(void *);
struct Vec;
extern "C" Vec *func_002861D8(void *,int);
struct Vec {
 float x,y,z,w;
 Vec() {func_002030A0(this);}
 Vec(float a,float b,float c,float d) {func_00203148(this,a,b,c,d);}
 Vec(const Vec &);
 ~Vec() {func_00203118(this,2);}
 Vec &operator=(const Vec &v) __asm__("func_002030E8");
 Vec operator*(float f) const {return Vec(x*f,y*f,z*f,w*f);}
 Vec operator+(const Vec &v) const {return Vec(x+v.x,y+v.y,z+v.z,w+v.w);}
};
struct EI {short d,i; int (*fn)(void *);};
struct EF {short d,i; float (*fn)(void *);};
struct EV {short d,i; void (*fn)(void *);};
struct EI1 {short d,i; int (*fn)(void *,void *);};
struct EDraw {short d,i; void (*fn)(void *,int,void *,void *,void *);};
static inline int vi(Obj *o,int n) { EI *e=(EI *)(o->vt+n); return e->fn((char *)o+e->d); }
static inline float vf(Obj *o,int n) { EF *e=(EF *)(o->vt+n); return e->fn((char *)o+e->d); }
static inline void vv(Obj *o,int n) { EV *e=(EV *)(o->vt+n); e->fn((char *)o+e->d); }
static inline int vi1(Obj *o,int n,void *p) { EI1 *e=(EI1 *)(o->vt+n); return e->fn((char *)o+e->d,p); }
extern "C" void func_002979A8(void *self,Obj *ctx,Obj *img,float x,float y,float w,float h) {
 struct P {float x,y;} pos[4],uv[4];
 float right=x+w,bottom=y+h;
 pos[0].x=x;pos[0].y=y;pos[1].x=right;pos[1].y=y;
 pos[2].x=x;pos[2].y=bottom;pos[3].x=right;pos[3].y=bottom;
 P *texture=0;
 if(img && vi(img,0x58)) {
  vv(ctx,0x1D0);vv(img,0x68);
  float iw=vf(img,0x70),ih=vf(img,0x78);
  P *puv=uv; puv[0].x=0; texture=puv;
  puv[0].y=0;puv[1].x=iw;puv[1].y=0;
  uv[2].x=0;puv[2].y=ih;puv[3].x=iw;puv[3].y=ih;
 } else {vv(ctx,0x1D8);}
 Vec *colors=0;
 Vec c[4];
 if(func_00286060(self)==1) {
  vi1(ctx,0x198,func_002861D8(self,0));
 } else if(func_00286060(self)==4) {
  float left=x/func_00231420(ctx);
  float top=y/func_00231440(ctx);
  float r=right/func_00231420(ctx);
  float b=bottom/func_00231440(ctx);
  colors=c;
  Vec *c0=func_002861D8(self,0);
  Vec *c1=func_002861D8(self,1);
  Vec *c2=func_002861D8(self,3);
  Vec *c3=func_002861D8(self,2);
  Vec a=*c0*(1.0f-left)+*c1*left;
  Vec d=*c2*(1.0f-left)+*c3*left;
  Vec e=*c0*(1.0f-r)+*c1*r;
  Vec f=*c2*(1.0f-r)+*c3*r;
  c[0]=a*(1.0f-top)+d*top;
  c[1]=e*(1.0f-top)+f*top;
  c[2]=a*(1.0f-b)+d*b;
  c[3]=e*(1.0f-b)+f*b;
 }
 EDraw *entry=(EDraw *)(ctx->vt+0x1B0);
 entry->fn((char *)ctx+entry->d,4,pos,texture,colors);
}
