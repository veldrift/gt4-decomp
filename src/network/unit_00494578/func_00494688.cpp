/* compiler: ee-gcc2.96-no-strict-aliasing */
struct V3 { float x,y,z; };
struct V2 { float x,y; };
extern "C" void func_004949A0(void*);
extern "C" void func_00494780(void*,V3*,V3*,V2*,unsigned*);
extern "C" void func_00494688(void* p,V3* a,V3* b,V2* c,unsigned* d,int n){
 int i=0;
 func_004949A0(p);
 for(;i<n;i++){
  func_00494780(p,a ? &a[i] : 0,b ? &b[i] : 0,c ? &c[i] : 0,d ? &d[i] : 0);
 }
 func_004949A0(p);
}
