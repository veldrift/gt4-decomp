/* compiler: ee-gcc2.96-no-strict-aliasing */
extern "C" void func_00576788(void*);
extern "C" void func_005767C0(void*);
extern "C" void func_00323B30(void*,void*);
extern "C" void func_00323B60(void*,int);
extern "C" void func_003285A8(void*);
extern "C" void func_003285F8(void*);
struct Sym{int id;Sym&operator=(const Sym&x){if(this!=&x)id=x.id;return *this;}};
extern Sym D_00841B80;
struct Handle {void *p;char pad[12];};
struct Tmp:Handle{Tmp(void*z){func_00323B30(this,z);}~Tmp(){func_00323B60(this,2);}};
static inline void assign(Handle *a,Handle *b){if(a!=b){void*p=b->p;if(p)func_003285A8(p);if(a->p)func_003285F8(a->p);a->p=p;}}
struct Entry{char pad[0x30];int tag;Sym key;void *handle;};
extern "C" void func_00325860(char*self){
char *cur=self;
func_00576788(self);
for(int i=0;i<2048;){
Entry *e=(Entry*)cur;
e->tag=0;e->key=D_00841B80;
Handle h;int zero=0;func_00323B30(&h,&zero);
Handle *dst=(Handle*)&e->handle;cur+=12;
assign(dst,&h);
func_00323B60(&h,2);++i;

}
func_005767C0(self);
}
