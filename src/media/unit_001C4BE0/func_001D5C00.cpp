/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Buf { int a,b,w; char pad[0x30]; };
struct Globals { Buf views[2]; int cur; char pad[0x7c]; Buf other; };
extern Globals D_0061850C;
extern char D_006883F8[];
struct Obj { void *p; char pad[0x10]; int id; int x18; int n; char sub[0x18]; int flag; int x3c; float x,y,z; char pad4c[0x10]; float weights[0x53]; float alpha; };
struct Camera { void *vt; char pad[0x4c]; float a,b; char tail[8]; };
union Temp { Camera cam; struct { char tex[0x30]; char b[0x40]; char c[0x40]; } s; };
extern "C" {
void func_00105280(void *, int);
int func_001052E0(void *,int,int,int);
void func_00105338(void *,void *,int);
void func_001056A0(void *); void func_00105708(void *); int func_00105818(void *);
void GSBuffer__getTexture(void *,void *); void func_00107328(void *);
void func_001D5258(void *) throw(); void func_001D5408(void *) throw();
void func_001D5588(void *,int,float) throw(); void func_001D5620(int,int,float) throw();
void func_001D56B0(void *,float,float,float) throw();
void func_001D6220(void *,void *); void func_001D6378(void *,void *,void *,void *,int);
void func_001D6C98(void *); void func_001D5AE8();
int func_004278B8(void *,int); int func_00427E18(void *,int);
void func_00427A70(void *,int,float,int,float);
void func_00427FE8(void *,int,int,float,float,float,float,float);
void func_0044EB10(void *,void *,void (*)(),void *,int,int,int);
void func_0044EEA8(void *); void func_0044EF18(void *,float,float,float); void CameraBase__structor_1(void *,int);
int ModelSet2__texLOD(int); void func_004568A0(float); void func_004568B0(float); void func_004568C0(void *); void func_00456918(float);
void func_004A1638(int); void func_004A19B0(int); void pglFrontFace(int); void func_004A26F0(int);
void func_004A2808(int,float); void func_004A2980(int); void func_004A29A8(int); void func_004A3078(int); void func_004A3088(float); void func_004A3230(int);
void func_004A40B0(float,float); void func_004A4550(int,int); void RaceEntryCar__update(int); void func_004A53F8(); void func_004A5400(); void pglPushAttrib(int); void func_004A5688(); void func_004A7454(); void func_004AA4A0(); void func_004AB040(int);
}
extern "C" void func_001D5C00(Obj *o,int arg) {
 char root[0x40]; Temp u;
 void *sub=o->sub;
 pglPushAttrib(0x887);
 ModelSet2__texLOD(0); func_00456918(1.0f); func_004568B0(1.5f); func_004568A0(0.8f);
 func_004AB040(0x12); func_004A40B0(100.0f,1.0f); func_004AB040(8);
 func_004A1638(15); pglFrontFace(0); func_004A19B0(2); func_004A26F0(3); func_004A1638(100); func_004AB040(8);
 func_004A4550(1,0); func_004A2980(-1); func_004A29A8(1);
 Globals *g=&D_0061850C;
 Buf *view=&g->views[g->cur];
 Buf *other=&g->other;
 func_001052E0(root,0,256,256);
 func_001D5258(o); func_001D5408(o);
 RaceEntryCar__update(1); func_004A53F8();
 if(func_00427E18(sub,o->id)) {
  func_004A7454();
  func_00427FE8(sub,o->id,0,o->alpha,(float)view->w/(float)func_00105818(view),0.1f,100.0f,0.0f);
  func_00107328((char*)g-0x3c);
 }
 RaceEntryCar__update(0); func_004A53F8();
 if(func_004278B8(sub,o->id)) { func_004A7454(); func_00427A70(sub,o->id,o->alpha,0,0.0f); }
 if(o->flag) {
  RaceEntryCar__update(1); func_004A53F8(); RaceEntryCar__update(0); func_004A53F8();
  Camera *c=&u.cam;
  func_0044EEA8(c); func_0044EF18(c,o->x,o->y,o->z);
  float zero=0.0f; c->a=zero; c->b=zero;
  func_0044EB10(root,c,func_001D5AE8,o,128,256,view->a);
  func_004A5400(); RaceEntryCar__update(1); func_004A5400(); RaceEntryCar__update(0);
  c->vt=D_006883F8; CameraBase__structor_1(c,0);
 }
 float total=0.0f;
 func_001056A0(view); func_00105708(other); func_004A3078(0x80000000); func_004A3088(1.0f); func_004A3230(3);
 int i=0;
 if(i<o->n) { float zero=0.0f; float *p=o->weights; do { float v=*p++; if(v!=zero) {total+=v;func_001D5588(o->p,i,v/total);} i++; } while(i<o->n); }
 int w=view->w; func_001D5620(w,func_00105818(view),1.0f-total);
 func_001D56B0(view,0.6f,4.0f,2.5f);
 if(o->flag) {
  func_001D6C98(o);
  void *tex=u.s.tex; GSBuffer__getTexture(root,tex);func_004568C0(tex);func_004AA4A0();
  void *b=u.s.b;func_00105338(b,view,0);
  void *c=u.s.c;func_00105338(c,view,0);
  func_001D6378(o,view,c,b,(arg+1)*2);
  func_00105280(c,2);func_00105280(b,2);
 }
 func_001D6220(o,view);func_004A5400();RaceEntryCar__update(1);func_004A5400();func_004A1638(6);func_004A2808(0x44,1.0f);
 func_004AB040(5);func_004AB040(4);func_004AB040(100);func_004A29A8(0);func_004AB040(15);func_004A5688();func_00105280(root,2);
}
