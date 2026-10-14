/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Flag { int v; };
extern volatile Flag D_0064C710,D_0064C714;
struct Port { int id; char state[0x3c]; int pending; char out[0x28]; };
extern char D_0086FC80[];
extern char D_0086F980[];
extern void *D_0086FD58;
extern "C" void func_00551758();
extern "C" void func_00551568(void *) throw();
extern "C" void *func_00575098(void *,void *);
extern "C" void func_00577F80();
extern "C" void *func_00578610(void *);
extern "C" int func_005788B8(void *);
extern "C" void *func_00578B50(unsigned int,int);
extern "C" int func_0058ED00(int);
extern "C" int func_0058EDA8(void *,void *);
extern "C" void *func_005A48D8(void *,int,unsigned int);
union Buffer { int words[8]; struct { void (*fn)(); int zero; } cb; };
extern "C" void func_00551810() {
 Buffer b;
 if (D_0064C710.v==0) {
  D_0064C710.v=1;
  D_0064C714.v=0;
  while (func_0058ED00(0)!=1) func_00577F80();
  char *base=D_0086FC80;
  char *buf=D_0086F980;
  for (int i=0,two=2,off=0; i<2; ++i,buf+=0x100,off+=0x6c) {
   Port *p=(Port *)(off+(int)base);
   func_005A48D8(&b,0,0x20);
   b.words[0]=two;
   b.words[1]=i!=0;
   func_005A48D8(p,0,0x6c);
   func_00551568(p->state);
   while ((p->id=func_0058EDA8(&b,buf))<0) func_00577F80();
  }
  D_0064C714.v=1;
  b.cb.fn=func_00551758;
  b.cb.zero=0;
  void *r=func_00575098(&b,func_00578610(func_00578B50(3,0)));
  D_0086FD58=r;
  func_005788B8(r);
 }
}
