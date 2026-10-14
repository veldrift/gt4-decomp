extern int D_0083CE50;
extern "C" void hModule__findModuleValue(void*,int*,int*);
extern "C" void* func_002F3A28(void*);
extern "C" void func_00305F80(void*,int*,int*);
extern "C" void func_002F3478(void* self,int* a,int* b){hModule__findModuleValue(self,a,b);if(*a)return;if(*b==D_0083CE50)return;void* p=func_002F3A28(self);if(p){func_002F3478(p,a,b);func_00305F80(self,b,a);}}
