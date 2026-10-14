/* compiler: ee-gcc2.96-no-strict-aliasing */
struct View { int words[15]; };
struct Global { View views[2]; int current; };
extern Global D_00618588;
extern "C" void func_00105728(void *);
extern "C" void func_001056A0(void *);
extern "C" void func_004A4550(int,int);
extern "C" void func_004AB040(int);
extern "C" int func_004A6E20(float);
extern "C" void func_004AA1D8(float,float,float,float);
extern "C" void func_004A6498(int,int,int,int,int,int,int,int);
static inline View *current(Global *g) { return &g->views[g->current]; }
extern "C" void func_00399DB0(void *o,void *p) {
 func_00105728(current(&D_00618588));
 func_001056A0(p);
 func_004A4550(3,0);
 func_004A4550(2,0);
 func_004AB040(4);
 func_004AB040(6);
 func_004AB040(5);
 func_004A6E20(0.0f);
 func_004AA1D8(1.0f,1.0f,1.0f,1.0f);
 func_004A6498(0,0,640,448,0,0,640,448);
}
