/* compiler: ee-gcc2.96-nogcse */
extern "C" int func_00520108(int,int,int,int*);
extern "C" void func_0053A860(void*);
extern "C" void func_0053A890(void*,unsigned*);
extern "C" int func_0051F930(int self,int p,int n,unsigned timeout) {
 struct Frame { char timer[16]; int done; unsigned elapsed; } f;
 f.elapsed=0; f.done=0;
 func_0053A860(f.timer);
 do {
  int result=func_00520108(self,p,n,&f.done);
  if(result) return result;
  n-=f.done;
  p+=f.done;
  func_0053A890(f.timer,&f.elapsed);
  if(f.elapsed>timeout) return 0xCB25;
 }while(n);
 return 0;
}
