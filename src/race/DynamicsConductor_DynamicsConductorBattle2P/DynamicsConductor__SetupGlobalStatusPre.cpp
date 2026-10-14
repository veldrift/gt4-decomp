/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned char u8;
struct V {short delta,index; int (*fn)(char *);};
struct V1 {short delta,index; int (*fn)(char *,char *);};
extern char D_00620B00[],D_00620AF0[];
extern "C" unsigned short RaceCourse__getSectionCount(void *);
extern "C" void RaceCourse__setSectionNumber(void *,int);
extern "C" int RaceOrganization__validArcadeOption(char *);
extern "C" int func_0034C998(char *) throw();
extern "C" int GtbSetupTireTwistParameters(char *);
extern "C" void func_003F7BE0();
extern "C" int GtbABC_SetupGlobal(char *,char *,int,int);
extern "C" int AutomobileOverrideEnvptr();
extern "C" void SetupEffectParameters(char *);
extern "C" int func_00366D68();
extern "C" void SetupBrakeHeatParameters();
extern "C" int func_003F3808();
extern "C" int DynamicsConductor__SetupSlowCarBoost(char *) throw();
extern "C" void func_00365480(char *,int);
extern "C" void func_00367C90(char *,char *,int,int);
extern "C" int SetupHumanInterfaceParameters(char *);
extern "C" int func_00347A00(char *,int) throw();
extern "C" int DynamicsConductor__BSpecCommand(char *);
extern "C" int func_003F1BD8(char *,int,int,int);
static inline int vc(char *p) {V *e=(V *)(*(char **)(p+0x10140)+0x30); return e->fn(p+e->delta);}
extern "C" int DynamicsConductor__SetupGlobalStatusPre(char *p,int arg1) {
 int section=*(signed char *)(p+0xF839);
 if(section>=RaceCourse__getSectionCount(*(void **)(p+0xCBD8))) section=-1;
 RaceCourse__setSectionNumber(*(void **)(p+0xCBD8),section);
 p[0xCBE2]=section;
 char *org=*(char **)p;
 p[0xCBE5]=0;
 if(RaceOrganization__validArcadeOption(org)) {
  int mode=*(int *)(org+4);
  V *e=(V *)(*(char **)(p+0x10140)+0x30);
  int select=e->fn(p+e->delta)?0:mode;
  switch(select) {
   case 1: p[0xF861]=8; p[0xF860]=40; p[0xF862]=10; break;
   case 2: p[0xF861]=8; p[0xF860]=40; p[0xF862]=-1; break;
   case 0:
   default: p[0xF862]=0; p[0xF861]=-1; p[0xF860]=-1; break;
  }
 }
 if(((u8 *)p)[0xCBE0]!=1 || func_0034C998(p) || vc(p)) {
  if(((u8 *)p)[0xF862]==255) p[0xF862]=0;
  p[0xF864]=0;
 }
 char *s=p+0xF818;
 GtbSetupTireTwistParameters(p);
 func_003F7BE0();
 GtbABC_SetupGlobal(D_00620B00,D_00620AF0,4,2);
 AutomobileOverrideEnvptr();
 SetupEffectParameters(p);
 func_00366D68();
 SetupBrakeHeatParameters();
 func_003F3808();
 DynamicsConductor__SetupSlowCarBoost(p);
 int a,b;
 {V1 *e=(V1 *)(*(char **)(p+0x10140)+0x60); a=e->fn(p+e->delta,s);}
 {V1 *e=(V1 *)(*(char **)(p+0x10140)+0x58); b=e->fn(p+e->delta,s);}
 func_00365480(p,a);
 if(func_0034C998(p)) b=0;
 func_00367C90(p+4,s,((u8 *)p)[0xCBE0]==1?b:0,arg1);
 SetupHumanInterfaceParameters(p);
 func_00347A00(p,arg1);
 DynamicsConductor__BSpecCommand(p);
 *(float *)(p+0xCBF8)=1.0f;
 return func_003F1BD8(p,1,0,0);
}
