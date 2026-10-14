/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Obj { int a,state; char data[0x60]; int n; };
extern "C" void AutomobileControlRecord__Recorder__save(void *,int *) throw();
extern "C" void func_00346890(Obj *,int) throw();
extern "C" void func_00346EB0(Obj *,int *);
extern "C" void AutomobileControlRecord__Manager__save(Obj *self,int *out) {
 int pos=*out;
 *out=pos+4;
 int *header=(int *)((char *)out+pos);
 switch(self->state) {
 case 0:
  *header=0;
  return AutomobileControlRecord__Recorder__save(self->data,out);
 case 1:
  *header=self->n;
  for(int i=0;i<self->n;i++) {
   func_00346890(self,i);
   func_00346EB0(self,out);
  }
  return;
 case 2:
  *header=1;
  return func_00346EB0(self,out);
 }
}
