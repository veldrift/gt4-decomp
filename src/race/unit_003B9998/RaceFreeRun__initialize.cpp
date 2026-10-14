/* compiler: ee-gcc2.96-no-strict-aliasing */
#define F(p,t,o) (*(t*)((char*)(p)+(o)))
struct EV {short delta,pad;void(*fn)(void*);};
struct Display {char pad0[8];void *p8;char padc[0x48];int text;};
extern "C" void func_00346890(void*,int),func_0038B7C0(void*,void*),func_0038B8D8(void*,void*),func_0038B990(void*,void*),func_0038BA90(void*,int),func_0038BAB0(void*,void*),RaceDisplay__virtual_06(void*,int),RaceSolitaire__initialize(void*,void*),func_00460538(),BGM__narrationFreeBuffer();
extern "C" char *RaceSolitaire__getInputGhost(void*);
extern "C" int DisplayRText__getRTextStr(void*),BGM__narrationEnable();
inline bool enabled(unsigned x){return x>=2;}
extern char *D_00622F4C;extern char D_006A26D0[];
extern "C" void RaceFreeRun__initialize(char *self,void *arg) {
 F(self,int,0x24694)=0;F(self,int,0x24698)=0;F(self,int,0x246A4)=0;F(self,int,0x246A0)=0;F(self,int,0x2469C)=0;
 BGM__narrationFreeBuffer();func_0038B7C0(self,0);func_0038B8D8(self,0);func_0038BAB0(self,0);func_0038B990(self,0);func_0038BA90(self,0);RaceSolitaire__initialize(self,arg);
 char *org=F(self,char*,0x6C);char *ghost=RaceSolitaire__getInputGhost(self);
 if(F(ghost,int,0x1D0))func_00346890(ghost+0xD4,0);
 func_00460538();unsigned mode=F(self,unsigned,0xCC8);
 if(mode-2<2) {
  func_0038B7C0(self,0);func_0038B8D8(self,0);func_0038BAB0(self,0);func_0038B990(self,0);func_0038BA90(self,0);
  if(F(org,int,0xE0)==0&&F(self,int,0xF054)!=0){EV *e=(EV*)(F(self,char*,0x64)+0x4C8);e->fn(self+e->delta);F(org,int,0xB4)=-1;}
 }else {
  char *p=self+0x1F2D0;int flag=0;if(mode==1||mode==3)flag=1;F(p,int,0x34)=flag;
  func_0038B7C0(self,self+0x1F2D0);func_0038B8D8(self,0);func_0038B990(self,F(self,void*,0xE408));func_0038BAB0(self,self+0x23238);
  F(F(self,char*,0xE424),void*,0x14)=self+0x1F2A0;
  func_0038BA90(self,F(self,int,0xE410));
 }
 Display *d=(Display*)(self+0x1F308);RaceDisplay__virtual_06(d,7);d->p8=self+0x1F2A0;
 if(enabled(F(self,unsigned,0xCC8))){int flag=F(D_00622F4C,int,0x39DEC)==1;if(BGM__narrationEnable()!=0&&F(D_00622F4C,int,0x39D64)==0&&flag==0)d->text=DisplayRText__getRTextStr(D_006A26D0);}
}
