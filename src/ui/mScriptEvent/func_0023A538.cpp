extern char D_00698C18[];
extern "C" void* func_00326750(int,int,void*);
extern "C" void mScriptEvent__structor_0(void*,int,int,int,int);
extern "C" void func_0028E348(void*,void**);
extern "C" void func_0023A538(void* self,int a,int b,int c,int d) {
 void* p=func_00326750(40,4,D_00698C18);
 mScriptEvent__structor_0(p,a,b,c,d);
 void* q=p;
 func_0028E348(self,&q);
}
