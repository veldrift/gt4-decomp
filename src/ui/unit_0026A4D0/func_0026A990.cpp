extern "C" void func_003285A8(void*),func_003285F8(void*);
struct Ref { void* p; Ref() asm("func_00210810"); Ref(const Ref&) asm("func_002106F8"); ~Ref() asm("func_00210710"); Ref& operator=(const Ref& o) {if(this!=&o){void* q=o.p;if(q)func_003285A8(q);if(p)func_003285F8(p);p=q;}return *this;} };
struct Str {char* p;};
struct Entry {short adjustment;short unused;Ref(*call)(void*,Str*,int,int);};
struct Service {int unknown;Entry* table;};
struct Obj {char unknown[16];Service* service;};
extern "C" int mRootWindow__getDataCache(Obj*,Ref*,Str*);
extern "C" void func_0026A698(Obj*,Str*,Ref*);
extern "C" Ref func_0026A990(Obj* self,Str* key,int cached,int a,int b) {
 Ref result;
 if(cached && mRootWindow__getDataCache(self,&result,key))return result;
 Service* service=self->service;
 Entry* e=service->table+70;
 result=e->call((char*)service+e->adjustment,key,a,b);
 if(cached)func_0026A698(self,key,&result);
 return result;
}
