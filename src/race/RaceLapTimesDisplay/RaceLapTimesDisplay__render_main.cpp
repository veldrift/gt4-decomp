/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Self { unsigned char p0,fx,fy,p3; short x,y,w,h; float alpha; char p10[8]; int laps,count,rows; int times[8]; float spacing; };
struct Font { int p0,flags; char p8[32]; float scale; };
extern Font D_00623838;
extern char D_006A1460[],D_006A1468[];
extern "C" {
float RaceDisplayUtil__wideOffset(int);
unsigned func_003AFEC8(unsigned,float);
void RaceDisplayUtil__timeToString(char *,int);
void func_0044D920(void *,void *);
void func_0044D988(void *);
float func_0044DC30(void *);
void func_0044DDF8(void *,float,float,float);
void func_0044DE80(void *,unsigned);
float func_0044DFC8(void *,void *);
void func_0044E030(void *,void *);
void func_0044E088(void *,const char *,int);
int func_0044E3F8(void *);
}
static inline float maxf(float a,float b) { float r; __asm__("max.s %0,%1,%2":"=f"(r):"f"(a),"f"(b)); return r; }
extern "C" void RaceLapTimesDisplay__render_main(Self *s) {
 D_00623838.flags=2;
 float width=90.0f;
 func_0044DE80(&D_00623838,func_003AFEC8(0x80c8c8c8,s->alpha));
 func_0044D920(&D_00623838,D_006A1460);
 float spacing=(float)func_0044E3F8(&D_00623838)*s->spacing;
 int start=s->count-s->rows; if(start<0) start=0;
 float scale=1.0f/func_0044DC30(&D_00623838);
 float y=(float)s->x;
 float x=y+RaceDisplayUtil__wideOffset(s->fx);
 y=(float)s->y;
 char buf[16];
 for (int i=start;i<start+s->rows;i++) {
  int t=-1; if(i<s->count) t=s->times[i];
  RaceDisplayUtil__timeToString(buf,t);
  float w=func_0044DFC8(&D_00623838,buf);
  width=maxf(width,w);
  if(i<s->count) {
   func_0044DDF8(&D_00623838,x-w*scale,y,0.0f);
   func_0044E030(&D_00623838,buf);
   y+=spacing;
  }
 }
 func_0044DE80(&D_00623838,func_003AFEC8(0x80b3b3b3,s->alpha));
 func_0044D920(&D_00623838,D_006A1460);
 int start2=s->laps-s->rows; if(start2<=0) start2=0;
 y=(float)s->y;
 width=(width+10.0f)*D_00623838.scale;
 x-=width;
 for(int i=start2;i<start2+s->rows;i++) {
  if(i<s->laps) {
   func_0044DDF8(&D_00623838,x,y,0.0f);
   func_0044E088(&D_00623838,D_006A1468,i+1);
   y+=spacing;
  }
 }
 D_00623838.flags=0;
 func_0044D988(&D_00623838);
}
