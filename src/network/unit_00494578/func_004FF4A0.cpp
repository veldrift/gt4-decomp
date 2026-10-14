/* compiler: ee-gcc2.96-no-strict-aliasing */
extern "C" int func_0052EEC8(void *);
extern "C" int func_0052FA88();
extern "C" int func_0052FFB0(void *, void *);
extern "C" void func_0053A860(void *);
extern "C" void func_0053A890(void *, unsigned int *);
extern "C" void func_00578B10(int);
extern "C" void *func_005A48D8(void *, int, unsigned int);
extern "C" int func_005A6AB0(void *, void *, int) throw();
extern "C" void func_004FF5B0();
struct Request { int x0, handle; char data[12]; int type; int x18,x1c; int cb; void *state; char pad[0x48-0x28]; };
struct Frame { int state[4]; Request req; char pad[8]; long out; char pad68[8]; char timer[16]; unsigned int elapsed; char pad84[12]; };
extern "C" int func_004FF4A0(char *self) {
 Frame sp;
 func_005A48D8(&sp.req,0,0x48);
 sp.out=0;
 func_0052EEC8(&sp.req);
 sp.req.handle=*(int *)(self+0x3f3c);
 sp.req.type=0x21;
 sp.req.cb=(int)func_004FF5B0;
 sp.req.x1c=0;
 func_005A6AB0(sp.req.data,self+0x222c,12);
 sp.state[1]=1;
 sp.req.state=sp.state;
 sp.state[0]=0;
 sp.elapsed=0;
 func_0053A860(sp.timer);
 do {
  if(sp.state[1]) {
   if(func_0052FFB0(&sp.req,&sp.out)!=0) return 0;
   sp.state[1]=0;
  }
  func_0052FA88();
  func_0053A890(sp.timer,&sp.elapsed);
  func_00578B10(10000);
  if(sp.state[0]) break;
 } while(sp.elapsed<10000u);
 if(sp.state[0]) { *(int *)(self+0xfb8)=1; return 1; }
 return 0;
}
