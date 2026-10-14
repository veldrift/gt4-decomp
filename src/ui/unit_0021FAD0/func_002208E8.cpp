extern "C" char D_00698050[];
extern "C" const char* MMovieSetting__makeMoviePath();
extern "C" unsigned func_0057F260(const char*);
extern "C" char* func_005A5DC8(char*,const char*);
extern "C" int func_002208E8(char* dst,unsigned capacity,const char* name,const char* suffix) {
 if(!suffix)suffix=D_00698050;
 const char* prefix=MMovieSetting__makeMoviePath();
 unsigned n=func_0057F260(prefix);n+=func_0057F260(name);n+=func_0057F260(suffix);
 int r=0;
 if(n<capacity){*dst=0;func_005A5DC8(dst,prefix);func_005A5DC8(dst,name);func_005A5DC8(dst,suffix);r=1;}
 return r;
}
