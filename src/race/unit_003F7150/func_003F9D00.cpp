/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned char u8;
#define F(p,o) (*(float *)((char *)(p)+(o)))
#define I(p,o) (*(unsigned *)((char *)(p)+(o)))
extern u8 D_00620CD8[];
extern "C" u8 *func_00359510(void *);
extern "C" float func_003596C0(void *, float);
extern "C" u8 *func_00360F80(void *, int, int);
extern "C" float func_003F1E40(void *) throw();
extern "C" float func_003F9C80(float,float,float) throw() __attribute__((const));
extern "C" int func_003F9CD0(void *) throw();
extern "C" void func_003F9CF0(void *) throw();
inline bool positive(u8 *info, int i, signed char *sign) { if(i >= info[1]) return false; return *sign > 0; }
inline bool negative(u8 *info, int i, signed char *sign) { if(i >= info[1]) return false; return *sign < 0; }
inline void smooth(float *x,float *v,float target) {
    *v += ((target-*x)*500.0f-*v*50.0f)*0x1.11111p-6f;
    *x += *v*0x1.11111p-6f;
}
extern "C" void func_003F9D00(u8 *self, u8 *arg) {
    u8 *s=self+0x104;
    u8 *data=*(u8 **)(self+0x10);
    s[0x5f9]=func_003F9CD0(arg);
    u8 *mode=data+0x234;
    if(!s[0x5f9]) return func_003F9CF0(s);
    float scale=1.0f;
    if(D_00620CD8[0x117]==0) scale=func_003F9C80(F(s,0x58c),F(arg,0x24),F(arg,0x28));
    if(F(s,0x4e8)<=0.0f) return;
    if(s[0x522]==0) return func_003F9CF0(s);
    if(F(s,0x494)>0.0f) {
        float minimum=1.0f;
        u8 *info=func_00359510(data);
        int i=0;
        float grip=1.0f;
        float factor=1.0f;
        {
            for(;i<info[1];i++) {
                signed char *sign=(signed char *)info+0x3c+i;
                u8 *w=self+0x164+i*0xec;
                switch(*mode) {
                case 0: case 5: case 6: case 7:
                    if(!negative(info,i,sign)) continue;
                    break;
                case 1:
                    if(!positive(info,i,sign)) continue;
                    break;
                }
                float contact=F(w,0x48);
                float slip=F(w,0x38);
                if(contact>0.0f && slip<minimum) {
                    minimum=slip;
                    u8 *item=func_00360F80(data,i,w[0x89]);
                    factor=F(w,0x3c);
                    grip=F(item,0x164);
                    if(D_00620CD8[0x117]==1) {
                        float g=func_003596C0(item+0x170,F(w,0x5c));
                        if(grip<g) grip=g;
                    }
                }
            }
        }
        if(D_00620CD8[0x117]==0) grip*=scale;
        grip*=F(arg,0x2c);
        if((I(s,0x464)&0xffff0000)==0x10000) grip*=func_003F1E40(self);
        float speed=F(s,0x53c);
        if(D_00620CD8[0x146]) {
            float lo=D_00620CD8[0x147]*0x1.638e36p+1f;
            if(lo<speed) {
                float hi=D_00620CD8[0x148]*0x1.638e36p+1f;
                float f=D_00620CD8[0x149]*0x1.47ae14p-7f+1.0f;
                if(speed<hi) f*=(speed-lo)/(hi-lo);
                grip*=f;
            }
        }
        float f=(minimum-grip)*(F(arg,0x20)*factor)+1.0f;
        if(f<0.0f) f=0.0f;
        else if(f>1.0f) f=1.0f;
        int fast=1;
        if(speed<0x1.bc71c4p+4f) fast=0;
        if(!fast) {
            if(f<1.0f) s[0x5f9]=2;
            F(s,0x494)*=f;
            return func_003F9CF0(s);
        }
        float *x=(float *)(s+0x644);
        float *v=(float *)(s+0x648);
        smooth(x,v,F(s,0x494)*f*0x1.199998p+0f);
        if(*x>F(s,0x494)) { *x=F(s,0x494); *v=0; }
        else if(*x<0.0f) { *x=0.0f; *v=0.0f; }
        if(*x<F(s,0x494)) { s[0x5f9]=2; F(s,0x494)=*x; }
    }
}
