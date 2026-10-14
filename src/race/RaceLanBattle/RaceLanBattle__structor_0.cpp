/* compiler: ee-gcc2.96-no-strict-aliasing */
#define F(p,t,o) (*(t *)((char *)(p)+(o)))
extern "C" {
void func_00109A28(void *,void *);
void RaceInputLan__structor_0(void *) throw();
void RaceLanControlManager__structor_0(void *,void *) throw();
void func_00337918(void *);
char *func_0033D958(int);
void func_00346808(void *,int);
void DynamicsConductorBattleMP__structor_2(void *);
void func_0038BB50(void *,void *);
int func_00393700(void *);
void RaceDisplay__structor_0(void *);
void RacePause__structor_0(void *);
void func_003C31C8(void *,void *);
int PauseBase__structor_0(void *);
int ResultArcade__structor_0(void *);
int func_003DF898(void *,void *);
void RaceInput__structor_0(void *);
void *func_005030E8();
void func_0055EEC0(void *,void *);
int func_0055F420(const char *);
int func_005F31E0(void *);
void func_003359B0();
extern char RaceLanBattle__vtable[],ResultLinkBattle__vtable[];
extern char *D_00622F4C;
extern char *D_006201C8;
}
struct Entry {short delta,index; int (*fn)(void *,int);};
inline void *operator new(unsigned int, void *p) {return p;}
struct Input {char x[0x20c]; Input() __asm__("func_00426800");};
struct Dynamics {char x[0x10148]; Dynamics() __asm__("func_00347380");};
struct Elem {char x[8]; Elem() __asm__("func_00393700");};
struct Region {Input input; Dynamics dynamics; Elem elems[6];};
extern "C" int RaceLanBattle__structor_0(char *p) {
    char *cur=p+0xe50c;
    int n=5;
    func_005F31E0(p);
    F(p,int,0xe44c)=0;F(p,int,0xe454)=0;
    F(p,char *,0x64)=RaceLanBattle__vtable;
    F(p,int,0xe458)=0;
    F(p,void *,0xe480)=func_005030E8();
    F(p,char *,0xe484)=D_00622F4C+0x39ff4;
    RaceLanControlManager__structor_0(p+0xe488,p);
    do {RaceInputLan__structor_0(cur);cur+=0x214;n--;} while(n!=-1);
    new (p+0xf184) Region;
    char *result=p+0x1f508;
    char *display=p+0x1fa4c;
    char *input=p+0xf184;
    ResultArcade__structor_0(result);
    F(result,char *,12)=ResultLinkBattle__vtable;
    cur=p+0xe50c;
    RacePause__structor_0(p+0x1fa14);
    RaceDisplay__structor_0(display);
    PauseBase__structor_0(p+0x2397c);
    D_006201C8=p;
    func_00337918(p);
    F(p,char *,0x70)=p+0xf390;
    func_0038BB50(p,display);
    typedef void (*Callback)();
    F(p,Callback,0x78)=func_003359B0;
    F(input,int,0)=func_0055F420(func_0033D958(0));
    char *obj=D_00622F4C+0x39e80;
    Entry *e=(Entry *)(F(obj,char *,0)+0x40);
    F(input,int,0x194)=e->fn(obj+e->delta,0);
    char *h=p+0xf364;
    F(h,short,4)=0;F(h,short,2)=0;F(h,short,0)=0;F(h,short,10)=0;F(h,short,8)=0;F(h,short,6)=0;
    F(p,char *,0x58)=p+0xe488;
    func_00109A28(p,input);
    for(int i=0;i<6;i++,cur+=0x214) {
        Entry *v=(Entry *)(F(obj,char *,0)+0x40);
        F(cur,int,0x194)=v->fn(obj+v->delta,0);
        func_0055EEC0(p+0xe488,cur);
    }
    char *rec=p+0xf258;
    char *data=p+0xe350;
    F(rec,int,4)=0;
    func_00346808(rec,0);
    char *pause=p+0x1fa14;
    F(pause,int,0x30)=0;
    func_003C31C8(pause,data);
    return func_003DF898(p+0x1f508,data);
}
