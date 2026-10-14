extern "C" int func_4F9E60(void*,int);extern "C" bool func_4F68C8(void*);extern "C" int func_579358();
extern "C" int func_004FA0E0(char* self,int mode){int i=func_4F9E60(self,*(int*)(self+0xcc4));if(i==-1)return 0;if((mode==0||mode==6)&&func_4F68C8(self))*(int*)(self+0xf6c)=func_579358();*(int*)(self+i*228+0x2280)=mode;return 1;}
