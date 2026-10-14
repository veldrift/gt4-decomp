/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Buffer { int x[12]; int flag; int rest[2]; };
struct Pair { Buffer b[2]; int cur; Buffer *current() { return &b[cur]; } Buffer *other() { return &b[1-cur]; } void flip(){cur=1-cur;} };
struct Globals { Pair a,b; };
extern Globals D_0061850C;
struct Self { char pad[0x198]; int frame, count, pending, disabled; };
struct Root { char pad[0xe320]; int a; char p[0x10]; int b; char q[0x14]; int c; };
struct Camera {
 virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
 virtual float v10(float); virtual float v11(); virtual void v12(); virtual float v13(); virtual float v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual float v18(); virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24(); virtual void v25(float,float);
};
extern "C" Root *func_003C3F98(Self *) throw();
extern "C" Camera *func_003C3FA0(Self *) throw();
extern "C" void func_00330CA8();
extern "C" void RaceBase___setSignal(Root *,int);
extern "C" int func_00333E50(void *,int);
extern "C" void func_001074D0(void *,int,int,int,int);
extern "C" int func_001052E0(Buffer *,int,int,int);
extern "C" Buffer *func_00105378(Buffer *,Buffer *);
extern "C" void func_00105460(Buffer *,int,int);
extern "C" float func_00330998(void *);
extern "C" void func_00374118(Camera *,float);
extern "C" void func_003C58C0(Self *);
extern "C" void func_0033E368(Root *,Buffer *,Buffer *,int,float);
extern "C" void func_003308E8(void *,Buffer *,int,int);
extern "C" void func_0033E6E0(Root *,Buffer *,Buffer *,Buffer *,float,float,float);
extern "C" void func_001056A0(Buffer *);
extern "C" void func_00105708(Buffer *);
extern "C" void func_004AB040(int);
extern "C" void func_003C4F38(Self *) throw();
extern "C" void func_004A3078(int);
extern "C" void func_004A3230(int);
extern "C" void func_004A29A8(int);
extern "C" void func_004A4550(int,int);
extern "C" void func_003C5AB8(Self *,Buffer *,int);
extern "C" void func_003C4EF8(Self *) throw();
extern "C" void func_001079C8(int,int);
extern "C" void func_00105280(Buffer *,int);
extern "C" void func_003C5430(Self *self) {
 if(self->disabled) return;
 if(self->count) { func_00330CA8(); --self->count; return; }
 if(self->pending) { self->pending=0; RaceBase___setSignal(func_003C3F98(self),0x2ee1); return; }
 if(self->frame>=0) {
  func_00330CA8();
  if(!func_00333E50((char*)self+0x20,self->frame++)) {
   D_0061850C.a.current()->flag=0; D_0061850C.a.other()->flag=0;
   func_001074D0((char*)&D_0061850C-0x3c,1,2,640,448);
   self->frame=-1; self->count=2; self->pending=1;
  }
 } else {
  float f;
  D_0061850C.a.flip(); D_0061850C.b.flip();
  func_003C3F98(self)->c=1;
  Buffer *old=D_0061850C.a.current();
  Buffer buf,copy;
  func_001052E0(&buf,0,448,352);
  func_00105378(&copy,D_0061850C.b.current());
  func_00105460(&copy,448,352);
  Camera *cam=func_003C3FA0(self);
  func_00374118(cam,func_00330998((char*)self+0x18c));
  cam->v25(1.3333332538604736328125f,1.0f);
  func_003C58C0(self);
  func_003C3F98(self)->b=0;
  func_0033E368(func_003C3F98(self),&buf,&copy,-1,0.0f);
  func_003C3F98(self)->b=1;
  func_003C3F98(self)->a=0;
  func_003308E8((char*)self+0x18c,&copy,224,176);
  int flag=cam->v18()>0.5f;
  f=cam->v13();
  float x=1.0f/cam->v14()+1.0f;
  __asm__("sqrt.s %0,%1":"=f"(x):"f"(x));
  f*=x; f*=1000.0f;
  float g=cam->v11();
  float h=cam->v10(0.0f);
  func_0033E6E0(func_003C3F98(self),&buf,&copy,&buf,f,g,h);
  func_001056A0(&buf); func_00105708(&copy);
  func_004AB040(5); func_003C4F38(self); func_004A3078(0);
  func_001056A0(old); func_004A3230(1); func_004AB040(6); func_004AB040(4);
  func_004A29A8(0); func_004A4550(3,1); func_004A4550(2,1);
  func_003C5AB8(self,&buf,flag); func_003C4EF8(self); func_001079C8(0,0);
  D_0061850C.a.flip(); D_0061850C.b.flip();
  func_003C3F98(self)->c=0;
  func_00105280(&copy,2); func_00105280(&buf,2);
 }
}
