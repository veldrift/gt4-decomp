// Name pointer and full64 key are independently traced through 00443E00.
// Existing void metadata for this mutator and queue helper remains unasserted.
struct Packet{unsigned char kind,a,b;int value;long data;};
extern "C" long long func_00447C50(const char*);
extern "C" void func_0042F0E0(void*,Packet*);
extern "C" void func_0042F270(void*self,const char* arg,unsigned char a,unsigned char b,int value){Packet p;p.kind=3;p.data=func_00447C50(arg);p.a=a;p.b=b;p.value=value;func_0042F0E0(self,&p);}
