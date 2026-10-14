/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Inner { char pad[0x60]; int current[4]; char pad70[0x20]; float scale[4]; };
struct Obj { union { struct { char pad[0x50]; int current[4]; char pad60[0x20]; float value[4]; } a; struct { char pad[8]; Inner in; } b; }; };
struct Ctx { char pad[0x9684]; int status[4]; };
extern "C" int func_0034C190(int);
extern "C" void func_003CBA88(Obj *,int,Ctx *,int);
extern "C" int func_003CBD00(Obj *,int,int,Ctx *,int,int,int);
static inline void clear(Obj *o,int i,float z) {
    o->a.current[i] = 0;
    o->b.in.current[i] = 0;
    o->a.value[i] = z;
    o->b.in.scale[i] = z;
}
extern "C" void func_003CB990(Obj *o,int i,Ctx *ctx,int id) {
    func_0034C190(id);
    int status = ctx->status[i];
    if (status == 0) {
        clear(o,i,0.0f);
        return;
    }
    if (status == 5) return func_003CBA88(o,i,ctx,-1);
    int next = func_003CBD00(o,id,i,ctx,-1,status,0);
    func_003CBA88(o,i,ctx,next);
}
