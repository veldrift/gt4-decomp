/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Vec { float x,y,z; };
extern "C" void *func_0034C190(void *, int);
extern "C" unsigned char *func_00359538(void *);
extern "C" float func_00344858(void *,float);
extern "C" float func_003448B8(void *,float);
extern "C" float func_00344888(void *,float);
extern "C" float func_00344798(void *,float);
extern "C" float func_003447F8(void *,float);
extern "C" float func_00344828(void *,float);
extern "C" float func_00344C88(void *,int);
extern "C" void func_0046BEC0(void *,int,void *,void *,void *);
extern "C" void func_0048BE88(void *,float,float,float);
extern "C" void func_0048AF20(void *,float);
extern "C" void func_0048A3B8(void *,void *,void *);
static inline void set(float *x,float *y,float *z,float a,float b,float c) { *x=a; *y=b; *z=c; }
static inline void sum(Vec *out,float a,float b,float c,Vec *base) { out->x=a+base->x; out->y=b+base->y; out->z=c+base->z; }
static inline void add(float *x,float *y,float *z,float a,float b,float c) { *x+=a; *y+=b; *z+=c; }
extern "C" int func_003CB2C0(Vec *out,Vec *input,Vec *offset,Vec *points,Vec *base,void *ctx,int id,int mode,int direction,float angle) {
    float q[4]; Vec result; Vec local; int extra[4]; Vec pos; Vec rot0; Vec rot1;
    int i1=1,i2=2,i3=3;
    void *car=func_0034C190(ctx,id);
    float *x=&local.x,*y=&local.y,*z=&local.z;
    set(x,y,z,input->x,input->y,input->z);
    int index=0;
    switch (*func_00359538(car)) {
    case 2: i1=0; i2=1; i3=2; break;
    case 3: i3=2; break;
    case 1: i1=0; i2=1; i3=1; break;
    }
    int kind;
    switch(mode) {
    case 0: if(!direction) add(x,y,z,0,0,0); kind=0; break;
    case 2: index=0; if(!direction) add(x,y,z,points[0].x,points[0].y,points[0].z); kind=1; break;
    case 3: index=i1; if(!direction) add(x,y,z,points[i1].x,points[i1].y,points[i1].z); kind=1; break;
    case 4: index=i2; if(!direction) add(x,y,z,points[i2].x,points[i2].y,points[i2].z); kind=1; break;
    case 5: index=i3; if(!direction) add(x,y,z,points[i3].x,points[i3].y,points[i3].z); kind=1; break;
    case 6: if(!direction) { add(x,y,z,offset->x,offset->y,offset->z); if (*y>=1.625f) *y=1.625f; } kind=0; break;
    case 1: if(!direction) add(x,y,z,0,0,0); kind=2; break;
    case 7: if(!direction) add(x,y,z,0,0,0); kind=3; break;
    default: return 0;
    }
    switch(kind) {
    case 0: {
        float a=func_00344858(car,0.0f);
        float b=func_003448B8(car,0.0f);
        float c=func_00344888(car,0.0f);
        func_0048BE88(q,a,b,-c);
        float *rx=&result.x;
        func_0048A3B8(q,rx,&local);
        if(!direction) {
            out->x=*rx+func_00344798(car,0.0f);
            out->y=result.y+func_003447F8(car,0.0f);
            out->z=result.z+func_00344828(car,0.0f);
        } else set(&out->x,&out->y,&out->z,*rx,result.y,result.z);
        break;
    }
    case 2: {
        func_0046BEC0((char *)ctx+0xDA50,id,&pos,&rot0,extra);
        func_0048AF20(q,rot0.z);
        float *rx=&result.x;
        func_0048A3B8(q,rx,&local);
        if(!direction) set(&out->x,&out->y,&out->z,*rx+pos.x,result.y+pos.z,result.z-pos.y);
        else set(&out->x,&out->y,&out->z,*rx,result.y,result.z);
        break;
    }
    case 1: case 3: {
        func_0046BEC0((char *)ctx+0xDA50,id,&pos,&rot1,extra);
        func_0048AF20(q,angle);
        float *rx=&result.x;
        func_0048A3B8(q,rx,&local);
        if(direction) set(&out->x,&out->y,&out->z,*rx,result.y,result.z);
        else if(kind==1) {
            out->x=*rx+base->x;
            out->y=result.y+pos.z+func_00344C88(car,index);
            out->z=result.z+base->z;
        } else {
            sum(out,*rx,result.y,result.z,base);
        }
        break;
    }
    default: return 0;
    }
    if(direction) {
        float a=out->x,b=out->y,c=out->z;
        float len=a*a+b*b+c*c;
        if(len<0x1.a36e2cp-14f) return 0;
        float inv;
        __asm__("rsqrt.s %0, %1, %2" : "=f"(inv) : "f"(1.0f),"f"(len));
        out->x=a*inv; out->y=b*inv; out->z=c*inv;
    }
    return 1;
}
