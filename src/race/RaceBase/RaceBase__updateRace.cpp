/* compiler: ee-gcc2.96-no-strict-aliasing */
struct V { short delta,index; void (*fn)(void *,...); };
struct VF { short delta,index; void (*fn)(void *,float); };
struct R { short delta,index; char *(*fn)(void *,int); };
#define F(p,t,o) (*(t *)((char *)(p)+(o)))
extern "C" void func_0034DB30(void *,int);
extern "C" int func_00373DA0(char *,int);
extern "C" int func_00387E88(void *) throw();
extern "C" void RaceCarSound__setDive(int);
extern "C" void RaceCourse__update(int);
extern "C" void func_00394D80(void *,float);
extern "C" void DynamicsConductor__Update(void *,void *);
extern "C" void RaceOrganization__racePreUpdate(void *);
extern "C" void RaceDisplayLapDiffEvent__structor_2(void *);
extern "C" void func_003C0F40(void *,float,float);
extern "C" int RaceBase__updateReplayEndingFrames(void *);
static inline char *get(char *s,int off,int a) { R *e=(R *)(F(s,char *,0x64)+off); return e->fn(s+e->delta,a); }
static inline bool exceeds(int n,int limit) { return n>limit; }
extern "C" void RaceBase__updateRace(char *s) {
 char *race=F(s,char *,0x6c);
 char *input=get(s,0xd0,0);
 if((unsigned)F(s,int,0xcc8)>=2) RaceCarSound__setDive(func_00373DA0(input,0));
 if(F(s,int,0xd48)==0) {
  char *p=F(s,char *,0x74);
  RaceOrganization__racePreUpdate(race);
  V *e=(V *)(F(p,char *,4)+0x10); e->fn(p+e->delta);
  if(F(s,int,0xcd0)==0) RaceCourse__update((unsigned)F(s,int,0xcc8)>=2);
  float dt=0x1.11111p-6f;
  func_00394D80(F(F(s,char *,0x6c),void *,0x80),dt);
  char *a=F(F(F(s,char *,0x6c),char *,0x80),char *,4);
  DynamicsConductor__Update(F(a,void *,0x80),a);
  func_0034DB30(F(s,void *,0x70),0);
  VF *ef=(VF *)(F(s,char *,0x64)+0x158); ef->fn(s+ef->delta,dt);
  RaceDisplayLapDiffEvent__structor_2(race);
  char *replay=get(s,0x240,0x100);
  if((unsigned)(F(s,int,0xcc8)-2)<2) {
   int frame=F(replay,int,0x11c); F(s,int,0xd28)=frame;
   int flag=1; if(!(F(race,float,0xd4)>=0.0f)) flag=0;
   if(flag==0 && F(race,int,0xe0)==0) {
    if(F(s,int,0xd54)==0) {
     int left=F(s,int,0xd2c)-frame;
     if(exceeds(left,60)) { } else func_003C0F40(race,(float)left*dt,1.0f);
    } else func_00387E88(s);
   }
  }
  if(RaceBase__updateReplayEndingFrames(replay)==0) F(s,int,0xd30)=0;
 }
 V *e=(V *)(F(input,char *,0)+0xb0); e->fn(input+e->delta,race,F(s,void *,0x70),F(s,int,0xd44)==0);
}
