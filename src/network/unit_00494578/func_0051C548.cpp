struct Context { int ready; int handle; };
struct Ops { char pad[0x2c]; int (*run)(int,int *,long long,int); };
extern Context D_00863798;
extern Ops *D_0064B4B0;
extern "C" {
int func_0051BE28() throw();
int func_0051BE60() throw();
int func_0051C548(int *p,long long value,int n) {
 volatile long long copy=value;
 int r=func_0051BE28();
 if(r==0) {
  *p=0;
  int v;
  if(D_00863798.ready) v=D_0064B4B0->run(D_00863798.handle,p,copy,n);
  else v=5;
  func_0051BE60();
  r=v;
 }
 return r;
}
}
