struct Context { char pad[8]; char name[256]; char buffer[256]; unsigned int offset; int error; };
extern const char *D_0064C154;
extern char D_006C49B8[],D_006C49C0[],D_006C49C8[];
extern "C" int func_0053F280(char *,unsigned int *,const char *) throw();
extern "C" int func_00594470(const char *,const char *,unsigned int);
extern "C" void func_005A6AB0(void *,const void *,int) throw();
extern "C" void func_0053F400(const char *str,const char **attrs,Context *ctx) {
    if (ctx->error == 0) {
        if (!func_0053F280(ctx->buffer,&ctx->offset,str)) ctx->error = 1;
        if (func_00594470(D_006C49B8,str,256) == 0) {
            for (int i = 0; attrs[i]; i++) {
                switch(i) {
                case 0:
                    if (func_00594470(D_006C49C0,attrs[0],256) != 0) ctx->error = 1;
                    break;
                case 1:
                    if (func_00594470(D_0064C154,attrs[1],256) != 0) ctx->error = i;
                    break;
                }
            }
        } else if (func_00594470(D_006C49C8,str,256) == 0) {
            func_005A6AB0(ctx->name,str,256);
        }
    }
}
