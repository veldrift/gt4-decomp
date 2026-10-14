/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Vec { int a; int *begin,*end,*cap; };
struct Self { int a,b; Vec names; void *handle; };
extern "C" int func_003284E8(void *);
extern "C" void *func_00306E80(void *);
extern "C" void *func_00322060(void *);
extern "C" void func_0030BB18(void *);
extern "C" void *func_0030F628(void *,void *,int);
extern "C" void func_003069F8(void *,void *,void *);
extern "C" int func_00304258(void *,void *);
extern "C" void HModule__dynamicAssign(void *,void *);
extern "C" void func_003041B8(void *,int);
extern "C" void *func_00306638(void *,void *,void *);
extern "C" void func_00323B60(void *,int);
extern "C" void func_00309378(void *,int);
extern "C" void func_00321AE8(void *,void *,void *);
extern "C" void func_003285A8(void *);
extern "C" void func_003285F8(void *);
extern "C" void func_00328660(void *);
extern "C" void func_003286B8(void *);
extern "C" void HModuleFrame__structor_0(void *,void *) throw();
static inline void *get(void **p) { int bad=0; if(*p==0 || func_003284E8(*p)==0) bad=1; void *v=0; if(!bad)v=*p; return v; }
static inline void assign(void **dst,void **src) { if(dst!=src) { void *p=*src; if(p)func_003285A8(p); if(*dst)func_003285F8(*dst); *dst=p; } }
extern "C" void mModuleDefine__execute(Self *self,void *thread) {
 void **h=&self->handle;
 if(get(h)==0) {
  Vec *names=&self->names;
  void *module[4];
  func_00306E80(module);
  if((unsigned)(names->end-names->begin)<2) {
   void *context=func_00322060(thread);
   void *value[4];
   void *symbol[4];
   func_0030BB18(value);
   func_0030F628(symbol,names,0);
   func_003069F8(context,value,symbol);
   if(func_00304258(module,value)==0) {
    void *symbol2[4];
    func_0030F628(symbol2,names,0);
    HModule__dynamicAssign(symbol,symbol2);
    assign(module,symbol);
    func_003041B8(symbol,2);
    func_00306638(symbol,context,module);
    func_00323B60(symbol,2);
   }
   func_00309378(value,2);
  } else {
   void *result[4];
   func_00321AE8(result,thread,names);
   assign(module,result);
   func_003041B8(result,2);
  }
  void *p=module[0];
  if(p)func_00328660(p);
  if(*h)func_003286B8(*h);
  *h=p;
  func_003041B8(module,2);
 }
 HModuleFrame__structor_0(thread,get(h));
}
