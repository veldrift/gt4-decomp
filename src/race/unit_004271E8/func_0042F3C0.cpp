struct Command { unsigned char type,x,y,z; int mode; long handle; };
extern "C" long func_004409D8(const char*);
extern "C" void func_0042F0E0(void*,Command*);
extern "C" void func_0042F3C0(void*self,const char*input,unsigned char x,unsigned char y){Command c;c.type=6;c.x=x;c.y=y;c.handle=func_004409D8(input);func_0042F0E0(self,&c);}
