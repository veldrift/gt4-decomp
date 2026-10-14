extern char D_0068BB20[],D_006A5510[];
extern "C" int func_00447C50(char *);
extern "C" int func_00430F40(int,int);
extern "C" char *func_005A6AB0(char *,const char *,int);
extern "C" char *func_005A6900(char *,const char *,int);
extern "C" int func_00430E58(int self,char *name){
 char buf[64];
 int n=func_00447C50(name);
 if(n!=-1)return func_00430F40(self,n);
 func_005A6AB0(buf,D_0068BB20,64);func_005A6900(buf,name,64);
 n=func_00447C50(buf);
 if(n!=-1)return func_00430F40(self,n);
 func_005A6AB0(buf,D_006A5510,64);func_005A6900(buf,name,64);
 n=func_00447C50(buf);
 if(n!=-1)return func_00430F40(self,n);
 return 0;
}
