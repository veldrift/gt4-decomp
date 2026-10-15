typedef unsigned char u8;
#define F(p,o) (*(float *)((char *)(p)+(o)))
extern u8 D_00620CD8[];
extern float D_006202A4,D_006202A8;
extern "C" u8 *func_00359510(void *);
extern "C" float *func_00360F80(void *,int,int);
extern "C" float func_0057D2B8(float) throw();
inline bool negative(u8 *info,int i,signed char *sign) { if(i>=info[1]) return false; return *sign<0; }
inline bool special(u8 *s) { int mode=s[0x466]; return mode==1||mode==2; }
inline float root(float x) { float r; __asm__("sqrt.s %0,%1" : "=f"(r):"f"(x)); return r; }
inline float spring(float *x,float *v,float target,float dt) {
    *v+=((target-*x)*500.0f-*v*20.0f)*dt;
    return *x+*v*dt;
}
union U { float f; int i; };
struct Sub { char pad[0x53c]; U speed; };
extern "C" void func_003F71E8(u8 *self) {
    u8 *s=self+0x104;
    float slip=0.0f;
    u8 *data=*(u8 **)(self+0x10);
    float under=0.0f;
    float total=0.0f;
    u8 *info=func_00359510(data);
    int i;
    if(!(((Sub *)s)->speed.f<=0.0f)) {
        for(i=0;i<info[1];i++) total+=*func_00360F80(data,i,self[0x1ed+i*0xec]);
        float angle=F(s,0x468);
        float yaw=F(s,0x57c);
        float accel=F(s,0x588);
        int mode2;
        if(angle*yaw>=0.0f) {
            if(angle<0.0f) { angle=-angle; yaw=-yaw; accel=-accel; }
            float a;
            float expect=F(s,0x53c)*func_0057D2B8(angle)/F(data,0x18);
            if(expect>0.0f) {
                a=F(s,0x554);
                if(a<0.0f) a=-a;
                a/=total;
                if(a>0x1.999998p-3f) {
                    if(accel*yaw>0.0f) yaw+=accel*0.5f;
                    if(yaw<expect) under=1.0f-yaw/expect;
                }
            }
            int mode=s[0x466];
            if(mode==1 || mode==2) goto specialMode;
            if(!s[0x467]) {
                if(((signed char *)self)[0x55] && D_00620CD8[0x134]) {
                    under*=D_006202A4;
                    if(under>1.0f) under=1.0f;
                }
            }
        }
        mode2=s[0x466];
        if(!(mode2==1 || mode2==2) && !s[0x467]) {
            for(i=0;i<info[1];i++) {
                signed char *sign=(signed char *)info+0x3c+i;
                if(negative(info,i,sign)) {
                    float a=F(self,0x198+i*0xec);
                    if(a<0.0f) a=-a;
                    if(slip<a) slip=a;
                }
            }
            float speed=root(F(s,0x53c)*F(s,0x53c)+F(s,0x540)*F(s,0x540));
            float f=speed*0x1.26e97ap-6f;
            if(f>1.0f) f=1.0f;
            float lo=D_00620CD8[0xdd]*0x1.1df468p-6f;
            float threshold=f*(D_00620CD8[0xde]*0x1.1df468p-6f-lo)+lo;
            if(threshold<=slip) {
                float lo=D_00620CD8[0xdf]*0x1.999998p-4f;
                slip=((f*(D_00620CD8[0xe0]*0x1.999998p-4f-lo)+lo)*(slip-threshold))/(0x1.921fb2p+0f-threshold);
                if(((signed char *)self)[0x55] && D_00620CD8[0x135]) slip*=D_006202A8;
                if(slip>1.0f) slip=1.0f;
            }
        } else {
        specialMode:
            float speed=root(F(s,0x53c)*F(s,0x53c)+F(s,0x540)*F(s,0x540));
            if(!(speed<0x1.bc71c4p+2f)) {
                float a=speed*F(s,0x57c);
                float b=F(s,0x554);
                if(!(a*b>=0.0f)) {
                    if(a<0.0f) a=-a;
                    if(b<0.0f) b=-b;
                    a-=b;
                    if(a<0.0f) a=0.0f;
                    slip=(a+a)/total;
                }
            }
        }
    }
    float dt=F(self,0x54c);
    if(D_00620CD8[0x136]) {
        float *v=(float *)(s+0x474);
        *v+=((under-F(s,0x470))*500.0f-*v*20.0f)*dt;
        under=F(s,0x470)+*v*dt;
    }
    if(D_00620CD8[0x137]) {
        float *v=(float *)(s+0x47c);
        *v+=((slip-F(s,0x478))*500.0f-*v*20.0f)*dt;
        slip=F(s,0x478)+*v*dt;
    }
    F(s,0x470)=under;
    F(s,0x478)=slip;
}
