/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef short s16;
typedef float f32;
#define F(p,t,o) (*(t *)((char *)(p)+(o)))
struct VEntry { s16 delta,index; void *(*fn)(void *,s32); };
struct VFEntry { s16 delta,index; f32 (*fn)(void *); };
extern "C" s32 func_00376638(void *,s32,void *,void *,s32) throw();
extern "C" void func_00378F28(void *,void *,void *,void *,void *);
extern "C" void func_003FC4F0(void *,s32);
extern "C" s32 func_003FCD00(void *,s32);
extern "C" s32 func_003FD620(void *,s32,void *,s32,s32 *);
extern "C" void func_004007D8(void *,s32);
extern "C" s32 func_00400B90(void *);
extern "C" s32 func_00400BA8(void *);
extern "C" f32 func_00578598(void *);
extern "C" void func_00376AF0(char *arg0,void *arg1,s32 arg2,s32 arg3,s32 flags,char *out) {
    s32 scratch;
    char *s7=arg0+0xB80;
    char *s=arg0+arg3*0x19C;
    char *fp=arg0+4;
    char *p2=s+0xE0;
    char *sel=s+0x10;
    s32 reset=func_00400B90(s7)!=0;
    if(F(p2,s32,0x10)&0x10) reset=1;
    if(reset) {
        s32 n=F(arg0,s32,0xACC);
        s32 active=func_00400BA8(s7);
        s32 eligible=(n<120)==0;
        if(!active) eligible=0;
        flags|=2;
        if(eligible) {
            s16 old=F(sel,s16,0xC);
            s32 count=*F(arg1,s32 *,0x60);
            s32 i=(s32)(func_00578598(fp)*(f32)count);
            count--;
            if(i<=0) i=0;
            if(i>=count) i=count;
            func_003FC4F0(sel,func_003FCD00(arg1,i));
            if(F(sel,s16,0xC)!=old) F(out,s32,4)=1;
        }
    }
    s32 pending=F(sel,s32,0x18C);
    if(pending>=0) {
        flags|=2;
        func_003FC4F0(sel,pending);
        F(out,s32,4)=1;
    }
    func_004007D8(arg0+0xBC0,reset);
    s32 status=func_003FD620(arg1,arg2,sel,0,&scratch);
    if(status==1 || status==3) flags|=2;
    if((flags&2) && func_00376638(arg0,arg3,arg1,sel,arg2)) {
        F(out,s32,0)=1;
        F(s7,f32,0x20)=0.0f;
        if(func_00578598(fp)<0.1f) F(s7,f32,0x20)=func_00578598(fp)*0.5f+0.5f;
    }
    VEntry *e=(VEntry *)(F(arg0,char *,0)+0xD8);
    func_00378F28(e->fn(arg0+e->delta,arg3),arg1,p2,sel,arg0+0x9C0);
    F(out,f32,0xC)=F(s7,f32,0x20);
    VEntry * e_2 = (VEntry *)(F(arg0,char *,0)+0xD8);
    char *o=(char *)e_2->fn(arg0+e_2->delta,arg3);
    VFEntry *ef=(VFEntry *)(F(o,char *,0)+0xD8);
    f32 f=ef->fn(o+ef->delta);
    if(f>0.0f) F(out,f32,0xC)=f;
}
