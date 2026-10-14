struct Obj { char pad[8]; int handle,state; char pad10[12]; int ready; };
extern "C" int func_005220F8(Obj*);
extern "C" int func_005216D8(Obj*,int*);
extern "C" int func_00522AE0(int,int,int,int*);
extern "C" int func_005221B0(int,int,int);
extern "C" int func_00520EB0(Obj* self,int a,int b,int* out) {
 *out=0;
 if(!func_005220F8(self))return 2;
 int state=self->state;
 if(state!=0 && state!=2)return 0xC355;
 if(!self->ready && !state){
  int value=0;
  int result=func_005216D8(self,&value);
  if(result)return result;
  if(!value){*out=0;return 0;}
  self->ready=1;
 }
 int result=func_00522AE0(self->handle,a,b,out);
 if(result)return result;
 func_005221B0(*out,0,0x28);
 return 0;
}
