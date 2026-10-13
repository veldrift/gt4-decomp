typedef int s32;
struct Rep{int len,cap,ref,sel;};
struct Str{char*p;};
struct Ref{int p;char pad[12];};
struct Owner{char pad[0x10];char*p;};
extern char D_00692C08[];
extern "C" void func_001A7780(void*);
extern "C" void func_001A7728(void*,int);
extern "C" void func_00312370(void*,void*);
extern "C" void func_00312318(void*,int);
extern "C" Str*func_00314920(int);
extern "C" void*func_005A6AB0(void*,const char*,unsigned int);
static inline const char*c_str(Str*s){
 int len=((Rep*)s->p)[-1].len;
 if(len==0)return D_00692C08;
 s->p[len]=0;
 return s->p;
}
extern "C" void MRunViewer__setCapturePath(void*,void*,int count,void*args){
 int h[4];int buf[4];int*ps;char*dst;
 if(count>0){
 func_001A7780(h);
 ps=buf;
 func_00312370(ps,args);
 dst=((Owner*)h[0])->p;
 func_005A6AB0(dst+0x25C,c_str(func_00314920(*ps)),0x7F);
 func_00312318(ps,2);
 func_001A7728(h,2);
 }
}
