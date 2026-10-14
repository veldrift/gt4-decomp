/* compiler: ee-gcc2.96-no-strict-aliasing */
struct W { char pad[12]; unsigned short w,h; };
struct G { char pad[0x54]; float dx,dy; char pad5c[0x24]; int flag; };
extern G *PDISTD__global_font_manager;
extern int D_006D6180,D_006D6188,D_006D618C,D_006D6190;
extern float D_0062498C,D_00624990;
extern char D_0088FED0[];
extern "C" int func_00491CB8(W *,int);
extern "C" void *func_00490618(G *);
extern "C" void func_004A4DE0(int,int,int,int,int,int,int,void *);
extern "C" void func_00499B60(int,int,int,int,int,int,int);
extern "C" void func_004A4B40(int,int);
extern "C" void func_004A4930(int);
extern "C" void func_0049CC48(void *);
extern "C" void func_004A4810(int,int,int);
extern "C" void func_0049FE28();
extern "C" void func_00499C38(int);
extern "C" void func_00499948(float,float,float,float,float,float,float,float);
extern "C" void func_004A6668(float,float,float,float,float,float,float,float);
extern "C" void func_00492198(W *w,int code,float x,float y,float r,float b) {
 int texture=func_00491CB8(w,code);
 if(D_006D618C!=2) {
  if(D_006D6188==0) {
   void *p=func_00490618(PDISTD__global_font_manager);
   func_004A4DE0(D_006D6180,0,8,0,0,8,2,p);
   func_00499B60(D_006D6190,20,64,0,0,w->w,w->h);
  }
  func_004A4B40(D_006D6180,0);
  func_004A4930(3);
  func_0049CC48(D_0088FED0);
  func_004A4810(0,0,w->w-1);
  func_004A4810(1,0,w->h-1);
  func_0049FE28();
  D_006D618C=2;
 }
 if(D_006D6188!=texture) {
  D_006D6188=texture;
  func_00499C38(texture);
 }
 G *g=PDISTD__global_font_manager;
 if(g->flag) return func_00499948(x,y,r,b,0.0f,0.0f,(float)w->w,(float)w->h);
 func_004A6668((x+g->dx)*D_0062498C,(y+g->dy)*D_00624990,(r+g->dx)*D_0062498C,(b+g->dy)*D_00624990,0.0f,0.0f,(float)w->w,(float)w->h);
}
