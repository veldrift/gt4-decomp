extern char D_0068BB20[],D_006A5510[];
extern "C" long long func_00447C50(const char *);
struct Slot;
extern "C" Slot* func_00430E08(void*,long long);
extern "C" char *func_005A6AB0(char *,const char *,int);
extern "C" char *func_005A6900(char *,const char *,int);
extern "C" Slot* func_00430D20(void* self,const char *name){
 char buf[64];
 long long n=func_00447C50(name);
 if(n!=-1)return func_00430E08(self,n);
 func_005A6AB0(buf,D_0068BB20,64);func_005A6900(buf,name,64);
 n=func_00447C50(buf);
 if(n!=-1)return func_00430E08(self,n);
 func_005A6AB0(buf,D_006A5510,64);func_005A6900(buf,name,64);
 n=func_00447C50(buf);
 if(n!=-1)return func_00430E08(self,n);
 return 0;
}
