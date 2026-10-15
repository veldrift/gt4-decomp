/* compiler: ee-gcc2.96-nsa-nosib */
struct Entry { int id, flag; float alpha,scale,angle; char pad[0x16c-20]; float x,y,z; };
struct Model { char pad[0x7c]; struct State *state; };
struct State { char pad[20]; void *p; };
struct Inner { int a,b,c; Model *model; int other; };
struct VT { short off, pad; int (*fn)(void *); };
struct Obj { int a; Inner *inner; int count; Entry *entries; VT *vt; };
struct Global { int a,b; }; extern Global D_00845C20;
extern "C" {
int func_004080B8(Obj *) throw(); int func_00407D28(float,float,float) throw();
float func_00407FA0(Entry *,float,float) throw();
void func_0040A1D0(void *,void *); void *func_00398758(void *,void *);
void func_00427820(void *); void GT4_Motion__MotionSetPlayer__set(void *,void *,int);
void func_00428AD8(void *,int,int,int,float,float); void func_00428C00(void *,int,int,int,int,float,float);
void func_004567E0(int); void func_0049AB58(float); void func_004A29A8(int);
void RaceEntryCar__update(int); void func_004A53F8(); void func_004A5400();
void func_004A7698(void *); void func_004A7844(float,float,float); void func_004A7890(float,float,float); void func_004A79B0(float);
}
static inline int vcall(Obj *o) { VT *v=o->vt+1; return v->fn((char*)o+v->off); }
extern "C" void Concourse__render(Obj *o,void *car) {
 char buf[16]; float matrix[16]; float pos[4];
 if(func_004080B8(o)) {
  for(int i=0;i<o->count;i++) {
   Entry *e=o->entries+i;
   float *x, *y, *z; z=&e->z; x=&e->x; y=&e->y;
   float scale=e->scale; int flag=e->flag; float angle=e->angle;
   if(func_00407D28(*x,*y,*z)) {
    func_0040A1D0((char*)(o->entries+i)+0x20,car);
    RaceEntryCar__update(0); func_004A53F8(); func_004A7844(*x,*y,*z);
    float degrees=angle*180.0f/3.14f; func_004A79B0(degrees);
    func_00427820(buf); func_004A53F8();
    float *px=&pos[0]; func_00398758(car,pos); pos[3]=0;
    float *pz=&pos[2];
    float len=*px**px+*pz**pz;
    if(len>=2.25f) {float factor=1.5f; __asm__("rsqrt.s %0,%1,%2":"=f"(factor):"f"(factor),"f"(len)); *px *= factor; *pz *= factor; }
    pos[1]=func_00407FA0(o->entries+i,*px,*pz);
    float xx=*px, yy=pos[1], zz=*pz; float *m=matrix; *m=1; matrix[4]=xx; matrix[5]=yy; matrix[6]=zz;
    matrix[12]=matrix[8]=0.0f; matrix[13]=matrix[9]=matrix[1]=0.0f; matrix[2]=0.0f; matrix[10]=1; matrix[14]=0.0f; matrix[11]=matrix[7]=matrix[3]=0.0f; matrix[15]=1;
    RaceEntryCar__update(1);func_004A53F8();func_0049AB58(.01f);RaceEntryCar__update(0);
    func_004A79B0(-angle*180.0f/3.14f);func_004A7698(m);func_004A79B0(degrees);func_004A29A8(0);
    if(scale!=1)func_004A7890(scale,scale,scale);
    GT4_Motion__MotionSetPlayer__set(buf,(void*)o->inner->other,o->inner->b);
    if(vcall(o)) {Entry *p=o->entries+i; int id=p->id; int v=vcall(o); Entry *q=o->entries+i;func_00428C00(buf,id,v,0,0,q->alpha,0);}
    else {Entry *q=o->entries+i;func_00428AD8(buf,q->id,0,0,q->alpha,0);}
    func_004A29A8(1);RaceEntryCar__update(1);func_004A5400();RaceEntryCar__update(0);func_004A5400();
    if(scale!=1)func_004A7890(scale,scale,scale);
    GT4_Motion__MotionSetPlayer__set(buf,o->inner->model,o->inner->b);
    if(flag>=0) {D_00845C20.b=flag;o->inner->model->state->p=&D_00845C20;func_004567E0(0);}
    else o->inner->model->state->p=0;
    if(vcall(o)) {Entry *p=o->entries+i; int id=p->id; int v=vcall(o); Entry *q=o->entries+i;func_00428C00(buf,id,v,0,0,q->alpha,0);}
    else {Entry *q=o->entries+i;func_00428AD8(buf,q->id,0,0,q->alpha,0);}
    if(flag>=0)func_004567E0(1);
    func_004A5400();
   }
  }
 }
}
