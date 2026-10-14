/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
struct E { short delta, index; int (*fn)(void *); };
struct O { int ref; E *vt; };
struct H { O *p; char pad[12]; };
struct Vec { int alloc; int *start,*finish,*end; char pad[16]; };
struct Tag { const char *name; };
extern char D_0069D2A0[],D_0069D2A8[];
extern "C" void func_002F41E0(void*,void*);
extern "C" void func_002F41F8(void*,void*);
extern "C" void func_002F4210(void*,int);
extern "C" void hCode__structor_0(void*,void*);
extern "C" void func_002F4A10(void*,void*);
extern "C" void func_002F6748(void*,int);
extern "C" int func_002F70A0(void*,void*,int);
extern "C" void func_002F7390(void*,void*);
extern "C" void func_00309348(void*,void*);
extern "C" void *func_00326750(unsigned int,int,const char*);
extern "C" void func_00326798(void*,int,int,const char*);
extern "C" void func_003285A8(void*);
extern "C" void func_003285F8(void*);
extern "C" int func_0057F238(const char*,const char*) throw();
extern "C" Tag *HSymID__tf();
static inline int read(H *h) { O *p=h->p; E *e=p->vt+55; return e->fn((char*)p+e->delta); }
static inline void finish(H *h) { O *p=h->p; E *e=p->vt+54; ((void(*)(void*))e->fn)((char*)p+e->delta); }
static inline int *value_type(int **) {return 0;}
static inline void destroy_aux(int *p,int *last,int *) {for(;p!=last;++p) {}}
extern "C" void *func_002EA7D0(void *out,void*,void *in) {
 H result;
 char scratch[2048];
 H stream;
 char magic[16];
 H temp;
 Vec vec;
 int *iter;
 int zero;
 void *raw;
 zero=0;
 func_002F41E0(&result,&zero);
 H *ps=&stream;
 func_002F7390(ps,scratch);
 if(func_002F70A0(ps->p,in,0x81)) {
  int i=0; char *pm=magic;
  do { int c=read(ps); pm[i]=c; i++; } while(i<7);
  magic[7]=read(ps);
  if(func_0057F238(pm,D_0069D2A0)==0) {
   H *pt=&temp;
   Vec *pv=&vec;
   void **pr=&raw;
   pv->start=0; pv->finish=0; pv->end=0;
   void *code=func_00326750(0x3c,4,D_0069D2A8);
   hCode__structor_0(code,pv);
   raw=code;
   func_00309348(pt,pr);
   if(&result!=pt) {
    O *n=pt->p;
    if(n) func_003285A8(n);
    if(result.p) func_003285F8(result.p);
    result.p=n;
   }
   func_002F4210(pt,2);
   iter=vec.start;
   destroy_aux(iter,vec.finish,value_type(&iter));
   int *p=pv->start;
   int n=pv->end-p;
   if(p) func_00326798(p,n*4,4,HSymID__tf()->name);
   func_002F4A10(result.p,ps);
  } else { if(magic[7]) magic[7]=0; }
  finish(ps);
 }
 func_002F41F8(out,&result);
 func_002F6748(ps,2);
 func_002F4210(&result,2);
 return out;
}
