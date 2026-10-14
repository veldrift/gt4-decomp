/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Vec { float x,y,z; float &X() { return x; } float &Y() { return y; } float &Z() { return z; } };
struct Obj { char p[8]; float distance,range; char q[0x170]; void *rng; void *course; };
extern "C" {
float func_00344720(void *); float func_00344748(void *); float func_00344770(void *);
float func_00344798(void *,float); float func_003447F8(void *,float); float func_00344828(void *,float);
int func_0034C518(void *,int,int,Vec *,float);
float func_0036EA98(Vec *) throw();
float RaceCourse__getVPosition(void *,void *);
int func_003FCB20(void *,Vec *);
float func_003FE358(void *,Vec *,int *);
int func_003FE7B0(void *,Vec *,Vec *,Vec *,int *,float);
void func_004A0690(); void func_004A06F0(); void func_004A53F8(); void func_004A5400(); void func_004A7454();
void func_004A7550(void *); void func_004A7844(float,float,float); void func_004A7988(float); void func_004A79B0(float); void func_004A79D8(float);
float func_00578598(void *); float func_005F5010(Vec *);
void func_005F5040(Vec *,Vec *); void func_005F5230(Vec *,Vec *); void func_005F5268(Vec *,Vec *);
}
static inline void set(Vec *v,float x,float y,float z) { v->X()=x; v->Y()=y; v->Z()=z; }
static inline void scale(Vec *v,float f) { v->X()*=f; v->Y()*=f; v->Z()*=f; }
extern "C" int func_00381D88(Obj *self,void *car,void *path,float factor) {
 Vec pos,angles,origin,dir,delta;
 Vec *porigin=&origin,*pdir=&dir,*pdelta=&delta;
 void *rng=self->rng;
 factor *= func_00578598(rng)*0x1.333332p-3f+0x1.999998p-5f;
 int ok=1;
 if(factor>0.5f) factor=0.5f;
 set(porigin,func_00344798(car,0.0f),func_003447F8(car,0.0f),func_00344828(car,0.0f));
 func_005F5040(porigin,pdir);
 set(pdelta,func_00344720(car),func_00344748(car),func_00344770(car));
 func_005F5268(pdir,pdelta);
 float range=func_00578598(rng)*30.0f+50.0f;
 func_005F5040(pdir,&pos);
 scale(&pos,factor*60.0f);
 func_005F5230(&pos,porigin);
 pos.X() += 2.0f*func_00578598(rng)-1.0f;
 pos.Y() = origin.Y()+3.0f;
 pos.Z() += 2.0f*func_00578598(rng)-1.0f;
 void *course=self->course;
 struct Query { Vec v; int id; } query;
 Vec hit;
 int id=-1;
 query.id=-1;
 query.v.x=pos.X(); query.v.y=pos.Y()+0.0f; query.v.z=pos.Z();
 Vec start,end;
 float height; Vec *pend;
 if(func_0034C518(path,6,0,&hit,RaceCourse__getVPosition(course,&query))<0 ||
    (set(&start,hit.x,hit.y,hit.z),pend=&end,id=func_003FCB20(course,&start),id<0) ||
    (func_003FE7B0(course,&start,&pos,pend,&id,0.5f),id=-1,height=func_003FE358(course,pend,&id),id<0)) ok=0;
 else { float h=height+0x1.999998p-4f; float *ey=&end.Y(); *ey=h+func_00578598(rng)*0x1.333332p-1f; func_005F5040(pend,&pos); }
 func_005F5040(&pos,pdelta);
 func_005F5268(pdelta,porigin);
 float *ay=&angles.Y(),*ax=&angles.X(); *ay=func_00578598(rng)*20.0f-15.0f;
 float a=func_0036EA98(pdelta);
 *ax=a+func_00578598(rng)*20.0f-10.0f;
 float *az=&angles.Z(); *az=func_00578598(rng)*30.0f-15.0f;
 float len=func_005F5010(pdelta);
 __asm__("sqrt.s %0,%1":"=f"(len):"f"(len));
 self->distance=len; self->range=range;
 func_005F5040(&pos,(Vec *)((char *)self+0x190));
 func_004A0690();func_004A53F8();func_004A7454();
 func_004A79D8(angles.Z());func_004A7988(angles.Y());func_004A79B0(angles.X());
 func_004A7844(-pos.x,-pos.y,-pos.z);func_004A7550((char *)self+0x100);func_004A5400();func_004A06F0();
 return ok;
}
