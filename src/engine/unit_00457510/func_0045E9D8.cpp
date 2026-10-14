/* compiler: ee-gcc2.96-no-strict-aliasing */
struct V2 {float x,y; V2(){} V2(float a,float b):x(a),y(b){} };
struct P {V2 p; char pad8[8]; int flags; char pad14[0x18]; int car,edge; char pad34[0x10];};
struct C {char pad[0x18]; V2 p; char gap8[8];int flags;char gap14[0x18];int car,edge;};
struct O {char pad0[0x18]; P p[8]; char pad238[0x158]; V2 pos; char pad398[0x2c]; V2 vel; char pad3cc[0x64]; int active; char pad434[0x74]; O *cars;};
static inline void scale(V2 *p,float f){p->x*=f;p->y*=f;}
static inline void add(V2 *p,V2 *v){float x=p->x+v->x;float y=p->y+v->y;p->x=x;p->y=y;}
static inline void sub(V2 *p,V2 *v){p->x-=v->x;p->y-=v->y;}
static inline float dot(V2 *a,V2 *b){return a->x*b->x+a->y*b->y;}
static inline float cross(V2 *a,V2 *b){return a->x*b->y-a->y*b->x;}
extern "C" void func_0045E9D8(O *self){
 V2 off,edge;
 if(self->active){
 for(int i=0;i<8;i++){
 C *c=(C *)((char *)self+i*0x44);
 int flags=c->flags;
 if(flags&2){
 O *other=(O *)((char *)self->cars+c->car*0x4f0);
 int index=c->edge;
 V2 *a=&other->p[index].p;
 V2 *b=&other->p[(index+1)&7].p;
 float ox=c->p.x-a->x,oy=c->p.y-a->y;off.x=ox;off.y=oy;
 V2 *pe=&edge;
 float xx=b->x-a->x,yy=b->y-a->y;
 pe->x=xx;edge.y=yy;

 float inv=1.0f/dot(&edge,&edge);
 float t=dot(&off,&edge)*inv;
 if(t<0.0f || t>1.0f){c->flags=flags&~2;}
 else {
 if(cross(&off,&edge)>0.0f){c->flags=flags&~2;}
 else {V2 delta; V2 *d=&delta;float dx=edge.x*t-off.x,dy=edge.y*t-off.y;d->x=dx;delta.y=dy;d->x*=0.5f;delta.y*=0.5f;add(&self->pos,d);sub(&other->pos,d);}
 V2 *velocity=&self->vel; V2 delta=*velocity; V2 *d=&delta;
 V2 *ov=&other->vel;d->x-=ov->x;delta.y-=ov->y;
 float dx=d->x,dy=delta.y;
 float ex=pe->x,ey=edge.y;
 if(dx*ey-dy*ex<0.0f){
 float u=(dx*ex+dy*ey)*inv;
 pe->x*=u;edge.y*=u;pe->x-=d->x;edge.y-=delta.y;pe->x*=0.5f;edge.y*=0.5f;float vx=velocity->x+pe->x,vy=velocity->y+edge.y;velocity->x=vx;velocity->y=vy;ov->x-=pe->x;ov->y-=edge.y;
 }
 }
 }
 }
 }
}
