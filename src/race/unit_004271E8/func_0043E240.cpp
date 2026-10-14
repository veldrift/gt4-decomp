extern "C" void func_004442B8(void*);
inline void fillLong(long value,const int& count,unsigned char* self,const int& offset){int n=count-1;long* p=(long*)(self+offset);for(;n>=0;--n)*p--=value;}
inline void fillByte(const int& count,unsigned char* self,const int& offset){int n=count-1;unsigned char* p=self+offset;for(;n>=0;--n)*p--=0;}
extern "C" void func_0043E240(unsigned char* self){unsigned char* p=self+8;for(int n=2;n>=0;--n){func_004442B8(p);p+=0x178;}fillLong(-1L,4,self,0x488);fillByte(12,self,0x49f);*(int*)(self+0x490)=0;}
