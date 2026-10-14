/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Thread { int sema; };
extern Thread D_0086CB80;
extern "C" void func_00578500(int);
extern "C" int func_00578168(Thread*,int,int,void*,int);
extern "C" int func_005487C0() {
 int *p;
 {
  int n=128;
  char buf[n];
  p=(int*)(((unsigned)buf+63)&~63U);
  func_00578500(D_0086CB80.sema);
  func_00578168(&D_0086CB80,4,0,p,64);
 }
 int result=-1;
 if(p[0]) result=p[1];
 return result;
}
