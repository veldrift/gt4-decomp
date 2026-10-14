/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned int u32;
struct VE { short delta,index; char *(*fn)(char *,int); };
struct Manager { char pad[0x64]; VE *vt; char pad68[0xd54-0x68]; int flag; };
struct State { char pad[0xc]; int a,b; };
struct Owner { char pad[0x84]; Manager *mgr; State state; char pad9c[0xe0-0x9c]; int e0,e4; };
struct Self { Owner *owner; char pad4[0xcbdc-4]; unsigned char cbdc; char padcbdd[0xf8a0-0xcbdd]; int mode; char padf8a4[0x10024-0xf8a4]; int a,b; };
struct Game { char pad[0x39d7c]; int flag; };
extern Game *D_00622F4C;
#define F(p,T,o) (*(T *)((char *)(p)+(o)))
extern "C" char *func_0034C190(Self *,int);
extern "C" void DynamicsConductor__ReportDifferenceFromRecord(Self *,int,u32);
extern "C" void RaceDisplayGeneralTimeEvent__structor_1(Self *,int,int,int,u32,int);
extern "C" int func_00426C38(char *);
extern "C" void func_00426C78(char *);
extern "C" char *func_00346A28(void *);
extern "C" void func_00426CA0(char *);
extern "C" void func_003C08C0(Owner *,int,int);
extern "C" void func_003F58B0(char *,char *,int,float) throw();
extern "C" int func_003F5820(char *,char *,int,float) throw();
extern "C" int func_00345520(char *);
extern "C" int func_003454A8(char *);
extern "C" void func_00363528(char *);
static inline char *get(Manager *m,int id) {
    VE *e=(VE *)((char *)m->vt+0x240);
    return e->fn((char *)m+e->delta,id);
}
static inline void event(Self *s,int i,int l,const int &tr,u32 tm,char *car) {
    RaceDisplayGeneralTimeEvent__structor_1(s,i,l,tr,tm,F(car,unsigned char,0x5b7));
}
extern "C" void DynamicsConductorFreeRun__ProcessControlLine(Self *self,int index,int lap,int unused,int transfer,u32 time,int flag,float t) {
    char *car=func_0034C190(self,index);
    DynamicsConductor__ReportDifferenceFromRecord(self,index,time);
    char *data=car+0x104;
    event(self,index,lap,transfer,time,car);
    Owner *owner=self->owner;
    if(index==0) {
        Manager *mgr=owner->mgr;
        char *input=get(mgr,0x100);
        if(self->cbdc==0) {
            int first=func_00426C38(input)==0;
            func_00426C78(input);
            if(first) {
                int better=0;
                F(func_00346A28(F(input,void *,0x148)),u32,0x10)=time;
                char *record=func_00346A28(F(input,void *,0x144));
                if(F(car,unsigned char,0x5b7)==0)better=time<F(record,u32,0x10);
                if(better) {
                    State *s=&owner->state;
                    func_00426CA0(input);
                    s->b=1;
                    char *othercar=get(mgr,1);
                    int update;
                    if(F(othercar,int,0x1d0)!=0) update=1;
                    else update=time<F(func_00346A28(get(mgr,1)+0xd4),u32,0x10);
                    if(update) {
                        s->a=1;
                        func_003C08C0(owner,1,1);
                        if(D_00622F4C->flag) {
                            char *other=func_0034C190(self,1);
                            F(other,int,0x10)=F(func_0034C190(self,0),int,0x10);
                            self->b=self->a;
                        }
                    }
                }
            }
        }
        if(owner->e0==0 && self->mode==2) {
            char *other=get(mgr,1);
            func_003F58B0(other,func_0034C190(self,1),lap,t);
        }
        if(self->cbdc==0)func_003F5820(get(mgr,0x100),car,flag,t);
    }
    if(F(data,unsigned char,0x441)!=0 || self->owner->e4!=0)func_00345520(car);
    Manager *mgr=self->owner->mgr;
    if(mgr->flag) {
        func_003454A8(car);
        VE *e=(VE *)((char *)mgr->vt+0xb0);
        e->fn((char *)mgr+e->delta,-1);
    }
    func_00363528(car);
    F(data,int,0x614)=transfer;
}
