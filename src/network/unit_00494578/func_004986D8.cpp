/* compiler: ee-gcc2.96-no-strict-aliasing */
extern "C" void *func_00496C28() throw();
extern "C" void func_00497F98(void *,void *,float,float,float,float) throw();
extern "C" void func_004A1638(int);
extern "C" void func_004A2808(int,float);
extern "C" void func_004A29A8(int);
extern "C" void func_004A53F8();
extern "C" void func_004A5400();
extern "C" void func_004A747C();
extern "C" void func_004A74A0();
extern "C" void func_004A7844(float,float,float);
extern "C" void func_004A7890(float,float,float);
extern "C" void func_004AB040(int);
extern "C" void func_004986D8(void *a,float *b,float x,float y,float z,float scale,float s) {
 if(!(s<=0.0f)) {
  func_004A29A8(0);
  func_004AB040(5);
  func_004AB040(15);
  func_004AB040(4);
  func_004A2808(72,0.0f);
  func_004A53F8();
  func_004A74A0();
  func_004A7844(b[0],b[1],b[2]);
  func_004A747C();
  func_004A7890(s,s,s);
  func_00497F98(a,func_00496C28(),x,y,z,scale);
  func_004A5400();
  func_004A29A8(1);
  return func_004A1638(15);
 }
}
