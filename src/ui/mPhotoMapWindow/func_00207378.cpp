struct V{short d,i;void(*fn)(void*,void*);};
extern "C" void func_231508(void*,void*);
extern "C" void func_231798(void*,void*);
extern "C" void func_00207378(void*,void* a,char* b){func_231508(a,b);V* v=(V*)(*(char**)(b+4)+0x2e8);v->fn(b+v->d,a);func_231798(a,b);}
