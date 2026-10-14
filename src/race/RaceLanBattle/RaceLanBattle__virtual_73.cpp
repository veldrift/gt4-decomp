/* compiler: ee-gcc2.96-no-strict-aliasing */
#define F(p,t,o) (*(t *)((char *)(p)+(o)))
extern "C" {
int func_00336008(void *) throw();
int func_00373DA0(void *,int);
void RaceBasic__updatePlay(void *,float);
void RaceDisplay__virtual_10(void *,int);
void RaceDisplay__setViewMode(void *,int);
void RaceDisplay__setDiveReplayMode(void *,int);
void RaceDisplay__commonPreUpdate(void *);
void func_0039DA80(void *);
void RaceDisplay__update(void *,float);
void RaceDisplay__setDisplayEnableInReplay(void *,int);
void func_003B76F0(void *,int,int,int);
}
struct Rec {char pad[0x1c];short state;char tail[0x19c-0x1e];};
struct Car {Rec recs[6];char pad[0x14];int current;};
struct Entry {short delta,index;int (*fn)(void *);};
struct Entry1 {short delta,index;char *(*fn)(void *,int);};
struct Entry3 {short delta,index;void (*fn)(void *,void *,int);};
extern "C" void RaceLanBattle__virtual_73(char *p,float dt) {
    if(F(p,int,0xf378)) {
        char *sub=p+0xf260;
        char *display=p+0x1fa4c;
        do {
            RaceBasic__updatePlay(p,dt);
            if(F(p,int,0xcc8)==2 && F(p,int,0xe454) && F(sub,int,0x38))
                func_003B76F0(F(p,char *,0x6c)+0xf4,1,0,0);
            RaceDisplay__commonPreUpdate(F(p,void *,0x6c));
            Entry1 *e=(Entry1 *)(F(p,char *,0x64)+0xd0);
            char *car=e->fn(p+e->delta,0);
            RaceDisplay__virtual_10(display,((Car *)car)->recs[((Car *)car)->current].state);
            Entry *v=(Entry *)(F(car,char *,0)+0x120);
            RaceDisplay__setViewMode(display,v->fn(car+v->delta));
            RaceDisplay__setDiveReplayMode(display,func_00373DA0(car,0));
            Entry *v2=(Entry *)(F(car,char *,0)+0x1b0);
            RaceDisplay__setDisplayEnableInReplay(display,v2->fn(car+v2->delta));
            RaceDisplay__update(display,dt);
            if(F(p,void *,0xe41c)) {
                void *org=F(p,void *,0x6c);
                Entry *v3=(Entry *)(F(p,char *,0x64)+0x230);
                int result=v3->fn(p+v3->delta);
                char *obj=F(p,char *,0xe41c);
                Entry3 *v4=(Entry3 *)(F(obj,char *,12)+0x20);
                v4->fn(obj+v4->delta,org,result);
            }
            func_0039DA80(F(p,void *,0x6c));
            if(F(p,int,0xe468)) break;
            if(!func_00336008(p+0xe488)) break;
        } while(F(p,int,0xf378));
    }
}
