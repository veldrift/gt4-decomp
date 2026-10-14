/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Entry { short delta,index; void *fn; };
struct Color { float x,y,z,w; };
struct Vec { float x; int y; float z; };
struct Item { unsigned int flags; unsigned short id,pad6,count,pada; int padc,pad10; unsigned short *indices; char pad18[0x28]; };
struct Scene { char pad[0x14]; void *model; int count; Item *items; };
struct Link3 { char pad[0xCC]; Scene *scene; };
struct Link2 { int pad; Link3 *next; };
struct Link1 { char pad[0x80]; Link2 *next; };
struct Face { char pad[0x64]; Entry *vt; int pad68; Link1 *next; };
struct Target { Entry *vt; };
struct Owner { char pad[0xEC]; int mode; char padf0[0x20]; float pulse; };
#define F(p,o) (*(float *)((char *)(p)+(o)))
#define I(p,o) (*(int *)((char *)(p)+(o)))
extern Color D_00618AB8;
extern Color D_00618A98[2];
extern "C" void func_00194CE0(Color *,float) throw();
extern "C" float func_0036FD98(void *);
extern "C" void func_003C66F0(Scene *,int,float,float,float,float);
extern "C" void ModelSet2__render(void *,void *);
extern "C" void func_0049FD50(int,void *,int,int,int,int);
extern "C" void func_004A1638(int);
extern "C" void pglFrontFace(int);
extern "C" void func_004A2808(int,float);
extern "C" void func_004A2980(int);
extern "C" void func_004A29A8(int);
extern "C" void func_004A3078(int);
extern "C" void func_004A3088(float);
extern "C" void func_004A3230(int);
extern "C" void RaceEntryCar__update(int);
extern "C" Vec *func_004A5B70(int);
extern "C" void func_004A70E8(Vec *,Vec *);
extern "C" void func_004A7454();
extern "C" void func_004AA168(int);
extern "C" void func_004AB040(int);
extern "C" float func_0057D1F0(float);
extern "C" float func_0057D2B8(float) throw();
static inline Target *target(Face *f) {
 Entry *e=(Entry *)((char *)f->vt+0x4B0);
 return ((Target *(*)(void *))e->fn)((char *)f+e->delta);
}
static inline void call(Target *t,int slot) {
 Entry *e=(Entry *)((char *)t->vt+slot);
 ((void (*)(void *))e->fn)((char *)t+e->delta);
}
extern "C" void func_00194DB0(Owner *self,Face *face) {
 func_004A2980(-1);
 func_004A29A8(1);
 func_004A3078(0);
 func_004A3088(1.0f);
 func_004A3230(3);
 pglFrontFace(0);
 Scene *scene=face->next->next->next->scene;
 if (scene) {
  Target *t;
  int i=0;
  void *model=scene->model;
  t=target(face);
  RaceEntryCar__update(1);func_004A7454();
  char *camera=(char *)t+0xE28;
  call(t,0x210);
  RaceEntryCar__update(0);func_004A7454();call(t,0x218);
  ModelSet2__render(model,0);
  func_004AB040(15);func_004AB040(4);func_004AB040(2);func_004A1638(6);func_004A2808(0x44,1.0f);
  for (;i<scene->count;i++) {
   Item *item=scene->items+i;
   int id=item->id;
   int active;
   if (I(camera,0x40)==i) {
    active=1;
    for (int j=0;j<item->count;j++) {
     int index=item->indices[j];
     Color color=D_00618AB8;
     if(self->mode==1)func_00194CE0(&color,self->pulse);
     func_003C66F0(scene,index,color.x,color.y,color.z,color.w);
    }
   } else active=0;
   if (item->flags&1) {
   } else {
    Color *c=D_00618A98+active;
    func_003C66F0(scene,id,c->x,c->y,c->z,c->w);
   }
  }
  if (self->mode!=2) {
   float length=2.0f*func_0036FD98(camera);
   float x=F(camera,0x60);
   float width=F(camera,0xCC)/F(t,0x9C0);
   float z=F(camera,0x68);
   float angle=F(camera,0x6C);
   Vec *v=func_004A5B70(3);
   angle-=90.0f;
   v[0].x=x;v[0].y=0;v[0].z=z;
   width*=0.5f;
   float a=(angle-width)*0x1.921fb4p+1f/180.0f;
   float b=(angle+width)*0x1.921fb4p+1f/180.0f;
   float c=func_0057D1F0(a);
   v[1].y=0;v[1].x=x+length*c;
   v[1].z=z+length*func_0057D2B8(a);
   c=func_0057D1F0(b);
   v[2].y=0;v[2].x=x+length*c;
   v[2].z=z+length*func_0057D2B8(b);
   func_004AA168(0x23ffffff);
   func_0049FD50(3,v,0,0,0,0);
   if (I(camera,0xBC)) {
    float angles[2]; Vec points[2];
    angles[0]=(F(camera,0xC4)-90.0f)*0x1.921fb4p+1f/180.0f;
    angles[1]=(F(camera,0xC8)-90.0f)*0x1.921fb4p+1f/180.0f;
    for (int k=0;k<2;k++) {
     points[0].x=x;points[0].y=0;points[0].z=z;
     float c=func_0057D1F0(angles[k]);
     points[1].y=0;points[1].x=x+length*c;
     points[1].z=z+length*func_0057D2B8(angles[k]);
     func_004AA168(0x50ffffff);
     func_004A70E8(points,points+1);
    }
   }
  }
 }
}
