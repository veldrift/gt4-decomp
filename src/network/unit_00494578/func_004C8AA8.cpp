/* compiler: ee-gcc2.96-no-strict-aliasing */
extern "C" void func_004C8B50(void*,void*);
extern "C" void func_004C8C38(void*,void**);
extern "C" void func_004C8AA8(void *self,void **p,int n) {
 if(p) {
  void **base=p;
  while(n--) {
   func_004C8B50(self,*p++);
  }
  return func_004C8C38(self,base);
 }
}
