/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned char u8; typedef signed char s8; typedef unsigned short u16; typedef short s16;
struct State {u8 type,n,count; char p[0x65]; float ratios[16];};
struct Owner {char p[0x200];u16 rpm;char q[0x32];State state;};
struct Data {char p[0x462];s8 b462,b463;char q[0x24];float f488,f48c;char r[4];float f494;char s[0x62];s16 rpm;char t[0x24];u8 gear,b521,mode,b523,b524,b525,delay,bias;char u[2];u16 timer;char v[0x10];float speed;};
struct Wheel {char p[0x38];float a,b;char q[8];float c;char r[0x3d];u8 kind;char s[0x62];};
struct Obj {char p[0x10];Owner*owner;char q[0xf0];Data data;};
struct Config {char p[8];u8 mode,a,b,c;};extern Config D_00622110;
struct Axles {u8 x,n;char p[0x3a];s8 sign[16];};
struct Tire {char p[0x164];float x;};
extern "C" void func_0036C098(Data*) throw();
extern "C" int func_0036BF68(Obj*,float) throw();
extern "C" int func_0036BEE0(Obj*,int) throw();
extern "C" int func_0036BF28(Obj*,int) throw();
extern "C" Axles* func_00359510(Owner*);
extern "C" Tire* func_00360F80(Owner*,int,int);
inline bool positive(Axles*a,int i){if(i>=a->n)return false;return a->sign[i]>0;}
inline bool negative(Axles*a,int i){if(i>=a->n)return false;return a->sign[i]<0;}
extern "C" int func_0036C160(Obj*o,int automatic){
 Data*d=&o->data;Owner*p=o->owner;State*s=&p->state;int gear=d->gear;
 if(d->timer)d->timer=d->timer+0xffff;
 if(automatic)func_0036C098(d);
 if(d->delay){d->delay=d->delay+0xff;if(D_00622110.mode==2){if(!d->delay){if(d->b463)d->delay=1;goto fail;}}return -1;}
 if(d->b462)return gear?0:-1;
 {float speed=d->speed;
 if(speed>0x1.1c71c6p-2f && gear==0)return 1;
 if(d->f494>0.0f){if(speed<0x1.1c71c6p-2f)return gear==1?-1:1;}
 else if(speed< -0x1.1c71c6p-2f){if(gear!=0)return 0;goto mode;}
 if(gear>0 && gear<s->count){if(speed>(float)(p->rpm+500)*0x1.acee9cp-4f/s->ratios[gear])return gear+1;}
 mode:
 switch((int)D_00622110.mode){case 0:break;case 1:if(d->b463)return -1;break;case 2:
 if(d->b463>0 && gear<p->state.count){d->delay=1;d->timer=240;return gear+1;}
 if(d->b463<0 && gear>1){d->delay=1;d->timer=240;return gear-1;}
 if(d->timer)return -1;break;}
 if(d->mode!=1)return -1;
 if(automatic){if(!gear)return -1;int g=func_0036BF68(o,speed)+d->bias;int max=p->state.count;if(g>max)g=max;return gear==g?-1:g;}
 if(!gear)return -1;
 int hi,lo;
 if(gear==1){if(s->count==gear)return -1;hi=func_0036BEE0(o,1);lo=-20000;}
 else{if(gear<s->count)hi=func_0036BEE0(o,gear);else hi=20000;lo=func_0036BF28(o,gear);
 float throttle=d->f488;if(throttle<0.0499999970197678f)lo+=D_00622110.b*100;
 if(d->f48c>0x1.999998p-1f)lo+=D_00622110.c*100;
 if(throttle>0.25f)lo-=D_00622110.a*100;}
 int front=0,rear=0;
 switch(s->type){case 1:case 2:case 9:front=1;rear=0;break;case 0:case 4:case 5:case 6:case 7:front=0;rear=1;break;case 3:case 8:case 10:front=1;rear=1;break;}
 Axles*a=func_00359510(p);int rpm=d->rpm;if(rpm<lo)return d->gear-1;if(hi<rpm){
 int result=d->gear+1;
 for(int i=0;i<a->n;++i){
 if((front && positive(a,i)) || (rear && negative(a,i))){Wheel*w=(Wheel*)((char*)o+0x164)+i;if(w->c==0.0f)goto fail;Tire*t=func_00360F80(p,i,w->kind);if(w->a<t->x*w->b)return -1;}}
 return result;
 }
 }
 fail:return -1;
}
