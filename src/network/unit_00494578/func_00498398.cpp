/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Vec { float x,y,z; };
struct Quad { float a,b,c,d; };
extern "C" void *func_00496C28() throw();
extern "C" void func_00497F98(void *,void *,float,float,float,float) throw();
extern "C" void func_004A1638(int);
extern "C" void func_004A2808(int,float);
extern "C" void func_004A29A8(int);
extern "C" void func_004A53F8();
extern "C" void func_004A5400();
extern "C" void func_004A74B4(void *);
extern "C" void func_00498398(void *o,Vec *v,Quad *q,float n,float x,float y,float z,float s) {
 float m[16];
 func_004A53F8();
 if(s>0.0f) {
  func_004A29A8(0); func_004A1638(6); func_004A1638(5); func_004A2808(0x48,0.0f);
  float d=-v->z;
  if(d<0.0f) return;
  float t=(d-n)/d;
  m[0]=q->a; m[1]=q->b; m[2]=0; m[3]=0;
  m[4]=q->c; m[5]=q->d; m[6]=0; m[7]=0;
  m[8]=0; m[9]=0; m[10]=1; m[11]=0;
  m[12]=v->x*t; m[13]=v->y*t; m[14]=v->z*t; m[15]=1;
  func_004A74B4(m);
  func_00497F98(o,func_00496C28(),x,y,z,s);
  func_004A29A8(1);
 }
 func_004A5400();
}
