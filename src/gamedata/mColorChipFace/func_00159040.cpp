/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned int u32;
struct Color { char data[16]; };
struct VEntry { short delta,index; void *fn; };
struct Obj { char pad[0xB4]; int b4,b8,bc; u32 c0,c4,c8; };
struct Draw { int pad; char *vt; };
union Point { struct {float x,y;} v; float data[2]; };
static inline void xy(Point *p,float x,float y) {p->v.x=x;p->v.y=y;}
static inline void sx(Point *p,float x) {p->v.x=x;}
static inline void sy(float &p,float y) {p=y;}
static inline float &y(Point *p) {return p->data[1];}
struct Array { Color c[4]; Array(); };
extern "C" void func_002030A0(Color *);
struct Elem {char data[16]; Elem() {func_002030A0((Color *)this);} };
struct ConstructArray {Elem c[4];};
inline void *operator new(unsigned int,void *p) throw() {return p;}
extern float D_0068FF40[],D_0068FF58[];
extern "C" void mWidget__getWindowSize(Obj *,float *,float *);
extern "C" void func_002030A0(Color *);
extern "C" void func_00203118(Color *,int);
extern "C" int func_00202C20(Color *,u32);
extern "C" void func_00202C48(Color *,u32);
static inline void setcolor(Draw *d,Color *c) { VEntry *e=(VEntry *)(d->vt+0x198); ((int (*)(void *,Color *))e->fn)((char *)d+e->delta,c); }
static inline void drawi(Draw *d,Point *p,Color *c) { VEntry *e=(VEntry *)(d->vt+0x1B0); ((int (*)(void *,int,Point *,int,Color *))e->fn)((char *)d+e->delta,4,p,0,c); }
static inline void drawv(Draw *d,Point *p) { VEntry *e=(VEntry *)(d->vt+0x1B0); ((void (*)(void *,int,Point *,int,Color *))e->fn)((char *)d+e->delta,4,p,0,0); }
extern "C" void func_00159040(Obj *self,Draw *d) {
 struct Local { float width,height; char pad[8]; Point points[4]; Color colors[4]; } u;
 mWidget__getWindowSize(self,&u.width,&u.height);
 Point *points=u.points;
 *(int *)&points[0].v.x=0;
 sx(&u.points[1],u.width);
 *(int *)&u.points[2].v.x=0;
 sx(&u.points[3],u.width);
 float *table;
 if (self->bc==0) table=D_0068FF40;else table=D_0068FF58;
 if (self->b4) {
  Color *colors=u.colors;
  new (colors) ConstructArray;
  float a=u.height*table[0];
  float b=u.height*table[1];
  float c=u.height*table[4];
  float &p0=y(&u.points[0]);float &p1=y(&u.points[1]);float &p2=y(&u.points[2]);float &p3=y(&u.points[3]);
  sy(p0,a);sy(p1,a);sy(p2,b);sy(p3,b);
  func_00202C20(&u.colors[0],self->c0);func_00202C20(&u.colors[1],self->c0);func_00202C20(&u.colors[2],self->c4);func_00202C20(&u.colors[3],self->c4);
  { VEntry *entry=(VEntry *)(d->vt+0x1B0); ((int (*)(void *,int,Point *,int,Color *))entry->fn)((char *)d+entry->delta,4,points,0,colors); }
  sy(p0,b);sy(p1,b);sy(p2,c);sy(p3,c);
  func_00202C20(&u.colors[0],self->c4);func_00202C20(&u.colors[1],self->c4);func_00202C20(&u.colors[2],self->c8);func_00202C20(&u.colors[3],self->c8);
  { VEntry *entry=(VEntry *)(d->vt+0x1B0); ((int (*)(void *,int,Point *,int,Color *))entry->fn)((char *)d+entry->delta,4,points,0,colors); }
  Color *end=colors+4;while (colors!=end) {--end;func_00203118(end,2);}
 } else {
  float a=u.height*table[0];float b=u.height*table[1];float c=u.height*table[2];float e=u.height*table[4];
  Color *color=&u.colors[0];
  func_00202C48(color,self->c0);setcolor(d,color);func_00203118(color,2);
  float &p0=y(&u.points[0]);float &p1=y(&u.points[1]);float &p2=y(&u.points[2]);float &p3=y(&u.points[3]);
  sy(p0,a);sy(p1,a);sy(p2,b);sy(p3,b);{ VEntry *entry=(VEntry *)(d->vt+0x1B0); ((int (*)(void *,int,Point *,int,Color *))entry->fn)((char *)d+entry->delta,4,points,0,0); }
  func_00202C48(color,self->c4);setcolor(d,color);func_00203118(color,2);
  sy(p0,b);sy(p1,b);sy(p2,c);sy(p3,c);{ VEntry *entry=(VEntry *)(d->vt+0x1B0); ((void (*)(void *,int,Point *,int,Color *))entry->fn)((char *)d+entry->delta,4,points,0,0); }
  func_00202C48(color,self->c8);setcolor(d,color);func_00203118(color,2);
  sy(p0,c);sy(p1,c);sy(p2,e);sy(p3,e);{ VEntry *entry=(VEntry *)(d->vt+0x1B0); ((void (*)(void *,int,Point *,int,Color *))entry->fn)((char *)d+entry->delta,4,points,0,0); }
 }
}
