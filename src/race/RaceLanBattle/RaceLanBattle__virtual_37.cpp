/* compiler: ee-gcc2.96-no-strict-aliasing */
#define F(p,t,o) (*(t *)((char *)(p)+(o)))
extern "C" {
void func_00335960() throw();
void func_00335E28(void *) throw();
void func_00335F58(void *,void *) throw();
void func_00337918(void *);
void AutomobileControlRecord__Manager__reset(void *);
void RaceBasic__initialize(void *,int);
void func_0038B7C0(void *,void *);
void func_0038B8D8(void *,void *);
void func_0038BC88(void *,int);
void RaceDisplay__setOrganization(void *,int);
void RaceDisplay__virtual_06(void *,int);
void RaceDisplay__virtual_07(void *,int);
void RaceDisplay__initialize(void *);
void RaceInput__setRunMode(void *,unsigned);
int func_004395E8();
void func_0043A138(void *);
void func_00501A68(void *,int);
void func_00336338(); void func_00336368(); void func_00336408();
extern char D_00645570[];
}
struct Entry {short delta,index; int (*fn)(void *);};
struct Entry2 {short delta,index; void (*fn)(void *,int);};
typedef void (*Callback)();
struct State {int v; State(int n) {v=n;} void set(int n) {v=n;} int get() const {return v;} bool is(int n) const {return v==n;} bool isNot(int n) const {return v!=n;} };
struct Flag {unsigned lo:16; unsigned val:8; unsigned hi:8;};
inline void setFlag1(char *d,bool b) { unsigned int value=(unsigned int)b<<16; F(d,unsigned int,0x34)=(F(d,unsigned int,0x34)&0xff00ffff)|value; }
inline void setFlag2(char *d,bool b) { unsigned int value=(unsigned int)b<<16; F(d,unsigned int,0x40)=(F(d,unsigned int,0x40)&0xff00ffff)|value; }
extern "C" void RaceLanBattle__virtual_37(char *p,int mode) {
    F(p,int,0xe440)=mode;
    int run=mode;
    func_00337918(p);
    int t=F(F(p,void *,0xe484),int,0x44);
    State state(t);
    if(t!=2) {t=F(F(p,void *,0xe480),int,0xf8)!=0;state.set(t);}
    int empty=t==0;
    F(p,int,0xe458)=empty;
    F(p,int,0xe454)=empty;
    if(state.get()) { if(mode==0) run=2; else run=mode==1?3:2; }
    char *g=D_00645570;
    int value=F(g,int,0x3fa0);
    if(value<0) {Entry *e=(Entry *)(F(p,char *,0x64)+0x310); value=e->fn(p+e->delta);}
    F(p,int,0xe444)=value;
    char *input=p+0xf184;
    char *items=p+0xe50c;
    F(p,int,0xe448)=F(g,int,0x3fa8);
    AutomobileControlRecord__Manager__reset(p+0xf258);
    RaceInput__setRunMode(input,run);
    func_0043A138(p+0xf2f4);
    for(int i=0;i<6;i++,items+=0x214) {RaceInput__setRunMode(items,mode);func_00335E28(items);}
    F(p,int,0xe470)=0;
    F(p,int,0xe46c)=1;
    F(p,int,0xe474)=0; F(p,int,0xe478)=0; F(p,int,0xe47c)=0;
    func_00335960();
    char *cb=p+0xcf88;
    F(cb,Callback,8)=func_00336338;
    F(cb,Callback,12)=func_00336408;
    F(cb,Callback,16)=func_00336368;
    RaceBasic__initialize(p,run);
    RaceDisplay__setOrganization((p+0x1fa4c),F(p,int,0x6c));
    RaceDisplay__virtual_06((p+0x1fa4c),0x11);
    RaceDisplay__virtual_07((p+0x1fa4c),state.get()==1?4:mode);
    RaceDisplay__initialize((p+0x1fa4c));
    char *g2=D_00645570;
    F(p,int,0xe450)=F(g2,int,0x3f68);
    func_00501A68(F(p,void *,0xe480),0x40);
    func_00335F58(p+0xe488,F(p,void *,0xe480));
    int flag=0;
    if(run==2) { if(mode==run) flag=func_004395E8()!=0; func_0038BC88(p,flag);func_0038B8D8(p,0); }
    else {func_0038BC88(p,0);func_0038B8D8(p,p+0x1f508);}
    char *d=p+0x1fa4c;
    setFlag1(d,state.get()==1);
    setFlag2(d,state.get()==2);
    func_0038B7C0(p,state.isNot(2)?p+0x1fa14:p+0x2397c);
    int v=F(p,int,0xe444);
    char *obj=F(p,char *,0xe420);
    if(obj) { Entry2 *e=(Entry2 *)(F(obj,char *,0)+0x50);e->fn(obj+e->delta,v); }
    F(p,int,0x1f50c)=v;
}
