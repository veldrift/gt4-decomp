/* compiler: ee-gcc2.96-no-strict-aliasing */
extern "C" {
void func_00385470(int *,int);
float func_003856F8(void *);
float func_00385798(void *);
float func_003857D8(void *);
float func_003857A0(void *);
float func_003857E0(void *);
float func_00385818(void *);
float func_00385820(void *);
float func_00385AB8(void *);
float *func_00385B48(int *);
float *func_00385BD8(int *);
float *func_00385BF8(int *);
float *func_00385BE8(int *);
float *func_00385C08(int *);
float *func_00385C18(int *);
float *func_00385C28(int *);
float *func_00385E58(int *);
int func_00422A20(float);
}
static inline float maxf(float x,float y) { float r; asm("max.s %0,%1,%2":"=f"(r):"f"(x),"f"(y)); return r; }
static inline float minf(float x,float y) { float r; asm("min.s %0,%1,%2":"=f"(r):"f"(x),"f"(y)); return r; }
static inline float clamp(float x) {return minf(maxf(x,0.0f),1.0f);}
static inline float clampref(float v) { float r; asm("max.s %0,%1,%2":"=f"(r):"f"(v),"f"(0.0f):"memory"); asm("min.s %0,%1,%2":"=f"(r):"f"(r),"f"(1.0f)); return r; }
extern "C" void func_00403BD8(char *self,int arg,float t) {
 struct { int h; float x; } sp;
 char *a=self+0x160;
 func_00385470(&sp.h,arg);
 char *b=self+0x260;
 float x=clamp(func_003856F8(a));
 float y=clamp(func_003856F8(b));
 if(y-x>0.8f) {
  y=y*t+(x+1.0f)*(1.0f-t);
  y=y-(float)func_00422A20(y);
  *func_00385B48(&sp.h)=y;
 }
 float v=func_00385798(a);
 if(v==func_003857D8(a)) {
  v=func_00385798(b);
  if(v!=func_003857D8(b)) {
   float *p=func_00385BD8(&sp.h); *p=func_00385798(b);
   p=func_00385BF8(&sp.h); *p=func_003857D8(a);
   clamp(func_00385818(a));
   sp.x=clamp(func_00385818(b))*t+(1.0f-t);
   sp.x=clampref(sp.x);
   *func_00385C18(&sp.h)=sp.x;
  }
 }
 v=func_003857A0(a);
 if(v==func_003857E0(a)) {
  v=func_003857A0(b);
  if(v!=func_003857E0(b)) {
   float *p=func_00385BE8(&sp.h); *p=func_003857A0(b);
   p=func_00385C08(&sp.h); *p=func_003857E0(a);
   clamp(func_00385820(a));
   sp.x=clamp(func_00385820(b))*t+(1.0f-t);
   sp.x=clampref(sp.x);
   *func_00385C28(&sp.h)=sp.x;
  }
 }
 float z=func_00385AB8(b);
 float w=func_00385AB8(a);
 int iz=(int)z;
 if(z-w>0.5f || w-z>0.5f) {
  float iw=(float)(int)w;
  z=z*t+((float)iz+(w-iw))*(1.0f-t);
  int n=(int)z;
  if(n==iz) *func_00385E58(&sp.h)=z;
  else *func_00385E58(&sp.h)=iw+(z-(float)n);
 }
}
