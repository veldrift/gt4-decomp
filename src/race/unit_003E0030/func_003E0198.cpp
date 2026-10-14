/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Text {long head;char eighth,ninth;} __attribute__((packed));
extern "C" Text D_006A37A8;
extern "C" const char D_006A37B8[],D_006A37D0[];
extern "C" void func_0057DA20(char*,const char*,...);
extern "C" void func_003E0198(char*out,unsigned time){
 if(time==0x157529ff){*(Text*)out=D_006A37A8;return;}
 unsigned milliseconds=time%1000;unsigned seconds=time/1000;
 unsigned second=seconds%60;unsigned minutes=seconds/60;
 unsigned minute=minutes%60;unsigned hours=minutes/60;
 if(hours!=0){func_0057DA20(out,D_006A37B8,hours,minute,second,milliseconds);return;}
 func_0057DA20(out,D_006A37D0,minute,second,milliseconds);
}
