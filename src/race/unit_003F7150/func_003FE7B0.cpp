/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Vec { float x,y,z; };
struct Collision { Vec start,end; int hit; Vec point; float distance; };
struct Search { char pad[44]; unsigned short low; short high; };
struct Scene { int a; void *course; };
extern "C" {
void func_00395A38(void *,void *,void *,int,float,float,float,float);
void *CourseData__getRunway(void *);
int GT4Course__RunwayData__search(void *,void *,void *);
float func_005F5010(void *);
void func_005F5040(void *,void *);
void func_005F5230(void *,void *);
void func_005F5268(void *,void *);
void func_003FE680();
}
static inline float &element(Vec *v, int i) { return ((float*)v)[i]; }
static inline float length(void *v) { float r=func_005F5010(v); __asm__("sqrt.s %0, %1":"=f"(r):"f"(r)); return r; }
static inline void scale(Vec *v,float f) {
 int o1=4,o2=8; float *y=(float*)((char*)v+o1), *z=(float*)((char*)v+o2);
 v->x*=f;*y*=f;*z*=f;
}
extern "C" int func_003FE7B0(Scene *scene,Vec *start,Vec *end,Vec *out,int *id,float margin) {
 Vec delta,prev,next;
 Collision collision;
 Search search;
 float z=0.0f;
 func_005F5040(end,out);
 func_005F5040(end,&delta);
 func_005F5268(&delta,start);
 float distance=func_005F5010(&delta);
 __asm__("sqrt.s %0, %1":"=f"(distance):"f"(distance));
 float temp=0.0001f;
 if(distance<temp)return 0;
 int done=0, count=0;
 float travelled=z;
 float factor=(distance+margin)/distance;
 float *dy=&element(&delta,1), *dz=&element(&delta,2);
 temp=delta.x; delta.x=temp*factor; *dy*=factor; *dz*=factor;
 float total=length(&delta);
 func_005F5040(start,&prev);
 
 Vec *pp=&prev; Vec *np=&next;
 for(;;) {
  travelled+=4.0f;
  if(total<=travelled) { travelled=total;done=1; }
  func_005F5040(&delta,&next);
  float ratio=travelled/total;
  scale(&next,ratio);
  func_005F5230(&next,start);
  float zero=0.0f;
  collision.hit=0;collision.distance=zero;
  func_005F5040(&prev,&collision.start);
  func_005F5040(&next,&collision.end);
  float lx=pp->x, hx=element(&next,0), lz=prev.z;
  if(hx<lx) { float t=hx;hx=lx;lx=t; }
  z=element(&next,2);
  if(z<lz) {float t=z;z=lz;lz=t;}
  func_00395A38(scene,(void*)func_003FE680,&collision,*id,lx,lz,hx,z);
  if(collision.hit) {
   func_005F5040(&collision.point,out);
   func_005F5268(out,start);
   float d=length(out);
   if(d>0.001f) {
    float len=d-margin;
    if(len<zero)len=zero;
    scale(out,len/d);
   }
   func_005F5230(out,start);return 1;
  }
  unsigned short *lo=&search.low; Search *ps=&search;
  *lo=0xffff;search.high=-1;
  collision.start.x=element(&next,0);collision.start.y=element(&next,1)+10.0f;collision.start.z=element(&next,2);
  if(GT4Course__RunwayData__search(CourseData__getRunway(scene->course),ps,&collision.start)) {
   *id=(search.high<<16)|*lo;
  } else {
   func_005F5040(&prev,out);return 0;
  }
  func_005F5040(&next,out);
  func_005F5040(&next,&prev);
  if(done)break;
  ++count; if(count<9)done=0; else done=1;
 }
 return 0;
}
