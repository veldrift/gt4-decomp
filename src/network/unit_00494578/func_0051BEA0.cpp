extern int D_0064AE0C,D_0064AE20,D_0064AE14,D_0064AE10,D_0064B710;
extern char D_008637A8[],D_00863798[];
struct API { int a,b; int (*fn)(); };
extern API *D_0064B4B0;
extern "C" void *func_00538760(int,char *);
extern "C" int func_00539788(void *);
extern "C" void *func_005A48D8(void *,int,unsigned int);
extern "C" int func_0051BEA0(char *p) {
 if(D_0064AE0C==0) {
  int result=D_0064B4B0->fn();
  if(result) return result;
  result=func_00539788(D_008637A8);
  if(result) return result;
  D_0064AE20=1;
  D_0064AE14=0;
  D_0064AE10=0;
  func_005A48D8(D_00863798,0,12);
  if(D_0064B710) func_00538760(0,p);
 }
 D_0064AE0C++;
 return 0;
}
