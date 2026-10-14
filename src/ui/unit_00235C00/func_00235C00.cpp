extern "C" void func_005769F0(void*);extern "C" void func_00576A28(void*);extern "C" int func_003284E8(void*);extern char D_0082E7C0[];
extern "C" void* func_00235C00(char* self){void** slot=(void**)(self+0xC8);int invalid=0;func_005769F0(D_0082E7C0);if(!*slot||!func_003284E8(*slot))invalid=1;void* result=0;if(!invalid)result=*slot;func_00576A28(D_0082E7C0);return result;}
