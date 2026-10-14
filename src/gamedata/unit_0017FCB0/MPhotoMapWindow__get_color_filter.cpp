// Reconstructed void callback contract follows the explicit output protocol and audited callers.
// The spelling of the original stripped callback typedef is not claimed.
struct Object;struct Str;struct Entry{short adjustment,unused;void(*call)();};struct Object{unsigned count;Entry*vtable;};
extern "C" void func_003285A8(Object*),func_003285F8(Object*);
struct Handle{Object*p;Handle(){}Handle(const Handle&) asm("func_00309348");};
struct Rep{int size,capacity,refs,unique;};
extern "C" Rep D_00659FA8;
extern "C" char*func_005C2560(Rep*);
extern "C" unsigned func_0057F260(const char*) throw();
struct Str;
extern "C" Str*func_005C2630(Str*,unsigned,unsigned,const char*,unsigned);
extern "C" Object**func_005C11A8();
extern "C" void func_00326798(void*,unsigned,int,Object*);
inline void releaseRep(Rep*r,unsigned capacity){capacity+=16;Object*allocator=*func_005C11A8();func_00326798(r,capacity,4,allocator);}
struct Str{
 char*p;
 Str(const Str &other){Rep*r=(Rep*)(other.p-16);if(r->unique)p=func_005C2560(r);else{++r->refs;p=(char*)(r+1);}}
 Str(){Rep*r=&D_00659FA8;char*data;if(r->unique)data=func_005C2560(r);else{++r->refs;data=(char*)(r+1);}p=data;}
 Str(const char*s){Rep*r=&D_00659FA8;char*data;if(r->unique)data=func_005C2560(r);else{++r->refs;data=(char*)(r+1);}p=data;unsigned n=func_0057F260(s);func_005C2630(this,0,-1,s,n);}
 ~Str(){Rep*r=(Rep*)(p-16);if(--r->refs==0)releaseRep(r,r->capacity);}
};

struct Shell{Object*p;Shell(const Shell&) asm("func_002009F8");Shell(const Handle&) throw() asm("func_00192A58");~Shell() throw() asm("func_00192A00");};
struct StringHandle{Object*p;StringHandle(const StringHandle&) asm("func_00309348");StringHandle(const Str&) asm("func_00314B20");~StringHandle() asm("func_00312318");};
extern "C" const char*D_00618AE8[];
extern "C" int func_005CD320(const Str*,const char*,unsigned,unsigned);
inline void assign(Handle*out,const StringHandle*from){if((void*)out!=(void*)from){Object*n=from->p;if(n)func_003285A8(n);if(out->p)func_003285F8(out->p);out->p=n;}}
inline void*operator new(unsigned,void*p){return p;}
inline Str stringValue(Object*self){Entry*e=self->vtable+3;return ((Str(*)(Object*))e->call)((Object*)((char*)self+e->adjustment));}
extern "C" void MPhotoMapWindow__get_color_filter(Handle*out,const Handle*context,int count,const Handle*args){
 Handle shellSlot;
 if(count==0){new(&shellSlot)Shell(*context);int index=*(int*)((char*)((Shell*)&shellSlot)->p+0x120);Handle resultSlot;{Str text(D_00618AE8[index]);StringHandle*result=new(&resultSlot)StringHandle(text);assign(out,result);result->~StringHandle();new(&resultSlot)Handle();}((Shell*)&shellSlot)->~Shell();new(&shellSlot)Handle();}
 else if(count==1){new(&shellSlot)Shell(*context);{Str text=stringValue(args->p);int i=0;do{const char*name=D_00618AE8[i];if(!func_005CD320(&text,name,0,func_0057F260(name))){*(int*)((char*)((Shell*)&shellSlot)->p+0x120)=i;break;}++i;}while(i<3);}((Shell*)&shellSlot)->~Shell();new(&shellSlot)Handle();}
}
