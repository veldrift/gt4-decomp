/* compiler: ee-gcc2.96-no-strict-aliasing */
extern "C" void *func_00322058(void *);
extern "C" void *func_003055C8(void *);
extern "C" void func_00306B08(void *,void **,int);
extern "C" void func_00321E38(void *self,void **out,int key) {
 void *p=func_00322058(self);
 func_00306B08(p,out,key);
 if(!*out) {
  for(void *q=func_003055C8(p);q!=0;q=func_003055C8(q)) {
   func_00306B08(q,out,key);
   if(*out) return;
  }
 }
}
