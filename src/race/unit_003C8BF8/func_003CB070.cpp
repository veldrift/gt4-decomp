/* compiler: ee-gcc2.96-no-strict-aliasing */
struct V3 { float x,y,z; };
struct Point { float x,y,z,a; };
struct O { char pad[8]; int i8; float x,y,z; int i18; float angle; int i20; Point target; char pad34[0xC]; float m40,m44,m48,m4c,m50,m54,m58,m5c,m60,m64,m68,m6c; };
struct Data { char pad[0x52]; unsigned short count; char pad54[0x3C]; Point *points; };
extern "C" void func_0046BEC0(void *,int,float *,float *,int *);
extern "C" void func_0057D8A0(float *,float *,float);
static inline Point *get(Data *d,int i) { Point *p=d->points; p+=i; return p; }
static inline void set2(float *a,float *b,float v0,float v1) { *a=v0; *b=v1; }
static inline int getcount(Data *d) { return d->count; }
static inline float read(float *p) { return *p; }
static inline void invert(O *out,float *a,float *b,float *c,float *d,float *e,float *f) {
 out->m58=read(a); out->m5c=read(d);
 out->m60=-read(a)*read(c)-read(d)*read(f);
 out->m64=read(b); out->m68=read(e);
 out->m6c=-read(b)*read(c)-read(e)*read(f);
}
extern "C" void func_003CB070(O *o,int idx,char *ctx,Data *data) {
 int state;
 V3 v,w;
 float sc[2];
 float *p40=&o->m40;
 func_0046BEC0(ctx+0xDA50,idx,&v.x,&w.x,&state);
 o->i18=0;
 o->x=v.x; o->y=v.z; o->z=-v.y;
 o->angle=w.z; o->i20=0;
 func_0057D8A0(&sc[0],&sc[1],w.z);
 float *p44=&o->m44, *p4c=&o->m4c, *p50=&o->m50, *p54=&o->m54, *p48=&o->m48;
 *p40=sc[1]; *p44=sc[0]; *p4c=-sc[0]; *p50=sc[1];
 set2(p48,p54,o->x,o->z);
 invert(o,p40,p44,p48,p4c,p50,p54);
 int found=0;
 if(data) {
  
  int best=0; float dist=-1.0f;
  int i=0;
  if(data->count!=0) {
  float ox=o->x, oy=o->y, oz=o->z;
  Point *p=data->points;
  do {
   float dx=p->x-ox;
   float dy=p->y-oy;
   float dz=p->z-oz;
   float d=dx*dx+dy*dy+dz*dz;
   p++;
   if(i==0 || d<dist) { dist=d; best=i; }
   i++;
  } while(i<(int)data->count);
  }
  if(dist>=0.0f) {
   found=1;
   o->target.x=get(data,best)->x;
   o->target.y=get(data,best)->y;
   o->target.z=get(data,best)->z;
   o->target.a=get(data,best)->a+0x1.921cacp+1f;
  }
 }
 if(found==0) {
  o->target.x=o->x; o->target.y=o->y; o->target.z=o->z; o->target.a=o->angle;
 }
 o->i8=state;
}
