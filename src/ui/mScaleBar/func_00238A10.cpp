struct Temp{int a,b,c,d;};
extern "C" void func_0020D738(Temp*,void**,int,void*,void*);extern "C" void func_002319A0(void*,Temp*);extern "C" void func_0020D1B8(Temp*,int);
extern "C" void func_00238A10(char* self,void* output){void** slot=(void**)(self+252);Temp value;if(*slot){func_0020D738(&value,slot,2,output,self);func_002319A0(output,&value);func_0020D1B8(&value,2);}}
