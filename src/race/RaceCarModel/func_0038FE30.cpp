extern "C" void *func_004510E0(void *);
extern "C" void func_0044F4A8();
extern "C" void func_003B0FD0(void *,void *);
extern "C" void func_003B1C98(void *,void *);
extern "C" int func_0038FE30(void *self,int other) {
void *first=(char *)self+0x5E0;void *resource=func_004510E0((char *)self+0x18);if(!resource) return (int)resource;func_0044F4A8();func_003B0FD0(first,resource);if(other) func_003B1C98((char *)self+0xE20,first);return 1;}
