/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Buf { int w0, w4; char pad[56]; };
struct E { short delta, index; void (*fn)(void *, float); };
struct Obj { E *vt; };
extern char D_006A7D00[];
extern "C" {
void func_00105250(void *);
void func_00105280(void *,int);
void func_001053F8(void *,int);
void func_00105460(void *,int,int);
int func_00105528(void *);
void func_001056A0(void *);
void func_00105708(void *);
void func_00105728(void *);
int func_00105848(void *);
void func_0049CC38(int);
void func_0049CE40(int);
void func_0049CE68(int);
void func_0049D308(void *);
void func_004A1638(int);
void func_004A2980(int);
void func_004A29A8(int);
void func_004A3078(int);
void func_004A3230(int);
void func_004A4910();
void RaceEntryCar__update(int);
void func_004A53F8();
void func_004A5400();
void pglPushAttrib(int);
void func_004A5688();
void func_004A59B8(float,float,float,float,float,float,float);
void func_004A5A90(float,float,float,float,float,float);
void func_004A60E0(float,float,float,float);
void func_004A6100(float,float,float,float);
void func_004A7454();
void func_004A7988(float);
void func_004A79D8(float);
void func_004AB040(int);
}
extern "C" void func_0044EB10(void *a0, Obj *a1, void (*cb)(int), int a3, int a4, int a5, int a6) {
 if (cb) {
  pglPushAttrib(0x887);
  func_001056A0(a0);
  func_004A2980(-1); func_004A29A8(1); func_004A3078(0x80000000); func_004A3230(1);
  func_004A6100(0.0f,0.0f,0.0f,0.0f);
  func_004A60E0(1.0f,1.0f,1.0f,1.0f);
  Buf b0,b1;
  func_00105250(&b0); func_00105250(&b1);
  b0.w4=0; func_00105460(&b0,a4,a5);
  b1.w4=0x31; func_00105460(&b1,a4,a5);
  if (a6<0) { func_00105528(&b0); func_00105528(&b1); }
  else { func_001053F8(&b0,a6); func_001053F8(&b1,a6+func_00105848(&b0)); }
  int i=0;
  do {
   float f=(float)i;
   RaceEntryCar__update(1); i++; func_004A7454();
   func_004A59B8(-0.5f,0.5f,-0x1.81ef30p-1f,0x1.cf1f14p-1f,0x1.47ae14p-8f,200.0f,0x1.4779a6p-3f);
   RaceEntryCar__update(0); func_004A7454();
   func_004A7988(0x1.3fe668p+6f); func_004A79D8(f*-120.0f);
   func_001056A0(&b0); func_00105708(&b1);
   func_004A1638(5); func_004AB040(4); func_004A3230(3); func_004A53F8();
   E *e=(E *)((char *)a1->vt+0x18); e->fn((char *)a1+e->delta,0.0f);
   cb(a3); func_004A5400(); func_004A4910();
   func_001056A0(a0); func_00105728(&b0);
   RaceEntryCar__update(1); func_004A7454();
   func_004A5A90(-0x1.ccccccp-1f,0x1.ccccccp-1f,-0x1.ccccccp-1f,0x1.ccccccp-1f,-1.0f,1.0f);
   RaceEntryCar__update(0); func_004A7454();
   func_004A79D8(240.0f-f*120.0f);
   func_004AB040(5); func_004AB040(4); func_004AB040(3); func_004AB040(15);
   func_004A29A8(0); func_004A2980(0xffffff);
   func_0049CE68(0); func_0049CE40(0); func_0049CC38(0); func_0049D308(D_006A7D00);
   func_004A1638(17); func_004A29A8(1); func_004A2980(-1);
  } while(i<3);
  func_004A4910(); func_004A5688();
  func_00105280(&b1,2); func_00105280(&b0,2);
 }
}
