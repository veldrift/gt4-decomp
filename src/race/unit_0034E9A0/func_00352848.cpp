/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned char u8;
#define F(p,o) (*(float *)((char *)(p)+(o)))
extern "C" void func_00350D40(void *) throw();
extern "C" float func_003522B0(void *) throw();
extern "C" u8 *func_00359510(void *);
struct Item {float scale; float spare; float factors[1];};
extern "C" Item *func_00360F80(void *, int, int);
extern "C" int func_003F7C80(void);
extern "C" float func_00467470(void *, int);
extern "C" float func_0057D1F0(float);
extern "C" float func_0057D2B8(float) throw();
inline u8 getIndex(u8 *base, int index) { return *(u8 *)((unsigned)base + (unsigned)index); }
inline bool positive(u8 *info, int i, signed char *sign) { if(i >= info[1]) return false; return *sign > 0; }
inline bool negative(u8 *info, int i, signed char *sign) { if(i >= info[1]) return false; return *sign < 0; }
extern "C" void func_00352848(u8 *self, int reset) {
    u8 *s=self+0x104;
    u8 *data=*(u8 **)(self+0x10);
    u8 *info=func_00359510(data);
    float dt=F(self,0x54c);
    unsigned i;
    if(reset) {
        F(s,0x554)=0;
        F(s,0x58c)=0;
        for(i=0;i<info[1];i++) F(self+0x164+i*0xec,0xd4)=0;
    } else {
        float total=0;
        i=0;
        float torque=0;
        if(info[1]) {
            u8 *dims;
            u8 *indices;
            indices=info+0xc;
            signed char *signs=(signed char *)info+0x3c;
            dims=data+8;
            u8 *modes=info+0x1c;
            float *forces=(float *)(s+0x430);
            u8 *w=self+0x164;
            do {
                float old=F(w,0);
                if(func_003F7C80()==1) F(w,0)=F(w,0)+F(w,0x1c);
                else if(func_003F7C80()==2) F(w,0)=F(w,0x1c);
                float extra, load, x, z;
                extra=F(w,0x70)+F(w,0x74);
                load=F(w,0x68);
                if(w[0xdd]==1) {
                    x=-func_0057D1F0(F(w,0))*load;
                    z=-func_0057D2B8(F(w,0))*load;
                } else {
                    float angle=F(w,0x30);
                    float sn=func_0057D1F0(angle);
                    float cs=func_0057D2B8(angle);
                    x=-sn*load;
                    z=-cs*load;
                    x+=cs*F(w,0x6c);
                    z+=-sn*F(w,0x6c);
                }
                float force=*forces;
                float sn=-func_0057D1F0(F(w,0));
                float cs=-func_0057D2B8(F(w,0));
                x+=sn*force;
                z+=cs*force;
                float drag=func_003522B0(w);
                x-=func_0057D1F0(F(w,0))*drag;
                z-=func_0057D2B8(F(w,0))*drag;
                x-=func_0057D2B8(F(w,0))*extra;
                z+=func_0057D1F0(F(w,0))*extra;
                F(w,0xd4)=x;
                total+=x;
                int coordIndex=(int)i+0x20;
                float lateral=F(dims+modes[0x10]*4,0x20);
                int mode=*modes;
                if(mode==0) lateral=-lateral;
                else if((mode^1)!=0) lateral=0;
                float longitudinal=F(data+getIndex(indices,coordIndex)*4,0x10);
                float moment;
                if(positive(info,i,signs)) moment=longitudinal;
                else if(negative(info,i,signs)) moment=-longitudinal;
                else moment=0;
                F(w,0)=old;
                i++;
                signs++;
                modes++;
                forces++;
                w+=0xec;
                torque+=lateral*z-moment*x;
            } while(i<info[1]);
        }
        F(s,0x588)=torque*F(data,0x118);
        func_00350D40(s);
        F(s,0x57c)+=F(s,0x588)*dt;
        if(F(s,0x57c)>0x1.921fb4p+2f) F(s,0x57c)=0x1.921fb4p+2f;
        else if(F(s,0x57c)<-0x1.921fb4p+2f) F(s,0x57c)=-0x1.921fb4p+2f;
        float sum=0;
        total=total/F(s,0x4d4);
        float acceleration=total;
        F(s,0x554)=acceleration;
        for(i=0;i<info[1];i++) {
            int index=self[0x1ed+i*0xec];
            Item *item=func_00360F80(data,i,index);
            float factor=item->factors[index];
            sum+=factor*func_00467470(self,index)*item->scale;
        }
        F(s,0x58c)=acceleration*info[1]/sum;
    }
}
