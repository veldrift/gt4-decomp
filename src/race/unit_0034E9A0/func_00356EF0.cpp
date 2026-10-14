/* compiler: ee-gcc2.96-no-strict-aliasing */
#define F(p,o) (*(float *)((char *)(p)+(o)))
#define B(p,o) (*(unsigned char *)((char *)(p)+(o)))
extern "C" void *func_00359510(void *);
extern "C" void *func_00360F80(void *, int, int);
extern "C" int TireWearParameters__isWearAvailable(void *);
extern "C" int TireWearParameters__isHeatAvailable(void *);
extern "C" int func_00356EF0(char *self, char *p) {
 char *sub=self+0x104;
 void *car=*(void **)(self+0x10);
 char *info=(char *)func_00359510(car);
 if (!TireWearParameters__isWearAvailable(p) && !TireWearParameters__isHeatAvailable(p)) return 0;
 if (B(sub,0x4b1)&0x10) return 0;
 int i;
 if (TireWearParameters__isWearAvailable(p)) {
  for(i=0;i<B(info,1);i++) {
   char *w=self+0x164+i*0xec;
   float x=F(w,0xac);
   if (x>=F(p,0x18)) {
    F(w,0xac)=F(p,0x18);
    F(w,0x50)=1.0f-F(p,0x1c);
    if (!TireWearParameters__isHeatAvailable(p)) B(w,0xb1)=127;
   } else if(x>=F(p,0x10)) {
    float t=(x-F(p,0x10))/(F(p,0x18)-F(p,0x10));
    F(w,0x50)=(1.0f-F(p,0x14))-t*(F(p,0x1c)-F(p,0x14));
    if(!TireWearParameters__isHeatAvailable(p)) {
     if(t>=1.0f) B(w,0xb1)=127;
     else B(w,0xb1)=(int)(t*0x1.ff3332p+5f)+64;
    }
   } else if(x>=F(p,8)) {
    float t=(x-F(p,8))/(F(p,0x10)-F(p,8));
    F(w,0x50)=(1.0f-F(p,0xc))-t*(F(p,0x14)-F(p,0xc));
    if(!TireWearParameters__isHeatAvailable(p)) {
     if(t>=1.0f) B(w,0xb1)=64;
     else B(w,0xb1)=(int)(t*0x1.fe6666p+4f)+32;
    }
   } else if(x>=0.0f) {
    float t=x/F(p,8);
    F(w,0x50)=1.0f-F(p,0xc)*t;
    if(!TireWearParameters__isHeatAvailable(p)) {
     if(t>=1.0f) B(w,0xb1)=32;
     else B(w,0xb1)=(int)(t*0x1.fe6666p+4f);
    }
   } else if(x>=F(p,0) && !TireWearParameters__isHeatAvailable(p)) {
    float t=F(w,0xac)/F(p,0);
    F(w,0x50)=1.0f-F(p,4)*t;
    if(t>=1.0f) B(w,0xb1)=-63;
    else B(w,0xb1)=-(int)(t*0x1.ff3332p+5f);
   } else {
    F(w,0x50)=1.0f;
    if(!TireWearParameters__isHeatAvailable(p)) B(w,0xb1)=-128;
   }
  }
 }
 if(TireWearParameters__isHeatAvailable(p)) {
  for(i=0;i<B(info,1);i++) {
   char *w=self+0x164+i*0xec;
   float x=F(w,0xa8);
   float grip=1.0f;
   int v;
   if(x>F(p,0x58)) {
    float t=(x-F(p,0x58))/(F(p,0x60)-F(p,0x58));
    if(t>1.0f) t=1.0f;
    grip=(1.0f-F(p,0x5c))-(F(p,0x64)-F(p,0x5c))*t;
    v=(int)(t*0x1.ff3332p+5f)+64;
   } else if(x>=0.0f) {
    float t=x/F(p,0x58);
    grip=1.0f-F(p,0x5c)*t;
    v=(int)(t*0x1.ff3332p+5f);
   } else if(x>=F(p,0x50)) {
    float t=x/F(p,0x50);
    grip=1.0f-F(p,0x54)*t;
    v=-(int)(t*0x1.ff3332p+5f);
   } else v=-128;
   B(w,0xb1)=v;
   if(TireWearParameters__isWearAvailable(p)) F(w,0x50)*=grip;
   else F(w,0x50)=grip;
  }
 }
 for(i=0;i<B(info,1);i++) {
  char *w=self+0x164+i*0xec;
  float minimum=F(func_00360F80(car,i,B(w,0x89)),0x68);
  if(F(w,0x50)<minimum) F(w,0x50)=minimum;
 }
 return 1;
}
