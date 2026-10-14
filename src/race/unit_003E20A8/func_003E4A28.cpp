/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Obj { char pad[0x10]; float x,y,z; char pad1[0x44-0x1c]; unsigned char index,kind,a,b; };
struct Render;
struct Manager2 {char pad[0x80]; Render* render;};
struct Manager {char pad[4]; Manager2* p;};
extern Manager* D_006D6060;
extern int D_00621D0C,D_00621D10,D_00621D24;
extern "C" {
int func_003E20A8(int) throw() __attribute__((const));
bool func_003E4C20(Obj*);
void func_003E4930(Obj*,float*) throw();
void func_003E4968(Obj*,float*) throw();
void func_00398058(Render*,float,float);
float func_003983E0(Render*,float,float);
void func_003E53B8(int,int);
void func_0049AB58(float);
void func_004A29A8(int);
void RaceEntryCar__update(int);
void func_004A53F8();
void func_004A5400();
void func_004A60E0(float,float,float,float);
void func_004A7698(float*);
}
extern "C" void func_003E4A28(Obj* o) {
 float m[16],n[16];
 if(func_003E20A8(o->kind) && func_003E4C20(o)) {
 func_003E4930(o,m);
 m[12]=o->x;m[13]=o->y;m[14]=o->z;
 Render* r=D_006D6060->p->render;
 int a=o->a,b=o->b;
 float fa=(float)a*0x1.010100p-8f;
 float fb=(float)b*0x1.010100p-8f;
 
 if(D_00621D0C!=a || D_00621D10!=b) {
 func_00398058(r,fa,fb);D_00621D0C=o->a;D_00621D10=o->b;
 }
 if(D_00621D24) {
 func_003E4968(o,n);RaceEntryCar__update(1);func_004A53F8();func_0049AB58(0x1.47ae14p-8f);
 RaceEntryCar__update(0);func_004A53F8();func_004A7698(n);func_004A7698(m);func_004A29A8(0);
 func_004A60E0(1,1,1,func_003983E0(r,fa,fb));func_003E53B8(o->index,1);func_004A29A8(1);
 RaceEntryCar__update(1);func_004A5400();RaceEntryCar__update(0);func_004A5400();
 }
 func_004A53F8();func_004A7698(m);func_003E53B8(o->index,0);func_004A5400();
 }
}
