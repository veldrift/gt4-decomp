/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Entry {short delta,index; int (*fn)(void*);};
struct Self {char pad[12];float alpha;int pad10;Entry *vt;float value,lo,hi;char pad24[12];float previous;signed char count;char pad35[19];float start,end,r0,r1;};
extern float D_006A2918;
extern "C" {
void func_0049FD50(int,int,int,int,int,int);
void func_004A1638(int);
void func_004A2808(int,float);
void func_004A2B10(float,float);
void func_004A2C58(int,int,float);
void func_004A53F8();void func_004A5400();
void func_004A7844(float,float,float);void func_004A7890(float,float,float);
void func_004A79D8(float);void func_004AA168(int);
}
static inline float maxf(float a,float b) {float r;__asm__("max.s %0, %1, %2":"=f"(r):"f"(a),"f"(b));return r;}
static inline float minf(float a,float b) {float r;__asm__("min.s %0, %1, %2":"=f"(r):"f"(a),"f"(b));return r;}
static inline int virtual12(Self *s) {Entry *e=s->vt+12;return e->fn((char*)s+e->delta);}
static inline int virtual13(Self *s) {Entry *e=s->vt+13;return e->fn((char*)s+e->delta);}
extern "C" void RaceRoundMeterBase__virtual_14(Self *s) {
 func_004AA168(0x800000c8);
 func_004A1638(6);
 func_004A2808(100,s->alpha*0x1.555554p-3f);
 float ratio=(s->value-s->lo)/(s->hi-s->lo);
 float next=ratio*(s->end-s->start)+s->start;
 next=maxf(next,s->start);
 next=minf(next,s->end+2.0f);
 float previous=s->previous==D_006A2918 ? next : s->previous;
 s->previous=next;
 float step=(next-previous)*(1.0f/(float)s->count);
 float span=s->r1-s->r0;
 int a=virtual12(s);
 int b=virtual13(s);
 for(int i=0;i<s->count;) {
  previous+=step;
  func_004A53F8();
  func_004A79D8(previous);
  func_004A7844(s->r0,0.0f,0.0f);
  func_004A7890(span,span,span);
  func_004A2C58(s->count,i,1.0f);
  i++;
  func_0049FD50(6,a,0,b,0,0);
  func_004A5400();
 }
 func_004A2B10(0.5f,0.5f);
 func_004A2808(0x44,1.0f);
}
