/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned char u8;
#define F(p,o) (*(float *)((u8 *)(p)+(o)))
extern "C" u8 *func_00359510(void *);
extern "C" u8 *func_00360F80(void *,int,int);
extern "C" float func_00359778(void *,float);
extern "C" int func_0034C998(void *);
extern "C" void func_003F92D0(void *) throw();
extern "C" void func_003F94C0(void *,int,void *,int) throw();
extern "C" void func_003F9340(void *,void *,void *) throw();
extern u8 D_00620CD8[];
extern u8 D_00620CDD[];
inline u8 degrees(u8 *p) { return p[0xe5]; }
struct Gains {float a[2],b[2],c[4],d[4],e[4];};
struct Tables {u8 pad[0x1020];float a[4];float b[4];};
inline u8 index(u8 *info,int i) { if(i<info[1]) return info[0x14+i]; return 0; }
extern "C" void func_003F9870(u8 *self,int arg1,int arg2) {
    Gains g;
    float values[8];
    u8 *state=self+0x104;
    u8 *data=*(u8 **)(self+0x10);
    u8 *info=func_00359510(data);
    func_003F92D0(&g);
    for(int i=0;i<info[1];i++) {
        values[i]=F(func_00360F80(data,i,self[0x1ed+i*0xec]),0x168);
    }
    for(int i=0;i<info[1];i++) {
        int weight=D_00620CDD[0x110+info[0x14+i]];
        u8 *w=self+0x164+i*0xec;
        if(weight) {
            u8 *item=func_00360F80(data,i,w[0x89]);
            if(item[0x1d8]==1) {
                float x=func_00359778(item+0x170,F(w,0x5c));
                float old=values[i];
                if(x<old) {
                    float factor=weight/100.0f;
                    values[i]=factor*x+(1.0f-factor)*old;
                }
            }
        }
    }
    if(func_0034C998(*(void **)(self+4))) {
        if(D_00620CD8[0xe5]) {
            int deg=D_00620CD8[0xe5];
            float x=F(state,0x468);
            float limit=(float)deg;
            limit*=0x1.1df468p-6f;
            if(x<0) x=-x;
            if(limit<=x) x=1.0f; else x=x/limit;
            for(int i=0;i<2;i++) g.a[i]*=1.0f-x*(D_00620CD8[0xe6+i]*0.01f);
        }
    }
    func_003F94C0(self,arg1,&g,arg2);
    if(data[0x32]==2) {
        for(int i=0;i<4;i++) {
            u8 *w=self+0x164+i*0xec;
            w[0x88]=0;
            if(g.c[i]!=1.0f || g.d[i]!=1.0f || g.e[i]!=0.0f) w[0x88]=1;
        }
    }
    func_003F9340(self,&g,values);
    for(int i=0;i<(int)info[1];i++) {
        u8 *w=self+0x164+i*0xec;
        int ix=index(info,i);
        Tables *t=(Tables *)(data+4);
        float a=t->a[ix];
        float b=F(w,0x4c)*t->b[ix];
        float old=F(w,0x64);
        if(old!=0.0f) {
            a*=F(w,0x3c);
            float delta=F(w,0x38)-values[i];
            float x=b*(1.0f-delta*a);
            if(x<0.0f) x=0.0f; else if(x>1.0f) x=1.0f;
            x=x*old;
            if(x==0.0f) x=0x1.0624dcp-10f;
            F(w,0x64)=x;
        }
    }
}
