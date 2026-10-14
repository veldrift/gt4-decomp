struct State { unsigned long words[5]; };
struct Texture { char pad[0x18]; State *state; };
struct Obj { unsigned char b0,xf,yf,b3; short x,y,w,h; float alpha; void *a10,*vt; Texture *tex; float angle,old; };
extern char D_006A14C8[];
extern float D_006A14DC;
extern "C" {
void *func_003A1E10(const char *);
void func_003AEF18(Texture *,float,float,unsigned,unsigned);
int func_003AFD78(int,int,int);
void func_004A2808(int,float);
void func_004A2B10(float,float);
void func_004A2C58(int,int,float);
void func_004A53F8();
void func_004A5400();
void func_004A7844(float,float,float);
void func_004A7890(float,float,float);
void func_004A79D8(float);
void func_004AA1D8(float,float,float,float);
}
extern "C" void RaceSteeringDisplay__render_main(Obj *o) {
 if (!o->tex) o->tex=(Texture *)func_003A1E10(D_006A14C8);
 float old=o->old;
 float step;
 if (old!=D_006A14DC) step=(o->angle-old)*0.25f;
 else step=0.0f;
 int i=0;
 func_004A53F8();
 func_004A7844(func_003AFD78(o->x,0,o->xf),o->y,0.0f);
 func_004A2808(0x44,1.0f);
 func_004AA1D8(1.0f,1.0f,1.0f,o->alpha*0.4375f);
 func_004A53F8();
 short h=o->h;
 short w=o->w;
 unsigned long bits=o->tex->state->words[4];
 int tw=(int)(((bits>>14)&0x3ff)+1);
 int th=(int)(((bits>>34)&0x3ff)+1);
 func_004A7890(2.0f*((float)w/(float)tw),2.0f*((float)h/(float)th),1.0f);
 func_004A79D8(o->angle-step*4.0f);
 do {
  int n=i;
  i++;
  func_004A2C58(4,n,1.0f);
  func_003AEF18(o->tex,0.0f,-85.0f,2,0);
  func_004A79D8(step);
 } while(i<4);
 func_004A2B10(0.5f,0.5f);
 func_004A5400();
 func_004A5400();
}
