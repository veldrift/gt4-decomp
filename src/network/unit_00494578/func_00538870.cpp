extern char* D_0064B70C;
extern int func_00538830(void*);
extern void* func_005A4724(void*,const void*,int);
extern void* func_005A48D8(void*,int,int);
extern "C" int func_00538870(int type,void* out){
 int result=0;
 if(type==(-2147483647-1)){
  if(func_00538830(D_0064B70C+4))result=-3;
  if(out)func_005A4724(out,D_0064B70C+4,64);
 }else if(type==-1){
  if(func_00538830(D_0064B70C+0x104))result=-3;
  if(out)func_005A4724(out,D_0064B70C+0x104,64);
 }else{
  if(func_00538830(D_0064B70C+0x84))result=-3;
  if(out)func_005A4724(out,D_0064B70C+0x84,64);
 }
 if(out && result)func_005A48D8(out,0,64);
 return result;
}
