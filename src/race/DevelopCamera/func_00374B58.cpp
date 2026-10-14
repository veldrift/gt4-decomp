/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned long long u64;
struct Bounds { float x0,x1,y0,y1; };
struct Matrix { u64 v[8]; };
struct Work { char v[32]; };
struct Vec { float x[1],y[1],z[1]; };
struct Entry { short delta,index; void (*fn)(char *,Matrix *,char *); };
struct Samples { float a,b,c,d,e; };
extern Samples D_00621008[8];
extern "C" void func_0036F000(float *,const void *,const float *) throw();
extern "C" float func_003F3708(void *);
extern "C" float func_003F3720(void *);
extern "C" float func_003F3738(void *);
extern "C" float func_003F3748(void *);
extern "C" void func_003FCE70(void *);
extern "C" void func_003FCEA8(void *,void *,void *,float);
extern "C" void func_00374B58(char *self,char *cam,Bounds *out,void *other,float a,float b,float c) {
 Matrix *input=(Matrix *)(cam+0x100);
 Matrix first=*input;
 Matrix mat;
 Work w;
 Vec pos;
 int i=0;
 Entry *e=(Entry *)(*(char **)cam+0x78);
 e->fn(cam+e->delta,&mat,self+0x9c0);
 func_003FCE70(&w);
 float k=func_003F3708(other)*b;
 float m=func_003F3720(other);
 float n=func_003F3738(other)*0.5f;
 float scale=func_003F3748(other);
 float *px=pos.x,*py=pos.y,*pz=pos.z;
 Samples *s=D_00621008;
 for(;i<8;i++,s++) {
  *px=n*s->c;
  *py=scale*(s->d*c-s->e*a);
  *pz=k*s->a+m*s->b;
  func_003FCEA8(&w,px,other,0.0f);
  func_0036F000(px,&first,px);
  func_0036F000(px,&mat,px);
  float x=*px;
  float z=*pz;
  float y=*py;
  if(z<0x1.0624dcp-10f) {
   if(x<0.0f) x=-1.0f;
   if(x>0.0f) x=1.0f;
   if(y<0.0f) y=-1.0f;
   if(y>0.0f) y=1.0f;
  } else {
   x/=z;
   y/=z;
  }
  if(x<=-10.0f) x=-10.0f;
  if(x>=10.0f) x=10.0f;
  if(y<=-10.0f) y=-10.0f;
  if(y>=10.0f) y=10.0f;
  if(i==0) {
   out->x1=out->x0=x;
   out->y1=out->y0=y;
  } else {
   if(x<out->x0) out->x0=x;
   if(out->x1<x) out->x1=x;
   if(y<out->y0) out->y0=y;
   if(out->y1<y) out->y1=y;
  }
 }
}
