/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned char u8;
typedef unsigned int u32;
#define I(p,o) (*(int *)((u8 *)(p)+(o)))
#define S(p,o) (*(signed char *)((u8 *)(p)+(o)))
extern "C" int func_003F8818(void *,int) throw();
extern "C" void func_003F88E8(void *) throw();
extern "C" void func_00343D78(void *,int);
extern "C" int func_00358000(void *,int,u32);
extern "C" void func_0035DF80(void *,int,int,int);
extern "C" void DynamicsConductor__ReportDifferenceFromRecord(void *,int,u32);
extern "C" void RaceDisplayGeneralTimeEvent__structor_1(void *,int,int,u32,u32,int);
extern "C" int ToyotaPrius_GetAverageGasMileage10(void *);
extern "C" int func_003C0B80(void *);
extern "C" u32 RaceOrganization__getLicenseRank(void *,int);
extern int D_006244E8;
struct Pair {int rank;u32 time;void set(int a,u32 b){rank=a;time=b;}};
inline u8 flag(u8 *p) { return p[0xcbdc]; }
extern "C" void func_003F8AB0(u8 *self,u8 *object,u32 time) {
    int success=0;
    u8 *owner=*(u8 **)self;
    u8 *state=object+0x104;
    func_00343D78(object,func_003F8818(self,0));
    if(S(state,0x466)==2) return;
    func_003F88E8(self);
    if(!state[0x441]) {
        if(I(owner,0xdc)) return;
        if(I(owner,0xf0)) {
            func_0035DF80(owner,5,state[0x440],2);
        } else {
            u8 *config=self+0xf818;
            int n=func_003C0B80(owner);
            int rank=0;
            if(config[0x40]<3u) {
                for(int i=0;i<n;i++) {
                    if(RaceOrganization__getLicenseRank(owner,i)>=time) {
                        rank=i+1;
                        success=1;
                        break;
                    }
                }
            } else {
                int position=S(state,0x4af);
                if(position<4) { rank=position+1;success=1; }
                else {rank=0;time=0x157529ff;}
            }
            if(success) {
                if(config[0x45]) {
                    int difference=ToyotaPrius_GetAverageGasMileage10(object)-config[0x45];
                    if(D_006244E8==3) difference=-difference;
                    if(difference<0) {success=0;rank=0;time=0x157529ff;}
                }
            }
            if(success) {
                if(flag(self)) func_0035DF80(owner,5,state[0x440],2);
            } else func_0035DF80(owner,10,state[0x440],0);
            if(!flag(self)) {
                ((Pair *)(owner+0x88))->set(rank,time);
                func_00358000(self,state[0x440],time);
            }
        }
    }
    if(time!=0x157529ff) {
        u8 *config=self+0xf818;
        if(config[0x40]==0 || config[2]==6) DynamicsConductor__ReportDifferenceFromRecord(self,state[0x440],time);
        return RaceDisplayGeneralTimeEvent__structor_1(self,state[0x440],1,time,time,object[0x5b7]);
    }
}
