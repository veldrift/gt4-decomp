/* compiler: ee-gcc2.96-no-strict-aliasing */
extern "C" void free(void*) throw();
struct Vec { int pad; unsigned char *begin,*end,*cap; ~Vec(){if(begin)free(begin);} };
struct Rng { unsigned x[4]; };
struct MT { char b[0x9d0]; };
struct Entry { short delta,index; int (*fn)(void*,char*,void*,unsigned); };
struct File { Entry *vt; };
extern char *D_00622F4C;
extern "C" unsigned func_001CE578() throw();
extern "C" void *func_00575E60(int,unsigned);
extern "C" void free(void*) throw();
extern "C" unsigned char *func_005CDD50(unsigned char*,int,unsigned char*);
extern "C" void func_005792E8(Rng*,int);
extern "C" unsigned func_00579330(Rng*);
extern "C" int func_00579420(MT*,int);
extern "C" unsigned func_005794C0(MT*);
extern "C" void *func_005A48D8(void*,int,unsigned);
extern "C" int func_001CBAD0(void*,int) throw();
extern "C" void func_001CBB48(void*,int,int) throw();
extern "C" unsigned long func_004359E0(char*);
extern "C" void func_001CB8D8(void*,unsigned long) throw();
extern "C" void func_001CB900(void*) throw();
extern "C" char *func_001CE460(void*,char*) throw();
static inline void reserve(Vec *v,unsigned n) {
 v->begin=0;v->end=0;v->cap=0;
 unsigned char *p=n?(unsigned char*)func_00575E60(0x40,n):0;
 v->begin=p;v->end=p;v->cap=p+n;
}
extern "C" long func_001CE630(void *self,File *file) {
 Vec vec;char gap[0x10]; Rng rng;MT mt;char path[0x50];unsigned char zero;
 char *g=D_00622F4C+0xbc30;
 int seed=*(int*)(g+0x81cc);
 unsigned n=func_001CE578();
 Vec *v=&vec;reserve(v,n);
 unsigned i=0x40;unsigned char *start=v->begin;zero=0;
 rng.x[0]=(unsigned)start;
 v->end=func_005CDD50(start,n,&zero);
 Rng *r=&rng;func_005792E8(r,seed);
 MT *m=&mt;func_00579420(m,seed);
 for(;i<n;) { unsigned a=func_005794C0(m);unsigned char *p=vec.begin+i;i++;*p=func_00579330(r)^a; }
 unsigned char *data=vec.begin;
 func_005A48D8(data,0,0x40);
 *(int*)(data+0x38)=seed;
 func_001CBAD0(data,*(int*)(g+0x81f0));
 func_001CBB48(data,0,1);
 func_001CB8D8(data,func_004359E0(g));
 int saved=*(int*)(data+0x3c);func_001CB900(data);
 func_001CE460(self,path);
 Entry *e=file->vt+16;
 if(__builtin_expect(e->fn((char*)file+e->delta,path,vec.begin,n),0)!=0) {
  return 0;
 }
 *(int*)(g+0x81f0)=saved;*(int*)(g+0x81e0)=1;
 return 1;
}
