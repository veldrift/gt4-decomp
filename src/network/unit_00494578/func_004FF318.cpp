/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned int u32;
struct Obj { char pad[0x3f3c]; int value; };
struct Work { int done; int busy; };
typedef void (*Fn)();
struct Req {
 int v0,v4,v8,vC; char str[16]; int v20; char pad24[0xa4-0x24];
 Fn cbA4; Work *work; char padAC[8]; Fn cbB4; Obj *objB8; Fn cbBC; Obj *objC0; Fn cbC4; int vC8; char padCC[0x13c-0xcc];
};
struct Rsp { int v0,v4,value; };
struct Timer { char pad[16]; };
extern "C" int func_0057F260(const char *) throw();
extern "C" void *func_005A48D8(void *,int,u32);
extern "C" int func_00533650(Req *);
extern "C" char *func_005A609C(char *,const char *);
extern "C" void func_004FF5D8();
extern "C" void func_004FF670();
extern "C" void func_004FF6B0();
extern "C" void func_004FF6F0();
extern "C" void func_0053A860(Timer *);
extern "C" int func_0052EE68(Req *,Rsp *);
extern "C" int func_0052FA88();
extern "C" void func_0053A890(Timer *,u32 *);
extern "C" void func_00578B10(int);
extern "C" int func_0052E8A0(int,int,int);
extern "C" int func_004FF318(Obj *obj,const char *name,int arg2,int arg3) {
 Req req;
 Rsp rsp;
 Work work;
 Timer timer;
 u32 elapsed;
 int r=func_0057F260(name);
 if(r!=0) {
  func_005A48D8(&req,0,0x13c);
  Rsp *ps=&rsp;
  func_005A48D8(ps,0,12);
  func_00533650(&req);
  req.v4=arg3;
  req.v8=2;
  req.vC=2;
  func_005A609C(req.str,name);
  Timer *pt=&timer;
  req.v20=arg2;
  req.cbA4=func_004FF5D8;
  req.cbB4=func_004FF670;
  req.cbBC=func_004FF6B0;
  req.cbC4=func_004FF6F0;
  work.busy=1;
  req.work=&work;
  req.objB8=obj;
  req.objC0=obj;
  req.vC8=0;
  work.done=0;
  elapsed=0;
  func_0053A860(pt);
  u32 *pe=&elapsed;
  do {
   if(work.busy) {
    work.busy=func_0052EE68(&req,ps)==0?0:work.busy;
   }
   func_0052FA88();
   func_0053A890(pt,pe);
   func_00578B10(10000);
  } while(!work.done && elapsed<10000u);
  if(work.done) {
   obj->value=rsp.value;
   func_0052E8A0(rsp.value,0,0);
   r=1;
  } else r=0;
 }
 return r;
}
