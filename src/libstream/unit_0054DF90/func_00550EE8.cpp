/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Result {char data[0x40];};
struct Ctx {int handle; char pad[0x3C]; char path[0x40];};
extern Ctx D_0086F800;
extern "C" void func_00578500(int);
extern "C" char *func_005A609C(char*,const char*);
extern "C" int func_00578168(void*,int,int,void*,int);
extern "C" Result func_00550EE8(const char *path) {
 int n=0x80;
 char buffer[n];
 Result *p=(Result*)(((unsigned int)buffer+0x3F)&~0x3F);
 Ctx *ctx=&D_0086F800;
 func_00578500(ctx->handle);
 func_005A609C(ctx->path,path);
 func_00578168(ctx,1,0,p,0x40);
 return *p;
}
