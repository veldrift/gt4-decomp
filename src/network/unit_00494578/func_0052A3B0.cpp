extern int func_005293D0(void*,const void*,void**);
extern "C" int func_0052A3B0(void* self,const void* input,void** out){
 *out=0;
 if(!self)return 0xd2f2;
 int result=func_005293D0(self,input,out);
 if(!result)*(short*)((char*)*out+0x6e)=0;
 return result;
}
