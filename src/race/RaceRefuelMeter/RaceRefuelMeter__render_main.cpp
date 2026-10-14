struct Obj { unsigned char b0,xflag,yflag,b3; short x,y; int z; float alpha; void *tex; void *vt; void *bar,*mark; float amount,capacity; };
struct Text { int a,align; };
extern Text D_00623838;
extern char D_006A1460[],D_006A1488[];
extern "C" {
void func_003A5C68(Obj *);
void func_003AF108(void *,int,int,float,float,float,float);
void func_003AF4F8(void *,float,float,float,float,int,int);
float func_003AFD18(int,float,float);
unsigned int func_003AFEC8(unsigned int,float);
void func_004AA168(unsigned int);
void func_004AA1D8(float,float,float,float);
void func_0044D920(Text *,const char *);
void func_0044D988(Text *);
void func_0044DDF8(Text *,float,float,float);
void func_0044DE80(Text *,unsigned int);
void func_0044E088(Text *,const char *,...);
}
static inline float maxf(float a,float b) { float r; __asm__("max.s %0, %1, %2":"=f"(r):"f"(a),"f"(b)); return r; }
static inline float minf(float a,float b) { float r; __asm__("min.s %0, %1, %2":"=f"(r):"f"(a),"f"(b)); return r; }
extern "C" void RaceRefuelMeter__render_main(Obj *o) {
 if (!o->tex) func_003A5C68(o);
 Text *t=&D_00623838;
 func_004AA1D8(1.0f,1.0f,1.0f,o->alpha);
 func_003AF108(o->tex,o->xflag,o->yflag,o->x,o->y,256.0f,26.0f);
 func_004AA168(func_003AFEC8(0x805ea8f2,o->alpha));
 float x=func_003AFD18(o->xflag,o->x,256.0f)+15.0f;
 float y=func_003AFD18(o->yflag,o->y,26.0f);
 float w=minf(maxf(o->amount/o->capacity,0.0f),1.0f)*155.0f;
 func_003AF4F8(o->bar,x,y,x+w,y+26.0f,0,0);
 func_004AA1D8(1.0f,1.0f,1.0f,o->alpha);
 float x2=func_003AFD18(o->xflag,o->x,256.0f)+14.0f;
 float y2=func_003AFD18(o->yflag,o->y,26.0f)+7.0f;
 float bottom=y2+12.0f;
 func_003AF4F8(o->mark,x2,y2,x2+157.0f,bottom,0,0);
 func_0044D920(t,D_006A1460);
 func_0044DE80(t,func_003AFEC8(0x805ea8f2,o->alpha));
 t->align=2;
 func_0044DDF8(t,x2+227.0f,bottom-1.0f,0.0f);
 func_0044E088(t,D_006A1488,(int)(o->amount+0.5f),(int)(o->capacity+0.5f));
 t->align=0;
 func_0044D988(t);
}
