struct S{char pad[0x7c];void *value;};
extern "C" char D_0082E550[];
extern "C" void func_005769F0(void*),func_00576A28(void*),func_00328660(void*),func_003286B8(void*);
extern "C" void func_0022F178(S*self,void *value){func_005769F0(D_0082E550);void **slot=&self->value;if(value)func_00328660(value);if(*slot)func_003286B8(*slot);*slot=value;func_00576A28(D_0082E550);}
