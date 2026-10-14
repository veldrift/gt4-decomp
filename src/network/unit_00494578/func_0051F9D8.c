struct Obj { int type; char pad[0x68]; char ring[16]; };
extern int D_0064AE18;
extern int func_00520108(struct Obj *,int,int,int *);
extern int func_005380D8(void *,int);
extern int func_00538460(void *,int,int);
extern int func_00538558(void *,int *);
extern int func_00538630(void *,int *);
extern int func_00538710(void *,int *);
extern void func_0053A860(void *,int);
int func_0051F9D8(struct Obj *self) {
 int available;
 int wrapped;
 int ptr;
 int amount;
 int result;
 void *ring=self->ring;
 ptr=0;
 available=0;
 amount=0;
 func_00538558(ring,&available);
 if (available) {
 if (self->type==1) {
  wrapped=1;
  func_00538710(ring,&wrapped);
  if(wrapped) {
   result=func_00538460(ring,1,D_0064AE18);
   if(result) return result;
   func_00538558(ring,&available);
  }
 }
 do {
  result=func_00538630(ring,&ptr);
  if(result) return result;
  amount=0;
  result=func_00520108(self,ptr,available,&amount);
  if(result) return result;
  if(amount) func_0053A860((char *)self+0x20,amount);
  result=func_005380D8(ring,amount);
  if(result) return result;
  func_00538558(ring,&available);
 } while(available && amount);
 }
 return 0;
}
