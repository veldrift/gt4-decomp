struct Field{char pad[0x28];signed char flag;};
struct Owner{char pad[0x10];int p;};
extern "C" void func_0015F3E0(void*,void*);
extern "C" void func_0015F388(void*,int);
extern "C" void func_002FE278(void*,int);
extern "C" void func_002FC870(void*,int);
extern "C" void func_003285A8(int);
extern "C" void func_003285F8(int);
extern "C" void MGame__isSuspended(int*out,void *arg1,int,void*){int buf[4];int nv,old;int p;func_0015F3E0(buf,arg1);p=*(int*)((char*)buf[0]+0x10)+0x38BF8;func_0015F388(buf,2);func_002FE278(buf,((Field*)p)->flag!=0);if(out!=buf){nv=buf[0];if(nv)func_003285A8(nv);old=*out;if(old)func_003285F8(old);*out=nv;}func_002FC870(buf,2);}
