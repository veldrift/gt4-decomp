/* compiler: ee-gcc2.96-no-strict-aliasing */
union Color { unsigned int word; unsigned char b[4]; };
struct Group {
 char pad[0xc4]; int fC4; float fC8;
 char padCC[0x901-0xcc]; unsigned char events;
};
struct Obj {
 int f0; void *p4; int f8; Group *group;
 int f10,f14,f18,f1c,f20,f24,f28,f2c,f30,f34,f38,f3c;
 int f40,f44,f48,f4c,f50,f54,f58,f5c,f60,f64,f68,f6c,f70,f74,f78,f7c;
 float f80,f84; int f88,f8c,f90,f94,f98,f9c,fa0; Color ca4,ca8;
};
extern "C" {
void func_00393548(int,int,float,float);
void RaceTooltipDisplay__update(void *,float);
void RaceDisplayObjectBase__update(void *);
int RaceEventQueue__check(void *,int,int *,int);
void func_003BEE58(void *,float);
int func_003D8B78() throw();
int func_003D8C48(Obj *) throw();
void func_003D9470(Obj *,float);
void func_003D9518(Obj *);
int func_003D9520(Obj *,int);
void func_003D95F0(Obj *,int);
void func_003D9720(Obj *,int);
void func_003D97A8(Obj *,int);
int func_003D9918(Obj *,int);
void func_003D9998(Obj *);
void func_003D9A80(Obj *);
void func_003D9B20(Obj *);
void func_003D9C70(Obj *,int);
void RaceMonitor__setState(Obj *,Group *);
void func_003DB520(Obj *);
void func_003DBBD0(Obj *);
void RaceMonitor__setCarGapState(Obj *,Group *);
void func_003DC5D8(Obj *,Group *);
void func_003DC7B0(Obj *);
void func_00475488(void *,float);
}
static inline float maxfloat(float a,float b) {
 float r; __asm__("max.s %0, %1, %2" : "=f"(r) : "f"(a), "f"(b)); return r;
}
extern "C" void func_003D8DB8(Obj *p,int arg1) {
 p->f9c=-1;
 p->f68=0;
 if (func_003D8B78()!=0) {
  Group *g=p->group;
  if (g->fC4!=0 && (int)g->fC8<181) {
   func_003D9C70(p,2);
   p->f20=1;
  }
  for(int i=0;i<p->group->events;i++) {
   int out=0;
   if (RaceEventQueue__check((char *)p->group+0xf4,5,&out,i)!=0 && out==0) {
    func_003D9C70(p,0);
    p->f20=1;
   }
  }
  func_003D9998(p);
  func_003D9A80(p);
  int step=p->f78;
  void *object=p->p4;
  p->f90=(p->f90+step)&31;
  float dt=(float)step*0x1.111110p-6f;
  if(object) func_00475488(object,dt);
  func_003BEE58((char *)p+0x298,dt);
  RaceDisplayObjectBase__update((char *)p+0x300);
  RaceDisplayObjectBase__update((char *)p+0x328);
  RaceTooltipDisplay__update((char *)p+0x358,dt);
  switch(p->f28) {
   case 0: break;
   case 1:
    func_003D9B20(p);
    func_003D9470(p,dt);
    if(p->f5c) p->ca4.word=(p->ca4.word&~0xffu)|1;
    break;
   case 2:
    func_003D9B20(p);
    func_003D9518(p);
    break;
  }
  if(func_003D8C48(p)) {
   func_003D9520(p,arg1);
   switch(p->f28) {
    case 0:
     func_003D9918(p,arg1);
     func_003D9720(p,arg1);
     break;
    case 1:
     func_003D95F0(p,arg1);
     break;
    case 2:
     func_003D97A8(p,arg1);
     func_003D9918(p,arg1);
     break;
   }
  }
  p->f80=maxfloat(p->f80-dt/0x1.999998p-3f,-1.0f);
  if(p->ca4.b[0]) {
   p->ca4.word&=~0xffu;
   func_003DBBD0(p);
  }
  if(p->ca4.b[1]) {
   p->ca4.word&=0xffff00ffu;
   func_003DB520(p);
  }
  if(p->ca4.b[2]) {
   p->ca4.word&=0xff00ffffu;
   RaceMonitor__setState(p,p->group);
   func_003DC5D8(p,p->group);
  }
  if(p->ca4.b[3]) {
   p->ca4.word&=0x00ffffffu;
   RaceMonitor__setCarGapState(p,p->group);
  }
  if(p->ca8.b[0]) {
   p->ca8.word&=~0xffu;
   func_003DC7B0(p);
  }
  if(p->f6c) {
   p->f6c=0;
   p->f9c=0x30;
  }
  int sound=p->f9c;
  if(sound>=0) func_00393548(sound,0x40,1.0f,1.0f);
 }
}
