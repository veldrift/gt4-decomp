/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned int u32;
struct Obj { char pad0[0x40]; int f40; char pad44[0x1c]; int f60; char pad64[0x40]; u32 fA4,fA8; };
struct Car { char pad[0x18]; int f18; };
extern "C" Car *RaceMonitor__get_player_car(Obj *);
extern "C" int GetPitStopStatus(int);
extern "C" void func_003D9C70(void *,int);
extern "C" void func_003D8AC0(void *,int) throw();
extern "C" void func_003D9998(Obj *p) {
 int r=GetPitStopStatus(RaceMonitor__get_player_car(p)->f18);
 switch(r) {
 case 0: {
  if(p->f40!=0) {
   p->f40=0;
   p->fA4=(p->fA4 & 0xffff00ffu)|0x100;
   p->fA8=(p->fA8 & 0xffff00ffu)|0x100;
  }
  return;
 }
 case 1: case 2: case 3: case 4: case 5:
 if(p->f40==0) {
  func_003D9C70(p,2);
  p->f40=1;
  p->fA4=(p->fA4 & 0xffff00ffu)|0x100;
  p->fA8=(p->fA8 & 0xffff00ffu)|0x100;
  return func_003D8AC0(p,p->f60);
 }
}
}
