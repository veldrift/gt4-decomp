extern int D_0064A220;
extern int D_0064A224;
extern int D_0064A228;
extern char D_006C15D0[];
extern char D_00853540[];
extern "C" int func_0050F440(void);
extern "C" int func_0050A5D8(int *);
extern "C" int func_0050A560(int *,unsigned);
extern "C" int func_0050F600(int,int,int *);
extern "C" void func_0053B310(void *,void **);
extern "C" void func_0057D9C0(const char *,...);
extern "C" int func_00509438(int *out,int *count,int *result) {
 void *tmp[4];
 int n=func_0050F440();
 int *data=&D_0064A220;
 func_0050A5D8(data);
 int *size=&D_0064A224;
 int *used=&D_0064A228;
 *size=0;
 *used=0;
 if(func_0050A560(data,n)!=0) {
  func_0057D9C0(D_006C15D0,n);
  return -4;
 }
 *size=n;
 if(n==0) {
  *count=0;
  *out=0;
  *result=0;
  return -8;
 }
 func_0050F600(*data,n,used);
 if(*data==0) {
  *count=0;
  *out=0;
  *result=0;
  return -8;
 }
 func_0053B310(D_00853540,tmp);
 *out=*data;
 *count=*used;
 *result=(int)tmp[0];
 return 0;
}
