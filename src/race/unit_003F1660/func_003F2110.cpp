/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned char u8;
#define F(p,t,o) (*(t *)((char *)(p)+(o)))
extern "C" float func_003554A0(void *,float);
extern "C" int func_003F1F78(void *) throw();
extern "C" void func_003F2070(void) throw();
extern "C" float D_00622104,D_00622108,D_006220F8,D_006220FC;
extern "C" float func_003F2110(char *self) {
    char *p=self+0x104;
    float v=1.0f;
    float dt=F(self,float,0x54c);
    char *q=F(self,char *,0x10)+0x234;
    func_003F2070();
    float x=F(p,float,0x494);
    float factor=F(p,float,0x488);
    if(F(p,u8,0x522)==1) {
        float target=1.0f;
        if(F(p,u8,0x520)) {
            v=F(p,float,0x4fc)/F(p,float,0x510);
            int flag=0;
            if(v>1.0f) v=1.0f;
            else {
                float low=F(q,float,0x40+F(q,u8,2)*4);
                if(v<low) v=low;
            }
            float speed;
            if(func_003F1F78(q)) {
                float n=F(q,unsigned short,0x30)*0x1.acee9cp-4f;
                float coeff=factor*0x1.999998p-2f+0x1.333332p-1f;
                n*=coeff;
                float high=F(p,float,0x510);
                target=1.0f;
                if(n<high) {
                    target=n/high;
                    float low=F(q,float,0x40+F(q,u8,2)*4);
                    if(target<low) target=low;
                    else if(target>1.0f) target=1.0f;
                }
                float a=D_006220FC;
                speed=a+factor*(D_006220F8-a);
            } else {
                if(F(p,u8,0x520)>=2) target=F(q,float,0x40+F(p,u8,0x520)*4);
                if(target<v) speed=D_00622104; else speed=D_00622108;
                if(F(p,signed char,0x466)==1 || F(p,u8,0x467)!=0 || F(p,u8,0x442)==0) flag=1;
            }
            if(target!=v) {
                speed*=dt;
                speed*=F(p,float,0x518);
                if(v<target) {
                    v+=speed;
                    if(target<=v) v=target;
                    else if(flag) F(p,u8,0x526)=1;
                } else {
                    v-=speed;
                    if(v<=target) v=target;
                    else if(flag) F(p,u8,0x526)=1;
                }
            }
        }
    }
    F(p,float,0x518)=v;
    return v*func_003554A0(self,x);
}
