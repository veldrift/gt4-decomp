extern "C" char D_0082E550[];
extern "C" void func_005769F0(int);
extern "C" void func_00576A28(int);
extern "C" void func_00328660(void*);
extern "C" void func_003286B8(void*);
inline void assign(void**p,void*object){if(object)func_00328660(object);if(*p)func_003286B8(*p);*p=object;}
extern "C" void func_0022F080(void*self,void*object){func_005769F0((int)D_0082E550);assign((void**)((char*)self+0x78),object);func_00576A28((int)D_0082E550);}
