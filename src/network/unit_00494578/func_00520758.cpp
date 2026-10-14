/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Req { void *src; int dst,size,zero; };
extern char D_0064AE80[],D_0064B435[];
extern "C" int func_0057F260(const char *) throw();
extern "C" void func_005A6AB0(void *,const void *,int) throw();
extern "C" int func_005AE060(Req *,int);
extern "C" int func_005AE040(int);
extern "C" int func_005B5E10(int,int,int);
extern "C" int func_005B5E90(int);
extern "C" int func_005B6A20(int,int,char *,unsigned int *);
extern "C" int func_00520758(const char *a,const char *b,unsigned int *out) {
 Req req;
 char buf[0x100];
 char *buffer=buf;
 unsigned int result=0;
 int length;
 char *p;
 *out=0;
 if(b) {
  int n=func_0057F260(a);
  length=n+func_0057F260(b)+2;
  if(length>=0xfb) return 0;
  func_005A6AB0(buffer,a,0xfb);
  p=buffer+func_0057F260(a);
  *p=0;
  p++;
  func_005A6AB0(p,b,0xfb);
  p+=func_0057F260(b);
  *p=0;
 } else {
  length=func_0057F260(a)+1;
  if(length>=0xfb) return 0;
  func_005A6AB0(buffer,a,0xfb);
  p=buffer+func_0057F260(a);
  *p=0;
 }
 unsigned int end=(unsigned int)D_0064B435;
 p=D_0064AE80;
 int size=(end-(unsigned int)p+15)&~15;
 int dst=func_005B5E10(0,size,0);
 if(dst) {
  req.src=p;
  req.dst=dst;
  req.size=size;
  req.zero=0;
  int dma=func_005AE060(&req,1);
  if(dma) {
   while(func_005AE040(dma)>=0) {}
   func_005B6A20(dst,length,buffer,&result);
   *out=result>>8;
  }
  func_005B5E90(dst);
 }
 return 0;
}
