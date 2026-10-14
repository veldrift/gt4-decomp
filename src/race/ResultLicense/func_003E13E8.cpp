/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Buf { int a,b,w,h,x,y,dx,dy; char pad20[8]; int tex; char pad[0x10]; };
struct Globals { Buf views[2]; int cur; char pad[0x7c]; Buf other; };
extern Globals D_0061850C,D_00618588;
extern "C" {
void func_00105280(void *,int); int func_001052E0(void *,int,int,int);
void func_001054A0(void *,int);
void func_00105250(void *); void *func_00105378(void *,void *); int GSBuffer__getBufferWidth(void *); void func_00105670(void *); void func_001056A0(void *);
void func_00105708(void *); void func_00105728(void *); int func_00105918(void *);
void func_003E1780(void *); int func_003E1880(void *); void func_003E1A80(void *,float);
void func_0049AC00(float,float,float,float); void func_004A1638(int); void func_004A26F0(int);
void func_004A2980(int); void func_004A29A8(int); void func_004A2A10(int); void func_004A2B10(float,float);
void func_004A2C58(int,int,float); void func_004A3088(float); void func_004A3998(int,float);
void func_004A4550(int,int); void RaceEntryCar__update(int); void func_004A53F8(); void func_004A5400();
void func_004A6788(float,float,float,float,float,float,float,float); int func_004A6E20(float);
void func_004A7454(); void func_004A7844(float,float,float); void func_004A7988(float); void func_004A79B0(float);
void func_004A79D8(float); void func_004AA168(int); void func_004AA1D8(float,float,float,float); void func_004AB040(int);
}
static inline float fixAspect(float aspect, int wide) { if(wide) return aspect * 0x1.555554p+0f; return aspect; }
#define F(off) (*(float *)(self+(off)))
extern "C" void func_003E13E8(char *self,Buf *arg) {
 Buf a,b;
 Globals *g=&D_0061850C;
 int width=GSBuffer__getBufferWidth(&g->views[g->cur]);
 int height=((Buf *)g)[g->cur].h;
 func_001052E0(&a,0,width,height); func_001056A0(&a);
 Buf *pb=&b;
 func_00105250(pb); func_00105378(pb,&g->other); b.b=0x3a; func_00105708(pb);
 func_004A29A8(1); func_004A2980(-1); func_004A3088(1.0f); func_004AB040(4); func_004AB040(3);
 RaceEntryCar__update(1); func_004A53F8(); func_004A7454();
 float aspect=(float)width/(float)height;
 aspect = fixAspect(aspect, *(int *)((char *)g-0x1c));
 float zero=0.0f;
 func_0049AC00(50.0f,aspect,0.1f,100.0f);
 RaceEntryCar__update(0); func_003E1780(self); func_004A53F8(); func_003E1A80(self,F(0x580)); func_004A7454();
 func_004A7844(F(0x584),F(0x594),F(0x5a4)); func_004A79B0(F(0x5c4)); func_004A7988(F(0x5b4)); func_004A79D8(F(0x5d4));
 func_001056A0(&a); func_00105728(arg); func_004AB040(6); func_004A1638(5); func_004A26F0(1);
 func_004A6E20(100.0f); func_004A4550(3,0); func_004A4550(2,0); float white=1.0f; func_004AA1D8(white,white,white,white);
 float w=(float)a.dx;
 float h=(float)func_00105918(&a);
 int x=arg->x; int dx=arg->dx; int dy=arg->dy; int y=arg->y;
 func_004A6788(zero,zero,w,h,(float)x,(float)y,(float)(x+dx),(float)(y+dy));
 func_004A26F0(3); func_004A2A10(D_00618588.views[D_00618588.cur].tex); func_003E1880(self); func_004A5400();
 RaceEntryCar__update(1); func_004A5400(); RaceEntryCar__update(0); func_004AB040(5); func_004A1638(6);
 func_004A2980(0xffffff); func_004A29A8(0); func_004A4550(2,1); func_004A4550(3,1); func_004AA168(0x80ffffff);
 func_001056A0(arg); func_00105670(&a); func_004A2A10(0);
 if(arg->b==2 || arg->b==10) func_004A1638(7);
 func_004A3998(5,F(0x614)); func_004AB040(7); func_00105280(pb,2); func_00105280(&a,2);
}
