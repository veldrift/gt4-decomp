/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned char u8;
#define F(p,o) (*(float *)((char *)(p)+(o)))
#define P(p,o) (*(char **)((char *)(p)+(o)))
#define B(p,o) (*(u8 *)((char *)(p)+(o)))
struct Body {char pad[0x2d0]; float scale[2];};
struct Car {char pad0[4]; Body body; char pad1[0x1088-4-sizeof(Body)]; float base[2]; float slope[2];};
struct Info {u8 pad0; u8 n; char pad1[0x12]; u8 wheel[8];};
static inline int wheel(char *info, int i) {if(i<B(info,1)) return ((Info *)info)->wheel[i]; return 0;}
extern "C" char *func_00359510(char *);
extern "C" char *func_00360F80(char *,int,int);
extern "C" int TireWearParameters__isWearAvailable(char *);
extern "C" int TireWearParameters__isHeatAvailable(char *);
static inline float root(float x) {float r; __asm__("sqrt.s %0,%1":"=&f"(r):"f"(x));return r;}
extern "C" void func_00352EA0(char *self) {
 char *s=self+0x104;
 char *car=P(self,0x10);
 char *info=func_00359510(car);
 float dt=F(self,0x54c);
 char *p=P(self,4)+4;
 int i;
 if(B(P(self,0x10),0x32)==4) return;
 if(TireWearParameters__isHeatAvailable(p)) {
  for(i=0;i<B(info,1);i++) {
   char *w=self+0x164+i*0xec;
   bool primary=B(w,0x89)==0;
   int j=0;
   if(i<B(info,1)) j=B(info,0x14+i);
   float a=F(w,0x70)*F(p,0x34)+F(w,0x74)*F(p,0x38);
   float b=F(w,0x68)*F(p,0x3c);
   float scale=F(p,0x4c)/((Car *)car)->body.scale[j];
   float heat;
   __asm__("sqrt.s %0,%1":"=f"(heat):"f"(b*b+a*a));
   heat*=scale;
   if(primary) heat+=F(w,0xb4)*F(p,0x40);
   float temp=F(w,0xa8);
   float cool=F(p,0x48);
   float low=F(p,0x50);
   heat-=((F(p,0x44)-cool)*(temp-low)/(F(p,0x60)-low))+cool;
   float next=temp+heat*dt*F(p,0x30);
   F(w,0xa8)=next;
   if(next<F(p,0x50)) F(w,0xa8)=F(p,0x50);
   else if(next>F(p,0x60)) F(w,0xa8)=F(p,0x60);
  }
 }
 if(!TireWearParameters__isWearAvailable(p)) return;
 for(i=0;i<B(info,1);i++) B(self,0x214+i*0xec)=0;
 if(B(s,0x4b1)&0x10) return;
 for(i=0;i<B(info,1);i++) {
  int j=0;
  if(i<B(info,1)) j=((Info *)info)->wheel[i];
  char *w=self+0x164+i*0xec;
  int mode=B(w,0x89);
  if(mode!=1) {
   float wear=F(w,0x48);
   if(wear!=0.0f) {
    wear=((Car *)car)->base[j]+wear*((Car *)car)->slope[j];
    if(wear<0.0f) wear=0.0f;
    char *tire=func_00360F80(car,i,mode);
    float rate=F(w,0xb4);
    float boost=F(p,0x28);
    if(boost>0.0f && (B(w,0x46)&12)) {
     float slip=F(w,0x38);
     float limit=F(p,0x2c);
     if(slip<=limit) rate*=boost+1.0f;
     else if(slip<0.0f) rate*=(boost+1.0f)*slip/limit;
    }
    if(F(p,0x24)<rate) rate=F(p,0x24);
    rate*=F(tire,4);
    F(w,0xac)+=rate*wear*dt;
    rate*=255.0f;
    if(rate>255.0f) rate=255.0f;
    B(w,0xb0)=(int)rate;
   }
  }
 }
}
