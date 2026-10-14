/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Drive {
char pad0[0x440];
unsigned char index;
char pad441[0x20];
unsigned char reverse;
char pad462[0x4];
signed char mode;
unsigned char state;
char pad468[0x49];
unsigned char flags;
unsigned char blocked;
char pad4b3[0x4];
signed char pit;
unsigned short service;
unsigned short timer;
char pad4bc[0x80];
float vx;
float vy;
char pad544[0x24];
float x;
float y;
float z;
char pad574[0x4f];
unsigned char warn;
char pad5c4[0x6a];
unsigned char pending;
char pad62f[0x1d];
short wait;
 bool isModeOne() {return mode==1;}
};
struct Car {char p[4]; char* owner; char q[0xfc]; Drive drive;};
extern "C" int func_00343C20(Car*);
extern "C" void func_00343D78(Car*,int);
extern "C" int func_00345228(Car*);
extern "C" int func_003453A0(Car*);
extern "C" void func_00345400(Car*);
extern "C" int func_00345450(Car*);
extern "C" float DynamicsConductor__GetCourseLength(char*);
extern "C" int func_0034C750(char*);
extern "C" float func_0034C780(char*,int);
extern "C" float func_0034C7A0(char*,int);
extern "C" float func_0034C7C0(char*,int);
extern "C" void func_00354D60(Car*,float) throw();
extern "C" void func_0035ACD8(Car*,int) throw();
extern "C" void func_0035AD10(char*,int) throw();
extern "C" void func_0035ADF0(char*,int) throw();
extern "C" int func_0035AF18(Car*) throw();
extern "C" int func_00363560(Car*);
extern "C" void func_0036C9F8(void*,void*,void*,float,float,float);
extern "C" int func_0045CC08(char*);
extern "C" int func_0045CC30(char*);
extern "C" void func_00463E80(void*);
extern "C" void func_0035B060(Car*car,float pos,float old) {
 Drive*d=&car->drive;
 char*owner=car->owner;
 d->warn=0;
 if(!func_0034C750(owner))return;
 float length=DynamicsConductor__GetCourseLength(owner);
 if(pos<length*0.5f)pos+=length;
 if(old<length*0.5f)old+=length;
 if(d->timer)func_0035ACD8(car,11);
 if(!d->timer && (unsigned char)(d->flags&1)) {
  if((unsigned)((unsigned char)d->mode-1)>=2U && !d->state && (d->flags&16) && func_0034C780(owner,3)<pos && pos<func_0034C780(owner,-2)) {
   if(d->vx>11.11111f)d->warn=2;
   else if(d->vx>2.7777774333953857421875f)d->warn=1;
   float gate=func_0034C780(owner,-3);
   if(gate<old && pos<=gate) {
    func_00345450(car);
    return func_0035ACD8(car,12);
   } else if(d->vx>1.38888871669769287109375f || d->vx < -1.38888871669769287109375f || d->vy>1.38888871669769287109375f || d->vy < -1.38888871669769287109375f) {
    if(!func_0045CC08(car->owner+d->index*0x4f0+0xda78))return func_0035ACD8(car,2);
   }
  }
 } else {
  unsigned service=d->service;
  int mode=func_00343C20(car);
  if(mode==2)mode=0;
  switch(d->state) {
   case 2: {
    float gate=func_0034C780(owner,1);
    if(gate<=pos && gate<length && !(d->flags&16)) {
     func_00345228(car);func_0035ACD8(car,0);
     d->service=0;d->flags&=0xf7;
     if(d->pending==2)d->pending=1;
    } else {
     if(old<gate && gate<=pos) {func_0035AD10(owner,d->index);d->service=func_0035AF18(car);}
     gate=func_0034C7A0(owner,d->pit)-25.0f;
     if(old<gate && gate<=pos) {
      if(mode) {func_00345450(car);return func_0035ACD8(car,8);}
      else if(!service) {func_00345450(car);return func_0035ACD8(car,9);}
      else if(!(d->vx>=27.777775f))return func_00345400(car);
      else {func_00345450(car);return func_0035ACD8(car,7);}
     } else if(func_0034C780(owner,2)<=pos)return func_0035ACD8(car,10);
    }
    break;
   }
   case 3: {
    if(d->timer==0) {
      float gate=func_0034C7A0(owner,d->pit);
      if(service && old<gate && gate<=pos) {
       func_00363560(car);d->timer=0x2d1;
       if(d->isModeOne()) {
        if(d->wait==-1)d->wait=0;
        else d->wait=300;
       } else d->wait=0;
      } else if(gate+0.5f<=pos)func_00345450(car);
     } else if(d->timer==0x2d0) {
      d->wait=0;
      d->z=func_0034C7C0(car->owner,d->pit);
      func_0036C9F8((char*)d+0xc,(char*)d+0x18,(char*)d+0x24,d->x,d->y,d->z);
      func_0035ACD8(car,11);
     } else if(d->timer==1) {d->service=0;d->flags&=0xfb;}
    if(d->service&0x100) {
     if(d->timer==0x285)d->service|=0x20;
     else if((unsigned short)(d->timer-1)<0x22a)return func_00354D60(car,0.0f);
    }
    break;
   }
   case 4: {
    if(func_0034C780(owner,1)<=pos && pos<length && !(d->flags&16)) {
     func_00345228(car);func_0035ACD8(car,0);
     if(d->pending==2)d->pending=1;
    }
    float gate,other;
    if(d->mode!=0 || d->blocked) {gate=func_0034C780(owner,-1);other=func_0034C780(owner,-2);}
    else {gate=func_0034C780(owner,-2);other=func_0034C780(owner,-3);}
    if(length+length*0.5f<=gate)gate-=length;
    if(old<gate && gate<=pos) {
     if(!d->blocked) {func_00345228(car);if(!mode)func_0035ADF0(owner,d->index);}
     else func_00343D78(car,3);
     d->flags&=0xf7;
     if(d->pending==2)d->pending=0;
    } else if(other<=pos) {
     if(!mode && (d->mode==0 || d->mode==3)) {
      if(d->reverse)return func_0035ACD8(car,5);
      return func_0035ACD8(car,4);
     }
    } else if(!d->blocked)return func_0035ACD8(car,10);
    break;
   }
   default:
    if(d->mode==0 && d->state!=1) {
     float gate;
     if(d->pending && (gate=func_0034C780(owner,0),old<gate && gate<=pos)) {
      func_003453A0(car);
      if(d->pending==0 && d->vx>0.0f)func_0035AD10(owner,d->index);
      d->service=func_0035AF18(car);
      if(d->pending)d->pending=2;
     } else if(d->flags&16) {
      gate=func_0034C780(owner,1);
      if(old<gate && gate<=pos) {
       if(d->vx<0.0f)func_00345450(car);
       else {func_003453A0(car);func_0035AD10(owner,d->index);d->service=func_0035AF18(car);}
       if(d->pending)d->pending=2;
      } else {
       gate=func_0034C780(owner,2);
       if(old<gate && gate<=pos) {func_00345450(car);d->service=0;return func_0035ACD8(car,9);}
      }
     }
    } else {
     if((d->flags&16) && func_0045CC30(car->owner+d->index*0x4f0+0xda78) && pos<length) {
      func_003453A0(car);return func_00463E80((char*)car+0x14);
     }
     if((d->flags&8) && mode==0) {
      float gate=func_0034C780(owner,0);
      if(old<gate && gate<=pos)return (void)func_003453A0(car);
     }
    }
    break;
  }
 }
}
