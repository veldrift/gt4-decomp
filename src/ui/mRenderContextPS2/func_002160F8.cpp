/* compiler: ee-gcc2.96-no-strict-aliasing */
struct View { int a,kind,width,c; int x,y,w,h; char pad[0x1c]; };
struct Pair { View v[2]; int cur; View *current() { return v+cur; } View *other() {return v+(1-cur);} };
struct Group { Pair a,b; };
struct Self { char pad[0x1d5c]; View view; int live; char pad2[8]; int pending,close; };
extern "C" {
extern Group D_0061850C;
View *func_00105378(View *,View *);
void func_001054A0(View *,int); int func_00105528(View *);
void func_001055C0(View *);void func_001056A0(View *);void func_00105728(View *);
int func_00105818(View *);
void func_004A1638(int);void func_004A2980(int);void func_004A3078(int);
void func_004A3230(int);void func_004A4550(int,int);void func_004A5FE0(int);
void func_004A6788(float,float,float,float,float,float,float,float);
void func_004AA168(int);void func_004AB040(int);
}
extern "C" void func_002160F8(Self *self) {
 if(self->pending) {
  View *v=&self->view;
  if(self->live) {func_001055C0(v);self->live=0;}
  func_00105378(v,D_0061850C.b.current());v->kind=2;
  if(func_00105528(v)>=0) {
   self->live=1;
   float zero=0.0f;
   Pair *g=&D_0061850C.a;
   func_001054A0(v,0);func_001056A0(v);
   func_004AB040(4);func_004AB040(5);func_004AB040(6);
   func_004A2980(0xff000000);func_004A3078(0x80ffffff);func_004A3230(1);
   func_004A2980(0xffffff);func_004AA168(-1);func_004A4550(3,0);func_004A4550(2,0);
   View *r=g->current();func_00105728(r);func_004A5FE0(2);
   float width=(float)v->width;
   func_004A6788(zero,zero,width,(float)func_00105818(v),(float)r->x,(float)r->y,(float)(r->x+r->w),(float)(r->y+r->h));
   r=g->other();func_00105728(r);func_004A5FE0(1);
   float width2=(float)v->width;
   func_004A6788(zero,zero,width2,(float)func_00105818(v),(float)r->x,(float)r->y,(float)(r->x+r->w),(float)(r->y+r->h));
   func_004A2980(-1);func_004A5FE0(0);func_004A1638(6);func_004A4550(3,1);func_004A4550(2,1);
  }
  self->pending=0;
 }
 if(self->close) {func_001055C0(&self->view);self->live=0;self->close=0;}
}
