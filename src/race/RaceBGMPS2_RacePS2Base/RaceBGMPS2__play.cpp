typedef long s64;
struct Record { int x[6]; };
struct VEntry { short delta, index; void (*fn)(void *); };
struct Settings { char pad[0x38D20]; int low; char p[12]; int high; };
struct State { char p[0xCC8]; unsigned mode; int pcc; int disabled; };
struct World { char p[0x84]; State *state; };
struct Obj { World *world; VEntry *vt; char p[12]; int a; Record rec; int b; char q[0x9D8-0x34]; char playlist[1]; };
extern "C" int RaceBGMPS2__isAutoDemo(Obj *) throw() __attribute__((const));
extern "C" int func_0033D4B8(Obj *) throw();
extern "C" void func_0033D110(Obj *, float) throw();
extern "C" void func_0033D810(Obj *, int, int, float);
extern "C" s64 *func_00438170(void *);
extern "C" void func_00462188(int, int, int, float);
extern "C" Record func_00462288(s64 *, int *);
extern "C" int SystemSoundGetOutputMode();
extern "C" float SystemSoundGetOutputModeVolume(int,int);
extern Settings *D_00622F4C;
static inline bool mode(State *s) { return s->mode>=2U; }
static inline void virt(Obj *o,int slot) { VEntry *e=o->vt+slot; e->fn((char*)o+e->delta); }
extern "C" void RaceBGMPS2__play(Obj *o,int id,int flag) {
 World *w=o->world; State *s=w->state;
 float volume=SystemSoundGetOutputModeVolume(SystemSoundGetOutputMode(),0);
 if(s->disabled==0) {
  if(RaceBGMPS2__isAutoDemo(o)) {
   virt(o,8);
   if(id==12) {
    float v; if(func_0033D4B8(o)) v=volume; else v=0.0f;
    func_00462188(26,0,0,v);
    o->a=0; o->b=0; func_0033D110(o,volume);
   }
  } else {
   if(id<0) {virt(o,8);return;}
   if(id==12) {
    float v;
    if(mode(w->state)) v=(float)D_00622F4C->high*0.0078125f;
    else v=(float)D_00622F4C->low*0.0078125f;
    volume*=v;
   }
   int index=-1;
   if(id==12) {
    s64 *key=func_00438170(o->playlist);
    if(key) {
     Record r=func_00462288(key,&index);
     Record tmp=r;
     o->rec=tmp;
     func_0033D810(o,index,0,volume);
    } else virt(o,8);
   } else {
    float v; if(func_0033D4B8(o)) v=volume; else v=0.0f;
    func_00462188(id,-1,flag,v);
    o->a=0; o->b=0; func_0033D110(o,volume);
   }
   virt(o,2);
  }
 }
}
