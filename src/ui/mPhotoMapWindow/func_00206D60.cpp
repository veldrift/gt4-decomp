/* compiler: ee-gcc2.96-no-strict-aliasing */
extern "C" int func_00206860(void *) throw();
extern "C" int func_0025C2F8(void *);
extern "C" int func_00206D60(void *self,void *target) {
 int i=0;
 void *p=(void *)func_00206860(self);
 while(p) {
  if(p==target) return i;
  ++i;
  p=(void *)func_0025C2F8(p);
 }
 return -1;
}
