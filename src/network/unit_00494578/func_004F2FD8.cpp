/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Info { int words[25]; };
struct Payload { char pad[0x1d8]; Info info; };
struct Context { char pad[0x5a8]; Payload *data; };
extern Context D_00645570;
extern char D_006C0490[];
extern "C" int func_004F0B08(Context *,Info *) throw();
extern "C" int func_004F0C38(Context *,const char *) throw();
extern "C" void func_004F87E8(Context *,int);
struct Guard {
    Context *ctx;
    Info *info;
    Guard(Context *c,Info *i) : ctx(c),info(i) {}
    ~Guard() { func_004F0B08(ctx,info); }
};
extern "C" void func_004F2FD8(Info *info,Context *ctx) {
    if (!ctx) ctx=&D_00645570;
    Guard g(ctx,info);
    if (func_004F0C38(ctx,D_006C0490)) return;
    ctx->data->info=*info;
    func_004F87E8(ctx,info->words[6]);
}
