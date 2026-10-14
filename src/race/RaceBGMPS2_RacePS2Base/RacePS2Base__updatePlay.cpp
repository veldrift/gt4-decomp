typedef int s32; typedef short s16; typedef float f32;
#define F(p,t,o) (*(t *)((char *)(p)+(o)))
struct E { s16 delta,index; void *fn; };
struct EI { s16 delta,index; s32 (*fn)(char *,s32); };
struct ER { s16 delta,index; f32 (*fn)(char *); };
struct EV { s16 delta,index; void (*fn)(char *); };
struct EF { s16 delta,index; void (*fn)(char *,f32); };
static inline E *entry(char *p,int off) { return (E *)(F(p,char *,0x64)+off); }
static inline char *get(char *p) { E *e=entry(p,0xD0); return ((char *(*)(char *,s32))e->fn)(p+e->delta,0); }
static inline s32 query(char *p,int off) { E *e=entry(p,off); return ((s32 (*)(char *))e->fn)(p+e->delta); }
static inline void action(char *p,int off) { EV *e=(EV *)(F(p,char *,0x64)+off); e->fn(p+e->delta); }
static inline f32 maxf(f32 a,f32 b) { f32 r; __asm__("max.s %0, %1, %2":"=&f"(r):"f"(a),"f"(b));return r; }
static inline f32 maxnormal(f32 a,f32 b) { f32 r; __asm__("max.s %0, %1, %2":"=f"(r):"f"(a),"f"(b));return r; }
static inline f32 minf(f32 a,f32 b) { f32 r; __asm__("min.s %0, %1, %2":"=f"(r):"f"(a),"f"(b));return r; }
extern "C" {
s32 RaceBase__updatePlay(char *,f32); void func_004965D8(char *); void FlareClass__updateFlare(char *,f32); void RaceSmoke__update(char *,f32); void RigidBodyManager__Update(char *,f32);
s32 ParticleManager__Update(char *,f32,s32); s32 RaceInput__getExtendButtonDown(s32); s32 func_00373DA0(char *,s32); void CourseData__render_course_for_renderer(char *,f32);
}
extern "C" void RacePS2Base__updatePlay(char *p,f32 dt) {
    RaceBase__updatePlay(p,dt);
    func_004965D8(F(p,char *,0xD94));
    FlareClass__updateFlare(p+0xDA0,dt); RaceSmoke__update(p+0x31D0,dt);RigidBodyManager__Update(p+0x35E8,dt);
    char *obj=get(p);
    EI *e=(EI *)(F(obj,char *,0)+0x138);
    ParticleManager__Update(p+0x3238,dt,e->fn(obj+e->delta,0));
    s32 flags=RaceInput__getExtendButtonDown(query(p,0x230));
    if ((flags&1) && F(p,s32,0xCF34)!=0) { char *a=F(F(p,char *,0x6C),char *,0x80);F(a,s32,0xB4)^=1; }
    s32 active=func_00373DA0(get(p),0);
    if(active != 0 && query(p,0x400)!=0) action(p,0x408);
    if((flags&4) && active==0) { action(p,0x408);action(p,0x410); }
    if(flags&8) {
        EF *e=(EF *)(F(p,char *,0x64)+0xF0);
        e->fn(p+e->delta,F(p,f32,0xD3C)==1.0f ? 4.0f:1.0f);
        action(p,0x418);
    }
    char *second=get(p); ER *er=(ER *)(F(second,char *,0)+0x118);
    f32 v=er->fn(second+er->delta);
    F(p,f32,0xCF38) += v*0x1.199998p+0f-0x1.0e5604p-5f;
    f32 duration=F(p,f32,0xCF40);
    F(p,f32,0xCF38)=minf(maxf(F(p,f32,0xCF38),0.0f),3.0f);
    if(duration>0.0f) F(p,f32,0xCF3C)=maxnormal(F(p,f32,0xCF3C)-dt/duration,0.0f);
    else F(p,f32,0xCF3C)=0.0f;
    f32 *rates=(f32 *)(p+0xCF50);
    f32 *values=(f32 *)(p+0xCF48);
    for(int i=0;i<2;i++,rates++,values++) { *values=minf(maxf(*values+dt**rates,0.0f),1.0f); }
    CourseData__render_course_for_renderer(F(F(F(p,char *,0x6C),char *,0x80),char *,4),F(p,f32,0xCF5C));
}
