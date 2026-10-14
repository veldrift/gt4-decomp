extern "C" void* exception__structor_0(unsigned int);
extern "C" int func_001C9468(void*);
extern "C" void func_001C95B0(void*,int);
extern "C" void* func_00197788(void*);
extern "C" void func_00335558(void*);
extern "C" void* func_005A47D4(void*,const void*,unsigned int);
extern "C" void func_005CD6E8(void*,unsigned char*,unsigned int,const unsigned char*);
extern "C" void func_001CA648(void*,unsigned char*,unsigned int);
struct Vector{int allocator;unsigned char* begin;unsigned char* end;unsigned char* capacity;};
inline void resize(Vector* vec,unsigned int n,const unsigned char& fill){
 unsigned char* finish=vec->end;
 unsigned int size=finish-vec->begin;
 if(size>n){unsigned char* resized=vec->begin+n;func_005A47D4(resized,finish,0);vec->end-=finish-resized;}
 else func_005CD6E8(vec,finish,n-size,&fill);
}
extern "C" void func_0019A698(unsigned char* self,void* input){
 void** slot=(void**)(self+0xa0);
 Vector* vec=(Vector*)(self+0xa4);
 if(!*slot){void* object=exception__structor_0(0x7c);func_001C9468(object);if(*slot)func_001C95B0(*slot,3);*slot=object;}
 void* result=func_00197788(input);if(result)func_00335558(result);
 unsigned char zero=0;
 resize(vec,0xcceb60,zero);
 func_001CA648(*slot,vec->begin,vec->end-vec->begin);
}
