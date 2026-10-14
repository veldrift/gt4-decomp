/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Entry { unsigned char kind; char pad1[3]; float x,y,height; short id; unsigned char a,b; float distance,radius,c,d,angle; unsigned char flags[4]; float length,delta,slope; };
struct View { int data,count,pad[2]; };
struct Point { float x,y,z,angle; };
struct Runway { char pad[0x52]; unsigned short count; char pad54[0x3c]; Point *points; };
struct Course { int pad; void *data; };
struct Obj { Course *course; int count; int *table; };
struct Input { char pad[0x14]; int count; int *table; };
struct Vec { float x,y,z; int id; };
extern unsigned char D_00624018[];
extern "C" float func_0036CB90(float);
extern "C" float RaceCourse__getVPosition(Course *, Vec *);
extern "C" Runway *CourseData__getRunway(void *);
extern "C" void func_00469F08(View *,Obj *,int);
extern "C" Entry *func_00469FC8(View *,int);
extern "C" int func_0046A050(Obj *,int);
extern "C" float func_0046A0B0(Obj *);
extern "C" float func_0046A0C8(Course *,int *,int *,float,float,float);
extern "C" int func_0046A140(Course *,float *,float *,float *,int *,int *,int *,int,float,float,float,float);
extern "C" int func_0046B230(Input *);
extern "C" void func_0046B248(Input *,Input *);
extern "C" int func_0046BCB0(int **,Input *,int);
extern "C" float func_0057D118(float,float);
static inline void setKind(Entry *e,int kind) { e->kind=kind; }
static inline void setVec(Vec *v,float *p,int id) { v->x=p[0];v->y=p[2];v->z=-p[1];v->id=id; }
static inline float root(float v) { float r; __asm__("sqrt.s %0,%1":"=f"(r):"f"(v)); return r; }
extern "C" int func_0046A510(Obj *self,Input *input) {
 View view;
 float pos[4];
 int extra,id,miss;
 Vec vec;
 float height,c,d;
 float courseLength=func_0046A0B0(self);
 if(func_0046B230(input)) {
  func_0046B248(input,input);
  self->count=input->count;
  self->table=input->table;
 } else self->count=func_0046BCB0(&self->table,input,0);
 for(int k=0;k<8;k++) {
  int type=D_00624018[k];
  float lastDistance=0.0f;
  int invalid=0;
  if(func_0046A050(self,type)) {
   int wrapped=0;
   func_00469F08(&view,self,type);
   int count=view.count;
   float h=1000.0f,oldX=0.0f,oldY=0.0f;
   int i;
   for(i=0;i<count;i++) {
    Entry *e=func_00469FC8(&view,i);
    pos[0]=e->x; pos[1]=e->y;
    if(i>0) {
     float dy=pos[1]-oldY;
     float dx=pos[0]-oldX;
     float estimate=h+(root(dx*dx+dy*dy)*0.1f+1.0f);
     float v=func_0046A0C8(self->course,&id,&miss,pos[0],pos[1],estimate);
     if(miss) {
      v=func_0046A0C8(self->course,&id,&miss,pos[0],pos[1],estimate+100.0f);
      if(miss) v=h+3.0f;
     }
     h=(int)v+2;
    }
    pos[2]=h; oldX=pos[0];oldY=pos[1];
    short recordId=e->id;
    if(e->kind) {
     if(type!=5) {
      if(!(e->radius>0.0f)) e->kind=2;
      else e->kind=1;
     } else e->kind=1;
    }
    if(type==4 && i>=3 && i<=count-4) {
     Runway *r=CourseData__getRunway(self->course->data);
     int nearest=-1;
     unsigned short pointCount=r->count;
     float minDist=100000.0f;
     for(int j=0;j<pointCount;j++) {
      float dx=r->points[j].x-pos[0];
      float dy=-r->points[j].z-pos[1];
      float dist=root(dx*dx+dy*dy);
      if(dist>5.0f) continue;
      if(dist<minDist || nearest==-1) { minDist=dist; nearest=j; }
     }
     if(nearest!=-1) {
      Point *p=r->points+nearest;
      pos[0]=e->x=p->x;
      pos[1]=e->y=-p->z;
      e->angle=func_0036CB90(p->angle+3.14159265f);
     }
    }
    setVec(&vec,pos,recordId);
    e->distance=RaceCourse__getVPosition(self->course,&vec);
    e->height=0;e->c=0;e->d=0;e->a=0;e->b=0;
    if(type!=5) {
     if(func_0046A140(self->course,&height,&c,&d,&miss,&id,&extra,recordId,e->x,e->y,h,e->angle)) {
      h=height;e->height=h;e->c=c;e->d=d;e->a=miss;e->b=id;
     }
    }
    if(type==4) {
     if(e->distance<courseLength*0.5f) wrapped=1;
     if(wrapped==1) e->distance+=courseLength;
    }
    if(e->distance<=lastDistance) invalid=1;
    lastDistance=e->distance;
   }
   for(i=0;i<count;i++) {
    Entry *e=func_00469FC8(&view,i);
    Entry *next=func_00469FC8(&view,i<count-1?i+1:0);
    e->flags[0]=0;e->flags[1]=0;e->flags[2]=0;e->flags[3]=0;
    float dx=next->x-e->x;float dy=next->y-e->y;
    e->length=root(dx*dx+dy*dy);
    unsigned char kind=e->kind;
    if(kind==1 || kind==2) {
     float radius=e->radius; if(radius<0) radius=-radius;
     float a=next->angle,b=e->angle;
     if(kind==1) { if(a<b) b-=6.2831853f; }
     else { if(b<a) a-=6.2831853f; }
     float diff=a-b;if(diff<0) diff=-diff;
     e->length=radius*diff;
    }
    e->delta=next->height-e->height;
    if(e->length>0) e->slope=func_0057D118(e->delta,e->length);
   }
   for(i=0;i<count;i++) {
    Entry *e=func_00469FC8(&view,i);
    Entry *prev=func_00469FC8(&view,i>0?i-1:count-1);
    if(e->slope-prev->slope < -0.017453292f) e->flags[0]=1;
   }
   if(invalid && (type==1 || type==2 || type==7)) self->table[type]=0;
  }
 }
 return 1;
}
