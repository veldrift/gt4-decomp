/* compiler: ee-gcc2.96-no-strict-aliasing */
struct VE { short d, index; int (*fn)(void *, int); };
extern char RaceSplitBattleBase__vtable[];
extern char *D_00622F4C;
extern "C" int func_005F2A08(void *);
extern "C" void func_0055F9F8(void *);
extern "C" void DynamicsConductorBattle2P__structor_1(void *);
extern "C" void RaceInput__structor_0(void *);
extern "C" int func_00393700(void *);
extern "C" void ResultArcade__structor_0(void *);
extern "C" int RacePause__structor_0(void *);
extern "C" void SimplePause__structor_0(void *);
extern "C" int RaceSplitDisplay__structor_0(void *);
extern "C" const char *func_0033D958(int);
extern "C" int func_0055F420(const char *);
extern "C" void func_00109A28(void *,void *);
extern "C" void func_00346808(void *,int);
extern "C" void func_003C31C8(void *,void *);
extern "C" void func_003DF898(void *,void *);
extern "C" int func_0038B850(void *,void *);
#define F(p,t,o) (*(t *)((char *)(p)+(o)))
extern "C" int RaceSplitBattleBase__structor_0(char *self) {
 int count = 5;
 char *elements = self + 0x1E988;
 func_005F2A08(self);
 F(self,char *,0x64) = RaceSplitBattleBase__vtable;
 func_0055F9F8(self+0xE440);
 DynamicsConductorBattle2P__structor_1(self+0xE480);
 RaceInput__structor_0(self+0x1E5C8);
 RaceInput__structor_0(self+0x1E7A8);
 for (; count != -1; --count) { func_00393700(elements); elements += 8; }
 int i = 0;
 ResultArcade__structor_0(self+0x1E9B8);
 char *p = self;
 RacePause__structor_0(self+0x1EEB8);
 SimplePause__structor_0(self+0x1EEF0);
 RaceSplitDisplay__structor_0(self+0x1EEFC);
 F(self,char *,0x70) = self+0xE480;
 char *q = self+0x1E6A0;
 char *global = D_00622F4C;
 F(self,char *,0x58) = self+0xE440;
 char *obj = global+0x39E80;
 do {
  char *input = p+0x1E5C8;
  F(q,int,-0xD8) = func_0055F420(func_0033D958(i));
  VE *e = (VE *)(*(char **)obj+0x40);
  F(q,int,0xBC) = e->fn(obj+e->d,i);
  func_00109A28(self,input);
  F(q,int,0) = 0;
  func_00346808(p+0x1E69C,i);
  p += 0x1E0;
  ++i;
  q += 0x1E0;
 } while (i < 2);
 char *pause = self+0x1EEB8;
 char *common = self+0xE350;
 F(pause,int,0x28) = 1;
 F(pause,int,0x30) = 0;
 func_003C31C8(pause,common);
 char *result = self+0x1E9B8;
 F(result,int,0x64) = 1;
 func_003DF898(result,common);
 return func_0038B850(self,self+0x1EEF0);
}
