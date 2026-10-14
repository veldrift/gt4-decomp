/* compiler: ee-gcc2.96-no-strict-aliasing */
extern "C" int func_00206868(void *) throw();
extern "C" void func_00206888(void *,int,void *) throw();
extern "C" int func_0025C300(void *);
extern "C" void func_00206DC8(void *self,int index,int child) {
 void *found=0;
 if(index>=0) {
  int i=0;
  void *p=(void *)func_00206868(self);
  while(p) {
   if(i==index) { found=p; break; }
   p=(void *)func_0025C300(p);
   ++i;
  }
 }
 func_00206888(self,child,found);
}
