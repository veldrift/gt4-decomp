/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Vec { float x,y,z,w; };
struct Rec { Vec a; Vec b; float f, g; };
struct Self { char pad[0x140]; Rec arr[6]; char p[4]; int count; };
struct VE { short delta; short pad; void (*fn)(void *,float); };
struct Obj { VE *vt; };
extern "C" void func_00105670(void *);
extern "C" void func_001056A0(void *);
extern "C" void func_0038F408(void *,void *,float) throw();
extern "C" void func_0049BBB0(int,int,int,int,int);
extern "C" int func_0049BBF0();
extern "C" void func_0049FE28();
extern "C" void func_004A1638(int);
extern "C" void func_004A2808(int,float);
extern "C" void func_004A2980(int);
extern "C" void func_004A3998(int,float);
extern "C" void func_004A4910();
extern "C" void RaceEntryCar__update(int);
extern "C" void func_004A53F8();
extern "C" void func_004A5400();
extern "C" void pglPushAttrib(int);
extern "C" void func_004A5688();
extern "C" void func_004A5A90(float,float,float,float,float,float);
extern "C" void func_004A7454();
extern "C" void func_004A7890(float,float,float);
extern "C" void func_004A7AA8(void *,void *);
extern "C" void func_004AB040(int);
extern "C" void func_0038F5D0(Self *self,void *arg1,void *arg2,Obj *obj) {
    Vec tmp[6];
    int i=0;
    pglPushAttrib(0x8c7);
    RaceEntryCar__update(1); func_004A53F8(); func_004A7454();
    func_004A5A90(-0.9f,0.9f,-0.9f,0.9f,-1.0f,1.0f);
    RaceEntryCar__update(0); func_004A53F8(); func_004A7454();
    func_004A7890(-1.0f,1.0f,-1.0f);
    VE *e=obj->vt+3;
    e->fn((char *)obj+e->delta,0.0f);
    func_00105670(arg2); func_001056A0(arg1);
    func_004A3998(4,1.0f);func_0049FE28();func_004A2980(0xffffff);
    func_004AB040(5);func_004AB040(4);func_004AB040(8);func_004AB040(2);
    func_004A1638(6);func_004A2808(0x44,0.0f);func_004AB040(15);func_004A1638(17);
    if(i<self->count) {
    float *val=&self->arr[0].g;
    Vec *src=&self->arr[0].a;
    Vec *out=tmp;
    for (;i<self->count;i++,val=(float *)((char *)val+40),src=(Vec *)((char *)src+40),out++) {
        func_004A7AA8(out,src);
        float x=out->x,y=out->y,z=out->z;
        float d=x*x+y*y+z*z;
        float v=*val;
        float inv;
        __asm__("rsqrt.s %0, %1, %2" : "=f"(inv) : "f"(1.0f),"f"(d));
        out->x=x*inv;out->y=y*inv;out->z=z*inv;
        out->w=v*inv;
    }
    }
    i=0;
    func_004A7454();func_0049BBB0(4,0x32,0x31,0x27,0x32);
    if(i<self->count) {
    float *val=&self->arr[0].f;Vec *src=&self->arr[0].b;Vec *out=tmp;
    for(;i<self->count;i++,out++,src=(Vec *)((char *)src+40),val=(float *)((char *)val+40))
        func_0038F408(out,src,*val);
    }
    func_0049BBF0();func_004A2980(-1);func_004AB040(6);func_004A1638(15);
    RaceEntryCar__update(1);func_004A5400();RaceEntryCar__update(0);func_004A5400();
    func_004A5688();func_0049FE28();func_004A4910();
}
