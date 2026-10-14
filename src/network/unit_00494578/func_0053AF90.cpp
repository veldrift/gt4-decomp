typedef unsigned int u32;
struct Time { u32 ms,sec,min,hour; u32 a,b,c,d,tick; };
extern unsigned char D_0064C10E;
extern Time D_0086B418;
extern char D_006C3A48[];
extern "C" int func_0053AE58() throw();
extern "C" int func_0053A7D0(u32 *) throw();
extern "C" void func_0057DA20(char *,const char *,...);
extern "C" int func_0053AF90(char *out) {
 if(!out) return 2;
 if(!D_0064C10E) {
  if(func_0053AE58()!=0) return 0x640;
  D_0064C10E=1;
 }
 Time t=D_0086B418;
 u32 now;
 if(func_0053A7D0(&now)!=0) return 0x640;
 t.ms+=now-D_0086B418.tick;
 t.sec+=t.ms/1000U;
 t.ms%=1000U;
 t.min+=t.sec/60U;
 t.sec%=60U;
 t.hour+=t.min/60U;
 t.min%=60U;
 t.hour%=24U;
 func_0057DA20(out,D_006C3A48,t.hour,t.min,t.sec);
 return 0;
}
