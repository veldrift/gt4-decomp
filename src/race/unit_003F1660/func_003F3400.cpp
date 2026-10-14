/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned char u8;
typedef unsigned short u16;
#define F(p,t,o) (*(t *)((char *)(p)+(o)))
extern "C" int func_00343D60(void *, float);
extern "C" void func_00348368(void *);
extern "C" int DynamicsConductor__GetCountDown(void *, int);
extern "C" int func_00368398(void *);
extern "C" void func_00463CD8(void *, int);
extern "C" void func_00464E40(void *);
extern "C" void func_00464F38(void *);
extern "C" void func_00465078(void *);
extern "C" void func_003F3400(char *self, char *arg) {
    char *p = self + 0x104;
    F(p,int,0x490)=0;
    F(p,u8,0x462)=0;
    F(p,u8,0x463)=0;
    switch(F(arg,u8,1)) {
    case 6: F(p,u8,0x465)=3; break;
    case 4: F(p,u8,0x465)=0; break;
    case 2: F(p,u8,0x465)=2; break;
    default: F(p,u8,0x465)=1; break;
    }
    if(F(p,u8,0x4bc)) func_00465078(self+0x14);
    if(func_00368398(F(self,char *,0x10)+0x234)) {
        func_00348368(p);
        if(F(p,float,0x514)==0.0f && F(p,u8,0x467)==8) {
            return func_00464E40(self+0x14);
        }
        if(!F(p,u8,0x4bc)) return func_00465078(self+0x14);
        return;
    }
    char *a = F(self,char *,0x10);
    if(F(a,u8,0x246)==4) {
        F(p,float,0x514)=1.0f;
        if(F(p,u8,0x4bc) || F(p,u16,0x4ba)) {
            float z=0.0f;
            func_00343D60(self,z);
            F(p,float,0x468)=z;
        } else {
            if(F(p,u8,0x467)==8) return func_00464E40(self+0x14);
            return func_00465078(self+0x14);
        }
    } else {
        if(F(p,u8,0x4bc)) {
            char *q=self+0x14;
            float z=0.0f;
            func_00463CD8(q,DynamicsConductor__GetCountDown(F(self,void *,4),F(p,u8,0x440)));
            func_00343D60(self,z);
            F(p,float,0x468)=z;
        } else if(F(p,u16,0x4ba)) {
            char *q=self+0x14;
            func_00464E40(q);
            return func_00464F38(q);
        } else if(F(p,u8,0x467)==8) {
            F(p,float,0x514)=0.0f;
            return func_00464E40(self+0x14);
        } else {
            if(!F(p,u8,0x522)) {
                F(p,float,0x514)=0.0f;
                if((F(a,u16,0x262)*3>>2)<F(p,short,0x4fa)) F(p,float,0x514)=1.0f;
            } else {
                F(p,float,0x514)=1.0f;
                if(F(p,short,0x4fa)<F(a,u16,0x202)) F(p,float,0x514)=0.0f;
            }
            func_00465078(self+0x14);
        }
    }
}
