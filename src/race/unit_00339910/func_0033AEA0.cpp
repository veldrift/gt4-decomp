/* compiler: ee-gcc2.96-no-strict-aliasing */
struct VEntry { short delta,index; float (*fn)(void*,float); };
struct Obj { VEntry *vt; };
extern "C" void func_004A53F8();
extern "C" void func_004A5400();
extern "C" void func_004A7454();
extern "C" void func_004A7550(void *);
extern "C" void func_004A7A54();
extern "C" float func_0057D008(float);
static inline const float &maximum(const float &a,const float &b) { return a<b?b:a; }
static inline float vcall(Obj *o,int i,float f) { VEntry *e=o->vt+i; return e->fn((char*)o+e->delta,f); }
struct PlainEntry {short delta,index; float (*fn)(void*);};
static inline float plain(Obj *o,int i) { PlainEntry *e=(PlainEntry*)o->vt+i;return e->fn((char*)o+e->delta); }
struct Out { float a[3],b[3],c[3];float d[8]; };
extern "C" void func_0033AEA0(Out *dst,Obj *o,float time) {
 float m[16];
 func_004A53F8(); func_004A7454();
 vcall(o,3,time);
 func_004A7A54(); func_004A7550(m);
 float *z=m+12,*y=m+8,*x=m+4;
 float scale=maximum(1.0f,vcall(o,10,time));
 for(int i=0;i<3;i++) {
  dst->a[i]=z[i];
  dst->b[i]=z[i]-y[i]*scale;
  dst->c[i]=x[i];
 }
 func_004A7454(); vcall(o,2,time); func_004A7550(m);
 dst->d[0]=func_0057D008(1.0f/m[0])*0x1.ca5dc2p+6f;
 dst->d[1]=m[0]/m[5];
 dst->d[2]=m[14]/(m[10]-1.0f);
 dst->d[3]=m[14]/(m[10]+1.0f);
 func_004A5400();
 dst->d[4]=plain(o,11); dst->d[5]=plain(o,12); dst->d[6]=plain(o,16);dst->d[7]=plain(o,17);
}
